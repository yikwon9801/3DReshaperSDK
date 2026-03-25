#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}
}

namespace GUI
{

	namespace Tool
	{

		namespace View
		{

			using namespace Display::View;

RsDEFINE_DLL_CLASS(CDSceneView) : RsINHERITANCE(CDSceneTool)
{
#pragma region Construction & Destruction
protected:
	CDSceneView();
	CDSceneView(LPCTSTR iTitle, CDOpenGLScene * iScene);
	virtual ~CDSceneView();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CRect &	GetPosition() const { return m_Rect; }
	inline LPCTSTR		GetTitle() const { return m_Title; }
public:
	inline void			SetPosition(const CRect & iRect) { m_Rect = iRect; }
	inline void			SetTitle(LPCTSTR iTitle) { m_Title = iTitle; }
#pragma endregion

protected:
	void				GetTitleRect(CRectDouble & oRect) const;
	void				GetClientRect(CRectDouble & oRect) const;
	void				GetWindowRect(CRectDouble & oRect) const;
	const CGPoint2DDouble	GetGapSize() const;

#pragma region Display
protected:
	virtual const INT	Display() const;
private:
	void				_DisplayBackground(const CRectDouble & iRect) const;
	const INT			_DisplayTitle(const CRectDouble & iRect) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

private:
	CRect				m_Rect;
	CString				m_Title;

private:
	struct  Internal;
	Internal *			m_Internal;
};

		}
	}

}