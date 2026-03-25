#pragma once

namespace Kernel
{

	namespace Compression
	{

RsDEFINE_DLL_CLASS(CCompression)
{
#pragma region Construction & Destruction
public:
	CCompression(const BYTE * iBytes, const UINT iLength);
	CCompression(const BYTE * iBytes, const CSize & iSize);
	virtual ~CCompression();
#pragma endregion

#pragma region Setter & Getter function
public:
	BYTE *			GetDesBytes() { return m_DesBytes; }
	const UINT		GetDesSize() const { return m_DesLen; }
	void			SetSlidingWindowSize(INT nSize) { m_SlidingWindowSize = nSize; }
#pragma endregion

#pragma region General Function
public:
	const INT		Compress();
	const INT		DeCompress();

	BYTE *			take();

private:
	void			_Release();
#pragma endregion

#pragma region Operator Declaration
public:
#pragma endregion

#pragma region Static Function
public:
#pragma endregion

#pragma region Memeber Variable
private:
	const BYTE *	m_SrcBytes;
	BYTE *			m_DesBytes;
	const UINT		m_SrcLen;
	UINT			m_DesLen;
	INT				m_SlidingWindowSize;
#pragma endregion
};

	}
}