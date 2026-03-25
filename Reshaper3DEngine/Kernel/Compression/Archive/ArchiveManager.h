#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}
	namespace Compression
	{
		namespace Archive
		{
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CArchiveManager)
{
#pragma region Types
public:
	enum ArchiveProgressType { ProgressType_InProgress, ProgressType_Completed, ProgressType_Error };
	enum ArchiveProcessType
	{
		ArchiveProcessType_CompressFile,
		ArchiveProcessType_CompressDirectory,
		ArchiveProcessType_AppendEntry,
		ArchiveProcessType_ExtractEntry,
		ArchiveProcessType_ExtractFiles,
	};
	typedef void(*ProgressCallback) (LPVOID Listener, INT nProcessType, INT nProgressType, UINT64 nCurrent, UINT64 nTotal);
	typedef int(*CancelCallback) (LPVOID Listener);
	enum CallbackType {	CallbackType_function, CallbackType_ProgressObject };
	typedef struct __progresscallbacktype
	{
		__progresscallbacktype(ProgressCallback iFunction) : Type(CallbackType_function), ProcessType(ArchiveProcessType_CompressFile), CallBack(iFunction), CurStep(0), TotalStep(1), Listener(NULL) {}
		__progresscallbacktype(CProgress * iProgress) : Type(CallbackType_ProgressObject), ProcessType(ArchiveProcessType_CompressFile), CallBack(iProgress), CurStep(0), TotalStep(1), Listener(NULL) {}
		__progresscallbacktype(const ArchiveProcessType iProcessType, ProgressCallback iFunction) : Type(CallbackType_function), ProcessType(iProcessType), CallBack(iFunction), CurStep(0), TotalStep(1), Listener(NULL) {}
		__progresscallbacktype(const ArchiveProcessType iProcessType, CProgress * iProgress) : Type(CallbackType_ProgressObject), ProcessType(iProcessType), CallBack(iProgress), CurStep(0), TotalStep(1), Listener(NULL) {}
		inline const CallbackType	GetType() const { return Type; }
		inline const ArchiveProcessType	GetProcessType() const { return ProcessType; }
		inline const UINT	GetCurStep() const { return CurStep; }
		inline const UINT	GetTotalStep() const { return TotalStep; }
		inline LPVOID		GetListener() const { return Listener; }
		inline LPVOID		GetCallBack() const { return CallBack; }
		inline void			SetProcessType(const ArchiveProcessType & iProcessType) { ProcessType = iProcessType; }
		inline void			SetCurStep(const UINT iStep) { CurStep = iStep; }
		inline void			SetTotalStep(const UINT iStep) { TotalStep = iStep; }
		inline void			SetListener(LPVOID iListener) { Listener = iListener; }
		void				CallFunc(LPVOID Listener, INT nProcessType, INT nProgressType, UINT64 nCurrent, UINT64 nTotal) const;
	private:
		CallbackType		Type;
		ArchiveProcessType	ProcessType;
		UINT				CurStep, TotalStep;
		LPVOID				Listener;
		LPVOID				CallBack;
	}ProgressCallbackType, *pProgressCallbackType;

	typedef struct __cancelcallbacktype
	{
		__cancelcallbacktype(CancelCallback iFunction, LPVOID iListener) : CallBack(iFunction), Listener(iListener) {}
		inline LPVOID		GetListener() const { return Listener; }
		inline LPVOID		GetCallBack() const { return CallBack; }
		int					CallFunc() const;
	private:
		LPVOID				Listener;
		LPVOID				CallBack;
	}CancelCallbackType, *pCancelCallbackType;;

#pragma endregion

#pragma region Construction & Destruction
	public:
		CArchiveManager(LPCTSTR iFilePath = _T(""));
		virtual ~CArchiveManager();
#pragma endregion


#pragma region Setter & Getter function
public:
	const BOOL				IsArchiveOpened();

	const UINT64			GetReadBufferSize();

	const INT64				GetEntryCount();
	const BOOL				HasEntry(LPCTSTR iEntryName);
	const vector<CString>	GetEntryList();
	const UINT64			GetEntryUnCompressedSize(LPCTSTR iEntryName);
	const UINT64			GetArchiveUnCompressedSize();

	void					SetReadBufferSize(UINT64 iSize);
	void					SetProgressUnit(DOUBLE iProgressUnit);

#pragma endregion


#pragma region General Function (Synchronize Function)
public:
	const BOOL			OpenArchive(LPCTSTR iArchiveFilePath = _T(""));
	const BOOL			CloseArchive();

	const BOOL			AppendEntry(BYTE* iBuffer, INT64 iBufferSize, LPCTSTR iEntryName);
	const BOOL			AppendEntry(LPCTSTR iAppendFilePath, LPCTSTR iEntryName);
	const BOOL			AppendDirectory(LPCTSTR iDirectoryEntryName);
	const BOOL			RemoveEntry(LPCTSTR iEntryName);

	const BOOL			ExtractEntryToFile(LPCTSTR iEntryName, LPCTSTR iDestFilePath, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	const UINT64		ExtractEntryToBuffer(LPCTSTR iEntryName, BYTE** oExtractedBuffer, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	const UINT64		ExtractEntryToBuffer(LPCTSTR iEntryName, BYTE** oExtractedBuffer, const UINT64 iReadSize, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	const BOOL			ExtractToDirectory(LPCTSTR iDestDirectory, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);

	const BOOL			Flush(const INT nProcessType, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	const BOOL			Discard();

	static const BOOL	CompressFile(LPCTSTR iSourceFilePath, LPCTSTR iDestFilePath, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	static const BOOL	CompressDirectory(LPCTSTR iSourceDir, LPCTSTR iDestFilePath, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	static const INT	CompressBufferToFile(BYTE* iSourceBuffer, INT iBufferSize, LPCTSTR iEntryName, LPCTSTR iDestFilePath, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);

	static const BOOL	ExtractEntryToFile(LPCTSTR iArchiveFilePath, LPCTSTR iEntryName, LPCTSTR iDestFilePath, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	static const UINT64 ExtractEntryToBuffer(LPCTSTR iArchiveFilePath, LPCTSTR iEntryName, BYTE** oExtractedBuffer, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	static const UINT64 ExtractEntryToBuffer(LPCTSTR iArchiveFilePath, LPCTSTR iEntryName, BYTE** oExtractedBuffer, const UINT64 iReadSize, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);
	static const BOOL	ExtractToDirectory(LPCTSTR iArchiveFilePath, LPCTSTR iDestDirectory, const ProgressCallbackType * iCallback = NULL, const CancelCallbackType * iCancelCallback = NULL);

#pragma endregion

#pragma region Private Methods
private:
	const INT64			FindEntryIndexByName(LPCTSTR iEntryName);
	const BOOL			GetEntryStat(LPCTSTR iEntryName, zip_stat_t& stat);
	const BOOL			GetEntryStatByIndex(UINT64 iIndex, zip_stat_t& stat);
	static const BOOL	GetFiles(LPCTSTR iDirectory, vector<CString>& oFiles, vector<CString>& oDirectories);
	static const BOOL	CreateDirectoryRecursive(LPCTSTR iDirectory);
	static CString		GetDirectory(CString& iPath);
	static TCHAR		GetDirectoryDelimiter();
#pragma endregion

#pragma region Fields
public:
	static DOUBLE			m_dProgressUnit;

protected:
	CString					m_ArchiveFilePath;
	BOOL					m_FileOpened;
	zip_t *					m_ZipHandle;
	UINT64					m_nReadBufferSize;
	ProgressCallbackType	m_ProgressCallBack;
	CancelCallbackType		m_CancelCallBack;
#pragma endregion
};
		}
	}
}