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

RsDEFINE_DLL_CLASS(CMultiThreadTimer) : RsINHERITANCE(CMultiThread)
{
#pragma region Type Definition
public:
#pragma endregion
#pragma region Construction & Destruction
public:
	CMultiThreadTimer();
	virtual ~CMultiThreadTimer();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

protected:

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}