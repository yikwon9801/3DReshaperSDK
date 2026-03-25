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

RsDEFINE_DLL_CLASS(CPIDControl) : RsINHERITANCE(CBaseObject)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CPIDControl(const DOUBLE iProportional, const DOUBLE iIntegral, const DOUBLE iDerivative, const DOUBLE iDt = 1.);
	CPIDControl(const CPIDControl & iPID);
	virtual ~CPIDControl();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetProportional() const { return m_Proportional; };
	inline const DOUBLE		GetIntegral() const { return m_Integral; };
	inline const DOUBLE		GetDerivative() const { return m_Derivative; };
	inline const DOUBLE		GetDt() const { return m_Dt; };

	inline const DOUBLE		GetIntegralError() const { return m_IntegralError; };
	inline const DOUBLE		GetDerivativeError() const { return m_DerivativeError; };
	inline const DOUBLE		GetPrevError() const { return m_PrevError; };
	inline void				GetOutput(DOUBLE & Proportional_Output, DOUBLE& Integral_Output, DOUBLE& Derivative_Output)
	{
		Proportional_Output = m_Proportional_Output;
		Integral_Output = m_Integral_Output;
		Derivative_Output = m_Derivative_Output;
	}

public:
	void					Init(const DOUBLE iProportional, const DOUBLE iIntegral, const DOUBLE iDerivative, const DOUBLE iDt = 1.);
	void					Set(const DOUBLE iProportional, const DOUBLE iIntegral, const DOUBLE iDerivative, const DOUBLE iDt = 1.)
	{
		m_Proportional = iProportional;
		m_Integral = iIntegral;
		m_Derivative = iDerivative;
		m_Dt = iDt;
	}

	void					ResetError();
#pragma endregion

#pragma region Mathematic
public:
	const DOUBLE			GetControlValue(const DOUBLE iReference, const DOUBLE iFeedback);
#pragma endregion

protected:
	const BOOL				IsEqual(const CPIDControl & iPID) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPIDControl *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CPIDControl &		operator = (const CPIDControl & iPID);
	const BOOL				operator == (const CPIDControl & iPID) const;
	const BOOL				operator != (const CPIDControl & iPID) const;
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Proportional;
	DOUBLE					m_Integral;
	DOUBLE					m_Derivative;
	DOUBLE					m_Dt;

	DOUBLE					m_IntegralError;
	DOUBLE					m_DerivativeError;
	DOUBLE					m_PrevError;

	DOUBLE					m_Proportional_Output;
	DOUBLE					m_Integral_Output;
	DOUBLE					m_Derivative_Output;
#pragma endregion
};

	}
}