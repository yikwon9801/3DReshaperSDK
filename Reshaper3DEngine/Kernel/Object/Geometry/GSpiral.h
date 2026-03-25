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

RsDEFINE_DLL_CLASS(CGSpiral) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGSpiral();
	CGSpiral(const CGPointDouble & iPoint, const DOUBLE iRadius, const CVector & iDirection);
	CGSpiral(const CGSpiral & rhs);
	virtual ~CGSpiral();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetCenterPoint() const	{ return m_CenterPoint; }
	inline const CVector &	GetDirection() const	{ return m_Direction; }
	inline const DOUBLE		GetRadius() const	{ return m_Radius; }
#pragma endregion

#pragma region General Function
public:

protected:
	const BOOL				IsEqual(const CGSpiral & iSpiral) const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGSpiral *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGSpiral &		operator = (const CGSpiral & iSpiral);
	const CGSpiral			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGSpiral			operator - () const;
	const CGSpiral			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGSpiral			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGSpiral			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGSpiral & iSpiral) const;
	const BOOL				operator != (const CGSpiral & iSpiral) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateSpiral2D(const CGPoint2DDouble & iCenterPoint, const DOUBLE iRadius, const DOUBLE iOffsetDistance, const UINT iNumberOfPoint, vector<Coordinate2D> & oResult);
	static void				CreateSpiral2D_BySpacing(const CGPoint2DDouble & iCenterPoint, const DOUBLE iRadius, const DOUBLE iOffsetDistance, const DOUBLE iSpacingBetweenPoints, vector<Coordinate2D> & oResult);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_CenterPoint;
	CVector					m_Direction;
	DOUBLE					m_Radius;
#pragma endregion
};

		}
	}
}