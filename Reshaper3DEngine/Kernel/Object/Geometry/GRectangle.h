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

RsDEFINE_DLL_CLASS(CGRectangle) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGRectangle();
	CGRectangle(const CGPointDouble & P1, const CGPointDouble & P2, const CGPointDouble & P3, const CGPointDouble & P4);
	CGRectangle(const CRectDouble & iRect);
	CGRectangle(const CGRectangle & rhs);
	virtual ~CGRectangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint(const UINT iIndex) const	{ return m_Points[iIndex]; }
public:
	inline void				SetRectangle(const CGPointDouble & P1, const CGPointDouble & P2, const CGPointDouble & P3, const CGPointDouble & P4);
#pragma endregion

#pragma region General Function
public:
	const CGPointDouble		GetCeneroid() const;
	const DOUBLE			GetRadius() const;
	const DOUBLE			GetRadius2D(const UINT16 iOption) const;
	void					GetMultiLine(CGMultiLine & oMultiLine) const;
protected:
	const BOOL				IsEqual(const CGRectangle & iRectangle) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetArea() const;
	const DOUBLE			GetArea2D(const CVector & iDirection) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGRectangle *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGRectangle &		operator = (const CGRectangle & iRectangle);
	const CGRectangle		operator + (const CVector & iVector) const;
	void					operator += (const CVector2D & iVector);
	void					operator += (const CVector & iVector);
	const CGRectangle		operator - () const;
	const CGRectangle		operator - (const CVector & iVector) const;
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CVector & iVector);
	const CGRectangle		operator * (const DOUBLE iValue) const;
	const CGRectangle		operator * (const CMatrix3x3 & iMatrix) const;
	const CGRectangle		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGRectangle		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGRectangle & iRectangle) const;
	const BOOL				operator != (const CGRectangle & iRectangle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Points[4];
#pragma endregion
};

		}
	}
}