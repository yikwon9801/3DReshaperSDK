#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CUtil);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableList;

		using namespace Kernel::Util;

template<typename _DataType> class CTableArray
{
#pragma region Construction & Destruction
public:
	CTableArray() : m_Table(NULL), m_Size(0)	{}
	CTableArray(const CTableArray<_DataType> & iTableArray) : m_Table(NULL), m_Size(0) { operator = (iTableArray); }
	CTableArray(const UINT64 iSizeToCreate) : m_Table(NULL), m_Size(0) { Resize(iSizeToCreate); }
	virtual ~CTableArray()	{ Clear(); }
#pragma endregion

public:
	inline const UINT64	Size() const	{ return m_Size; }
	inline _DataType &	data(const UINT64 iIndex) const { return const_cast<_DataType *>(m_Table)[iIndex]; }

public:
	void				Resize(const UINT64 iSizeToCreate)	{ _AllocateMemory(iSizeToCreate); }
	template<class _type>
	void				Resize(const UINT64 iSizeToCreate, const _type iForceValue)
	{
		_AllocateMemory(iSizeToCreate);
		for (UINT64 ii = 0; ii < m_Size; ii++)
			m_Table[ii] = iForceValue;
	}
	void				Copy(CTableArray<_DataType> & iArray, const UINT64 iStartPosition = 0)
	{
		for (UINT64 ii = 0; ii < iArray.Size(); ii++)
			m_Table[iStartPosition + ii] = iArray[ii];
	}
	void				AppendSize(const UINT64 iAppendingSizeToCreate)
	{
		ASSERT(iAppendingSizeToCreate);
		if (!iAppendingSizeToCreate)	return;
		_DataType * tmp = m_Table;
		const UINT64 preSize = m_Size;
		const UINT64 totalSize = preSize + iAppendingSizeToCreate;
		m_Table = new _DataType[(UINT)totalSize];
		ASSERT(m_Table);
		m_Size = totalSize;
		for (UINT64 ii = 0; ii < preSize; ii++)
			m_Table[ii] = tmp[ii];
		delete[] tmp;
	}
	void				Reverse()
	{
		_DataType tmp;
		for (UINT64 ii = 0; ii < (UINT64)(m_Size / 2); ii++)
		{
			CUtil::Swap(m_Table[ii], m_Table[(m_Size - ii) - 1]);
		}
	}
	void				put(_DataType * iData, const UINT64 iSize) { _Release(); m_Table = iData; m_Size = iSize; }
	_DataType *			get() { return m_Table; }
	_DataType *			take() { _DataType * tmp = m_Table; m_Table = NULL; return tmp; }
	void				Clear() { _Release(); }
private:
	void				_Release()	{ if (m_Table){ delete[] m_Table;	m_Table = NULL; }	m_Size = 0; }
	void				_AllocateMemory(const UINT64 iSizeToCreate)	
	{
		Clear();
		ASSERT(iSizeToCreate);
		if (!iSizeToCreate)	return;
		m_Table = new _DataType[(UINT)iSizeToCreate];
		ASSERT(m_Table);
		m_Size = iSizeToCreate;
	}

#pragma region Operator Declaration
public:
	inline _DataType &	operator [] (const UINT64 iIndex) const	{ return const_cast<_DataType *>(m_Table)[iIndex]; }
	const CTableArray<_DataType> &	operator = (const CTableList<_DataType> & iTableList)
	{
		if (!iTableList.Size())
			return *this;
		Clear();
		m_Size = iTableList.Size();
		_AllocateMemory(m_Size);
		for (UINT64 ii = 0; ii < m_Size; ii++)
			m_Table[ii] = iTableList[(UINT)ii];

		return *this;
	}
	const CTableArray<_DataType> &	operator = (const CTableArray<_DataType> & iTableArray)
	{
		if (this == &iTableArray)
			return *this;
		Clear();
		if (!iTableArray.Size())
			return *this;
		m_Size = iTableArray.Size();
		_AllocateMemory(m_Size);
		for (UINT64 ii = 0; ii < iTableArray.Size(); ii++)
			m_Table[ii] = iTableArray.m_Table[ii];

		return *this;
	}
	void operator += (const CTableArray<_DataType> & iTableArray)
	{
		if (!iTableArray.Size())
			return;
		const UINT64 preSize = m_Size;
		AppendSize(iTableArray.Size());
		for (UINT64 ii = 0; ii < iTableArray.Size(); ii++)
			m_Table[ii + preSize] = iTableArray[(UINT)ii];
	}
	const BOOL			operator == (const CTableArray<_DataType> & iTableArray) const
	{
		if (this == &iTableArray)	return TRUE;
		if (m_Size != iTableArray.m_Size)	return FALSE;
		for (UINT64 ii = 0; ii < m_Size; ii++) { if (m_Table[ii] != iTableArray.m_Table[ii])	return FALSE; }
		return TRUE;
	}
	const BOOL			operator != (const CTableArray<_DataType> & iTableArray) const
	{
		return !(operator == (iTableArray));
	}
#pragma endregion

#pragma region Memeber Variable
private:
	_DataType *			m_Table;
	UINT64				m_Size;
#pragma endregion
};

	}
}