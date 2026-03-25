#pragma once

#include <unordered_map>

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
		RsDEFINE_CLASS(CSlicedPolygon2D);

		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CMultiSegments2D) : RsINHERITANCE(CBaseObject)
{
#pragma region Type Definition
public:
	typedef vector<CSlicedSegment *>	_Polygon;
	typedef vector<_Polygon>			_Polygons;
	typedef unordered_map<INT, INT>		_FaceToSegmentUnorderedMap;
#pragma endregion

#pragma region Construction & Destruction
public:
	CMultiSegments2D();
	CMultiSegments2D(const CMultiSegments2D & iMultiSegments);
	virtual ~CMultiSegments2D();
#pragma endregion

#pragma region Setter & Getter function
#pragma endregion

protected:
	const BOOL				IsEqual(const CMultiSegments2D & iMultiSegments) const;

public:
	void					AddSegment(const INT iX1, const INT iY1, const INT iX2, const INT iY2, const INT iFaceIndex, const DOUBLE iScale = 1.);
	void					MakePolygons(const CGPolyhedron & iPolyhedron, CTableList<CGMultiLine *> & oSlicedMultiLines, const UINT iLayerIndex, const UINT iLayerCount);
	void					MakePolygons(const CGPolyhedron & iPolyhedron, CSlicedPolygon2D & oSlicedPolygon, const UINT iLayerIndex, const UINT iLayerCount);
protected:
	const INT				ChainFromOpenPolygons(_Polygons & oPolygons, _Polygons & ioOpenPolygons) const;
	const INT				ChainFromDepartureAndArrivalOfOpenPolygons(_Polygons & oPolygons, _Polygons & ioOpenPolygons) const;

	const BOOL				GetSlicedMultiLines(const _Polygons & iPolygons, CTableList<CGMultiLine *> & oSlicedMultiLines) const;
	const BOOL				GetSlicedMultiLines(const _Polygons & iPolygons, CSlicedPolygon2D & oSlicedPolygon) const;
	void					GetSegmentsAroundDepartureX(const _Polygons & iList, vector<UINT> & oList, const DOUBLE iX) const;
	void					GetSegmentsAroundArrivalX(const _Polygons & iList, vector<UINT> & oList, const DOUBLE iX) const;
private:
	const INT				_ChainSegmentsWithAdjacentFaces(const CTableArray<CGFace> & iTableFaces, _Polygons & oPolygons, _Polygons & oOpenPolygons) const;
	const INT				_ChainSegmentsWithCoordinate(_Polygons & oPolygons, _Polygons & ioOpenPolygons, const DOUBLE iDistanceToSearch) const;
	const INT				_ChainSegmentsWithBestCoordinate(_Polygons & oPolygons, _Polygons & ioOpenPolygons, const DOUBLE iDistanceToChain) const;
	const INT				_PutSegmentsForce(_Polygons & oPolygons, _Polygons & ioOpenPolygons) const;
public:
	const INT				ChainSegmentsWithCoordinate(_Polygons & oPolygons, _Polygons & ioOpenPolygons, const DOUBLE iDistanceToSearch) const
	{
		return _ChainSegmentsWithCoordinate(oPolygons, ioOpenPolygons, iDistanceToSearch);
	}

protected:
	void					Release();

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CMultiSegments2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	void					CopySegments(const _Polygon & iSegments);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
protected:
	const INT				ReadSegments(CFileReadObject & file, CProgress * iProgress = NULL);
	const INT				SaveSegments(CFileWriteObject & file, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Operator Declaration
public:
	const CMultiSegments2D &	operator = (const CMultiSegments2D & iMultiSegments);
	const BOOL				operator == (const CMultiSegments2D & iMultiSegments) const;
	const BOOL				operator != (const CMultiSegments2D & iMultiSegments) const;
#pragma endregion

#pragma region Static fuction
protected:
#pragma endregion

#pragma region Memeber Variable
private:
	_Polygon				m_Segments;
	_FaceToSegmentUnorderedMap	m_faceidxToSegmentidx;
#pragma endregion
};

	}
}