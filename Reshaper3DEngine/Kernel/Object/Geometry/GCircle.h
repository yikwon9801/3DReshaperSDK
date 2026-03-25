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

RsDEFINE_DLL_CLASS(CGCircle) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCircle();
	CGCircle(const CGPointDouble & iPoint, const DOUBLE iRadius, const CVector & iDirection);
	CGCircle(const CGCircle & rhs);
	virtual ~CGCircle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetCenterPoint() const	{ return m_CenterPoint; }
	inline const CVector &	GetDirection() const	{ return m_Direction; }
	inline const DOUBLE		GetRadius() const	{ return m_Radius; }
#pragma endregion

#pragma region General Function
public:
	void					ToMultiLine(CGMultiLine & oCircleLine, const UINT iNumberOfPoint = 40) const;
	void					ToMultiLine(vector<Coordinate2D> & oCircleLine, const UINT iNumberOfPoint = 40) const;

	const CGPointDouble		GetPoint(const DOUBLE iAngle) const;
	const CGPlane			GetPlane(const DOUBLE iAngle) const;
	const CVector			GetTangentialSlop(const DOUBLE iAngle) const;

protected:
	const BOOL				IsEqual(const CGCircle & iCircle) const;
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
	virtual CGCircle *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCircle &		operator = (const CGCircle & iCircle);
	const CGCircle			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGCircle			operator - () const;
	const CGCircle			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGCircle			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGCircle			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCircle & iCircle) const;
	const BOOL				operator != (const CGCircle & iCircle) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateCircle(const CGPointDouble & iCenterPoint, const CVector & iNormal, const DOUBLE iRadius, const UINT iNumberOfPoint, CGMultiLine & oCircleLine);
	static void				CreateCircle2D(const CGPointDouble & iCenterPoint, const DOUBLE iRadius, const UINT iNumberOfPoint, vector<Coordinate2D> & oCircleLine);
	static const UINT		ObtainPointNumberByRadius(const DOUBLE iRadius);
	static const DOUBLE		Circumference(const DOUBLE iRadius);
	static const DOUBLE		Area(const DOUBLE iRadius);
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