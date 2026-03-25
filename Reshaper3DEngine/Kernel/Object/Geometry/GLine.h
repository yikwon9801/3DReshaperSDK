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
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGLine) : RsINHERITANCE(CGMultiLine)
{
#pragma region Construction & Destruction
public:
	CGLine(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	CGLine(const Coordinate2D & iDeparture, const Coordinate2D & iArrival);
	CGLine(const CGLine & rhs);
	virtual ~CGLine();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGVertex &	First() const	{ return m_Vertices[0]; }
	inline const CGVertex &	Last() const	{ return m_Vertices[m_Vertices.size() - 1]; }
#pragma endregion

public:
	const CGPointDouble		ProjectOnLine(const CGPointDouble & iPointToProject) const;
	const CGPointDouble		ProjectOnLine(const CGPointDouble & iPointToProject, const CGPointDouble & iStartPoint, const CVector & iLineDirection) const;

	const INT				Intersect(const CGLine & iLineToTest, CGPointDouble & oIntersectedPoint) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGLine *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGLine &			operator = (const CGLine & iLine);
	const CGLine			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGLine			operator - () const;
	const CGLine			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGLine			operator * (const DOUBLE iValue) const;
	const CGLine			operator * (const CMatrix3x3 & iMatrix) const;
	const CGLine			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGLine			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGLine & iLine) const;
	const BOOL				operator != (const CGLine & iLine) const;
	CGVertex &				operator [] (const INT nIndex);
#pragma endregion

#pragma region Static fuction
public:
	static const INT		ProjectPointOnLine(const CGPointDouble & iPointToProject, const CGPointDouble & iStartPoint, const CVector & iLineDirection, CGPointDouble & oProjectPoint, const BOOL iHaveToBeOnLine = FALSE);
	static const INT		Intersect(const Coordinate2D & P11, const Coordinate2D & P12, const Coordinate2D & P21, const Coordinate2D & P22, Coordinate2D & oIntersectedPoint);
	static const INT		Intersect(const CGLine & iLine1, const CGLine & iLine2, CGPointDouble & oIntersectedPoint);
	static const INT		Intersect(const CGPointDouble & P1, const CVector & V1, const CGPointDouble & P2, const CVector & V2, CGPointDouble & oIntersectedPoint);
	static const DOUBLE		DistanceToPoint(const CGPointDouble & iPoint, const CGPointDouble & iLineP0, const CGPointDouble & iLineP1);
	static const INT		ClosestPointFromLine(const CTableArray<CGPointDouble> & iPoints, const CGPoint2DDouble & iLineP0, const CGPoint2DDouble & iLineP1);
	static const BOOL		IsOnLine(const DOUBLE iPX, const DOUBLE iPY, const DOUBLE iPZ, const DOUBLE iLPX1, const DOUBLE iLPY1, const DOUBLE iLPZ1, const DOUBLE iLPX2, const DOUBLE iLPY2, const DOUBLE iLPZ2);
#pragma endregion
};

		}
	}
}