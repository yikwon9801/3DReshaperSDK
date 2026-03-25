#pragma once

namespace Kernel
{
	namespace Collection
	{
		template<typename _DataType> class CTableList;
	}

	namespace Util
	{

		namespace Thread
		{
			using namespace Kernel::Collection;

RsDEFINE_DLL_CLASS(CMultiThread)
{
#pragma region Type Definition
public:
	enum {
		RESULT_MULTITHREAD_SUCCESS = 0,
		RESULT_MULTITHREAD_USERSTOP,




		RESULT_MULTITHREAD_LASTNUMBER,
	};
#pragma endregion
#pragma region Construction & Destruction
public:
	CMultiThread(const UINT iTimeForBlocking);
	virtual ~CMultiThread();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

public:
	const INT			Run(const UINT iNumberOfThreads, const BOOL iBlocking = TRUE);
	const INT			Stop();
protected:
	const BOOL &		IsStop() const;
protected:
	virtual const INT	OnRun(const UINT iThreadId);

public:
	const BOOL			IsFinished() const;
	const INT			GetResult(const UINT iThreadId) const;
	void				WaitingForFinishing(const UINT iWaitTime) const;

#pragma region Memeber Variable
private:
	struct Internal;
	shared_ptr<Internal>	m_Internal;
#pragma endregion
};

		}
	}
}