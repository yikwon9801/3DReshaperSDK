#pragma once

namespace GUI
{

	namespace MFC
	{

		namespace Dialog
		{

// CTransparencyDialog dialog

#ifdef _HYEXT
class __declspec(dllexport) CTransparencyDialog : public CDialog
#else
class __declspec(dllimport) CTransparencyDialog : public CDialog
#endif
{
	DECLARE_DYNAMIC(CTransparencyDialog)

public:
	CTransparencyDialog(UINT nIDTemplate, CWnd *pParent = NULL);   // standard constructor
	virtual ~CTransparencyDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg BOOL	OnEraseBkgnd(CDC* pDC);
	afx_msg void	OnClose();

protected:
	virtual void	OnOK();
	virtual void	OnCancel();
	virtual BOOL	OnInitDialog();

protected:
	inline void		SetTransparent(const BOOL iTransparent) { m_Transparency = iTransparent; }

private:
	BOOL			m_Transparency;
};

		}
	}
}