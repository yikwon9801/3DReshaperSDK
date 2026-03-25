#pragma once

namespace GUI
{

	namespace MFC
	{

		namespace Dialog
		{
			namespace Schedule
			{
				RsDEFINE_CLASS(CScheduleDialog);
			}
		}
	}
}

namespace Display
{
	namespace Util
	{

		namespace Schedule
		{
			using namespace GUI::MFC::Dialog::Schedule;

			RsDEFINE_CLASS(CScheduler);

RsDEFINE_DLL_CLASS(CScheduleCommand)
{
	friend class CScheduler;

#pragma region Construction & Destruction
protected:
	CScheduleCommand(const UINT iScheduleID, CScheduleDialog * iAttachedWnd);
public:
	virtual ~CScheduleCommand();
#pragma endregion

#pragma region Setter & Getter function
public:
	const UINT				GetId() const	{ return m_ScheduleID; }
	CScheduleDialog *		GetAttachedWnd()	{ return m_AttachedWnd; }

#pragma endregion

public:
	const BOOL				IsPrev(CDataObject & iObj) const;
	const BOOL				IsNext(CDataObject & iObj) const;

private:
	void					Hide();
	void					Show();

	void					MoveAttachedWnd(const CRect & iPosition);

public:
	virtual const BOOL		IsLicense() const = 0;
	virtual const CString	GetText() const = 0;
	virtual const BOOL		IsExecutable(CDataObject & iObj) const = 0;
	virtual const BOOL		IsFinished(CDataObject & iObj) const = 0;
	virtual void			ManageVisibleUI(CDataObject & iObj) const = 0;
	virtual void			ManageVisibleObject(CDataObject & iObj) const = 0;
	virtual void			BeginCommand(CDataObject & iObj) = 0;
	virtual void			EndCommand(CDataObject & iObj) = 0;

#pragma region Memeber Variable
private:
	const UINT				m_ScheduleID;
	CScheduleDialog *		m_AttachedWnd;
	CScheduler *			m_Scheduler;
#pragma endregion
};

		}
	}
}