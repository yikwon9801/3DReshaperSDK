#pragma once

namespace Kernel
{
namespace InterProcess
{
namespace NamedPipe
{

RsDEFINE_CLASS(CNamedPipeServerClient);

RsDEFINE_DLL_CLASS(CNamedPipeServer)
{
#pragma region Construction & Destruction
public:
	CNamedPipeServer(LPCTSTR strPipeName = _T(""), BOOL bBinaryMode = TRUE, BOOL bEveryOne = TRUE, INT nMaxClient = 10);
	virtual ~CNamedPipeServer();
#pragma endregion

#pragma region Setter & Getter function
	CString GetPipeName();
	BOOL	GetBinaryMode();
	BOOL	GetEveryOne();
	INT		GetMaxClientCount();
#pragma endregion

#pragma region Operator Declaration

#pragma endregion

#pragma region Public Operation
public:
	BOOL StartServer();
	BOOL StopServer();
	void SetDataEventHandler(CNamedPipeServerDataEvent sent_event_handle, CNamedPipeServerDataEvent receive_event_handler);

#pragma endregion

#pragma region Private Operation
private:
	HANDLE CreatePipe(CString strName, BOOL bBinaryMode, BOOL bEveryOne);

	CNamedPipeServerClient* EnqueueClient(CNamedPipeServerClient* instance);
	void DequeueClient(CNamedPipeServerClient* pInstance);
	
	INT GetRunningClientThread();
	INT TerminateAllClientThread();

	static DWORD ListenThread(LPVOID pParam);
#pragma endregion

#pragma region Fields
private:
	BOOL	m_bBinaryMode;		// binary or text message communication 
	BOOL	m_bEveryOne;		// communication with another station or pc.
	CString m_strPipeName;      // pipe name.
	INT     m_nMaxClient;       // concurrent connection count. 
	                            //server uses 1 thread for one client for handling individual communication
	BOOL    m_bServerListen;
	HANDLE  m_hListenThread;
	DWORD   m_dwListenThreadID;

	CRITICAL_SECTION m_ClientSync;
	std::vector<CNamedPipeServerClient*> m_Clients; // client handle structure vector array

	CNamedPipeServerDataEvent DataSent;
	CNamedPipeServerDataEvent DataReceipt;
#pragma endregion
};

} // NamedPipe
} // InterProcess
} // Kernel
