#pragma once

#include <memory>
using namespace std;

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDScene);
	}
}

namespace GUI
{

	namespace MFC
	{

		namespace View
		{

			using namespace Display::View;

// COpenGLView view

#ifdef _HYEXT
class __declspec(dllexport) COpenGLView : public CView
#else
class __declspec(dllimport) COpenGLView : public CView
#endif
{
	DECLARE_DYNCREATE(COpenGLView)

protected:
	COpenGLView();           // protected constructor used by dynamic creation
	virtual ~COpenGLView();

public:
	inline void				SetRotationType(const UINT iRotationType) { m_Scene->SetRotationType(iRotationType); }
	inline void				SetCancelSelection() { m_bLButtonDown = FALSE;	m_bDragForSelection = FALSE; }
	inline void				SetDisplayForSelection(const BOOL iDisplay) { m_bDisplayForSelection = iDisplay; }
	inline void				SetSelectionMode(const UINT iSelectionMode) { m_nSelectionMode = iSelectionMode; }
	inline void				SetCenterToRotate(const CGPointDouble & iPoint) { m_CenterToRotate = iPoint; }
	inline void				SetRotateScenePossible(const BOOL iPossible) { m_CanRotateScene = iPossible; }
	inline void				SetPanningScenePossible(const BOOL iPossible) { m_CanPanningScene = iPossible; }
	inline void				SetZoomScenePossible(const BOOL iPossible) { m_CanZoomScene = iPossible; }
	inline void				SetSelectModePossible(const BOOL iPossible) { m_CanSelectMode = iPossible; }

	inline const BOOL		IsDragForSelection() const { return m_bDragForSelection; }
	inline const BOOL		IsLButtonDown() const { return m_bLButtonDown; }
	inline const BOOL		IsRButtonDown() const { return m_bRButtonDown; }
	inline const BOOL		IsMoving() const { return m_bMoving; }
	inline const BOOL		IsDisplayForSelection() const { return m_bDisplayForSelection; }
	inline const BOOL		IsSelectionMode(const UINT iSelectionMode) const { return m_nSelectionMode == iSelectionMode; }
	inline const BOOL		IsRotateScenePossible() const { return m_CanRotateScene; }
	inline const BOOL		IsPanningScenePossible() const { return m_CanPanningScene; }
	inline const BOOL		IsZoomScenePossible() const { return m_CanZoomScene; }
	inline const BOOL		IsSelectModePossible() const { return m_CanSelectMode; }

	inline const CDScene *	GetScene() const { return m_Scene.get(); }

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void			OnInitialUpdate();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void			OnSize(UINT nType, int cx, int cy);
	afx_msg void			OnDestroy();
	afx_msg void			OnTimer(UINT_PTR nIDEvent);
	afx_msg void			OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void			OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void			OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void			OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void			OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void			OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void			OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL			OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void			OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void			OnMouseLeave();

public:
	void					LButtonMoveForSelection(const CPoint & iPoint);
	void					LButtonDownForSelection(const CPoint & iPoint);
	void					LButtonUpForSelection(const CPoint & iPoint);

	void					RButtonMoveForRotationCamera(const CPoint & iPoint);
	void					RButtonDownForRotationCamera(const CPoint & iPoint);
	void					RButtonUpForRotationCamera(const CPoint & iPoint);

public:
	const CRect				GetRect() const { return CRect(m_PrePos.x, m_PrePos.y, m_PostPos.x, m_PostPos.y); }

	CDScene &				Scene() { return *m_Scene.get(); };

public:
	void					AnimateMoveCameraToBoundingBox(const CMatrix3x3 & iWorldSysToRotate, const CBoundingBox & iBoundingBox, const UINT iNumberOfFrame, const DOUBLE iSecond);

protected:
	CPoint					m_PrePos;
	CPoint					m_PostPos;
protected:
	BOOL					m_bRButtonDown;
	BOOL					m_bMButtonDown;
	BOOL					m_bLButtonDown;
	BOOL					m_bMoving;
	UINT					m_nSelectionMode;
	BOOL					m_bDragForSelection;
	BOOL					m_bDisplayForSelection;

	BOOL					m_CanRotateScene;
	BOOL					m_CanPanningScene;
	BOOL					m_CanZoomScene;
	BOOL					m_CanSelectMode;

	UINT					m_RotationMode;
	CGPointDouble			m_CenterToRotate;

private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
	auto_ptr<CDScene>		m_Scene;
};

		}
	}
}