#pragma once

namespace Print3D
{
	namespace Object
	{
		HyDEFINE_CLASS(CPrintProject);
	}

	namespace Schedule
	{
		using namespace Print3D::Object;

HyDEFINE_DLL_CLASS(CPrintScheduler) : HyINHERITANCE(CScheduler)
{
#pragma region Construction & Destruction
protected:
	CPrintScheduler();
	virtual ~CPrintScheduler();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline CScheduleDialog *	GetAttachScheduler() { return m_SchedulerWnd; }
#pragma endregion

public:
	void					AttachScheduler(CScheduleDialog * iSchedulerWnd);

	void					RefreshView();

public:
	virtual const BOOL		Next(CDataObject & iObj);
	virtual const BOOL		Prev(CDataObject & iObj);
	virtual const BOOL		First(CDataObject & iObj);
	virtual const BOOL		End(CDataObject & iObj);
	virtual const BOOL		Last(CDataObject & iObj);
	virtual const BOOL		Stop(CDataObject & iObj);
protected:
	virtual void			Execute(CDataObject & iObj) const;

public:
	virtual void			MoveConnectedPosition(const CRect & iPosition);

#pragma region Schedule Command Identification
public:
	typedef enum 
	{
		PrintSchedulerCommandId_ImportModel		= 1,
		PrintSchedulerCommandId_LayoutModel ,
		PrintSchedulerCommandId_CorrectModel ,
		PrintSchedulerCommandId_SupportModel ,
		PrintSchedulerCommandId_SliceModel ,
		PrintSchedulerCommandId_ExportModel ,
	}PrintSchedulerCommandId;
#pragma endregion

#pragma region Memeber Variable
protected:
	CScheduleDialog *		m_SchedulerWnd;
#pragma endregion
};

	}
}