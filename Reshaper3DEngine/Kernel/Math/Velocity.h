#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Math
	{
		using namespace Kernel::File;

RsDEFINE_DLL_CLASS(CVelocity) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CVelocity();
	CVelocity(const DOUBLE iDriveSpeed);
	CVelocity(const CVelocity & iVelocity);
	virtual ~CVelocity();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetSpeed() const { return m_DriveSpeed; }
public:
	inline void				SetSpeed(const DOUBLE iSpeed) { m_DriveSpeed = iSpeed; }
#pragma endregion

#pragma region Mathematic
public:
#pragma endregion

protected:
	const BOOL				IsEqual(const CVelocity & iVelocity) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CVelocity *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CVelocity &		operator = (const CVelocity & iVelocity);
	const CVelocity			operator + (const DOUBLE iValue) const;
	const CVelocity			operator + (const CVelocity & iVelocity) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CVelocity & iVelocity);
	const CVelocity			operator - () const;
	const CVelocity			operator - (const DOUBLE iValue) const;
	const CVelocity			operator - (const CVelocity & iVelocity) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CVelocity & iVelocity);
	const CVelocity			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CVelocity			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CVelocity & iVelocity) const;
	const BOOL				operator != (const CVelocity & iVelocity) const;
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_DriveSpeed;
#pragma endregion
};

	}
}