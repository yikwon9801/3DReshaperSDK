#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsINTERFACE(ICreateFileObject);
	}

	namespace File
	{

RsDEFINE_DLL_CLASS(CFolderSystem)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
protected:
	CFolderSystem(LPCTSTR iFolderPath);
	virtual ~CFolderSystem();
#pragma endregion

#pragma region Setter & Getter function
protected:
	inline const UINT	GetLifeDays() const { return m_LifeDays; }
public:
	inline void			SetMonitoringDateTime(const BOOL iSet) { m_CheckDateTime = iSet; }
#pragma endregion

#pragma region General Function
public:
	const CString		GetCurrentFolderPath();
protected:
	void				LifeCheckAndCleanFolders();

	const BOOL			CheckToCreateNewFolder(LPCTSTR iPath);

#pragma endregion

#pragma region Memeber Variable
private:
	CRITICAL_SECTION	__log_lock__;
private:
	CString				m_DirPath;
	BOOL				m_CheckDateTime;
	UINT				m_LifeDays;
#pragma endregion
};

	}
}
