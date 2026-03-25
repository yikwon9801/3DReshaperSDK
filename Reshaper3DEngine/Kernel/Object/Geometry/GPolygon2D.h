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

			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangles);

RsDEFINE_DLL_CLASS(CGPolygon2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<Coordinate2D>	_VertexVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPolygon2D();
	CGPolygon2D(const CGPolygon2D & iPolygon);
	CGPolygon2D(const CGMultiLine & iPolygon);
	CGPolygon2D(const _VertexVector & iVertices);
public:
	virtual ~CGPolygon2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _VertexVector &	GetVertices() const { return m_Vertices; }
	inline _VertexVector &	Vertices() { return m_Vertices; }
	inline const UINT		GetVertexCount() const { return (UINT)m_Vertices.size(); }
protected:
	inline void				SetVertices(const _VertexVector & iVertices) { m_Vertices = iVertices; }
#pragma endregion

#pragma region General Function
public:
	void					Clear();
	void					Release();
	void					RemovePoint(const UINT iIndex);
	void					RemovePoints(const UINT iBegin, const UINT iEnd);

	void					InsertPoints(const UINT iIndex, const _VertexVector & iPoints);
	void					AddPoint(const Coordinate2D & iPoint);
	void					AddPoint(const CGPoint2DDouble & iPoint);
	void					AddPoint(const CGPointDouble & iPoint);

	const BOOL				HasPoint(const Coordinate2D & iPoint, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet()) const;

	void					AddPolygon(const CGPolygon2D & iPolygon);
	void					AddPolygon(const vector<vector<Coordinate2D>> & iSlicedPolygon);
	
	void					Get(CGMultiLine & oMultiLine) const;
	void					Get(FLOAT * oArray) const;
	void					Get(vector<pair<DOUBLE, DOUBLE>> & oPoints) const;
	void					Get(CGPolygons2D & oPolygons) const;
	void					Set(FLOAT * iArray, const UINT iNumberOfVertex);
protected:
	const BOOL				IsEqual(const CGPolygon2D & iPolygon) const;

public:
	virtual void			Close();
	virtual void			Open();
	virtual const BOOL		IsClosed() const;
#pragma endregion

#pragma region CAD Functions
public:
	void					ChangeStartingPoint(const UINT iIndex);

	const DOUBLE			Area(const UINT iStart, const UINT iEnd) const;

	const INT				GetLongestPoint(const CVector2D & iDirection, Coordinate2D * oLongestPoint = NULL) const;
	const INT				GetClosestPoint(const Coordinate2D & iPoint, Coordinate2D * oClosestPoint = NULL) const;
	const INT				GetClosestPoint(const Coordinate2D & iPoint, Coordinate2D * oClosestPoint, const vector<UINT> * const iExcludePolygon) const;

	const INT				Split1(const _VertexVector & iPolygon, vector<_VertexVector> & oResult) const;

	CGPolyhedron *			Reconstruct2D(const UINT16 iType = 0) const;
	const INT				Triangulate(CGTriangles & oTriangles) const;

public:
	virtual const DOUBLE	Area() const;

#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
	virtual const CGPoint2DDouble	GetCeneroid() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPolygon2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
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
	const CGPolygon2D &		operator = (const CGPolygon2D & iPolygon);
	const CGPolygon2D &		operator = (const CGMultiLine & iPolygon);
	const CGPolygon2D &		operator = (const _VertexVector & iPolygon);
	const CGPolygon2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGPolygon2D		operator - () const;
	const CGPolygon2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGPolygon2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGPolygon2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const CGPolygon2D		operator * (const CMatrix2x2 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	const CGPolygon2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGPolygon2D		operator * (const CMatrix3x3 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	const CGPolygon2D		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CGPolygon2D & iPolygon) const;
	const BOOL				operator != (const CGPolygon2D & iPolygon) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		Area(const _VertexVector & iPolygon, const UINT iStart, const UINT iEnd);
#pragma endregion

#pragma region Memeber Variable
protected:
	_VertexVector			m_Vertices;
#pragma endregion
};

		}
	}
}