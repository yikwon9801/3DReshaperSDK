#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace String
	{
		RsDEFINE_CLASS(CKeyString);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CVersion);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CPlatform);

		namespace Print
		{
			using namespace Kernel::File;
			using namespace Kernel::String;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CDevice) : RsINHERITANCE(CBaseObject), RsIMPLEMENT(IKeyObject)
{
public:
	BEGIN_ENUM()
	{
		DEVICETYPE_NONE,
		DEVICETYPE_DLP,
		DEVICETYPE_FDM,
		DEVICETYPE_DLP_SLA,
		DEVICETYPE_SLA,
	}
	END_ENUM(DEVICETYPE, DEVICETYPE_SLA)

#pragma region Construction & Destruction
public:
	CDevice(const UINT16 iType, LPCTSTR iName, const CPlatform & iPlatform, const CVersion & iVersion, const CVersion & iFirmwareVersion);
	CDevice(const CDevice & iDevice);
	virtual ~CDevice();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CPlatform &	GetPlatform() const	{ return m_Platform; }
	inline const UINT16		GetType() const { return m_Type; }
	inline LPCTSTR			GetName() const { return m_Name; }
	inline const CVersion &	GetVersion() const { return m_Version; }
	inline const CVersion &	GetFirmwareVersion() const { return m_FirmwareVersion; }
public:
	inline void				SetName(LPCTSTR iName) { m_Name = iName; }
protected:
	inline void				SetType(const UINT iType)	{ m_Type = iType; }
	inline void				SetPlatform(const CPlatform & iPlatform)	{ m_Platform = iPlatform; }
	inline void				SetVersion(const CVersion & iVersion)	{ m_Version = iVersion; }
	inline void				SetFirmwareVersion(const CVersion & iVersion)	{ m_FirmwareVersion = iVersion; }
public:
	const BOOL				HasOnlyDLP() const;
	const BOOL				HasOnlySLA() const;
	const BOOL				HasDLP() const;
	const BOOL				HasFDM() const;
	const BOOL				HasSLA() const;
	const BOOL				HasDLPandSLA() const;
#pragma endregion

#pragma region Abstract fuction of IKeyObject
public:
	virtual const CKeyString	MakeKey() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDevice *		Clone() const;
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
	const CDevice &			operator = (const CDevice & iDevice);
#pragma endregion

#pragma region Static Function
public:
	static const CString	GetDeviceName(const DEVICETYPE iType);
	static const DEVICETYPE	GetDeviceType(const CString & iName);
#pragma endregion

#pragma region Memeber Variable
private:
	CPlatform				m_Platform;
	CVersion				m_Version;
	CVersion				m_FirmwareVersion;
	UINT16					m_Type;
	CString					m_Name;
#pragma endregion
};

		}
	}
}