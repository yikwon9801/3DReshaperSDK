#pragma once

namespace Kernel
{
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
		
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CSlicedPolygons) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<CSlicedPolygon *>	_SlicedPolygons;
#pragma endregion

#pragma region Construction & Destruction
public:
	CSlicedPolygons();
	CSlicedPolygons(const CSlicedPolygons & iSlicedPolygons);
	virtual ~CSlicedPolygons();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetLayerCount() const { return (UINT)m_SlicedPolygons.size(); }
	inline const CSlicedPolygon *	GetSlicedPolygon(const UINT iIndex) { ASSERT(iIndex < (UINT)m_SlicedPolygons.size()); return m_SlicedPolygons[iIndex]; }
public:
	void					SetSlicedPolygons(const _SlicedPolygons & iSlicedPolygons, const BOOL iClone = TRUE);
#pragma endregion

#pragma region General Function
public:
	const UINT				GetPointCount() const;
	const UINT				GetLineCount() const;
	void					Clear();

public:
	void					Get(CTableArray<CGVertex *> & oPoints, CTableArray<UINT> * iSeperator = NULL);

protected:
	const BOOL				IsEqual(const CSlicedPolygons & iSlicedPolygons) const;
#pragma endregion

#pragma region Clear Internal Data
protected:
	void					Release();
	void					ReleaseSlicedPolygons();
#pragma endregion

#pragma region CAD Functions
public:
	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption = 0);

public:
	virtual void			Invert();
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlicedPolygons *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
private:
	void					_CopySlicedPolygons(const _SlicedPolygons & iSlicedPolygons);
#pragma endregion

#pragma region Operator Declaration
public:
	const CSlicedPolygons &	operator = (const CSlicedPolygons & iSlicedPolygons);
	const CSlicedPolygons	operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CSlicedPolygons	operator - () const;
	const CSlicedPolygons	operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CSlicedPolygons	operator * (const DOUBLE iValue) const;
	const CSlicedPolygons	operator * (const CMatrix3x3 & iMatrix) const;
	const CSlicedPolygons	operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CSlicedPolygons	operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CSlicedPolygons & iSlicedPolygons) const;
	const BOOL				operator != (const CSlicedPolygons & iSlicedPolygons) const;
#pragma endregion

#pragma region Static fuction
#pragma endregion

#pragma region Memeber Variable
private:
	_SlicedPolygons			m_SlicedPolygons;
#pragma endregion
};

	}
}