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
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);

		using namespace Kernel;
		using namespace Kernel::File;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CVector2D) : RsINHERITANCE(CGPoint2DDouble)
{
#pragma region Construction & Destruction
public:
	CVector2D();
	CVector2D(const CGPoint2DDouble & iPoint);
	CVector2D(const CGPointDouble & iPoint);
	CVector2D(const CVector2D & iVector);
	CVector2D(const CVector & iVector);
	CVector2D(const DOUBLE iVector[]);
	CVector2D(const CGPoint2DDouble & iDeparture, const CGPoint2DDouble & iArrival);
	CVector2D(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	CVector2D(const DOUBLE iDepartureX, const DOUBLE iDepartureY, const DOUBLE iArrivalX, const DOUBLE iArrivalY);
	CVector2D(const DOUBLE iX, const DOUBLE iY);
	CVector2D(const pair<DOUBLE, DOUBLE> point);
	virtual ~CVector2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetX() const { return _xx; }
	inline const DOUBLE		GetY() const { return _yy; }
	inline void				Get(DOUBLE Coordinate[]) const { for (INT ii = 0; ii < 2; ii++) Coordinate[ii] = _val[ii]; }
public:
	inline void				SetX(const DOUBLE iX) { _xx = iX; }
	inline void				SetY(const DOUBLE iY) { _yy = iY; }
	inline void				SetCoordinate(const DOUBLE iX, const DOUBLE iY) { _xx = iX;	_yy = iY; }

public:
	void					Init(const CGPoint2DDouble & iDeparture, const CGPoint2DDouble & iArrival);
	void					Init(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	void					Init(const DOUBLE iDepartureX, const DOUBLE iDepartureY, const DOUBLE iArrivalX, const DOUBLE iArrivalY);
	void					Init(const DOUBLE iX, const DOUBLE iY);
#pragma endregion

#pragma region Mathematic
public:
	const DOUBLE			Dot(const CVector2D & iVector) const;
	const DOUBLE			Cross(const CVector2D & iVector) const;
public:
	const CVector2D &		Normalized();
	const DOUBLE			Magnitude() const;

	const CVector2D			Inverted() const;

	void					Perpendicular(const BOOL iCCW = TRUE);
	const CVector2D			GetPerpendicular(const BOOL iCCW = TRUE) const;
	void					GetPerpendicular(CVector2D & oVector, const BOOL iCCW = TRUE) const;

public:
	const BOOL				IsOtho(const CVector2D & iDirection) const;
	const BOOL				IsParallel(const CVector2D & iDirection) const;
	const BOOL				IsOpposite(const CVector2D & iDirection) const;
	const BOOL				IsSame(const CVector2D & iDirection) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CVector2D *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CVector2D &		operator = (const CVector2D & iVector);
	const CVector2D &		operator = (const CVector & iVector);
	const CVector2D			operator + (const DOUBLE iValue) const;
	const CVector2D			operator + (const CVector2D & iVector) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CVector2D & iVector);
	const CVector2D			operator - () const;
	const CVector2D			operator - (const DOUBLE iValue) const;
	const CVector2D			operator - (const CVector2D & iVector) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CVector2D & iVector);
	const DOUBLE			operator ^ (const CVector2D & iVector) const;
	const DOUBLE			operator * (const CVector2D & iVector) const;
	const CVector2D			operator * (const CMatrix2x2 & iMatrix) const;
	const CVector2D			operator * (const CMatrix2x3 & iMatrix) const;
	const CVector2D			operator * (const DOUBLE iValue) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	void					operator *= (const DOUBLE iValue);
	const CVector2D			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CVector2D & iVector) const;
	const BOOL				operator != (const CVector2D & iVector) const;
	const BOOL				operator < (const CVector2D & iVector) const;
	const BOOL				operator <= (const CVector2D & iVector) const;
	const BOOL				operator > (const CVector2D & iVector) const;
	const BOOL				operator >= (const CVector2D & iVector) const;
#pragma endregion

#pragma region Static Function
public:
	static const DOUBLE		Angle(const CVector2D & vector1, const CVector2D & vector2);
	static const DOUBLE		Angle2(const CVector2D & vector1, const CVector2D & vector2);
	static const CVector2D	XAxis()	{ return CVector2D(1, 0); }
	static const CVector2D	YAxis()	{ return CVector2D(0, 1); }
	static const CVector2D	DiagonalAxis();
	static const CVector2D	GetDirectionFromAngle(const DOUBLE iAngle);
	static const CVector2D	GetDirectionFromAngle(const DOUBLE iAngle, const CVector2D & iOriginDirection, const BOOL iCCW = FALSE);
	static const BOOL		IsPositiveDirection(const CVector2D & iDirection1, const CVector2D & iDirection2);
	static const BOOL		IsPositiveDirection(const DOUBLE iAngle1, const DOUBLE iAngle2, const CVector2D & iOriginDirection, const BOOL iCCW = FALSE);
#pragma endregion
};

	}
}