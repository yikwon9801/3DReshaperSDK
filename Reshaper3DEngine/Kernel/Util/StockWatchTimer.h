#pragma once

namespace Kernel
{
	namespace Util
	{
RsDEFINE_DLL_STRUCT(StockWatchTimer)
{
	StockWatchTimer();
	~StockWatchTimer();

	inline const DWORD64	GetTaken() const { return m_Finished - m_Started; }

	const BOOL				IsValid() const;
	void					Start();
	void					Finish();

	DWORD64					m_Started, m_Finished;
};

RsDEFINE_DLL_STRUCT(StockWatchTimerLog) : RsINHERITANCE(StockWatchTimer)
{
	StockWatchTimerLog();

	inline void				SetTarget(const DWORD64 iTarget) { m_Target = iTarget; }
	inline const DWORD64	GetTarget() const { return m_Target; }

	const CString			GetLogText() const;
	void					Finish(LPCTSTR iLogText);
	void					SetLogText(LPCTSTR iLogText);
	void					InsertFirstText(LPCTSTR iLogText);
#define STOCKWATCHTIMERLOG_LOGTEXT_MAXLEN	256
	CTime					m_Time;
	USHORT					m_millitm;
	TCHAR					m_LogText[STOCKWATCHTIMERLOG_LOGTEXT_MAXLEN];
	DWORD64					m_Target;
};

	}
}