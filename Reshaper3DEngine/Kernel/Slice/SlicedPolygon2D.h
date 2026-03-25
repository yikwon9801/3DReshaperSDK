#pragma once

namespace Kernel
{
	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
		RsDEFINE_CLASS(CDimension);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLines);
		}
	}

	namespace Draw
	{
		RsDEFINE_CLASS(CExtBitmap);
	}

	namespace Slice
	{
		//RsDEFINE_CLASS(CLaserPolygon);

		using namespace Kernel::Primitive;
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Draw;

RsDEFINE_DLL_CLASS(CSlicedPolygon2D) : RsINHERITANCE(CGPolygons2D)
{
#pragma region Construction & Destruction
public:
	CSlicedPolygon2D();
	CSlicedPolygon2D(const CSlicedPolygon2D & iSlicedPolygon);
	CSlicedPolygon2D(const DOUBLE iZ, const CGMultiLine & iSlicedPolygon);
	virtual ~CSlicedPolygon2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetZ() const { return m_Z; }
public:
	inline void				SetZ(const DOUBLE iZ) { m_Z = iZ; }
#pragma endregion

#pragma region General Function
public:
	void					Get(CTableList<CGMultiLine *> & oTableMultiLine) const;
	void					Get(vector<CGMultiLine *> & oMultiLines) const;
	void					Get(CGMultiLines & oMultiLines) const;
	void					Get(const UINT iIndex, CGMultiLine & oMultiLine) const;
	void					Get(const UINT iIndex, CGPolygons2D & oPolygons) const;
	void					Get(const vector<UINT> & iSeparatorIndices, CGPolygons2D & oPolygons) const;
	void					Get(FLOAT * oArray) const;
	void					Get(CGPolygons2D & oSolidType, CGPolygons2D & oNonSolidType) const;
	void					Get(vector<vector<Coordinate2D>> & oPolygons) const;
	void					Get(vector<pair<DOUBLE, DOUBLE>> & oPoints) const;

	void					Clear();
	void					ClearOnlyPolygon();
	void					Release();
	void					ReleaseOnlyPolygon();

	const INT				GetLinesBetweenPolygons(CSlicedPolygon2D & oPolygons) const;
protected:
	const BOOL				IsEqual(const CSlicedPolygon2D & iSlicedPolygon) const;
#pragma endregion

#pragma region CAD Functions
public:
	CGPolyhedron *			Reconstruct() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlicedPolygon2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox	GetBoundingBox3D() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CSlicedPolygon2D &	operator = (const CSlicedPolygon2D & iSlicedPolygon);
	const CSlicedPolygon2D	operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CSlicedPolygon2D	operator + (const CSlicedPolygon2D & iPolygons) const;
	void					operator += (const CSlicedPolygon2D & iPolygons);
	const CSlicedPolygon2D	operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CSlicedPolygon2D	operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CSlicedPolygon2D	operator * (const CMatrix2x2 & iMatrix) const;
	const CSlicedPolygon2D	operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CSlicedPolygon2D	operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CSlicedPolygon2D & iSlicedPolygon) const;
	const BOOL				operator != (const CSlicedPolygon2D & iSlicedPolygon) const;
#pragma endregion

#pragma region Static fuction
public:
	static const BOOL		Divide2AreaPart(const DOUBLE iOffset, const DOUBLE iOverlapDistance
		, CSlicedPolygon2D & ioPart1, CSlicedPolygon2D & oPart2
		, const BOOL iUsePolygonFromBitmap, const CGPolygons2D::BITMAPPIXELFORMAT iFormat, const UINT iWidth, const UINT iHeight, const CRectDouble & iAreaToCreateBitmap, CExtBitmap *& oBitmap
		, const CRectDouble * iPrintablePart1 = NULL, const CRectDouble * iPrintablePart2 = NULL);
	static const BOOL		SkyWriting(const CGPoint2DDouble & iPoint1, const CGPoint2DDouble & iPoint2, const CGPoint2DDouble & iPoint3, CGPoint2DDouble & oPoint1, CGPoint2DDouble & oPoint2, const DOUBLE iDistance = 1.);
	static const BOOL		SkyWriting(const DOUBLE iPoint1X, const DOUBLE iPoint1Y, const DOUBLE iPoint2X, const DOUBLE iPoint2Y, const DOUBLE iPoint3X, const DOUBLE iPoint3Y, DOUBLE & oPoint1X, DOUBLE & oPoint1Y, DOUBLE & oPoint2X, DOUBLE & oPoint2Y, const DOUBLE iDistance = 1.);
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Z;
#pragma endregion
};

	}
}