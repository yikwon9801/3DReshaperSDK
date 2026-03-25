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

RsDEFINE_DLL_CLASS(CGSphere) : RsINHERITANCE(CGPointDouble)
{
#pragma region Construction & Destruction
public:
	CGSphere();
	CGSphere(const CGPointDouble & iPoint, const DOUBLE iRadius);
	CGSphere(const CGSphere & iSphere);
	virtual ~CGSphere();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetRadius() const	{ return m_Radius; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGSphere & iSphere) const;

#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetVolume() const;
	const DOUBLE			GetArea() const;
	const DOUBLE			GetArea2D() const;
	const DOUBLE			GetCircumference() const;

	const INT				Project(const CGPointDouble & iPointToProject, const CVector & iDirection, CGPointDouble * oProjectedPoint = NULL) const;
	const INT				ProjectToPlane(const CGPointDouble & iPointToProject, const CVector & iDirection, CGPointDouble * oProjectedPoint = NULL) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGSphere *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGSphere &		operator = (const CGSphere & iSphere);
	const CGSphere			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGSphere			operator - () const;
	const CGSphere			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGSphere			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGSphere			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGSphere & iSphere) const;
	const BOOL				operator != (const CGSphere & iSphere) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Radius;
#pragma endregion
};

		}
	}
}