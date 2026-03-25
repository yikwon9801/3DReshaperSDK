#pragma once

namespace GUI
{
	RsDEFINE_CLASS(CMouseEvent);

#define DECLARE_VIRTUAL_MOUSEEVENT(message)			virtual int message(const CMouseEvent & e);
#define DECLARE_MOUSEEVENT(message)					int message(const CMouseEvent & e);
#define IMPLEMENT_MOUSEEVENT(classname, message)	int classname::message(const CMouseEvent & e)

RsDEFINE_DLL_CLASS(CMouseEvent) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CMouseEvent(const UINT iFlags, const CPoint & iPoint, void * iWindow = NULL);
	CMouseEvent(const UINT iChar, const UINT iRepCnt, const UINT iFlags, void * iWindow = NULL);
	CMouseEvent(const CMouseEvent & iEvent);
	virtual ~CMouseEvent();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetFlags() const { return m_nFlags; }
	inline const CPoint &	GetPoint() const { return m_Point; }
	inline const UINT		GetChar() const { return m_nChar; }
	inline const UINT		GetRepCnt() const { return m_nRepCnt; }
	inline void *			Window() const { return m_Window; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	CMouseEvent *			Clone() const;
#pragma endregion

#pragma region Memeber Variable
private:
	UINT					m_nFlags;
	CPoint					m_Point;
	UINT					m_nChar;
	UINT					m_nRepCnt;
	void *					m_Window;
#pragma endregion
};

}