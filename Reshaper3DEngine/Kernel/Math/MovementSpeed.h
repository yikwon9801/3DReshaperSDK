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

RsDEFINE_DLL_CLASS(CMovementSpeed) : RsINHERITANCE(CBaseObject)
{
#pragma region Type Definition
public:
	typedef struct __movementspeed
	{
		__movementspeed() : Initial(0.), Acc(1.), Drive(1.), Dec(1.) {}
		DOUBLE		Initial;
		DOUBLE		Acc;
		DOUBLE		Drive;
		DOUBLE		Dec;
	}MovementSpeed;
#pragma endregion

#pragma region Construction & Destruction
public:
	CMovementSpeed();
	CMovementSpeed(const DOUBLE iInitialSpeed, const DOUBLE iAccSpeed, const DOUBLE iDriveSpeed, const DOUBLE iDecSpeed);
	CMovementSpeed(const MovementSpeed & iSpeed);
	CMovementSpeed(const CMovementSpeed & iMovementSpeed);
	virtual ~CMovementSpeed();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const MovementSpeed &	GetSpeed() const { return m_Speed; }
	inline const DOUBLE		GetInitialVelocity() const { return m_Speed.Drive - m_Speed.Initial; }
	inline const DOUBLE		GetTimeTakenAcc() const { return GetInitialVelocity() / m_Speed.Acc; }
	inline const DOUBLE		GetTimeTakenDec() const { return m_Speed.Drive / m_Speed.Acc; }
public:
	inline void				SetSpeed(const MovementSpeed & iSpeed) { m_Speed = iSpeed; }
public:
	void					Init(const DOUBLE iInitialSpeed, const DOUBLE iAccSpeed, const DOUBLE iDriveSpeed, const DOUBLE iDecSpeed);
	void					SetValue(LPCTSTR iString, LPCTSTR iDelimiter);
	const CString			ToString(LPCTSTR iDelimiter) const;
#pragma endregion

#pragma region Mathematic
public:
	const DOUBLE			GetDistanceMovedAcc() const;
	const DOUBLE			GetDistanceMovedDec() const;
	const DOUBLE			GetMovingTime(const DOUBLE iDistance) const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CMovementSpeed & iMovementSpeed) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMovementSpeed *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMovementSpeed &	operator = (const CMovementSpeed & iMovementSpeed);
	const BOOL				operator == (const CMovementSpeed & iMovementSpeed) const;
	const BOOL				operator != (const CMovementSpeed & iMovementSpeed) const;
#pragma endregion

#pragma region Static Function
public:
	static const CMovementSpeed	FromString(LPCTSTR iString, LPCTSTR iDelimiter);
#pragma endregion

#pragma region Memeber Variable
private:
	MovementSpeed			m_Speed;
#pragma endregion
};

	}
}