#pragma once

namespace Kernel
{
namespace InterProcess
{
namespace NamedPipe
{

#define PIPE_SERVER_INPUT_BUFFER_SIZE		(1*1024*1024)  // 1MB
#define PIPE_SERVER_OUTPUT_BUFFER_SIZE		(1*1024*1024)  // 1MB

typedef void(*CNamedPipeServerDataEvent)(void* pSender, INT nEventType, BYTE* pData, INT nSize);

RsDEFINE_DLL_CLASS(CNamedPipeServerClient)
{

#pragma region contructor
public:
	CNamedPipeServerClient(HANDLE pipe = INVALID_HANDLE_VALUE, HANDLE thread = INVALID_HANDLE_VALUE, DWORD thread_id = NULL);
	virtual ~CNamedPipeServerClient();
#pragma endregion

#pragma region getter & setter
public:
	BOOL IsThreadAlive();

#pragma endregion

#pragma region methods
public:
	void ClearBuffer();
	void Write(BYTE* pBuffer, INT iSize);

	BOOL StartClientThread();
	BOOL StopClientThread();

private:
	static void ClientThread(LPVOID pParam);
#pragma endregion

#pragma region fields
private:
	BOOL	bThreadAlive;
	HANDLE	hPipe;
	HANDLE	hThread;
	DWORD	dwThreadID;
	INT		nWriteSize;
	unique_ptr<BYTE> btReceiveBuffer;
	unique_ptr<BYTE> btSendBuffer;
	CRITICAL_SECTION m_BufferSync;
#pragma endregion

#pragma region events
public:
	CNamedPipeServerDataEvent SentEventHandler;
	CNamedPipeServerDataEvent ReceiptEventHandler;
#pragma endregion
};


}
}
}