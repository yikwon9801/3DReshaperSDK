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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{

		namespace Geometry
		{
			using namespace Kernel::Collection;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGPolygons);
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangles);

RsDEFINE_DLL_CLASS(CGPolygon) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<Coordinate3D>	_VertexVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPolygon();
	CGPolygon(const CGPolygon & iPolygon);
	CGPolygon(const CGPolygon2D & iPolygon);
	CGPolygon(const CGMultiLine & iPolygon);
	CGPolygon(const _VertexVector & iVertices);
public:
	virtual ~CGPolygon();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _VertexVector &	GetVertices() const { return m_Vertices; }
	inline _VertexVector &	Vertices() { return m_Vertices; }
	inline const UINT		GetVertexCount() const { return (UINT)m_Vertices.size(); }
protected:
	inline void				SetVertices(const _VertexVector & iVertices) { m_Vertices = iVertices; }
public:
	void					SetPolygons(const CGPolygon2D & iPolygons, const DOUBLE iZ = 0.);
#pragma endregion

#pragma region General Function
public:
	void					Clear();
	void					Release();
	void					RemovePoint(const UINT iIndex);
	void					RemovePoints(const UINT iBegin, const UINT iEnd);

	void					InsertPoints(const UINT iIndex, const _VertexVector & iPoints);
	void					AddPoint(const Coordinate3D & iPoint);
	void					AddPoint(const CGPoint2DDouble & iPoint);
	void					AddPoint(const CGPointDouble & iPoint);

	const BOOL				HasPoint(const Coordinate3D & iPoint, const DOUBLE iAccuracy = CGPointDouble::AbsoluteAccuracyGet()) const;

	void					AddPolygon(const CGPolygon & iPolygon);
	void					AddPolygon(const vector<Coordinate3D> & iPolygon);
	void					AddPolygon(const vector<Coordinate2D> & iPolygon, const DOUBLE iZ = 0.);
	void					AddPolygon(const vector<vector<Coordinate3D>> & iPolygons);
	void					AddPolygon(const vector<vector<Coordinate2D>> & iPolygons, const DOUBLE iZ = 0.);
	
	void					Get(CGMultiLine & oMultiLine) const;
	void					Get(vector<vector<Coordinate3D>> & oPolygon) const;
	void					Get(vector<LineCoordinate3D> & oLines) const;
	void					Get(FLOAT * oArray) const;
	void					Set(FLOAT * iArray, const UINT iNumberOfVertex);

	const DOUBLE			GetHighestZ() const;
	const DOUBLE			GetLowestZ() const;

protected:
	const BOOL				IsEqual(const CGPolygon & iPolygon) const;

public:
	virtual void			Close();
	virtual void			Open();
	virtual const BOOL		IsClosed() const;
	virtual const DOUBLE	GetLength() const;

#pragma endregion

#pragma region CAD Functions
public:
	const BOOL				Smooth(const DOUBLE iPara = .5);

	void					ChangeStartingPoint(const UINT iIndex);
protected:
	const BOOL				Smooth(const DOUBLE iPara, const Coordinate3D & iPrev, const Coordinate3D & iNext, Coordinate3D & iV);

public:
	virtual const INT		ProjectOntoMesh(const CGPolyhedron & iPolyhedron, const CVector & iDirection, CGPolygons & oResult);
	virtual const INT		ProjectOntoMeshByZAxis(const CGPolyhedron & iPolyhedron, CGPolygons & oResult);

#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
	virtual const CGPointDouble	GetCeneroid() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPolygon *		Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const CGPolygon2D & iPolygons);
	const BOOL				CopyPolygonFrom(const CGMultiLine & iPolygon);
	const BOOL				CopyPolygonFrom(const _VertexVector & iPolygon);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
private:
	const INT				ReadVertices(CFileReadObject & file);
	const INT				SaveVertices(CFileWriteObject & file);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPolygon &		operator = (const CGPolygon & iPolygon);
	const CGPolygon &		operator = (const CGPolygon2D & iPolygon);
	const CGPolygon &		operator = (const CGMultiLine & iPolygon);
	const CGPolygon &		operator = (const _VertexVector & iPolygon);
	const CGPolygon			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGPolygon			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGPolygon			operator - () const;
	const CGPolygon			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGPolygon			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGPolygon			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGPolygon			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const CGPolygon			operator * (const CMatrix2x2 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	const CGPolygon			operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGPolygon			operator * (const CMatrix3x3 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	const CGPolygon			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CGPolygon & iPolygon) const;
	const BOOL				operator != (const CGPolygon & iPolygon) const;
#pragma endregion

#pragma region Static fuction
public:
	enum { SPLINE_LINEAR, SPLINE_BEZIERCURVE, SPLINE_BSPLINE, SPLINE_HERMITE, SPLINE_CATMULLROM };
	static const INT		CreateSplineCurve(const UINT8 iType, const _VertexVector & iControlPoints, const UINT iNumberOfVertices, CGPolygon & oPolygon);
#pragma endregion

#pragma region Memeber Variable
protected:
	_VertexVector			m_Vertices;
#pragma endregion
};

		}
	}
}