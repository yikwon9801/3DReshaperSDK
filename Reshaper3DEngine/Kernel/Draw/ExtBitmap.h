#pragma once

namespace Kernel
{
	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableList;
		template<typename _DataType> class CTableArray;
	}

	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGRectangle);
			RsDEFINE_CLASS(CGPolygons2D);
		}
	}

	namespace Draw
	{
		using namespace Kernel::Primitive;
		using namespace Kernel::Collection;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CExtBitmap) : RsINHERITANCE(Bitmap)
{
#pragma region Construction & Destruction
public:
	CExtBitmap(IN INT width, IN INT height, IN PixelFormat format = PixelFormat32bppARGB);
	CExtBitmap(IN INT width, IN INT height, IN INT stride, IN PixelFormat format, _In_reads_opt_(_Inexpressible_("height * stride")) BYTE* scan0);
	CExtBitmap(IN HBITMAP hbm, IN HPALETTE hpal);
	CExtBitmap(IN const WCHAR *filename, IN BOOL useEmbeddedColorManagement = FALSE);
	CExtBitmap(IN const BITMAPINFO * gdiBitmapInfo, IN VOID * gdiBitmapData);
	virtual ~CExtBitmap();
protected:
	CExtBitmap(GpBitmap *nativeBitmap);
#pragma endregion

#pragma region Setter & Getter function
public:
	CExtBitmap *			Clone() const;
	inline CExtBitmap*		Clone(IN INT x, IN INT y, IN INT width, IN INT height, IN PixelFormat format);
#pragma endregion

#pragma region General Function
public:
	CExtBitmap *			GetDoubleScale() const;
	void					Get(BYTE oBytes[]) const;
	void					Set(const BYTE iBytes[]);

public:
	const Status			SaveBitmap(IN LPCTSTR lpctFileName);
	const Status			SavePng(IN LPCTSTR ipctFileName);
	const Status			Savejpg(IN LPCTSTR ipctFileName);
	const INT				SaveRaw(IN LPCTSTR lpctFileName);
	const INT				SaveTo8bppRaw(IN LPCTSTR lpctFileName);
#pragma endregion

#pragma region Image Processing
public:
	const INT				Move(const UINT iX, const UINT iY);
	const INT				Merge(const CExtBitmap & iBitmap);

	const INT				SplitHeight(CExtBitmap *& ioBitmap1, CExtBitmap *& ioBitmap2) const;

	const BOOL				BoundaryOnly(const UINT iPixel = 1);
	const DOUBLE			GetAreaPercentage() const;

	CExtBitmap *			GetDiagonalForSmoothing() const;
	
	const INT				SmoothQuadriDiagonal(const CExtBitmap & iUpScale4DivisionBitmap, const BOOL iOnlyBoundary, CTableList<CExtBitmap *> & oBitmaps) const;
	const INT				Smooth16DivisionDiagonal(const CExtBitmap & iUpScale4DivisionBitmap, const CExtBitmap & iUpScale16DivisionBitmap, const BOOL iOnlyBoundary, CTableList<CExtBitmap *> & oBitmaps) const;
	const INT				SmoothQuadriFull(const CExtBitmap & iUpScale4DivisionBitmap, const BOOL iOnlyBoundary, CTableList<CExtBitmap *> & oBitmaps) const;
	const INT				ExtractQuad(const CExtBitmap & iUpScale4DivisionBitmap, const BOOL iOnlyBoundary, CTableList<CExtBitmap *> & oBitmaps) const;
private:
	CExtBitmap *			_ExtractQuadriScale(const UINT iOption) const;
	CExtBitmap *			_Extract16DivisionScale(const UINT iOption) const;
#pragma endregion

#pragma region Static Function
public:
	static CExtBitmap *		ReScale(const UINT iNewWidth, const UINT iNewHeight, CExtBitmap * iOrgBitmap);
	static CExtBitmap *		ToSqaure(CExtBitmap * iOrgBitmap);
	static void				ExtractContourFrom1BitBitmap(Bitmap * iBitmap, const CRectDouble & iArea, CGPolygons2D & oPolygons);
	static const INT		GetEncoderClsid(LPCTSTR iFormat, CLSID & oClsid);
	static const INT		ConvertToBYTES(CExtBitmap * iBitmap, BYTE *& oBitmapBytes, UINT * oBitmapSize = NULL);
	static CExtBitmap *		FromRaw(const BYTE iBuff[], const UINT iWidth, const UINT iHeight, const UINT iChannel, const UINT iBitDepth);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

	}
}