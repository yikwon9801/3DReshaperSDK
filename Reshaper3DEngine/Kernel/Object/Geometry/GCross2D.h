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

RsDEFINE_DLL_CLASS(CGCross2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	typedef enum
	{
		BOUNDARYTYPE_NONE		,
		BOUNDARYTYPE_RECTANGLE	,
		BOUNDARYTYPE_ELLIPSE	,
	}BOUNDARYTYPE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGCross2D();
	CGCross2D(const CGPoint2DDouble & iOrigin, const DOUBLE iHorizontalLength, const DOUBLE iVerticalLength, const DOUBLE iRotation = 0.);
	CGCross2D(const CGCross2D & iCross);
	virtual ~CGCross2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetOrigin() const { return m_Origin; }
	inline const DOUBLE		GetHorizontalLength() const { return m_HorzontalLength; }
	inline const DOUBLE		GetVerticalLength() const { return m_VerticalLength; }
	inline const DOUBLE		GetRotationAngle() const { return m_RotationAngle; }

	void					Get(CGPolygons2D & oPolygons, const BOUNDARYTYPE iBoundaryType = BOUNDARYTYPE_NONE) const;
protected:
protected:
	const INT				GetBoundaryPolygonsForRectangle(CGPolygons2D & oPolygons) const;
	const INT				GetBoundaryPolygonsForEllipse(CGPolygons2D & oPolygons) const;
public:
	inline void				SetCross2D(const CGPoint2DDouble & iOrigin, const DOUBLE iHorizontalLength, const DOUBLE iVerticalLength, const DOUBLE iRotation = 0.);
#pragma endregion

#pragma region General Function
public:
	const CGPoint2DDouble	GetCeneroid() const;

	const INT				GetHorizontalLine(CGLine2D & oLine) const;
	const INT				GetVerticalLine(CGLine2D & oLine) const;
protected:
	const BOOL				IsEqual(const CGCross2D & iCross) const;

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
	virtual CGCross2D *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCross2D &		operator = (const CGCross2D & iCross);
	const CGCross2D			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	void					operator += (const CVector & iVector);
	const CGCross2D			operator - () const;
	const CGCross2D			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CVector & iVector);
	const CGCross2D			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGCross2D			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCross2D & iCross) const;
	const BOOL				operator != (const CGCross2D & iCross) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Origin;
	DOUBLE					m_HorzontalLength, m_VerticalLength;
	DOUBLE					m_RotationAngle;
#pragma endregion
};

		}
	}
}