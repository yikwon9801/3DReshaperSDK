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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CVector);
	}

	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

	namespace Object
	{

		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Primitive;

RsDEFINE_DLL_CLASS(CGLine2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGLine2D();
	CGLine2D(const CGPoint2DDouble & iDeparture, const CGPoint2DDouble & iArrival);
	CGLine2D(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	CGLine2D(const CGLine2D & iLine);
	virtual ~CGLine2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetDeparture() const { return m_Departure; }
	inline const CGPoint2DDouble &	GetArrival() const { return m_Arrival; }

	void					Get(CGPolygons2D & oPolygons) const;
	void					Get(Coordinate2D & oDeparture, Coordinate2D & oArrival) const;
public:
	void					SetLine2D(const CGPoint2DDouble & iDeparture, const CGPoint2DDouble & iArrival);
	void					SetLine2D(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
#pragma endregion

#pragma region General Function
public:
	const CGPoint2DDouble	GetCeneroid() const;
	const DOUBLE			GetLength() const;
	const DOUBLE			GetDistanceSquare() const;
	const DOUBLE			GetDistance() const;
protected:
	const BOOL				IsEqual(const CGLine2D & iLine) const;

public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetSlope() const;
	const INT				GetSolid(const DOUBLE iThickness, CGPoint2DDouble & oP1, CGPoint2DDouble & oP2, CGPoint2DDouble & oP3, CGPoint2DDouble & oP4) const;

	const INT				CutOverlappedOnlyAtX(const DOUBLE iMinX, const DOUBLE iMaxX);
	const INT				CutLineAtX(const DOUBLE iXtoCut, DOUBLE & oYtoCut) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGLine2D *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGLine2D &		operator = (const CGLine2D & iLine);
	const CGLine2D			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	void					operator += (const CVector & iVector);
	const CGLine2D			operator - () const;
	const CGLine2D			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CVector & iVector);
	const CGLine2D			operator * (const DOUBLE iValue) const;
	const CGLine2D			operator * (const CMatrix2x2 & iMatrix) const;
	const CGLine2D			operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGLine2D			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGLine2D & iLine) const;
	const BOOL				operator != (const CGLine2D & iLine) const;
#pragma endregion

#pragma region Static fuction
public:
	static const INT		CutLineAtX(const CGPoint2DDouble & iDeparture, const CGPoint2DDouble & iArrival, const DOUBLE iXtoCut, DOUBLE & oYtoCut);
	static const INT		Project(const Coordinate2D & iPointToProject, const Coordinate2D & iLP1, const Coordinate2D & iLP2, const CVector2D & iDirection, Coordinate2D & oIntersectedPoint);
	static const INT		Intersect2(const Coordinate2D & P11, const Coordinate2D & P12, const Coordinate2D & P21, const Coordinate2D & P22, Coordinate2D & oIntersectedPoint);
	static const INT		Intersect(const Coordinate2D & P11, const Coordinate2D & P12, const Coordinate2D & P21, const Coordinate2D & P22, Coordinate2D & oIntersectedPoint);
	static const INT		Intersect(const DOUBLE x1, const DOUBLE y1, const DOUBLE x2, const DOUBLE y2, const DOUBLE x3, const DOUBLE y3, const DOUBLE x4, const DOUBLE y4, DOUBLE & oIntersectedPointX, DOUBLE & oIntersectedPointY);
	static const INT		IntersectXAxis(const Coordinate2D & P1, const Coordinate2D & P2, const DOUBLE iYPosition, Coordinate2D & oP);
	static const INT		IntersectYAxis(const Coordinate2D & P1, const Coordinate2D & P2, const DOUBLE iXPosition, Coordinate2D & oP);
	static const BOOL		Contain(const CGPoint2DDouble iP1, const CGPoint2DDouble iP2, const CGPoint2DDouble iP3, const CGPoint2DDouble iP4, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		Contain(const Coordinate2D iP1, const Coordinate2D iP2, const Coordinate2D iP3, const Coordinate2D iP4, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		Contain(const DOUBLE iCX1, const DOUBLE iCY1, const DOUBLE iCX2, const DOUBLE iCY2, const DOUBLE iTX1, const DOUBLE iTY1, const DOUBLE iTX2, const DOUBLE iTY2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		Contain(const DOUBLE iCX, const DOUBLE iCY, const DOUBLE iTX1, const DOUBLE iTY1, const DOUBLE iTX2, const DOUBLE iTY2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		IsOnLine(const CGPoint2DDouble & iPoint, const CGPoint2DDouble & iLineP1, const CGPoint2DDouble & iLineP2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		IsOnLine(const DOUBLE iPX1, const DOUBLE iPY, const DOUBLE iLPX1, const DOUBLE iLPY1, const DOUBLE iLPX2, const DOUBLE iLPY2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		IsOnLineNormalised(const DOUBLE iPX1, const DOUBLE iPY, const DOUBLE iLPX1, const DOUBLE iLPY1, const DOUBLE iLPX2, const DOUBLE iLPY2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		IsOnLineDangerousFunction(const Coordinate2D iPoint, const Coordinate2D iLineP1, const Coordinate2D iLineP2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const BOOL		IsOnLineDangerousFunction(const DOUBLE iPX1, const DOUBLE iPY, const DOUBLE iLPX1, const DOUBLE iLPY1, const DOUBLE iLPX2, const DOUBLE iLPY2, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	static const DOUBLE		Distance(const CGPoint2DDouble iPoint, const CGPoint2DDouble iLineP1, const CGPoint2DDouble iLineP2, CGPoint2DDouble * oPoint = NULL);
	static const DOUBLE		Distance(const Coordinate2D iPoint, const Coordinate2D iLineP1, const Coordinate2D iLineP2, Coordinate2D * oPoint = NULL);
	static const DOUBLE		Distance(const DOUBLE iPX, const DOUBLE iPY, const DOUBLE iLPX1, const DOUBLE iLPY1, const DOUBLE iLPX2, const DOUBLE iLPY2, DOUBLE * oPX = NULL, DOUBLE * oPY = NULL);
	static const INT		Solid(const DOUBLE iThickness, const CGPoint2DDouble & iP1, const CGPoint2DDouble & iP2, CGPoint2DDouble & oP1, CGPoint2DDouble & oP2, CGPoint2DDouble & oP3, CGPoint2DDouble & oP4);
	static const BOOL		PointIsInside(const Coordinate2D & iPoint, const Coordinate2D & iLP1, const Coordinate2D & ILP2);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Departure, m_Arrival;
#pragma endregion
};

		}
	}
}