#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableList;
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CVector);
	}

	namespace Util
	{
		using namespace Kernel::Object;
		using namespace Kernel::Collection;
		using namespace Kernel::Math;

RsDEFINE_DLL_CLASS(CEditedNode)
{
#pragma region Type Definition
public:
	enum {
		EDITEDNODE_NONE			,
		EDITEDNODE_VECTOR		,
		EDITEDNODE_MATRIX3X3	,
		EDITEDNODE_MATRIX3X4	,
		EDITEDNODE_NEWOBJECT	,
		EDITEDNODE_DELETEOBJECT ,
	};
#pragma endregion

#pragma region Construction & Destruction
public:
	CEditedNode(IEditedData & iObj, const CDataObject & iData, const BOOL iClone = TRUE, VOID * iBuffer = NULL);
	CEditedNode(IEditedData & iObj, const CDataObject & iData, const UINT iType, const BOOL iClone = TRUE, VOID * iBuffer = NULL);
	~CEditedNode();
#pragma endregion

#pragma region Setter & Getter function
public:
	const UINT		GetType() const { return m_Type; }
	CDataObject *	GetDataToExec() { return m_DataToExec; }
	IEditedData *	GetObject() { return m_Object; }
	VOID *			GetBuffer() { return m_Buffer; }
#pragma endregion

protected:
	const UINT		RecognizeType(const CDataObject * iObj) const;

#pragma region Memeber Variable
private:
	BOOL			m_bClone;
	UINT			m_Type;
	CDataObject *	m_DataToExec;
	IEditedData *	m_Object;
	VOID *			m_Buffer;
#pragma region Memeber Variable
};

RsDEFINE_DLL_CLASS(CEditedDatas)
{
#pragma region Construction & Destruction
public:
	CEditedDatas(const CTableList<CEditedNode *> & iTable);
	~CEditedDatas();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CTableList<CEditedNode *> &	GetNodeList() const { return m_NodeList; }
#pragma endregion

public:
	const BOOL		ContainObjectToExec(CDataObject * iObject);

#pragma region Memeber Variable
private:
	CTableList<CEditedNode *>	m_NodeList;
#pragma region Memeber Variable
};

RsDEFINE_DLL_CLASS(CEditedDataModel)
{
#pragma region Construction & Destruction
protected:
	CEditedDataModel();
	virtual ~CEditedDataModel();
#pragma endregion

#pragma region Setter & Getter function
protected:
	inline const UINT	GetBeforeDataCount() const { return (UINT)m_BeforeDataList.Size(); }
	inline const UINT	GetAfterDataCount() const { return (UINT)m_AfterDataList.Size(); }
#pragma endregion

public:
	void				AddData(CEditedDatas * iData);

	void				Clear();

protected:
	void				Release();
	void				ReleaseBeforDataList();
	void				ReleaseAfterDataList();

	CEditedDatas *		GetLastBeforData();
	CEditedDatas *		GetFirstAfterData();

	const BOOL			MoveBeforeToAfterDataList(CEditedDatas * iDataToMove);
	const BOOL			MoveAfterToBeforeDataList(CEditedDatas * iDataToMove);
	const BOOL			MoveLastBeforeDataToAfterDataList();
	const BOOL			MoveFirstAfterDataToBeforeDataList();

	const BOOL			ContainObjectToExec(CDataObject * iObject);

#pragma region Memeber Variable
private:
	UINT				m_MaxDatas;
	CTableList<CEditedDatas *>	m_BeforeDataList;
	CTableList<CEditedDatas *>	m_AfterDataList;
#pragma endregion
};

	}
}