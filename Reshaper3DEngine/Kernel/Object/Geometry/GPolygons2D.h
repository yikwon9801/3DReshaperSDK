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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygon);
	}

	namespace Draw
	{
		RsDEFINE_CLASS(CExtBitmap);
	}

	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGLine);
			RsDEFINE_CLASS(CGTriangles2D);
			RsDEFINE_CLASS(CGTriangles);
			RsDEFINE_CLASS(CGPolygon);
			RsDEFINE_CLASS(CGPolygons);

			using namespace Kernel::Primitive;
			using namespace Kernel::Collection;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Slice;
			using namespace Kernel::Draw;

RsDEFINE_DLL_CLASS(CGPolygons2D) : RsINHERITANCE(CGPolygon2D)
{
#pragma region Type Definition
public:
	typedef vector<UINT>			_SeparateIndicesOfPolygons;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPolygons2D();
	CGPolygons2D(const CSlicedPolygon & iSlicedPolygon);
	CGPolygons2D(const CGPolygons2D & iPolygons);
	CGPolygons2D(const CGPolygons & iPolygons);
	CGPolygons2D(const CGPolygon2D & iPolygons);
	CGPolygons2D(const CGPolygon & iPolygons);
	CGPolygons2D(const _VertexVector & iPolygons);
	CGPolygons2D(const vector<vector<Coordinate2D>> & iPolygons);
	CGPolygons2D(const CGMultiLine & iSlicedPolygon);
	CGPolygons2D(const CGMultiLines & iSlicedPolygon);
	virtual ~CGPolygons2D();
private:
	CGPolygons2D(const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparator);
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _SeparateIndicesOfPolygons &	GetSeparator() const { return m_Separator; }
	inline _SeparateIndicesOfPolygons & Separator() { return m_Separator; }
	inline const UINT		GetSeparatorCount() const { return (UINT)m_Separator.size(); }
	inline const UINT		GetLineCount() const { return (UINT)m_Separator.size(); }
	inline const UINT		GetVectorCount() const { return CGPolygons2D::GetNumberOfVectors(m_Separator); }
protected:
	inline void				SetSeparator(const _SeparateIndicesOfPolygons & iSeparator) { m_Separator = iSeparator; }
public:
	void					SetPolygons(const CSlicedPolygon & iSlicedPolygon);
	void					SetPolygons(const CGPolygons2D & iPolygons2D);
	void					SetPolygons(const CGPolygons & iPolygons);
	void					SetPolygons(const vector<vector<Coordinate2D>> & iPolygons);
	void					SetPolygons(const vector<vector<Coordinate3D>> & iPolygons);
	void					SetPolygon(const CGPolygon2D & iPolygon2D);
	void					SetPolygon(const _VertexVector & iPolygon2D);
	void					SetPolygon(const CGPolygon & iPolygon, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS);
	void					SetPolygon(const vector<Coordinate3D> & iPolygon, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS);
#pragma endregion

#pragma region General Function
public:
	void					AddPolygons(const CGPolygons2D & iPolygons);
	void					AddPolygons(const CGMultiLines & iPolygons);
	void					AddPolygons(const vector<vector<Coordinate2D>> & iSlicedPolygon);
	void					AddPolygon(const CGMultiLine & iPolygon);
	void					AddPolygon(const CGPolygon2D & iPolygon);
	void					AddPolygon(const vector<Coordinate2D> & iPolygon);
	void					AddYLines(const CBoundingBox2D * const iLimitRect = NULL);
	void					InsertPolygons(const UINT iIndex, const CGPolygons2D & iPolygons);

	void					Clear();
	void					Release();
	void					RemovePolygon(const UINT iIndex);
	void					RemovePolygons(const UINT iBegin, const UINT iEnd);

	void					Get(const UINT iIndex, CGMultiLine & oMultiLine) const;
	void					Get(const UINT iIndex, CGPolygons2D & oPolygons) const;
	void					Get(const vector<UINT> & iSeparatorIndices, CGPolygons2D & oPolygons) const;
	void					Get(CGMultiLines & oMultiLines) const;
	void					Get(CTableList<CGMultiLine *> & oTableMultiLine) const;
	void					Get(FLOAT * oArray) const;
	void					Get(vector<vector<Coordinate2D>> & oPolygons) const;
	void					Get(vector<vector<LineCoordinate2D>> & oPolygons) const;
	void					Get(CGPolygons2D & oSolidType, CGPolygons2D & oNonSolidType) const;
	void					Get(vector<pair<DOUBLE, DOUBLE>> & oPoints) const;
	void					Get(vector<Coordinate3D> & oPolygon, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS) const;
	void					Get(vector<vector<Coordinate3D>> & oPolygons, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS) const;
	void					Get(CGPolygon & oPolygon, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS) const;
	void					Get(CGPolygons & oPolygons, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS) const;

	void					GetSeparator(vector<INT> & oSeparators) const;

	const INT				GetLinesBetweenPolygons(CGPolygons2D & oPolygons) const;
	const INT				GetStartingPosition(const UINT iIndex, UINT & oPosition) const;

	const BOOL				IsOnlyLine() const;
protected:
	const BOOL				IsEqual(const CGPolygons2D & iPolygons) const;

public:
	virtual void			Close();
	virtual void			Open();
	virtual const BOOL		IsClosed() const;
	virtual const DOUBLE	GetLength() const;

#pragma endregion

#pragma region CAD Functions
public:
	void					Fix(const UINT8 iType);
	const INT				GetClosedPolygons(vector<UINT> & oPolygonIndices) const;
	const INT				GetClosedPolygons(CGPolygons2D & oPolygons) const;
	const INT				GetLongestPoint(const CVector2D & iDirection, const vector<UINT> * const iIncludePolygon = NULL, const vector<UINT> * const iExcludePolygon = NULL, Coordinate2D * oLongestPoint = NULL) const;
	const INT				GetLongestLine(const CVector2D & iDirection, const vector<UINT> * const iIncludePolygon = NULL, const vector<UINT> * const iExcludePolygon = NULL, Coordinate2D * oLongestPoint = NULL) const;
	const INT				GetClosestPointOnLine(const Coordinate2D & iPoint, const vector<UINT> * const iIncludePolygon = NULL, const vector<UINT> * const iExcludePolygon = NULL, Coordinate2D * oResult = NULL, const CBoundingBox2D * iLimitBoundary = NULL) const;
	void					GetBoundingBoxLinesWithSegments(CGPolygons2D & oPolgyons, const DOUBLE iOffset = 0.) const;
	const BOOL				InPolygons(const Coordinate2D & iPoint) const;
	const BOOL				InPolygons(const CGPolygons2D & iPolygons2D) const;

	void					Union();
	void					Difference(const CGPolygons2D & iPolygons);
	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption = 0);
	void					Intersect(const CGPolygons2D & iPolygons);
	const INT				IsIntersectLine(const UINT iIndex1, const UINT iIndex2) const;
	const INT				IsIntersectLine(const CGPolygons2D & iPolygons) const;
	const INT				IsIntersectLine(const CGLine & iLine) const;
	const INT				IsIntersectLine(const CGLine & iLine, CGPoint2DDouble & oIntersectedPoint) const;
	const INT				GetIntersectedPoint(const Coordinate2D & iDeparture, const Coordinate2D & iArrival, vector<Coordinate2D> & oIntersectedLine) const;

	const INT				Explode(CGPolygons2D & oOuterPolygons, CGPolygons2D & oInnerPolygons) const;
	const UINT				Explode(vector<vector<UINT>> & oExplodedPolygon) const;
	const UINT				ProjectYAxis(const Coordinate2D & iPointToProject, Coordinate2D & oIntersectedPoint, const vector<UINT> * const iIncludePolygon = NULL, const vector<UINT> * const iExcludePolygon = NULL, vector<Coordinate2D> * iProjectedPoints = NULL, const UINT iType = 0) const;
	const UINT				ProjectAxis(const Coordinate2D & iPointToProject, const CVector2D & iAxis, Coordinate2D & oIntersectedPoint, const vector<UINT> * const iIncludePolygon = NULL, const vector<UINT> * const iExcludePolygon = NULL, const UINT iType = 0) const;
	const UINT				ProjectOverlapLine(const Coordinate2D & iLinePoint1, const Coordinate2D & iLinePoint2, vector<Coordinate2D> & oPolygon) const;
	const UINT				ProjectOverlapLine(const Coordinate2D & iLinePoint1, const Coordinate2D & iLinePoint2, vector<Coordinate2D> & oPolygon, vector<BOOL> & oInout) const;

	void					RemoveDuplicateCoordinate(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	const UINT				RemoveDuplicateOnlyVector2D(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	const UINT				RemovePolygonLessThanNumberOfPoint(const UINT iPointNumber);
	const UINT				RemovePolygonNoArea(const DOUBLE iTolerance = 0.);
	const UINT				RemoveIntersectedPolygons(const CGPolygons2D & iPolygons, const UINT16 iOption = 0);
	void					Reduce(const UINT16 iType, const DOUBLE iTolerance = 0.);
	void					ReduceJuttedAndLength(const DOUBLE iJuttedTolerance, const DOUBLE iLengthTolerance);
	void					IncreaseDensity(const DOUBLE iLimitLength);
	void					LeaveOutLineOnly();

	void					CutPolygonsAreInArea(const CRectDouble & iArea);
	void					CutPolygonsAreInArea(vector<Coordinate2D> & iRequestPolygon, vector<vector<Coordinate2D>> & oPolygonCut, vector<vector<Coordinate2D>> & oPolygonNoCut) const;
	void					CutPolygonsByAxis(const AXISTYPE iAxis, const DOUBLE iPosition, CGPolygons2D & oSide1, CGPolygons2D & oSide2) const;

	const INT				GenerateLineInfill(const DOUBLE iSpotSize, const CGPolygons2D & iPrevSlicedPolygon, const CGPolygons2D & iNextSlicedPolygon, const BOOL iUpDownSkinOnlyLaser, const UINT iNumberOfOutline, const DOUBLE iDistanceOfOverlappedOutline, const DOUBLE iAngleToRotateLine, const DOUBLE iAreaPictureDoesnotDraw, const DOUBLE iDistanceToOffsetInnerOutLine, const DOUBLE iDensity, const DOUBLE iOffsetDistanceForDLP, const BOOL iFullFill, const BOOL iZigZag, CGPolygons2D & oInfillLines, CGPolygons2D & oPolygonExceptFull) const;
	const INT				GenerateOutlineInfill(const DOUBLE iSpotSize, const UINT iNumberOfLine, const DOUBLE iAreaPictureDoesnotDraw, const DOUBLE iDensity, const DOUBLE iOffsetDistanceForDLP, CGPolygons2D & oInfillLines, CGPolygons2D & oPolygonExceptFull) const;

	const BOOL				Orientation(const UINT iIndex) const;

	CGPolyhedron *			Reconstruct2D() const;
	const INT				Triangulate(CGTriangles & oTriangles) const;
	const INT				Triangulate(CGTriangles2D & oTriangles) const;

	void					Solid(const DOUBLE iThickness, const UINT iSolidType = 0, const BOOL iChain = FALSE);
	enum { ChainType_All, ChainType_Parallel };
	void					Chain(const UINT8 iType = 0, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	void					ChainAll(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	void					ChainParallel(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	
	const INT				ConnectOverlappedOnlyParallelVector2D(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	const INT				ConnectJumpLine(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());

	const INT				ChangeVector2DPositiveDirection(const CVector2D & iDirection);
	const INT				ChangeVector2DOrdering(const CVector2D iDirection);

	void					Segmentation();
	void					FillGrid(const DOUBLE iGapDistance, const DOUBLE iOffset, const DOUBLE iThickness = 0.);
	void					Twist(const DOUBLE iLimitLength, const DOUBLE iTwistAngle);
	void					Twist(const UINT iIndex, const DOUBLE iLimitLength, const DOUBLE iTwistAngle, _VertexVector & oPolygon);

	void					ChangeStartingPoint(const UINT16 iType = 0);
	void					ChangeStartingPoint(const UINT iIndex, const UINT16 iType = 0);
protected:
	void					SolidVectorTo2Direction(const DOUBLE iThickness);
	void					SolidPolygonTo4Direction(const DOUBLE iThickness);
	void					SolidPolygonSmooth(const DOUBLE iThickness);

private:
	void					_ReducePointsByDistanceFromLine(const DOUBLE iTolerance = 0.);
	void					_ReducePointsByAngle(const DOUBLE iAngleToRemove = 0.);
	void					_ReduceByDistance(const DOUBLE iDistanceToRemove = 0.);

public:
	virtual const DOUBLE	Area() const;

#pragma endregion

#pragma region Bitmap
public:
	typedef enum { BitmapPixelFormat_1bppIndexed, BitmapPixelFormat_8bppIndexed }BITMAPPIXELFORMAT;
	CExtBitmap *			CreateBitmapReversedAxis(const BITMAPPIXELFORMAT iPixelformat, const UINT iWidth, const UINT iHeight, const CRectDouble & iAreaToCreate, const UINT iScaleForSmooth) const;
	CExtBitmap *			CreateBitmap(const BITMAPPIXELFORMAT iPixelformat, const UINT iWidth, const UINT iHeight, const CRectDouble & iAreaToCreate, const UINT iScaleForSmooth) const;
	CExtBitmap *			CreateBitmapYXAxis(const BITMAPPIXELFORMAT iPixelformat, const UINT iWidth, const UINT iHeight, const CRectDouble & iAreaToCreate, const UINT iScaleForSmooth = 1, const UINT16 iType = 0) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual void			GetBoundingBoxes(vector<CBoundingBox2D> & oBoundingBoxes) const;
	void					GetBoundingBoxes(const vector<vector<UINT>> & iGroups, vector<CBoundingBox2D> & oBoundingBoxes) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPolygons2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const CGPolygon2D & iPolygon);
	const BOOL				CopyFrom(const CGPolygon & iPolygon);
	const BOOL				CopyFrom(const CGPolygons2D & iPolygon);
	const BOOL				CopyFrom(const CGPolygons & iPolygons);
	const BOOL				CopyFrom(const _VertexVector & iPolygon);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
private:
	const INT				ReadVertices(CFileReadObject & file);
	const INT				ReadIndices(CFileReadObject & file);
	const INT				SaveVertices(CFileWriteObject & file);
	const INT				SaveIndices(CFileWriteObject & file);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPolygons2D &	operator = (const CGPolygons2D & iPolygons);
	const CGPolygons2D &	operator = (const CGPolygons & iPolygons);
	const CGPolygons2D &	operator = (const CGPolygon2D & iPolygon);
	const CGPolygons2D &	operator = (const CGPolygon & iPolygon);
	const CGPolygons2D &	operator = (const _VertexVector & iPolygon);
	const CGPolygons2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGPolygons2D		operator + (const CGPolygons2D & iPolygons) const;
	void					operator += (const CGPolygons2D & iPolygons);
	const CGPolygons2D		operator - () const;
	const CGPolygons2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGPolygons2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGPolygons2D		operator * (const CMatrix2x2 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	const CGPolygons2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGPolygons2D		operator * (const CMatrix3x3 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	const CGPolygons2D		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGPolygons2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGPolygons2D & iPolygons) const;
	const BOOL				operator != (const CGPolygons2D & iPolygons) const;
#pragma endregion

#pragma region Static fuction
public:
	enum HatchStyle_FillType { HatchStyle_FillType_Line, HatchStyle_FillType_Offset, HatchStyle_FillType_Cross };
	enum HatchOrderType { HatchOrderType_ZigZig, HatchOrderType_ZigZag, HatchOrderType_OptimizedSorting	};
	enum HatchSortingOrder { HatchSortingOrder_None, HatchSortingOrder_Direction };
	static void				GenerateInfill(const CGPolygons2D & iPolygonToFill, CGPolygons2D & oResult, const HatchStyle_FillType iHatchStyle = HatchStyle_FillType_Line, const DOUBLE iHatchDistance = 0., const UINT iNumberOfOutline = 0, const DOUBLE iAngle = 0., const HatchOrderType iOrder = HatchOrderType_ZigZig, const UINT iNumberOfPaths = 1, const BOOL iSeparate = TRUE, const BOOL iAppendPath = FALSE);
	static void				GenerateInfill(const CGPolygons2D & iPolygonToFill, CGPolygons2D & oResult, const HatchStyle_FillType iHatchStyle, const DOUBLE iHatchDistance, const UINT iNumberOfOutline, const DOUBLE iAngle, const HatchOrderType iOrder, const UINT iNumberOfPaths, const DOUBLE iShiftDistance, const HatchSortingOrder iHatchSortingOrder, const DOUBLE iHatchSortingAngle, const BOOL iSeparate, const BOOL iAppendPath);
	static const UINT		GetNumberOfVectors(const vector<UINT> & iSeparators);
	static const UINT		Get3DVectorLines(const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparators, FLOAT *& oResult);
	static const UINT		Get3DVectorLines(const vector<DOUBLE> & iThickness, const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparators, FLOAT *& oResult);
	static const UINT		Get3DTriangles(const vector<DOUBLE> & iThickness, const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparators, FLOAT *& oResult);
	static const UINT		GetTrianglesFromVectorLine(const Coordinate2D & iDeparture, DOUBLE iThickness, const DOUBLE iLength, const DOUBLE iAngle, vector<Coordinate2D> & oTriangles);
protected:
	static void				ConnectLines(const vector<vector<Coordinate2D>> & iLineToConnect, vector<vector<Coordinate2D>> & oResult);
#pragma endregion

#pragma region Memeber Variable
protected:
	_SeparateIndicesOfPolygons	m_Separator;
#pragma endregion
};

		}
	}
}