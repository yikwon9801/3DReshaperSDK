#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Unit
	{
		using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CMotorUnit) : RsIMPLEMENT(CUnit)
{
#pragma region Type Definition
	typedef enum
	{
		UNITTYPE_MM		,
		UNITTYPE_UM		,
	}UNITTYPE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CMotorUnit(const DOUBLE iPulse, const DOUBLE iShaftPitch, const UNITTYPE iType = UNITTYPE_MM);
	CMotorUnit(const CMotorUnit & iUnit);
	virtual ~CMotorUnit();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetPulse() const { return m_Pulse; }
	inline const DOUBLE		GetShaftPitch() const { return m_ShaftPitch; }

public:
	inline const DOUBLE		GetPulseFromDistance(const DOUBLE iDistance) { return iDistance * GetScale(); }
	inline const DOUBLE		GetDistanceFromPulse(const DOUBLE iPulse) { return iPulse / GetScale(); }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjToCopy);
private:
	virtual CMotorUnit *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
protected:
	const CMotorUnit &		operator = (const CMotorUnit & iUnit);
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		GetDistancePerPulse(const DOUBLE iPulse, const DOUBLE iShaftPitch) { return iPulse / iShaftPitch; }
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Pulse;
	DOUBLE					m_ShaftPitch;
	UNITTYPE				m_UnitType;
#pragma endregion
};

	}
}