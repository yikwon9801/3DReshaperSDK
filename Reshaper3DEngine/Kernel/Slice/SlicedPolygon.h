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
		}
	}

	namespace Draw
	{
		RsDEFINE_CLASS(CExtBitmap);
	}

	namespace Slice
	{
		using namespace Kernel::Primitive;
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Draw;

RsDEFINE_DLL_CLASS(CSlicedPolygon) : RsINHERITANCE(CGMultiLines)
{
#pragma region Construction & Destruction
public:
	CSlicedPolygon();
	CSlicedPolygon(const _MultiLineVector & iMultiLines, const BOOL iClone = TRUE);
	CSlicedPolygon(const CTableList<CGMultiLine *> & iMultiLines, const BOOL iClone = TRUE);
	CSlicedPolygon(const CSlicedPolygon & iSlicedPolygon);
	virtual ~CSlicedPolygon();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void				SetZ(const DOUBLE iZ) { m_Z = iZ; }
	inline const DOUBLE		GetZ() const { return m_Z; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CSlicedPolygon & iSlicedPolygons) const;
#pragma endregion

#pragma region CAD Functions
public:
	void					Union();
	void					Intersection(const CSlicedPolygon & iSlicedPolygon);
#pragma endregion

#pragma region Bitmap
public:
	CExtBitmap *			CreateBitmap(const UINT iWidth, const UINT iHeight, const CRectDouble & iAreaToCreate, const UINT iScaleForSmooth, CGPoint2DDouble * oDistancePerPixel = NULL) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlicedPolygon *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CSlicedPolygon &	operator = (const CSlicedPolygon & iSlicedPolygon);
	const CSlicedPolygon	operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CSlicedPolygon	operator - () const;
	const CSlicedPolygon	operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CSlicedPolygon	operator * (const DOUBLE iValue) const;
	const CSlicedPolygon	operator * (const CMatrix3x3 & iMatrix) const;
	const CSlicedPolygon	operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CSlicedPolygon	operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CSlicedPolygon & iSlicedPolygons) const;
	const BOOL				operator != (const CSlicedPolygon & iSlicedPolygons) const;
#pragma endregion

#pragma region Static fuction
	static CSlicedPolygon *	GetSlicedPolygon(const CRectDouble & iArea);
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Z;
#pragma endregion
};

	}
}