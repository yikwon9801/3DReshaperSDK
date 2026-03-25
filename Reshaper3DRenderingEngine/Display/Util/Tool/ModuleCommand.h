#pragma once

namespace Display
{
	namespace Util
	{

		namespace Tool
		{

			RsDEFINE_CLASS(CModuleManager);

RsDEFINE_DLL_CLASS(CModuleDialog) : RsINHERITANCE(CDialogEx)
{
	DECLARE_DYNAMIC(CModuleDialog)

public:
	CModuleDialog(UINT nIDTemplate, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CModuleDialog();

protected:
	virtual void		DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL		PreTranslateMessage(MSG* pMsg);

public:
	virtual void		BeginModuleDialog() = 0;
	virtual void		EndModuleDialog() = 0;
	virtual void		UpdateLanguage() = 0;
};

RsDEFINE_DLL_CLASS(CModuleCommand)
{
	friend class CModuleManager;

#pragma region Construction & Destruction
protected:
	CModuleCommand(const UINT iID, CModuleDialog * iAttachedWnd);
public:
	virtual ~CModuleCommand();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetId() const	{ return m_ID; }
	inline CModuleDialog *	GetAttachedWnd()	{ return m_AttachedWnd; }

#pragma endregion

public:
	void					MoveConnectedWnd(const CRect & iRect);
private:
 	void					Hide();
 	void					Show();
 
public:
 	virtual const BOOL		IsLicense() const = 0;
 	virtual const CString	GetText() const = 0;
 	virtual const BOOL		IsExecutable() const = 0;
 	virtual void			BeginCommand() = 0;
 	virtual void			EndCommand() = 0;

#pragma region Memeber Variable
private:
	const UINT				m_ID;
	CModuleDialog *			m_AttachedWnd;
#pragma endregion
};

		}
	}
}