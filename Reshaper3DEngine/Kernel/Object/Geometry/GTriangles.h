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

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGTriangles) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<CGTriangle>	_TriangleVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGTriangles();
	CGTriangles(const _TriangleVector & iTriangles);
	CGTriangles(const CGTriangles & iTriangles);
	virtual ~CGTriangles();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _TriangleVector &	GetTriangles() const { return m_Triangles; }
	inline const CGTriangle	&	GetTriangle(const UINT iIndex) const { return m_Triangles[iIndex]; }
	inline const UINT		GetCount() const { return (UINT)m_Triangles.size(); }
public:
	void					Get(vector<CGPointDouble> & oPoints) const;
	void					Get(CGPointDouble oPoints[]) const;
public:
	void					Set(const vector<Coordinate2D> & iPoints, const DOUBLE iZ = 0.);
	void					Set(const vector<CGPoint2DDouble> & iPoints, const DOUBLE iZ = 0.);
	void					Set(const CGPolyhedron & iPolyhedron);
#pragma endregion

#pragma region General Function
public:
	void					AddTriangle(const CGTriangle & iTriangle);
	void					AddTriangles(const CGTriangles & iTriangles);
	void					AddTriangles(const _TriangleVector & iTriangles);
protected:
	const BOOL				IsEqual(const CGTriangles & iTriangles) const;
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const BOOL				IsConnected(const CGTriangles & iTriangles, const UINT16 iType = 0) const;
	const BOOL				IsConnected(const CGTriangle & iTriangles, const UINT16 iType = 0) const;
	const INT				Explode(vector<CGTriangles> & oTriangles, CProgress * iProgress = NULL) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGTriangles *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGTriangles &		operator = (const CGTriangles & iTriangles);
	const CGTriangles		operator + (const CGTriangles & iTriangles) const;
	void					operator += (const CGTriangles & iTriangles);
	const CGTriangles		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGTriangles		operator - () const;
	const CGTriangles		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGTriangles		operator * (const DOUBLE iValue) const;
	const CGTriangles		operator * (const CMatrix3x3 & iMatrix) const;
	const CGTriangles		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGTriangles		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGTriangles & iTriangles) const;
	const BOOL				operator != (const CGTriangles & iTriangles) const;
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