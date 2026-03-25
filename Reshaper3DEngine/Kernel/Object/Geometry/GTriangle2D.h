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
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGLine2D);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGTriangle2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGTriangle2D();
	CGTriangle2D(const CGPoint2DDouble & iPoint1, const CGPoint2DDouble & iPoint2, const CGPoint2DDouble & iPoint3);
	CGTriangle2D(const CGTriangle2D & rhs);
	virtual ~CGTriangle2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetPoint(const UINT iIndex) const { return m_Points[iIndex]; }

	void					Get(CGPolygons2D & oPolygons) const;
public:
	inline void				SetPoint1(const CGPoint2DDouble & iPoint) { SetPoint(0, iPoint); }
	inline void				SetPoint2(const CGPoint2DDouble & iPoint) { SetPoint(1, iPoint); }
	inline void				SetPoint3(const CGPoint2DDouble & iPoint) { SetPoint(2, iPoint); }
	inline void				SetPoint(const UINT iIndex, const CGPoint2DDouble & iPoint) { m_Points[iIndex] = iPoint; }
	inline void				SetPoint(const CGPoint2DDouble & iPoint1, const CGPoint2DDouble & iPoint2, const CGPoint2DDouble & iPoint3) { SetPoint1(iPoint1); SetPoint2(iPoint2); SetPoint3(iPoint3); }
#pragma endregion

#pragma region General Function
public:
protected:
	const BOOL				IsEqual(const CGTriangle2D & iTriangle) const;

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
	virtual CGTriangle2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGTriangle2D &	operator = (const CGTriangle2D & iTriangle);
	const CGTriangle2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGTriangle2D		operator - () const;
	const CGTriangle2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGTriangle2D		operator * (const DOUBLE iValue) const;
	const CGTriangle2D		operator * (const CMatrix2x2 & iMatrix) const;
	const CGTriangle2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGTriangle2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGTriangle2D & iTriangle) const;
	const BOOL				operator != (const CGTriangle2D & iTriangle) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Points[3];
#pragma endregion
};

		}
	}
}