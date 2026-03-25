#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DInt);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace ClipperLib;

RsDEFINE_DLL_CLASS(CPolygonObject) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<IntPoint>	_Points;
	typedef vector<_Points>		_PolygonPoints;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CPolygonObject();
	CPolygonObject(const ClipperLib::Paths & iPolygons);
	CPolygonObject(const CPolygonObject & iPolygon);
	virtual ~CPolygonObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const ClipperLib::Paths &	GetPolygons() const { return m_Polygons; }
	inline void				SetPolygons(const ClipperLib::Paths & iPolygons) { m_Polygons = iPolygons; }
#pragma endregion

#pragma region CAD Function
public:
	void					RemovePathsByArea(const DOUBLE iAreaToRemove);
	const BOOL				HasPolygons(const CPolygonObject & iPolygon) const;
	const DOUBLE			Area() const;
	void					Offset(const DOUBLE iOffset);
	void					TolerenceArea(const DOUBLE iArea);
	void					Add(const ClipperLib::Paths & iPolygons);
	
	const IntRect			GetBoundingBox() const;

	const INT				ExtractStripePolygons(const UINT64 iSize, const INT64 iOffset, const DOUBLE iAngle, const CVector2D & iHatchDirection, vector<Paths> & oResult) const;
	const INT				ExtractChessPolygons(const UINT64 iSizeX, const UINT64 iSizeY, const INT64 iOffset, const DOUBLE iAngle, const CVector2D & iHatchDirection, const DOUBLE iSortingAngle, const UINT64 iMinFieldSize, vector<vector<Paths>> & oResult, CGPoint2DInt * oSize = NULL) const;
protected:
	const BOOL				IsEqual(const CPolygonObject & iPolygon) const;
	void					ReversePolygons();
#pragma endregion


#pragma region Abstract fuction of IDataObject
public:
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CPolygonObject &	operator = (const CPolygonObject & iPolygon);
#pragma endregion

#pragma region Static Functions
public:
	static const INT		BestLocationFromLocation(const UINT iAxis, const _PolygonPoints & iPaths, INT & oPos);

	static void				CalcBoundingBox(const _PolygonPoints & iPaths, IntRect & oBoundingBox);
	static const UINT		GetNumberOfIntersectedPoints(const UINT iAxis, const UINT iPos, const _PolygonPoints & iPaths);
	static void				GetPositionListForAxis(const UINT iAxis, const _PolygonPoints & iPaths, vector<INT> & oPositionList, const INT iOffset = 0);
	static const INT		GetLocationMinimumCuttingLine(const UINT iAxis, const _PolygonPoints & iPaths, vector<pair<INT, INT>> & oPositionList);
	static const DOUBLE		DistanceSqrt(const IntPoint & pt1, const IntPoint & pt2);
	static const INT		Distance(const IntPoint & pt1, const IntPoint & pt2);
#pragma endregion

#pragma region Memeber Variable
protected:
	ClipperLib::Paths		m_Polygons;
#pragma endregion
};

	}
}