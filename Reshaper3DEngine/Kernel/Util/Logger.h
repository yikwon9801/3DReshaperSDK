#pragma once

namespace Kernel
{
	namespace Util
	{
#define MAX_LOGLENGTH		1024

RsDEFINE_DLL_CLASS(CLogger)
{
#pragma region Type Definition
public:
	typedef enum : UINT64
	{
		DELIVERYTYPE_TRACE		= 0x0000000000000001,
		DELIVERYTYPE_FILE		= 0x0000000000000002,
	}DELIVERYTYPE;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CLogger(LPCTSTR iLogDirPath, LPCTSTR iPrefix = NULL, LPCTSTR iExtName = NULL);
	virtual ~CLogger();
#pragma endregion

#pragma region Setter & Getter function
protected:
	inline const BOOL	GetAddTime() const { return m_AddTime; }
	inline const BOOL	GetAddSourceLine() const { return m_AddSourceLine; }
	inline const UINT	GetLifeDays() const { return m_LifeDays; }
public:
	inline void			SetDeliveryType(const UINT64 iType) { m_DeliveryType = iType; }
	inline void			SetLifeDay(const UINT iDays) { m_LifeDays = iDays; }
	inline void			SetAddTime(const BOOL iSet) { m_AddTime = iSet; }
	inline void			SetAddSourceLine(const BOOL iSet) { m_AddSourceLine = iSet; }
	inline void			SetMonitoringDateTime(const BOOL iSet) { m_CheckDateTime = iSet; }
	inline void			SetMonitoringFileSize(const BOOL iSet, const UINT64 iFileSize) { m_CheckFileSize = iSet; m_LimitFileSize = iFileSize; }
	inline void			SetExtName(LPCTSTR iName) { m_ExtName = iName; }
#pragma endregion

#pragma region General Function
public:
	const BOOL			Write(const UINT64 iLevel, LPCTSTR iFileName, const UINT iSrcLine, const TCHAR * iPszFormat, ...);
	void				SetAndCleanFiles(const UINT iLifeDays);
protected:
	const BOOL			Trace(const CString & iTime, const CString & iSrcLine, const CString & iLogContent) const;
	const BOOL			WriteLogFile(CString & iTime, CString & iSrcLine, CString & iLogContent) const;

	void				LifeCheckAndCleanFiles();

	const BOOL			IsType(const UINT64 iType, const UINT64 iTypeToCheck) const { return (iType & iTypeToCheck) == iTypeToCheck; }

	const BOOL			CheckToCreateNewFile() const;
	void				CreateNewLogFile();

protected:
	virtual const BOOL	VerifyFlag(const UINT64 iLevel) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CRITICAL_SECTION	__log_lock__;
private:
	CString				m_FileName;
	CString				m_ExtName;
	CString				m_LogDirPath;
	CString				m_Prefix;

	BOOL				m_CheckDateTime;
	BOOL				m_CheckFileSize;
	UINT64				m_LimitFileSize;
	BOOL				m_AddTime;
	BOOL				m_AddSourceLine;
	UINT				m_nLogSeg;
	UINT				m_LifeDays;
	UINT8				m_SkipTimeToCheckNewFile;

	UINT64				m_DeliveryType;
#pragma endregion
};

	}
}
