#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_CLASS(IINIObject);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace File
	{

		namespace INI
		{
			using namespace Kernel::Interface;
			using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CIniObject) : RsINHERITANCE(CDataObject), RsIMPLEMENT(IINIObject)
{
#pragma region Type Definition
protected:
#pragma endregion

#pragma region Construction & Destruction
protected:
	CIniObject();
	CIniObject(LPCTSTR iFilePath);
	virtual ~CIniObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline LPCTSTR		GetFilePath() const { return m_FilePath; }
public:
	inline void			ChangeFilePath(LPCTSTR iFilePath) { SetFilePath(iFilePath); }
protected:
	inline void			SetFilePath(LPCTSTR iFilePath) { m_FilePath = iFilePath; }
#pragma endregion

#define BEGIN_SAVEELEMENTINI()											\
	CHyString sValue;
#define END_SAVEELEMENTINI(appname, keyname, setterfunction, value)		\
	setterfunction(value);												\
	VERIFY(WriteValue(appname, keyname, sValue));

#pragma region General function
protected:
	inline const INT	ReadValue(LPCTSTR iAppName, LPCTSTR iKeyName, const INT iDefault) const { return GetPrivateProfileInt(iAppName, iKeyName, iDefault, m_FilePath); }
	inline const CString	ReadValue(LPCTSTR iAppName, LPCTSTR iKeyName, LPCTSTR iDefault) const {
		// ====> do not use cstring for a argument, it may cause invalid intialize cstring types.
		// temporary fixed code to tchar array
		TCHAR tmpBuffer[4096] = { 0, };
		/*CString value;*/	GetPrivateProfileString(iAppName, iKeyName, iDefault, (LPTSTR)(LPCTSTR)tmpBuffer, 4096, m_FilePath);
		return tmpBuffer;
	}
	inline const BOOL	WriteValue(LPCTSTR iAppName, LPCTSTR iKeyName, LPCTSTR iValue) const { return WritePrivateProfileString(iAppName, iKeyName, iValue, m_FilePath); }
protected:
	const BOOL			IsExistSectionName(LPCTSTR iSectoinName) const;
	const BOOL			IsKeyExist(LPCTSTR lpSection, LPCTSTR lpKey) const;
	const vector<CString>	GetKeyList(LPCTSTR lpSection) const;
#pragma endregion

#pragma region Abstract fuction of IINIObject
public:
	virtual const BOOL	ReadIni();
	virtual const BOOL	WriteIni(const BOOL bCreate=FALSE);
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
	BOOL CreateNewFileAsUTF16(CString strFilePath, BOOL bWriteIniDummyData = FALSE);
	BOOL WriteDummySectionForUnicodeIni(HANDLE hFile);
#pragma endregion

public:
	static const CString	AppendName(LPCTSTR iName, const INT iNumberToAdd);

#pragma region Memeber Variable
protected:
	CString				m_FilePath;
#pragma endregion
};
		}
	}
}