#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);

		namespace File3D
		{
			RsDEFINE_CLASS(C3DFileSTL);
		}
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);

		namespace Thread
		{
			RsDEFINE_CLASS(CHealthCheck);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSegment);
		RsDEFINE_CLASS(CSlicedPolygon);
		RsDEFINE_CLASS(CSlicedPolygons2D);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGCloud);
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangles);

			namespace Mesh
			{
				using namespace Kernel::File;
				using namespace Kernel::File::File3D;
				using namespace Kernel::Math;
				using namespace Kernel::Collection;
				using namespace Kernel::Util;
				using namespace Kernel::Util::Thread;
				using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CGPolyhedron) : RsINHERITANCE(CGeometryObject)
{
	friend class C3DFileSTL;
#pragma region Type Definition
public:
	typedef vector<INT>			_IndexVector;
	typedef list<INT>			_IndexList;
	typedef vector<CGFace *>	_Surface;
	typedef vector<_Surface>	_Surfaces;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPolyhedron();
	CGPolyhedron(const CTableArray<CGVertex> & iVertices, const CTableArray<CGFace> & iFaces);
	CGPolyhedron(const vector<CGTriangle> & iTriangles);
	CGPolyhedron(const CGTriangles & iTriangles);
	CGPolyhedron(const CGPolyhedron & rhs);
	virtual ~CGPolyhedron();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CTableArray<CGVertex> &	GetVertices() const { return m_Vertices; }
	inline const CTableArray<CGFace> &		GetFaces() const { return m_Faces; }

	const CGVertex &		GetVertex(const UINT nIndex) const;
	const CGFace &			GetFace(const UINT nIndex) const;
#pragma endregion

#pragma region Clear Internal Data
protected:
	void					Release();
private:
	void					_Release();
	void					_ReleaseVertices();
	void					_ReleaseFaces();
#pragma endregion

#pragma region Normal
public:
	const INT				InvertNormal(const UINT iType = 0);
	void					UpdateNormal(const UINT iType);
private:
	void					_UpdateVertexNormalType0(const CTableArray<CGVertex> & ioVertices, const CTableArray<CGFace> & ioFaces);
	void					_UpdateVertexNormalType1(const CTableArray<CGVertex> & ioVertices, const CTableArray<CGFace> & ioFaces);
	void					_UpdateFaceNormalType0(const CTableArray<CGVertex> & ioVertices, const CTableArray<CGFace> & ioFaces);
	void					_UpdateVertexFaceNormalType0(const CTableArray<CGVertex> & ioVertices, const CTableArray<CGFace> & ioFaces);
	void					_UpdateVertexFaceNormalType1(const CTableArray<CGVertex> & ioVertices, const CTableArray<CGFace> & ioFaces);
#pragma endregion

#pragma region Slice
public:
	const CTableArray<CGMultiLines *>	SectionZPlaneType1(const DOUBLE iStartZ, const DOUBLE iThickness, const BOOL iSimplify = FALSE, const DOUBLE iMinSegLength = 1.e-3, CProgress * iProgress = NULL) const;
	const BOOL				SectionZPlaneType1(const DOUBLE iZ, CGMultiLines & oSlicedPolygon, const BOOL iSimplify = FALSE, const DOUBLE iMinSegLength = 1.e-3, vector<UINT> * oFaces = NULL, CProgress * iProgress = NULL) const;
	const BOOL				SectionZPlaneType1(const DOUBLE iZ, CSlicedPolygon & oSlicedPolygon, const BOOL iSimplify = FALSE, const DOUBLE iMinSegLength = 1.e-3, vector<UINT> * oFaces = NULL, CProgress * iProgress = NULL) const;
	const BOOL				SectionZPlaneType2(const DOUBLE iZ, CGMultiLines & oSlicedPolygon, CProgress * iProgress = NULL) const;
public:
	static const BOOL		SectionType1(const CTableArray<const CGPolyhedron *> & iTablePolyhedron, const vector<DOUBLE> & iSlicingHeight, vector<CSlicedPolygon *> & oSlicedPolygon, const BOOL iSimplify = FALSE, const DOUBLE iMinSegLength = 1.e-3, CProgress * iProgress = NULL, CHealthCheck * iHeathCheck = NULL);
	static const BOOL		SectionType2(const CTableArray<const CGPolyhedron *> & iTablePolyhedron, const vector<DOUBLE> & iSlicingHeight, vector<CSlicedPolygon *> & oSlicedPolygon, CProgress * iProgress = NULL, CHealthCheck * iHeathCheck = NULL);
	static const BOOL		SectionType3(const CTableArray<const CGPolyhedron *> & iTablePolyhedron, const vector<DOUBLE> & iSlicingHeight, vector<CSlicedPolygon *> & oSlicedPolygon, CProgress * iProgress = NULL, CHealthCheck * iHeathCheck = NULL);
	static const BOOL		SectionType3(const CTableArray<const CGPolyhedron *> & iTablePolyhedron, const vector<DOUBLE> & iSlicingHeight, CSlicedPolygons2D & oSlicedPolygon, CProgress * iProgress = NULL, CHealthCheck * iHeathCheck = NULL);
#pragma endregion

#pragma region Selection
public:
	const UINT				SelectVerticesInLine(const CVector & iDirection, const CGMultiLine & iMultiLine, const BOOL iDeselectAll = FALSE) const;
	const UINT				SelectFacesInLine(const CVector & iDirection, const CGMultiLine & iMultiLine, const BOOL iDeselectAll = FALSE) const;
	void					DeselectFaces();
	void					DeselectVertices();
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsClosed() const;
	const BOOL				IsSelectedFaces() const;
	const BOOL				IsEdge(const CGPointDouble & iP1, const CGPointDouble & iP2, const BOOL iHaveToOrder = TRUE, const UINT iType = 0) const;
	const BOOL				IsPoint(const CGPointDouble & iPoint, const UINT iType = 0) const;
	const BOOL				AddFace(const UINT iIndex1, const UINT iIndex2, const UINT iIndex3);
	const BOOL				RemoveFaces(const _IndexVector & iIndices);
protected:
	const BOOL				IsEqual(const CGPolyhedron & iPolyhedron) const;

	CGMultiLines *			ExtractEdgeLines(const CTableArray<CGEdge> & iEdges) const;
private:
	const INT				GetEdges(CTableArray<CGEdge> & oEdges) const;
	const INT				GetContourEdges(const CVector & iDirection, CTableArray<CGEdge> & oEdges) const;

	const INT64				FindVertexIndex(const CGPointDouble & iPoint, const UINT iType = 0) const;
	const BOOL				FindFaceIndex(const UINT iIndex1, const UINT iIndex2, _IndexVector & oAdjacentFaces, const INT iExceptFace = -1) const;
#pragma endregion

#pragma region CAD Functions
#pragma region Fixing
public:
	const INT				RemoveDuplicatedFaces();
	const INT				FixFaceNormals(const UINT iOption);
#pragma endregion
public:
	const INT				Compound(const CTableList<const CGPolyhedron *> & iPolyTable, CProgress * iProgress = NULL);
	CGPolyhedron *			MakePolyhedronWithSelectedFaces() const;
	typedef enum { EXPLODE_BYVERTEX, EXPLODE_BYFACE, EXPLODE_BYFACE2 }ExplodeType;
	const INT				Explode(CTableArray<CGPolyhedron *> & ioTablePolyhedronToExplode, const ExplodeType iType = EXPLODE_BYFACE, CProgress * iProgress = NULL) const;
	const DOUBLE			GetVolume() const;

	const INT				Project(const CGPointDouble & iPointToProject, const CVector & iDirection, CGPointDouble & oProjectedPoint) const;

	CGMultiLines *			GetContourView(const CVector & iDirection) const;

	const INT				Difference(const CGPolyhedron & iPolyhedron, void * ioData);
private:
	const CTableArray<CGPolyhedron *>	Clustering(CProgress * iProgress = NULL) const;
	const CTableArray<CGPolyhedron *>	Segmentation(CProgress * iProgress = NULL) const;
	const CTableArray<CGPolyhedron *>	Segmentation2(CProgress * iProgress = NULL) const;
	const INT				GetSurfaces(const UINT iOption, _Surfaces & oSurfaces) const;
	const INT				GetSurfacesForClustering(_Surfaces & oSurfaces) const;
	const INT				GetSurfacesForSegmentation(const UINT16 iOption, _Surfaces & oSurfaces) const;
#pragma endregion

#pragma region Optimization
public:
	void					ReconstructGeometry();
	void					OptimizeStruct(const BOOL iReCreate = FALSE);
#pragma endregion
	
#pragma region Read & Write 3D File
public:
	const BOOL				ReadSTL(const LPCTSTR lpStrFilePath, CProgress * iProgress = NULL);
	const BOOL				WriteSTL(const LPCTSTR lpStrFilePath, const INT iType, CProgress * iProgress = NULL);
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

	void					CalculateBoundingBox(CBoundingBox & oBoundingBox, const CMatrix3x4 & iMatrix) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPolyhedron *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const vector<CGTriangle> & iTriangles);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
protected:
	const INT				ReadVertices(CFileReadObject & file, CProgress * iProgress = NULL);
	const INT				ReadFaces(CFileReadObject & file, CProgress * iProgress = NULL);
	const INT				SaveVertices(CFileWriteObject & file, CProgress * iProgress = NULL);
	const INT				SaveFaces(CFileWriteObject & file, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Macro Definition
public:
#define OPTIMIZED_GEOMETRY(obj)				obj->ReconstructGeometry()
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPolyhedron &	operator = (const CGPolyhedron & iPolyhedron);
	const CGPolyhedron &	operator = (const vector<CGTriangle> & iTriangles);
	const CGPolyhedron &	operator = (const CGTriangles & iTriangles);
	const CGPolyhedron		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGPolyhedron		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGPolyhedron		operator * (const CMatrix3x3 & iMatrix) const;
	const CGPolyhedron		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CGPolyhedron & iPolyhedron) const;
	const BOOL				operator != (const CGPolyhedron & iPolyhedron) const;
#pragma endregion

#pragma region Static Functions
public:
	static const INT		GetSurfacesForSegmentation(const CTableArray<CGVertex *> & iVertices, const CTableArray<CGFace *> & iFaces, const UINT16 iOption, CTableArray<CTableArray<CGFace *>> & oSurfaces);
#pragma region Create Shapes
public:
	static CGPolyhedron *	Create3DArrow(const CGPointDouble & iDeparture, const CGPointDouble & iArrival, const DOUBLE iTailRadius = 1., const DOUBLE iHeadLengthRatio = 0., const DOUBLE iHeadRadiusRatio = 0., const UINT iResolution = 0.);
	static CGPolyhedron *	Create3DArcArrow(const CGPointDouble & iCenterPoint, const DOUBLE iRadius, const CVector & iDirection, DOUBLE iFromAngle, const DOUBLE iToAngle, const DOUBLE iMiddleRadius = 1., const DOUBLE iHeadLengthRatio = 0., const DOUBLE iHeadRadiusRatio = 0., const UINT iResolution = 0.);
	static CGPolyhedron *	CreateCyliner(const CGPointDouble & iPoint, const CVector & iDirection, const DOUBLE iRadius, const DOUBLE iHeight, const UINT iResolution = 0.);
	static CGPolyhedron *	CreateCyliner(const CGPointDouble & iPoint, const CVector & iDirection, const DOUBLE iHorRadius, const DOUBLE iVerRadius, const DOUBLE iHeight, const UINT iResolution = 0.);
	static CGPolyhedron *	CreateGridAndColumnWithPlateInSquare(const CBoundingBox2D & iBoundingBox,
		const DOUBLE iGapDistance,
		const DOUBLE iThickness,
		const DOUBLE iPlateHeight,
		const DOUBLE iColumnHeight,
		const DOUBLE iGridHeight,
		const DOUBLE iMiddleHoleLength,
		CProgress * iProgress = NULL);
#pragma endregion
#pragma endregion

#pragma region Memeber Variable
private:
	CTableArray<CGVertex>	m_Vertices;
	CTableArray<CGFace>		m_Faces;

private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
#pragma endregion
};

			}
		}
	}
}