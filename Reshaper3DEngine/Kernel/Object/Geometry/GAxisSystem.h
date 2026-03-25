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

RsDEFINE_DLL_CLASS(CGAxisSystem) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGAxisSystem(const CGPointDouble & iPoint, const CVector & iDirection);
	CGAxisSystem(const CGPointDouble & iPoint, const CVector & iDirection, const CVector & iXDirection);
	CGAxisSystem(const CGAxisSystem & rhs);
	virtual ~CGAxisSystem();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CVector &			GetDirection() const;
	const CVector &			GetXDirection() const;
	const CVector &			GetYDirection() const;
	const CVector &			GetOrigin() const;
#pragma endregion

public:
	void					ChangePosition(const CGPointDouble & iPosition);
protected:
	const BOOL				IsEqual(const CGAxisSystem & iAxisSystem) const;
private:
	const CVector			_CalculateXDirection(CVector iZDirection);

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGAxisSystem *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGAxisSystem &	operator = (const CGAxisSystem & iAxisSystem);
	const CGAxisSystem		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGAxisSystem		operator - () const;
	const CGAxisSystem		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGAxisSystem		operator * (const CMatrix3x3 & iMatrix) const;
	const CGAxisSystem		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CGAxisSystem & iAxisSystem) const;
	const BOOL				operator != (const CGAxisSystem & iAxisSystem) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Position;
	CVector					m_Orgin;
	CVector					m_Direction;
	CVector					m_XDirection;
	CVector					m_YDirection;
#pragma endregion
};

		}
	}
}