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
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPoint2DDouble);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);

		using namespace Kernel::File;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CVector) : RsINHERITANCE(CGPointDouble)
{
#pragma region Construction & Destruction
public:
	CVector();
	CVector(const CGPointDouble & iPoint);
	CVector(const CGPoint2DDouble & iPoint);
	CVector(const CVector & iVector);
	CVector(const CVector2D & iVector);
	CVector(const CGVertex & iVertex);
	CVector(const DOUBLE iVector[]);
	CVector(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	CVector(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	CVector(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	CVector(const DOUBLE iX, const DOUBLE iY);
	virtual ~CVector();
#pragma endregion

#pragma region Setter & Getter function
public:
	void					Init(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	void					Init(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	void					Init(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	void					Init(const DOUBLE iX, const DOUBLE iY);
#pragma endregion

#pragma region Mathematic
public:
	const CVector			Crossed(const CVector & iVector) const;
	const DOUBLE			Dot(const CVector & iVector) const;
	void					Cross(const CVector & iVector);
public:
	const CVector &			Normalized();
	const DOUBLE			Magnitude() const;

	const CVector			Inverted() const;
	const CVector2D			To2D() const { return CVector2D(_xx, _yy); }

public:
	const BOOL				IsOtho(const CVector & iDirection) const;
	const BOOL				IsParallel(const CVector & iDirection) const;
	const BOOL				IsOpposite(const CVector & iDirection) const;
	const BOOL				IsSame(const CVector & iDirection) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CVector *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CVector &			operator = (const CVector & iVector);
	const CVector &			operator = (const CGPointDouble & iPoint);
	const CVector &			operator = (const CVector2D & iVector);
	const CVector &			operator = (const CGPoint2DDouble & iPoint);
	const CVector &			operator = (const CGVertex & iVertex);
	const CVector			operator + (const DOUBLE iValue) const;
	const CVector			operator + (const CVector & iVector) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CVector & iVector);
	const CVector			operator - () const;
	const CVector			operator - (const DOUBLE iValue) const;
	const CVector			operator - (const CVector & iVector) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CVector & iVector);
	const CVector			operator ^ (const CVector & iVector) const;
	void					operator ^= (const CVector & iVector);
	const DOUBLE			operator * (const CVector & rhs) const;
	const CVector			operator * (const DOUBLE iValue) const;
	const CVector			operator * (const CMatrix3x3 & matrix) const;
	const CVector			operator * (const CMatrix3x4 & matrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & matrix);
	void					operator *= (const CMatrix3x4 & matrix);
	const CVector			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CVector & iVector) const;
	const BOOL				operator != (const CVector & iVector) const;
	const BOOL				operator < (const CVector & iVector) const;
	const BOOL				operator <= (const CVector & iVector) const;
	const BOOL				operator > (const CVector & iVector) const;
	const BOOL				operator >= (const CVector & iVector) const;
#pragma endregion

#pragma region Static Function
public:
	static const DOUBLE		Angle(const CVector & vector1, const CVector & vector2);
	static const CVector	XAxis()	{ return CVector(1, 0, 0); }
	static const CVector	YAxis()	{ return CVector(0, 1, 0); }
	static const CVector	ZAxis()	{ return CVector(0, 0, 1); }
#pragma endregion
};

	}
}