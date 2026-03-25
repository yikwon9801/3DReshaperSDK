#pragma once

namespace Kernel
{
	inline const BYTE Clamp(const INT iValue)
	{
		if (iValue < 0) return 0;
		if (iValue > 255) return 255;
		return static_cast<const BYTE>(iValue);
	}
	inline const BYTE At_Clamp(const BYTE img[], const UINT x, const UINT y, const UINT w, const UINT h)
	{
		return img[y * w + x];
	}
	inline void DemosaicNearestRGGB(const BYTE raw[], const UINT w, const UINT h, BYTE rgb_out[])
	{
		for (UINT y = 0; y < h; y++)
		{
			for (UINT x = 0; x < w; x++)
			{
				const BOOL y_even = (y % 2 == 0);
				const BOOL x_even = (x % 2 == 0);

				const UINT idx = (y * w + x) * 3;
				INT R = 0, G = 0, B = 0;

				if (y_even && x_even)
				{ // R
					R = At_Clamp(raw, x, y, w, h);
					G = At_Clamp(raw, x + 1, y, w, h);
					B = At_Clamp(raw, x + 1, y + 1, w, h);
				}
				else if (y_even && !x_even)
				{ // G (R row)
					G = At_Clamp(raw, x, y, w, h);
					R = At_Clamp(raw, x - 1, y, w, h);
					B = At_Clamp(raw, x, y + 1, w, h);
				}
				else if (!y_even && x_even)
				{ // G (B row)
					G = At_Clamp(raw, x, y, w, h);
					R = At_Clamp(raw, x, y - 1, w, h);
					B = At_Clamp(raw, x + 1, y, w, h);
				}
				else
				{ // B
					B = At_Clamp(raw, x, y, w, h);
					G = At_Clamp(raw, x - 1, y, w, h);
					R = At_Clamp(raw, x - 1, y - 1, w, h);
				}

				rgb_out[idx + 0] = (uint8_t)Clamp(B);
				rgb_out[idx + 1] = (uint8_t)Clamp(G);
				rgb_out[idx + 2] = (uint8_t)Clamp(R);
			}
		}
	}
	static void DemosaicBilinearRGGB(const uint8_t raw[], const UINT w, const UINT h, uint8_t rgb_out[] /* size = w*h*3 */)
	{
		auto avg4 = [](int a, int b, int c, int d) { return (a + b + c + d) / 4; };
		auto avg2 = [](int a, int b) { return (a + b) / 2; };

		for (UINT y = 0; y < h; ++y)
		{
			for (UINT x = 0; x < w; ++x)
			{
				const BOOL y_even = (y % 2 == 0);
				const BOOL x_even = (x % 2 == 0);

				const UINT idx = (y * w + x) * 3;
				INT R = 0, G = 0, B = 0;

				// 패턴 (RG/GB):
				// (even,even) = R
				// (even,odd)  = G (R row)
				// (odd,even)  = G (B row)
				// (odd,odd)   = B
				if (y_even && x_even)
				{
					// R 위치
					R = At_Clamp(raw, x, y, w, h);
					G = avg4(At_Clamp(raw, x - 1, y, w, h),
						At_Clamp(raw, x + 1, y, w, h),
						At_Clamp(raw, x, y - 1, w, h),
						At_Clamp(raw, x, y + 1, w, h));
					B = avg4(At_Clamp(raw, x - 1, y - 1, w, h),
						At_Clamp(raw, x + 1, y - 1, w, h),
						At_Clamp(raw, x - 1, y + 1, w, h),
						At_Clamp(raw, x + 1, y + 1, w, h));
				}
				else if (y_even && !x_even)
				{
					// G 위치 (R row)
					G = At_Clamp(raw, x, y, w, h);
					R = avg2(At_Clamp(raw, x - 1, y, w, h),
						At_Clamp(raw, x + 1, y, w, h));
					B = avg2(At_Clamp(raw, x, y - 1, w, h),
						At_Clamp(raw, x, y + 1, w, h));
				}
				else if (!y_even && x_even)
				{
					// G 위치 (B row)
					G = At_Clamp(raw, x, y, w, h);
					R = avg2(At_Clamp(raw, x, y - 1, w, h),
						At_Clamp(raw, x, y + 1, w, h));
					B = avg2(At_Clamp(raw, x - 1, y, w, h),
						At_Clamp(raw, x + 1, y, w, h));
				}
				else
				{ // (!y_even && !x_even)
				 // B 위치
					B = At_Clamp(raw, x, y, w, h);
					G = avg4(At_Clamp(raw, x - 1, y, w, h),
						At_Clamp(raw, x + 1, y, w, h),
						At_Clamp(raw, x, y - 1, w, h),
						At_Clamp(raw, x, y + 1, w, h));
					R = avg4(At_Clamp(raw, x - 1, y - 1, w, h),
						At_Clamp(raw, x + 1, y - 1, w, h),
						At_Clamp(raw, x - 1, y + 1, w, h),
						At_Clamp(raw, x + 1, y + 1, w, h));
				}

				// BMP는 BGR 순서
				rgb_out[idx + 0] = Clamp(B);
				rgb_out[idx + 1] = Clamp(G);
				rgb_out[idx + 2] = Clamp(R);
			}
		}
	}

	RESHAPER3D_EXT_API const INT funcata(const DOUBLE iArg);
}