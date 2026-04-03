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
			RsDEFINE_CLASS(CGTriangles);

			using namespace Kernel::Primitive;
			using namespace Kernel::Collection;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Slice;
			using namespace Kernel::Draw;

RsDEFINE_DLL_CLASS(CGPolygons) : RsINHERITANCE(CGPolygon)
{
#pragma region Type Definition
public:
	typedef vector<UINT>			_SeparateIndicesOfPolygons;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPolygons();
	CGPolygons(const CGPolygons & iPolygons);
	CGPolygons(const _VertexVector & iPolygons);
	CGPolygons(const CGMultiLine & iSlicedPolygon);
	CGPolygons(const CGMultiLines & iSlicedPolygon);
	CGPolygons(const vector<LineCoordinate3D> & iPolygons);
	CGPolygons(const vector<CGPolygons> & iPolygons);
	virtual ~CGPolygons();
private:
	CGPolygons(const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparator);
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
	void					SetPolygons(const CGPolygons & iPolygons);
	void					SetPolygons(const CGPolygons2D & iPolygons, const DOUBLE iZ = 0.);
	void					SetPolygons(const vector<vector<Coordinate3D>> & iSlicedPolygon);
	void					SetPolygons(const vector<CGPolygons> & iPolygons);
	void					SetPolygons(const vector<LineCoordinate3D> & iPolygons);
	void					SetPolygon(const CGPolygon & iPolygon);
	void					SetPolygon(const _VertexVector & iPolygon);
#pragma endregion

#pragma region General Function
public:
	void					AddPolygons(const CGPolygons & iPolygons);
	void					AddPolygons(const CGPolygons2D & iPolygons, const DOUBLE iZ = 0.);
	void					AddPolygons(const CGMultiLines & iPolygons);
	void					AddPolygons(const vector<vector<Coordinate3D>> & iPolygons);
	void					AddPolygons(const vector<vector<Coordinate2D>> & iPolygons, const DOUBLE iZ = 0.);
	void					AddPolygon(const CGMultiLine & iPolygon);
	void					AddPolygon(const CGPolygon & iPolygon);
	void					AddPolygon(const vector<Coordinate3D> & iPolygon);
	void					AddPolygon(const CGPolygon2D & iPolygon, const DOUBLE iZ = 0.);
	void					AddPolygon(const vector<Coordinate2D> & iPolygon, const DOUBLE iZ = 0.);
	void					InsertPolygons(const UINT iIndex, const CGPolygons & iPolygons);

	void					Clear();
	void					Release();
	void					RemovePolygon(const UINT iIndex);
	void					RemovePolygons(const UINT iBegin, const UINT iEnd);

	void					Get(const UINT iIndex, CGMultiLine & oMultiLine) const;
	void					Get(const UINT iIndex, CGPolygon & oPolygon) const;
	void					Get(const UINT iIndex, CGPolygons & oPolygons) const;
	void					Get(const vector<UINT> & iSeparatorIndices, CGPolygons & oPolygons) const;
	void					Get(CGMultiLines & oMultiLines) const;
	void					Get(CTableList<CGMultiLine *> & oTableMultiLine) const;
	void					Get(FLOAT * oArray) const;
	void					Get(vector<vector<Coordinate3D>> & oPolygons) const;
	void					Get(vector<vector<LineCoordinate3D>> & oPolygons) const;
	void					Get(CGPolygons & oSolidType, CGPolygons & oNonSolidType) const;

	void					GetSeparator(vector<INT> & oSeparators) const;

	const INT				GetLinesBetweenPolygons(CGPolygons & oPolygons) const;
	const INT				GetStartingPosition(const UINT iIndex, UINT & oPosition) const;

	const BOOL				IsOnlyLine() const;
protected:
	const BOOL				IsEqual(const CGPolygons & iPolygons) const;

public:
	virtual void			Close();
	virtual void			Open();
	virtual const BOOL		IsClosed() const;
	virtual const DOUBLE	GetLength() const;

#pragma endregion

#pragma region CAD Functions
public:
	const INT				GetClosedPolygons(vector<UINT> & oPolygonIndices) const;
	const INT				GetClosedPolygons(CGPolygons & oPolygons) const;

	void					RemoveDuplicateCoordinate(const DOUBLE iAccuracy = CGPointDouble::AbsoluteAccuracyGet());
	const UINT				RemovePolygonLessThanNumberOfPoint(const UINT iPointNumber);
	void					IncreaseDensity(const DOUBLE iLimitLength);

	void					Segmentation();

	void					ChangeStartingPoint(const UINT16 iType = 0);
	void					ChangeStartingPoint(const UINT iIndex, const UINT16 iType = 0);

	const INT				ProjectOntoMesh(const CGPolyhedron & iPolyhedron, CGPolygons & oResult, LPVOID ioData = NULL);
	const INT				ProjectOntoMesh(const CGPolyhedron & iPolyhedron, const CVector & iDirection, CGPolygons & oResult);
	const INT				ProjectOntoMeshByZAxis(const CGPolyhedron & iPolyhedron, CGPolygons & oResult);
	const INT				ProjectOntoMeshByZAxis2(const CGPolyhedron & iPolyhedron, CGPolygons & oResult);

	void					Reduce(const UINT16 iType, const DOUBLE iTolerance);

	CGPolyhedron *			ReconstructThickness(const CVector & iDirection, const DOUBLE iThickness) const;
	const INT				ReconstructThickness(const CVector & iDirection, const DOUBLE iThickness, CGTriangles & oTriangles) const;

private:
	void					_ReducePointsByAngle(const DOUBLE iAngleToRemove);
	void					_ReduceByDistance(const DOUBLE iDistanceToRemove = 0.);
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual void			GetBoundingBoxes(vector<CBoundingBox> & oBoundingBoxes) const;
	void					GetBoundingBoxes(const vector<vector<UINT>> & iGroups, vector<CBoundingBox> & oBoundingBoxes) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPolygons *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const CGPolygon & iPolygon);
	const BOOL				CopyFrom(const CGPolygons & iPolygons);
	const BOOL				CopyFrom(const CGPolygons2D & iPolygons);
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
	const CGPolygons &		operator = (const CGPolygons & iPolygons);
	const CGPolygons &		operator = (const vector<CGPolygons> & iPolygons);
	const CGPolygons &		operator = (const CGPolygons2D & iPolygons);
	const CGPolygons &		operator = (const CGPolygon & iPolygon);
	const CGPolygons &		operator = (const _VertexVector & iPolygon);
	const CGPolygons		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGPolygons		operator + (const CGPolygons & iPolygons) const;
	void					operator += (const CGPolygons & iPolygons);
	const CGPolygons		operator - () const;
	const CGPolygons		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGPolygons		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGPolygons		operator * (const CMatrix2x2 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	const CGPolygons		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGPolygons		operator * (const CMatrix3x3 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	const CGPolygons		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGPolygons		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGPolygons & iPolygons) const;
	const BOOL				operator != (const CGPolygons & iPolygons) const;
#pragma endregion

#pragma region Static fuction
public:
	static const UINT		GetNumberOfVectors(const vector<UINT> & iSeparators);
	static const UINT		Get3DVectorLines(const _VertexVector & iVertices, const _SeparateIndicesOfPolygons & iSeparators, FLOAT *& oResult);
	static const INT		CreateTooth(const CGPolygons & iPolygons, const DOUBLE iHeight, const CVector & iDirection, const DOUBLE iUpperlength, const DOUBLE iLowerLength, const DOUBLE iGapDistance, CGTriangles & oTriangles);
protected:
	static void				ConnectLines(const vector<vector<Coordinate3D>> & iLineToConnect, vector<vector<Coordinate3D>> & oResult);
#pragma endregion

#pragma region Memeber Variable
protected:
	_SeparateIndicesOfPolygons	m_Separator;
#pragma endregion
};

		}
	}
}