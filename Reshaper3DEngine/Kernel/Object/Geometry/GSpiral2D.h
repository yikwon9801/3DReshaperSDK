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
			RsDEFINE_CLASS(CGPolygons);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGSpiral2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGSpiral2D();
	CGSpiral2D(const CGPoint2DDouble & iPoint, const DOUBLE iOuterRadius, const DOUBLE iOffsetDistance);
	CGSpiral2D(const CGPoint2DDouble & iPoint, const DOUBLE iInnerRadius, const DOUBLE iOuterRadius, const DOUBLE iOffsetDistance);
	CGSpiral2D(const CGSpiral2D & rhs);
	virtual ~CGSpiral2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetCenterPoint() const	{ return m_CenterPoint; }
	inline const DOUBLE		GetOuterRadius() const	{ return m_OuterRadius; }
	inline const DOUBLE		GetInnerRadius() const { return m_InnerRadius; }
#pragma endregion

#pragma region General Function
public:
	void					ToPolygons(const UINT iNumberOfPoints, CGPolygon & oPolygon) const;
	void					ToPolygons(const UINT iNumberOfPoints, CGPolygons & oPolygons) const;
	void					ToPolygons(const UINT iNumberOfPoints, const BOOL iOuterBorder, const BOOL iInnerBorder, CGPolygons & oPolygons) const;
	void					ToPolygons2D(const UINT iNumberOfPoints, CGPolygon2D & oPolygon2D) const;
	void					ToPolygons2D(const UINT iNumberOfPoints, CGPolygons2D & oPolygons2D) const;
	void					ToPolygons2D(const UINT iNumberOfPoints, const BOOL iOuterBorder, const BOOL iInnerBorder, CGPolygons2D & oPolygons2D) const;
	void					ToPolygons(const DOUBLE iSpacingBetweenPoints, CGPolygon & oPolygon) const;
	void					ToPolygons(const DOUBLE iSpacingBetweenPoints, CGPolygons & oPolygons) const;
	void					ToPolygons2D(const DOUBLE iSpacingBetweenPoints, CGPolygon2D & oPolygon2D) const;
	void					ToPolygons(const DOUBLE iSpacingBetweenPoints, const BOOL iOuterBorder, const BOOL iInnerBorder, CGPolygons & oPolygons) const;
	void					ToPolygons2D(const DOUBLE iSpacingBetweenPoints, CGPolygons2D & oPolygons2D) const;
	void					ToPolygons2D(const DOUBLE iSpacingBetweenPoints, const BOOL iOuterBorder, const BOOL iInnerBorder, CGPolygons2D & oPolygons2D) const;

protected:
	const BOOL				IsEqual(const CGSpiral2D & iSpiral) const;
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
	virtual CGSpiral2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGSpiral2D &		operator = (const CGSpiral2D & iSpiral);
	const CGSpiral2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGSpiral2D		operator - () const;
	const CGSpiral2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGSpiral2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGSpiral2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGSpiral2D & iSpiral) const;
	const BOOL				operator != (const CGSpiral2D & iSpiral) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateSpiral2D(const CGPoint2DDouble & iCenterPoint, const DOUBLE iInnerRadius, const DOUBLE iOuterRadius, const DOUBLE iOffsetDistance, const UINT iNumberOfPoint, vector<Coordinate2D> & oResult);
	static void				CreateSpiral2D_BySpacing(const CGPoint2DDouble & iCenterPoint, const DOUBLE iRadius, const DOUBLE iOffsetDistance, const DOUBLE iSpacingBetweenPoints, vector<Coordinate2D> & oResult);
	static void				CreateSpiral2D_BySpacing(const CGPoint2DDouble & iCenterPoint, const DOUBLE iInnerRadius, const DOUBLE iOuterRadius, const DOUBLE iOffsetDistance, const DOUBLE iSpacingBetweenPoints, vector<Coordinate2D> & oResult, const UINT8 iType = 0);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_CenterPoint;
	DOUBLE					m_OuterRadius, m_InnerRadius;
	DOUBLE					m_OffsetDistance;
#pragma endregion
};

		}
	}
}