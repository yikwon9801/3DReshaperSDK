#pragma once

namespace Kernel
{
	namespace Collection
	{
		template<typename _DataType> class CTableList;
	}

	namespace Util
	{
		using namespace Kernel::Collection;

#pragma region Macro
#define BEGIN_PROGRESS(subObj)	{											\
	CProgress * subObj = NULL;
#define CREATE_PROGRESS(percentage, parentObj, subObj)						\
	if (parentObj)	subObj = new CProgress(percentage, *parentObj);
#define DELETE_PROGRESS(parentObj, subObj)									\
	if (parentObj)	delete subObj;
#define END_PROGRESS()	}
#define BEGINANDCREATE_PROGRESS(parentObj, subObj, percentage)				\
	BEGIN_PROGRESS(subObj)													\
	CREATE_PROGRESS(percentage, parentObj, subObj)
#define ENDANDDELETE_PROGRESS(parentObj, subObj)							\
	DELETE_PROGRESS(parentObj, subObj)										\
	END_PROGRESS()
#pragma endregion

RsDEFINE_DLL_CLASS(CProgress)
{
	typedef void(*pCallBackFunc)(CProgress * iProgress, const DOUBLE iPercent, const DOUBLE iRange);
#pragma region Construction & Destruction
public:
	CProgress(CProgressCtrl & iProgressBar);
	CProgress(HWND hWnd, pCallBackFunc iCallBackFunction);
	CProgress(const DOUBLE iResponsibilityRange, CProgress & iParentProgress);
	virtual ~CProgress();
#pragma endregion

public:
	inline const DOUBLE		GetResponsibilityRange() const	{ return m_ResponsibilityRange; }
	inline const DOUBLE		GetRemainRange() const	{ return m_RemainRange; }
	
	const BOOL				IsStop() const;
	void					Stop();
	void					CancelStop();
	LPCTSTR					GetComment() const;
	void					SetComment(LPCTSTR lpComment = NULL);
	HWND					GetHwnd();
protected:
	const DOUBLE			GetNeigborsResponsibilityRange();

	CTableList<CProgress *>	GetNeiborChilds(const UINT16 iUnderChilds);
	CProgress *				NextChild(const UINT16 iIndex);
	CProgress *				PrevChild(const UINT16 iIndex);
private:
	void					SetStopChilds(const BOOL iStop);
	void					SetStopParents(const BOOL iStop);
	void					SetStop(const BOOL iStop);
	void					NotiDeleteItself(CProgress * iChild);

public:
	void					Progress(const DOUBLE iPos, const BOOL iForce = FALSE);

private:
	void					AddProgress(CProgress & iChildProgress);

#pragma region Memeber Variable
private:
	struct Internal;
	Internal *				m_Internal;

	CProgress *				m_Parent;
	CTableList<CProgress *>	m_Childs;

	UINT16					m_index;
	DOUBLE					m_ResponsibilityRange;
	DOUBLE					m_RemainRange;
	BOOL					m_Stop;
	CCriticalSection		m_CS;
#pragma endregion
};

	}
}