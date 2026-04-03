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
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CGRectangle);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Primitive;

RsDEFINE_DLL_CLASS(CGRectangle2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGRectangle2D();
	CGRectangle2D(const CGPoint2DDouble & P1, const CGPoint2DDouble & P2, const CGPoint2DDouble & P3, const CGPoint2DDouble & P4);
	CGRectangle2D(const CGRectangle & iRectangle);
	CGRectangle2D(const CGRectangle2D & rhs);
	virtual ~CGRectangle2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetPoint(const UINT iIndex) const	{ return m_Points[iIndex]; }
public:
	inline void				SetRectangle(const CGPoint2DDouble & P1, const CGPoint2DDouble & P2, const CGPoint2DDouble & P3, const CGPoint2DDouble & P4);
	inline void				SetPoint(const UINT iIndex, const CGPoint2DDouble & iPoint) { m_Points[iIndex] = iPoint; }
public:
	void					Get(CGPolygons2D & oPolygons) const;
#pragma endregion

#pragma region General Function
public:
	const CGPoint2DDouble	GetCeneroid() const;
	const DOUBLE			GetRadius(const UINT16 iOption) const;
protected:
	const BOOL				IsEqual(const CGRectangle2D & iRectangle) const;

public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
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
	virtual CGRectangle2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CGRectangle & iRectangle);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGRectangle2D &	operator = (const CGRectangle2D & iRectangle);
	const CGRectangle2D &	operator = (const CGRectangle & iRectangle);
	void					operator += (const CVector2D & iVector);
	const CGRectangle2D		operator - () const;
	void					operator -= (const CVector2D & iVector);
	const CGRectangle2D		operator * (const DOUBLE iValue) const;
	const CGRectangle2D		operator * (const CMatrix2x2 & iMatrix) const;
	const CGRectangle2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGRectangle2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGRectangle2D & iRectangle) const;
	const BOOL				operator != (const CGRectangle2D & iRectangle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Points[4];
#pragma endregion
};

		}
	}
}