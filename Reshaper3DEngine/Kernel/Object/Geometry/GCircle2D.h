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

RsDEFINE_DLL_CLASS(CGCircle2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCircle2D();
	CGCircle2D(const CGPoint2DDouble & iPoint, const DOUBLE iRadius);
	CGCircle2D(const CGCircle2D & rhs);
	virtual ~CGCircle2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetCenterPoint() const	{ return m_CenterPoint; }
	inline const DOUBLE		GetRadius() const	{ return m_Radius; }

	void					Get(CGPolygons2D & oPolygons) const;
#pragma endregion

#pragma region General Function
public:
	void					ToMultiLine(vector<Coordinate2D> & oCircleLine, const UINT iNumberOfPoint = 40) const;

	const CGPoint2DDouble	GetPoint(const DOUBLE iAngle) const;

protected:
	const BOOL				IsEqual(const CGCircle2D & iCircle) const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetArea() const;
	const DOUBLE			GetCircumference() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGCircle2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCircle2D &		operator = (const CGCircle2D & iCircle);
	const CGCircle2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGCircle2D		operator - () const;
	const CGCircle2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGCircle2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGCircle2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCircle2D & iCircle) const;
	const BOOL				operator != (const CGCircle2D & iCircle) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateCircle2D(const CGPoint2DDouble & iCenterPoint, const DOUBLE iRadius, const UINT iNumberOfPoint, vector<Coordinate2D> & oCircleLine);
	static const DOUBLE		Circumference(const DOUBLE iRadius);
	static const DOUBLE		Area(const DOUBLE iRadius);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_CenterPoint;
	DOUBLE					m_Radius;
#pragma endregion
};

		}
	}
}