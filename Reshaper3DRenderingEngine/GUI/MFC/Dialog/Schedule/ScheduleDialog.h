#pragma once

namespace GUI
{
	RsDEFINE_CLASS(CMouseEvent);

	namespace MFC
	{

		namespace Dialog
		{
			RsDEFINE_CLASS(CTransparencyDialog);

			namespace Schedule
			{
				using namespace GUI;

				// CScheduleDialog dialog

#ifdef _HYEXT
class __declspec(dllexport) CScheduleDialog : public CTransparencyDialog
#else
class __declspec(dllimport) CScheduleDialog : public CTransparencyDialog
#endif
{
	DECLARE_DYNAMIC(CScheduleDialog)

public:
	CScheduleDialog(UINT nIDTemplate, CWnd *pParent = NULL);   // standard constructor
	virtual ~CScheduleDialog();

protected:
	virtual void		DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual void		RefreshActiveView() const = 0;

	virtual void		PrevExecute(CDataObject & iObj) = 0;
	virtual void		PostExecute(CDataObject & iObj) = 0;

	virtual const BOOL	Undo() = 0;
	virtual const BOOL	Redo() = 0;

	virtual const BOOL	Copy() = 0;
	virtual const BOOL	Paste() = 0;

	virtual	const BOOL	IsRunning() const = 0;

	virtual const BOOL	DropFiles(const list<CString> & iDroppedFiles) = 0;

public:
	DECLARE_VIRTUAL_MOUSEEVENT(MouseLButtonDown)
	DECLARE_VIRTUAL_MOUSEEVENT(MouseLButtonUp)
	DECLARE_VIRTUAL_MOUSEEVENT(MouseRButtonDown)
	DECLARE_VIRTUAL_MOUSEEVENT(MouseRButtonUp)
	DECLARE_VIRTUAL_MOUSEEVENT(MouseMove)
	DECLARE_VIRTUAL_MOUSEEVENT(KeyDown)
	DECLARE_VIRTUAL_MOUSEEVENT(KeyUp)
};

			}
		}
	}
}