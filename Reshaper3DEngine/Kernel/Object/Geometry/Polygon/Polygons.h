#pragma once

#include <vector>
using namespace std;

namespace Kernel
{
	struct IntPoint;
	struct IntRect;
}

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
		RsDEFINE_CLASS(CBoundingBox2D);
		
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGPolygon);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGPolygons);
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGMultiLines);

			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}
		
			namespace Polygons
			{
				using namespace Kernel::Util;
				using namespace Kernel::Object;
				using namespace Kernel::Object::Geometry;
				using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CPolygons) : RsINHERITANCE(CPolygonObject)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CPolygons();
	CPolygons(const _PolygonPoints & iPolygons);
	CPolygons(const CGMultiLines & iMultiLines);
	CPolygons(const CGMultiLine & iMultiLine);
	CPolygons(const CGPolyhedron & iPolyhedron);
	CPolygons(const CGPolygon2D & iPolygon);
	CPolygons(const CGPolygons2D & iPolygons);
	CPolygons(const CGPolygon & iPolygon);
	CPolygons(const CGPolygons & iPolygons);
	CPolygons(const vector<vector<Coordinate2D>> & iPolygons);
	CPolygons(const vector<Coordinate2D> & iPolygon);
	CPolygons(const CPolygons & iPolygons);
	virtual ~CPolygons();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CPolygons::_PolygonPoints &	GetPolygons() const { return m_Polygons; }
	inline void				SetPolygons(const _PolygonPoints & iPolygons) { m_Polygons = iPolygons; }
public:
	void					Put(const CGMultiLines & iMultiLines);
	void					Put(const CGMultiLine & iMultiLine);
	void					Put(const CGPolyhedron & iPolyhedron);
	void					Put(const CGPolygon2D & iPolygon);
	void					Put(const CGPolygons2D & iPolygons);
	void					Put(const CGPolygon & iPolygon);
	void					Put(const CGPolygons & iPolygons);
	void					Put(const vector<vector<Coordinate2D>> & iPolygons);
	void					Put(const vector<Coordinate2D> & iPolygon);
	void					Put(const vector<vector<Coordinate3D>> & iPolygons);
	void					Put(const vector<Coordinate3D> & iPolygons);
	void					Get(CGMultiLines & oMultiLines, const DOUBLE iZ = 0.) const;
	void					Get(CGMultiLine & oMultiLine, const DOUBLE iZ = 0.) const;
	void					Get(CGPolygons2D & oPolygons) const;
	void					Get(CGPolygon2D & oPolygons) const;
	void					Get(vector<CGPolygon2D> & oPolygons) const;

	void					Close();
	void					Open();
#pragma endregion

#pragma region General Function
public:
	void					Add(const _Points & iPoints);
	void					Add(const _PolygonPoints & iPointsList);
#pragma endregion

#pragma region CAD Functions
public:
	void					Union();
	void					Intersection(const CPolygons & iPolygons);
	void					Difference(const CPolygons & iPolygons);
	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption);
	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption, _PolygonPoints & oPolygon);
	void					OffsetNagative(const DOUBLE iOffsetDistance, const UINT16 iOption);
	void					OffsetNagative(const DOUBLE iOffsetDistance, const UINT16 iOption, _PolygonPoints & oPolygon);

	void					MakeSolidLine(const DOUBLE iOffsetDistance, const UINT16 iOption);
	const BOOL				Contain(const CPolygons & iPolygons) const;
	void					Chain();
	void					Fix_Winding();

	const UINT				Split(vector<CPolygons> & oSplitPolygons, const BOOL iUnionAll = FALSE) const;

	void					LeaveOuterLineOnly();
	void					LeaveInnerLineOnly();

	const BOOL				IsIntersectLine(const IntPoint & iPointA, const IntPoint & iPointB) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CPolygons *		Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CPolygons &		operator = (const CPolygons & iPolygons);
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		GetConvertScale();
	static void				ConvertType(const CGPolygons2D & iPolygon2D, _PolygonPoints & oPath);
	static void				ConvertType(const _PolygonPoints & iPath, vector<UINT> & oSeparators, vector<Coordinate2D> & oVertices);
	static void				ConvertType(const _PolygonPoints & iPath, CGPolygons2D & oPolygon2D);
	static void				ConvertType(const vector<_PolygonPoints> & iPathsList, CGPolygons2D & oPolygon2D);
	static const UINT		Split(const _PolygonPoints & iPolygon, vector<_PolygonPoints> & oSplitPolygons, const BOOL iUnionAll = FALSE);
	static void				Offset(const _PolygonPoints & iPolygon, _PolygonPoints & oPolygon, const DOUBLE iOffsetDistance, const UINT16 iOption);
	static void				OffsetNagative(const _PolygonPoints & iPolygon, _PolygonPoints & oPolygon, const DOUBLE iOffsetDistance, const UINT16 iOption);
	static void				Difference(const _PolygonPoints & iTarget, const _PolygonPoints & iDiff, _PolygonPoints & oPolygon);
	static void				Intersection(const _PolygonPoints & iTarget, const _PolygonPoints & iDiff, _PolygonPoints & oPolygon);
	static void				Union(_PolygonPoints & ioPolygon);
	static void				TolerenceArea(_PolygonPoints & ioPolygon, const DOUBLE iTolerence, const UINT iScale = 1);
	static void				MakeSolidLine(const _PolygonPoints & iPolygon, _PolygonPoints & oPolygon, const DOUBLE iOffsetDistance, const UINT16 iOption);
	static const DOUBLE		Area(const _PolygonPoints & iPolygon);
	static void				Close(_PolygonPoints & ioPolygon);
	static const IntRect	CalculateInRect(const CBoundingBox2D & iBoudingBox);
	static const BOOL		InRect(const IntRect & iBoundingBox, const _Points & iPolygonToCheck, const BOOL iOnBoundary = TRUE);
	static const BOOL		InRect(const IntRect & iBoundingBox, const _PolygonPoints & iPolygonsToCheck, const BOOL iOnBoundary = TRUE);
	static const INT		IntersectLineToLine(const IntPoint & A, const IntPoint & B, const IntPoint & C, const IntPoint & D, IntPoint & oResult);
	static const BOOL		IsIntersectLineToLine(const IntPoint & A, const IntPoint & B, const IntPoint & C, const IntPoint & D);
	static const BOOL		IsIntersectLineToLine(const IntPoint & A, const IntPoint & B, const IntPoint & C, const IntPoint & D, const DOUBLE iAccuray);
	static const BOOL		IsIntersectLineToBox(const IntPoint & A, const IntPoint & B, const IntRect & Box);
	static const BOOL		IsIntersectPathToBox(const _Points & iPath, const IntRect & Box);
	static const INT		DecideScanField(const map<INT, IntRect> & iScanFields, const _PolygonPoints & iPathsToCheck);
	static const INT		DecideScanField(const map<INT, IntRect> & iScanFields, const _Points & iPathToCheck);
	static const INT		DecideNoOverlappedScanField(const map<INT, IntRect> & iScanFields, const _Points & iPathToCheck);
	static const BOOL		IsOnPolygon(const _Points & iPolygonToCheck, const _PolygonPoints & iPolygons);
	static const BOOL		IsOnPolygon(const _Points & iPolygonToCheck, const _Points & iPolygon);
	static const INT		BestLocationFromLocation(const UINT iAxis, const _PolygonPoints & iPaths, INT & oPos);
	static const INT		DividePolygons(const UINT iAxis, const CPolygons::_PolygonPoints & iPaths, const INT iPositionToCut, CPolygons & iCut1, CPolygons & iCut2);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion	
};

			}
		}
	}
}