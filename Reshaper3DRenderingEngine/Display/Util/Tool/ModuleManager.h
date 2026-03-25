#pragma once

#include <map>
using namespace std;

namespace Display
{
	namespace Util
	{
		namespace Tool
		{
#pragma region Macro
#define REGISTER_MODULECOMMAND(scheduler, commandclass, uiInstance)								\
	scheduler.AddCommand(new commandclass(commandclass::IDD, uiInstance));
#pragma endregion

RsDEFINE_DLL_CLASS(CModuleManager)
{
	typedef map<UINT, CModuleCommand *>	MANAGE_MODULE;

#pragma region Construction & Destruction
protected:
	CModuleManager();
	virtual ~CModuleManager();
#pragma endregion

public:
	void					Clear();

 	const BOOL				SetCurrentCommand(const UINT iCommandId);
 	CModuleCommand *		GetCurrentCommand()	{ return m_CurCommand; }

public:
	const CString			GetText() const;

	void					AddCommand(CModuleCommand * iCommand);

	CModuleCommand *		GetCommand(const UINT iCommandId);
	const BOOL				IsCommand(const UINT iCommandId) const;

	const BOOL				ExitCommand();

public:
 	const BOOL				IsExecutable(const UINT iCommandId) const;
 	const BOOL				IsLicense(const UINT iCommandId) const;

public:
	void					MoveConnectedWnd(const CRect & iRect);
private:
 	void					AllHideAttachedWnd();

protected:
	virtual void			Execute() const;
	MANAGE_MODULE*	GetModules() { return &m_Modules; }

#pragma region Memeber Variable
private:
	CModuleCommand *		m_CurCommand;
	MANAGE_MODULE			m_Modules;
#pragma endregion
};

		}
	}
}