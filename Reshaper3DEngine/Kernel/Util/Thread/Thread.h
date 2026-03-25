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

RsDEFINE_DLL_CLASS(CThread)
{
#pragma region Type Definition
public:
	typedef UINT(*ThreadFunctionCall)(LPVOID lpVoid);
#pragma endregion
#pragma region Construction & Destruction
public:
	CThread(ThreadFunctionCall iCallFunc);
	virtual ~CThread();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void			SetParam(const CHealthCheck::Parameter iParam);
	inline const BOOL	IsRunning() const;
#pragma endregion

public:
	void				Run();
	void				Stop();
	void				StopForce();

#pragma region Memeber Variable
private:
	struct Internal;
	shared_ptr<Internal>	m_Internal;
#pragma endregion
};

		}
	}
}