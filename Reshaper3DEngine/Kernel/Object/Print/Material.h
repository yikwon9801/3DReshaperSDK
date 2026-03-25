#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Object
	{

		namespace Print
		{

			using namespace Kernel::File;

RsDEFINE_DLL_CLASS(CMaterial) : RsINHERITANCE(CBaseObject), RsIMPLEMENT(IKeyObject)
{
#pragma region Construction & Destruction
public:
	CMaterial(const LPCTSTR iName, const FLOAT iDensity);
	CMaterial(const CMaterial & iMaterial);
	virtual ~CMaterial();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const LPCTSTR	GetName() const	{ return m_Name; }
	inline const FLOAT		GetDensity() const { return m_Density; }
public:
	inline void				SetName(const LPCTSTR iName)	{ m_Name = iName; }
	inline void				SetDensity(const FLOAT iDensity)	{ m_Density = iDensity; }
#pragma endregion

#pragma region Abstract fuction of IKeyObject
public:
	virtual const CKeyString	MakeKey() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CMaterial *		Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMaterial &		operator = (const CMaterial & iMaterial);
#pragma endregion

#pragma region Memeber Variable
private:
	CString					m_Name;
	FLOAT					m_Density;
#pragma endregion
};

		}
	}
}