#pragma once

#include <list>
using namespace std;

namespace Kernel
{

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;

template<typename _DataType> class CTableList
{
	typedef list<_DataType>	_ObjectList;

#pragma region Construction & Destruction
public:
	CTableList()	{}
	CTableList(const CTableList<_DataType> & iTableList) { operator = (iTableList); }
	virtual ~CTableList()	{ Clear(); }
#pragma endregion

public:
	inline const UINT	Size() const	{ return (UINT)m_List.size(); }
	inline const _ObjectList &	GetList() const { return m_List; }
	inline _ObjectList &	List() { return m_List; }
public:
	void				Clear()	{ _Release(); }

	void				Add(_DataType & iData)	{ m_List.push_back(iData); }
	void				AddFirst(_DataType & iData) { m_List.push_front(iData); }
	void				Remove(_DataType & iData)
	{
		_ObjectList::iterator it = find(m_List.begin(), m_List.end(), iData);
		if (it != m_List.end())
			m_List.erase(it);
	}
	const BOOL			Contain(_DataType & iData) const { return std::find(m_List.begin(), m_List.end(), iData) != m_List.end(); }

private:
	void				_Release()	{ m_List.clear(); }

#pragma region Operator Declaration
public:
	inline _DataType &	operator [] (const UINT iIndex) const	{ _ObjectList::iterator it = const_cast<_ObjectList &>(m_List).begin(); advance(it, iIndex); return *it; }
	const CTableList<_DataType> &	operator = (const CTableList<_DataType> & iTableList)
	{
		if (this == &iTableList)	return *this;
		Clear();
		for (_ObjectList::const_iterator it = iTableList.m_List.begin(); it != iTableList.m_List.end(); it++)
			m_List.push_back(*it);
		return *this;
	}
	void operator += (const CTableArray<_DataType> & iTableArray)
	{
		if (!iTableArray.Size())	return;
		for (UINT64 ii = 0; ii < iTableArray.Size(); ii++)
			m_List.push_back(iTableArray[ii]);
	}
	void operator += (const CTableList<_DataType> & iTableList)
	{
		if (!iTableList.Size())	return;
		for (_ObjectList::const_iterator it = iTableList.m_List.begin(); it != iTableList.m_List.end(); it++)
			m_List.push_back(*it);
	}
#pragma endregion

#pragma region Memeber Variable
private:
	_ObjectList			m_List;
#pragma endregion
};

	}
}