#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{
		using namespace Display::View;

RsDEFINE_DLL_CLASS(CDCompModel)
{
	friend class CDOpenGLScene;
#pragma region Construction & Destruction
protected:
	CDCompModel();
	virtual ~CDCompModel();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline CDOpenGLScene *	GetCurScene();
protected:
	inline void			SetCurScene(CDOpenGLScene * iScene);
#pragma endregion

public:
	void				HideAllComponents();

#pragma region Camera
public:
	virtual void		FitModelView(const CBoundingBox & iBoundingBox, const DOUBLE iOffsetDistance = 20.);
	virtual void		InitModelView();
#pragma endregion

#pragma region Static Function
public:
	static CDOpenGLScene *	GetActiveScene(CDOpenGLScene * iScene = NULL);
#pragma endregion

#pragma region Memeber Variable
protected:
	CDOpenGLScene *		m_curScene;
#pragma endregion
};

	}
}