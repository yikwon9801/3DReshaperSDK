#pragma once

namespace Display
{

	namespace Object
	{
		namespace Vision
		{

RsDEFINE_DLL_CLASS(CDLight) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDLight();
	CDLight(const CDLight & rhs);
	virtual ~CDLight();
#pragma endregion

#pragma region Setter & Getter function
public:
	const UINT16		GetNumOfLight() const;
	const FLOAT			GetAmbiLight() const;
	const FLOAT			GetDiffLight() const;
	const FLOAT			GetSpecLight() const;
	const CGPointDouble	GetPosition() const;
public:
	void				SetLight(const UINT16 iNumOfLight, const FLOAT iAmbi, const FLOAT iDiff, const FLOAT iSpec, const CGPointDouble & iPosition);
private:
	void				SetNumOfLight(const UINT16 iNumOfLight);
	void				SetAmbiLight(const FLOAT value);
	void				SetDiffLight(const FLOAT value);
	void				SetSpecLight(const FLOAT value);
	void				SetPosition(const CGPointDouble & value);
#pragma endregion

private:
	void				_TurnOffLight();

#pragma region Display
public:
	virtual const INT	Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDLight *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDLight &		operator = (const CDLight & iLight);
#pragma endregion

#pragma region Memeber Variable
public:
#define NUMBEROFLIGHTS	8
private:
	UINT16				m_NumOfLight;

	FLOAT				_ambiLight;
	FLOAT				_diffLight;
	FLOAT				_specLight;

	CGPointDouble		m_Position;
#pragma endregion
};

		}
	}
}