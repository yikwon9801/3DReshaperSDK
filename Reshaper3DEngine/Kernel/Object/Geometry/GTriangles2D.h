#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangle2D);
			RsDEFINE_CLASS(CGTriangles);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGTriangles2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<CGTriangle2D>	_TriangleVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGTriangles2D();
	CGTriangles2D(const _TriangleVector & iTriangles);
	CGTriangles2D(const CGTriangles2D & iTriangles);
	virtual ~CGTriangles2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _TriangleVector &	GetTriangles() const { return m_Triangles; }
	inline _TriangleVector &	Triangles() { return m_Triangles; }
	inline const CGTriangle2D	&	GetTriangle(const UINT iIndex) const { return m_Triangles[iIndex]; }
	inline const UINT		GetCount() const { return (UINT)m_Triangles.size(); }
public:
	void					Get(vector<CGPoint2DDouble> & oPoints) const;
	void					Get(CGPoint2DDouble oPoints[]) const;
	void					Get(vector<Coordinate2D> & oPoints) const;
	void					Get(CGTriangles & oTriangles, const AXIS2DTYPE iType = AXIS2DTYPE_XYAXIS) const;
public:
	void					Set(const vector<CGPoint2DDouble> & iPoints);
	void					Set(const vector<Coordinate2D> & iPoints);
	void					Set(const CGPolyhedron & iPolyhedron);
#pragma endregion

#pragma region General Function
public:
	void					AddTriangle(const CGTriangle2D & iTriangle);
	void					AddTriangle(const CGPoint2DDouble & iPoint1, const CGPoint2DDouble & iPoint2, const CGPoint2DDouble & iPoint3);
	void					AddTriangles(const CGTriangles2D & iTriangles);
	void					AddTriangles(const _TriangleVector & iTriangles);
protected:
	const BOOL				IsEqual(const CGTriangles2D & iTriangles) const;
public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGTriangles2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGTriangles2D &	operator = (const CGTriangles2D & iTriangles);
	const CGTriangles2D		operator + (const CGTriangles2D & iTriangles) const;
	void					operator += (const CGTriangles2D & iTriangles);
	const CGTriangles2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGTriangles2D		operator - () const;
	const CGTriangles2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGTriangles2D		operator * (const DOUBLE iValue) const;
	const CGTriangles2D		operator * (const CMatrix2x2 & iMatrix) const;
	const CGTriangles2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGTriangles2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGTriangles2D & iTriangles) const;
	const BOOL				operator != (const CGTriangles2D & iTriangles) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	_TriangleVector			m_Triangles;
#pragma endregion
};

		}
	}
}