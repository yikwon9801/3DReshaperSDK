#pragma once

namespace Kernel
{
	namespace Slice
	{
		namespace Path
		{
			using namespace Kernel;
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPolygonNTreeNode)
{
#pragma region Type Definition
public:
	typedef vector<CPolygonNTreeNode *>	_PointerChildNodes;
#pragma endregion

#pragma region Construction & Destruction
public:
	CPolygonNTreeNode(Kernel::Path * iData = NULL, const BOOL iClosed = TRUE);
	virtual ~CPolygonNTreeNode();
#pragma endregion

#pragma region Setter & Getter function
public:
	enum { None, Positive, Negative };
	inline Kernel::Path *	Data() { return m_Data; }
	inline const INT	GetOrientation() const { return m_Orientation; }
	inline const CPolygonNTreeNode::_PointerChildNodes &	GetChilds() const { return m_Childs; }
	inline const IntPoint &	GetDeparture() const { return m_Departure; }
	inline const IntPoint &	GetArrival() const { return m_Arrival; }
	inline const BOOL	IsSortChilds() const { return m_SortChilds; }
	inline const BOOL	BeChildsMustClosed() const { return m_ChildsMustBeClosed; }
	inline const BOOL	GetLastNodeOfParent() const { return m_LastNodeOfParent; }
	inline void			SetSortChilds(const BOOL iSort) { m_SortChilds = iSort; }
	inline void			SetChildsMustBeClosed(const BOOL iClosed) { m_ChildsMustBeClosed = iClosed; }
	inline void			SetForceChild(const BOOL iSet) { m_ForceChild = iSet; }
	inline void			SetLastNodeOfParent(const BOOL iSet) { m_LastNodeOfParent = iSet; }
	inline void			SetArrival(const IntPoint & iPoint) { m_Arrival = iPoint; }	// 사용하지 말것
#pragma endregion

#pragma region General Function
public:
	const INT			AddChild(CPolygonNTreeNode * iData);
	CPolygonNTreeNode *	GetChild(const UINT iIndex) { return m_Childs[iIndex]; }
	const IntPoint &	GetLowestDeparture() const;
	const IntPoint &	GetLowestArrival() const;
	const INT			GetClosestPointIndex(const IntPoint & iPoint, IntPoint * oPoint = NULL) const;
	const IntPoint &	GetClosestPoint(const IntPoint & iPoint) const;

	void				ShortestPaths(const BOOL iTopDown, const IntPoint & iStartingPosition);

	void				ChangeNearestStartPositionInPolygon(const IntPoint & iPoint);

	const BOOL			Contains(CPolygonNTreeNode * iNode, const UINT8 iContainType);
protected:
	void				SortPath(const IntPoint & iDeparture);
	void				ShortPathTopDown(const IntPoint & iStartingPosition);
	void				ShortPathBottomUp(const IntPoint & iStartingPosition);
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
#pragma endregion

#pragma region Operator Declaration
public:
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	Kernel::Path *		m_Data;
	INT					m_Orientation;
	_PointerChildNodes	m_Childs;

	IntPoint			m_Departure;
	IntPoint			m_Arrival;
	BOOL				m_SortChilds;
	BOOL				m_ChildsMustBeClosed;
	BOOL				m_ForceChild;
	BOOL				m_LastNodeOfParent;
#pragma endregion
};

		}
	}
}