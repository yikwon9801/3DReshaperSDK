#pragma once

namespace Kernel
{
namespace InterProcess
{
namespace NamedPipe
{

#define PIPE_CLIENT_INPUT_BUFFER_SIZE		(1*1024*1024)  // 1MB
#define PIPE_CLIENT_OUTPUT_BUFFER_SIZE		(1*1024*1024)  // 1MB

RsDEFINE_DLL_CLASS(CNamedPipeClient)
{

#pragma region Construction & Destruction
public:
	CNamedPipeClient(LPCTSTR strName = _T(""), BOOL bBinaryMode=TRUE);
	virtual ~CNamedPipeClient();
#pragma endregion


#pragma region Getter & Setter
public:
	BOOL			IsConnected();
	CString			GetPipeName();
	const INT		GetSendTimeout();
	const INT		GetReceiveTimeout();

	void			SetSendTimeout(const INT iTimeOut);
	void			SetReceiveTimeout(const INT iReceiveTimeout);

private:
	HANDLE	GetPipeHandle();
	INT		GetWritePendingBytes();

protected:
	void	SetWaitAck(BOOL bWaitAck);

#pragma endregion

#pragma region Public Operations
public:
	BOOL Connect();
	BOOL DisConnect();
	void Write(BYTE* pBuffer, INT iSize);

#pragma endregion

#pragma region Virtual functions
protected:
	virtual BOOL HandleReceiptBuffer(BYTE* pData, INT nSize) { m_nSendByte = 0; return TRUE; }
#pragma endregion


#pragma region Private Operations
private:
	void		ClearBuffer();
	BOOL		StartCommunicationThread();
	BOOL		StopCommunicationThread();
	static void CommunicationThread(LPVOID pParam);
	INT			WaitAck();

#pragma endregion

#pragma region Fields
private:
	BOOL	m_bBinaryMode;
	BOOL    m_bIsConnected;
	BOOL    m_bCommunicationThread;
	INT     m_nConnectionRetry;
	BOOL	m_bWaitAck;
	INT		m_nSendTimeout;
	INT     m_nReceiveTimeout;
	CString m_strPipeName;
	HANDLE	m_hNamedPipe;
	HANDLE  m_hCommunicationThread;
	DWORD   m_dwCommunicationThread;
	CRITICAL_SECTION m_BufferSync;

	DWORD  m_nSendByte;
	unique_ptr<BYTE> m_pSendBuff;
	unique_ptr<BYTE> m_pReceiveBuff;

#pragma endregion

};

} // NamedPipe
} // InterProcess
} // Kernel