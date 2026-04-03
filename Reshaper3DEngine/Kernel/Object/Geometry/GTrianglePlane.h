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

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangles);
			RsDEFINE_CLASS(CGPolygon);
			RsDEFINE_CLASS(CGPolygons);
			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGPolygons2D);

			using namespace Kernel::File;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGTrianglePlane) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGTrianglePlane(const CGPointDouble & iOrigin, const CVector & iU, const CVector & iV);
	CGTrianglePlane(const CGPointDouble & iPoint1, const CGPointDouble & iPoint2, const CGPointDouble & iPoint3);
	CGTrianglePlane(const Coordinate3D & iPoint1, const Coordinate3D & iPoint2, const Coordinate3D & iPoint3);
	CGTrianglePlane(const CGTrianglePlane & rhs);
	virtual ~CGTrianglePlane();
#pragma endregion

#pragma region Setter & Getter function
public:
	void					Init(const CGPointDouble & iOrigin, const CVector & iU, const CVector & iV);
	void					Init(const CGPointDouble & iPoint1, const CGPointDouble & iPoint2, const CGPointDouble & iPoint3);
	void					Init(const Coordinate3D & iPoint1, const Coordinate3D & iPoint2, const Coordinate3D & iPoint3);
#pragma endregion

#pragma region General function
public:
	const CGPoint2DDouble	ProjectTo2D(const CGPointDouble & iPoint) const;
	const CGPointDouble		ProjectTo3D(const CGPoint2DDouble & iPoint) const;
	const Coordinate2D		ProjectTo2D(const Coordinate3D & iPoint) const;
	const Coordinate3D		ProjectTo3D(const Coordinate2D & iPoint) const;

	void					ProjectTo2D(const Coordinate3D & iTP1, const Coordinate3D & iTP2, const Coordinate3D & iTP3, vector<Coordinate2D> & oResult) const;
	void					ProjectTo2D(const vector<vector<Coordinate3D>> & iPolygons, vector<vector<Coordinate2D>> & oPolygons2D) const;
	void					ProjectTo2D(const vector<Coordinate3D> & iPolygon, vector<Coordinate2D> & oPolygon2D) const;
	void					ProjectTo2D(const CGPolygon & iPolygon, CGPolygon2D & oPolygon2D) const;
	void					ProjectTo3D(const vector<vector<Coordinate2D>> & iPolygons2D, vector<vector<Coordinate3D>> & oPolygons) const;
	void					ProjectTo3D(const vector<Coordinate2D> & iPolygon2D, vector<Coordinate3D> & oPolygon) const;
	void					ProjectTo3D(const CGPolygon2D & iPolygon2D, CGPolygon & oPolygon) const;
	void					ProjectTo3D(vector<CGTriangle> & ioTriangles) const;
	void					ProjectTo3D(CGTriangles & ioTriangles) const;
	void					ProjectTo3D(const CGPolygons2D & iPolygons2D, CGPolygons & oPolygons) const;
protected:
	const BOOL				IsEqual(const CGTrianglePlane & iPlane) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGTrianglePlane *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGTrianglePlane &	operator = (const CGTrianglePlane & iPlane);
	const BOOL				operator == (const CGTrianglePlane & iPlane) const;
	const BOOL				operator != (const CGTrianglePlane & iPlane) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Origin;
	CVector					m_U, m_V, m_N;
#pragma endregion
};

		}
	}
}