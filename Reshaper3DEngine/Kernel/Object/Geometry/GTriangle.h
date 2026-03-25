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
			RsDEFINE_CLASS(CGPlane);
			RsDEFINE_CLASS(CGTriangles);
			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGLine);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGTriangle) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGTriangle();
	CGTriangle(const CGPointDouble & iPoint1, const CGPointDouble & iPoint2, const CGPointDouble & iPoint3);
	CGTriangle(const DOUBLE iP1X, const DOUBLE iP1Y, const DOUBLE iP1Z, const DOUBLE iP2X, const DOUBLE iP2Y, const DOUBLE iP2Z, const DOUBLE iP3X, const DOUBLE iP3Y, const DOUBLE iP3Z);
	CGTriangle(const CGTriangle & rhs);
	virtual ~CGTriangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint(const UINT iIndex) const { return m_Points[iIndex]; }

	void					Get(CGPointDouble oPoints[]) const;
	void					Get(CGPolygons2D & oPolygons2D) const;
	void					Get(CGPolygon2D & oPolygon2D) const;
public:
	inline void				SetPoint1(const CGPointDouble & iPoint) { SetPoint(0, iPoint); }
	inline void				SetPoint2(const CGPointDouble & iPoint) { SetPoint(1, iPoint); }
	inline void				SetPoint3(const CGPointDouble & iPoint) { SetPoint(2, iPoint); }
	inline void				SetPoint(const UINT iIndex, const CGPointDouble & iPoint) { m_Points[iIndex] = iPoint; }
	inline void				SetPoint(const CGPointDouble & iPoint1, const CGPointDouble & iPoint2, const CGPointDouble & iPoint3) { SetPoint1(iPoint1); SetPoint2(iPoint2); SetPoint3(iPoint3); }
	inline void				SetPoint(const DOUBLE iP1X, const DOUBLE iP1Y, const DOUBLE iP1Z, const DOUBLE iP2X, const DOUBLE iP2Y, const DOUBLE iP2Z, const DOUBLE iP3X, const DOUBLE iP3Y, const DOUBLE iP3Z)
	{
		m_Points[0].SetCoordinate(iP1X, iP1Y, iP1Z);
		m_Points[1].SetCoordinate(iP2X, iP2Y, iP2Z);
		m_Points[2].SetCoordinate(iP3X, iP3Y, iP3Z);
	}
#pragma endregion

#pragma region General Function
public:
	const CVector			GetNormal(const BOOL iNormalized = TRUE) const;
	void					GetDirections(CVector oDirections[], const BOOL iNormalized = TRUE) const;
protected:
	const BOOL				IsEqual(const CGTriangle & iTriangle) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const BOOL				IsConnected(const CGTriangle & iTriangle, const UINT iType = 0) const;
	const BOOL				Contains(const CGPointDouble & iPoint) const;
	const INT				Intersect(const CGPlane & iPlane, CGPointDouble & oIntP1, CGPointDouble & oIntP2) const;
	const DOUBLE			GetArea() const;
	const DOUBLE			GetCircumference() const;

	const INT				Triangulate(const CGMultiLine & iSplitLine, vector<CGTriangles> & oSplitTriangles, void * ioData) const;
	const INT				Triangulate(const CGMultiLines & iSplitLines, vector<CGTriangles> & oSplitTriangles, void * ioData) const;
	const INT				Triangulate(const vector<vector<CGPointDouble>> & iSplitLines, vector<CGTriangles> & oSplitTriangles, void * ioData) const;
	const INT				GetOnEdge(const CGPointDouble & iPoint) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGTriangle *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGTriangle &		operator = (const CGTriangle & iTriangle);
	const CGTriangle		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGTriangle		operator - () const;
	const CGTriangle		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGTriangle		operator * (const DOUBLE iValue) const;
	const CGTriangle		operator * (const CMatrix3x3 & iMatrix) const;
	const CGTriangle		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGTriangle		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGTriangle & iTriangle) const;
	const BOOL				operator != (const CGTriangle & iTriangle) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		CalculateArea(const CGPointDouble & P1, const CGPointDouble & P2, const CGPointDouble & P3);
	static void				CalculateNormal(const CGVertex & v1, const CGVertex & v2, const CGVertex & v3, CVector & oNormal, const BOOL iNormalized = TRUE);
	static void				CalculateNormal(const CGPointDouble & P1, const CGPointDouble & P2, const CGPointDouble & P3, CVector & oNormal, const BOOL iNormalized = TRUE);
	static const INT		IntersectWithRay(const CGVertex & v1, const CGVertex & v2, const CGVertex & v3, const CGLine & iRay, CGPointDouble & oPoint);
	static const INT		Intersect(const CGTriangle & iTri1, const CGTriangle & iTri2, CGPointDouble & oIntP1, CGPointDouble & oIntP2);
	static const INT		Intersect(const CGPointDouble & iT1P1, const CGPointDouble & iT1P2, const CGPointDouble & iT1P3, const CGPointDouble & iT2P1, const CGPointDouble & iT2P2, const CGPointDouble & iT2P3, CGPointDouble & oIntP1, CGPointDouble & oIntP2);
	static const INT		Intersect2(const CGPointDouble & iT1P1, const CGPointDouble & iT1P2, const CGPointDouble & iT1P3, const CGPointDouble & iT2P1, const CGPointDouble & iT2P2, const CGPointDouble & iT2P3, CGPointDouble & oIntP1, CGPointDouble & oIntP2);
	static const BOOL		IsInsideOnZ(const CGVertex & v1, const CGVertex & v2, const CGVertex & v3, const DOUBLE iZ);
	static const BOOL		MakeSegment(const INT x1, const INT y1, const INT z1, const INT x2, const INT y2, const INT z2, const INT x3, const INT y3, const INT z3, const INT z, INT & oX1, INT & oY1, INT & oX2, INT & oY2);
	static void				MinMaxZ(const CGPointDouble & P1, const CGPointDouble & P2, const CGPointDouble & P3, DOUBLE & oMinZ, DOUBLE & oMaxZ);
protected:
	static void				SectionZPlane(const INT x1, const INT y1, const INT z1, const INT x2, const INT y2, const INT z2, const INT x3, const INT y3, const INT z3, const INT z, INT & oX1, INT & oY1, INT & oX2, INT & oY2);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Points[3];
#pragma endregion
};

		}
	}
}