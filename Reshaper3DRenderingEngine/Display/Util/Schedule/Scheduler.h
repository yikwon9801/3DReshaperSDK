#pragma once

#include <map>
using namespace std;

namespace Display
{
	namespace Util
	{

		namespace Schedule
		{
#pragma region Macro
#define REGISTER_SCHEDULECOMMAND(scheduler, commandclass, uiInstance)								\
	scheduler.AddCommand(new commandclass(commandclass::IDD, uiInstance));
#pragma endregion

RsDEFINE_DLL_CLASS(CScheduler)
{
	typedef map<UINT, CScheduleCommand *>	SCHEDULE_ORDER;

#pragma region Construction & Destruction
protected:
	CScheduler();
	virtual ~CScheduler();
#pragma endregion

public:
	const BOOL				IsReady() const;

	void					Clear();

public:
	const CString			GetText() const;
	const BOOL				IsCommand(const UINT iCommandId) const;
	CScheduleCommand *		GetNextCommandHasLicensed(const INT iCommandId);
	CScheduleCommand *		GetPrevCommandHasLicensed(const INT iCommandId);
	CScheduleCommand *		GetCommand(const UINT iCommandId);
	void					AddCommand(CScheduleCommand * iCommand);
	
	const BOOL				SetCurrentCommand(const UINT iCommandId);
	CScheduleCommand *		GetCurrentCommand()	{ return m_CurCommand; }

	const BOOL				IsExecutable(const UINT iCommandId) const;
	const BOOL				IsLicense(const UINT iCommandId) const;

	const BOOL				IsCurrentCommand(const UINT iCommandId) const;

protected:
	virtual const BOOL		Next(CDataObject & iObj);
	virtual const BOOL		Prev(CDataObject & iObj);
	virtual const BOOL		First(CDataObject & iObj);
	virtual const BOOL		End(CDataObject & iObj);
	virtual const BOOL		Last(CDataObject & iObj);
	virtual void			Execute(CDataObject & iObj) const;
	virtual void			Complete(CDataObject & iObj) const;
	virtual const BOOL		Stop(CDataObject & iObj);

protected:
	virtual const UINT		GetScheduleStartId() const = 0;
	virtual const UINT		GetScheduleEndId() const = 0;

public:
	virtual CDataObject *	GetActiveProject() = 0;

public:
	virtual void			MoveConnectedPosition(const CRect & iPosition);

private:
	void					AllHideAttachedWnd();

#pragma region Memeber Variable
private:
	CScheduleCommand *		m_CurCommand;
	SCHEDULE_ORDER			m_Order;
#pragma endregion
};

		}
	}
}