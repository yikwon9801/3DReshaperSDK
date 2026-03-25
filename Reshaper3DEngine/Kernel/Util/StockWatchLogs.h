#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Util
	{
		RsDEFINE_STRUCT(StockWatchTimerLog);

		using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CStockWatchLogs) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
protected:
	typedef vector<StockWatchTimerLog>		StockWatchTimerLogList;
#pragma endregion

#pragma region Construction & Destruction
public:
	CStockWatchLogs();
	CStockWatchLogs(const CStockWatchLogs & iSWLogs);
	virtual ~CStockWatchLogs();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const StockWatchTimerLogList &	GetLogList() const { return m_LogList; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CStockWatchLogs *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
#pragma endregion

#pragma region General Function
public:
	void					Clear();

	void					AddLog(const StockWatchTimerLog & iLog);
	void					AddLogList(const StockWatchTimerLogList & iLogList);
	void					AddLogList(const CStockWatchLogs & iLogs);

	void					InsertFirstTextAll(LPCTSTR iLogText);
#pragma endregion

#pragma region Operator Declaration
public:
	const CStockWatchLogs &	operator = (const CStockWatchLogs & iSWLogs);
	const CStockWatchLogs 	operator + (const CStockWatchLogs & iSWLogs);
	void					operator += (const CStockWatchLogs & iSWLogs);
	StockWatchTimerLog &	operator [] (const INT iIndex);
#pragma endregion

#pragma region Static Function
public:
#pragma endregion

#pragma region Memeber Variable
private:
	StockWatchTimerLogList	m_LogList;
#pragma endregion
};

	}
}