#pragma once

namespace Kernel
{
	namespace Collection
	{
		template<typename _DataType> class CTableList;
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);

		namespace Thread
		{
			using namespace Kernel::Collection;

RsDEFINE_DLL_CLASS(CHealthCheck)
{
#pragma region Type Definition
public:
	typedef CTableList<VOID *>	Parameter;
public:
#pragma region Type Definition
public:
#pragma endregion
#pragma region Construction & Destruction
public:
	CHealthCheck();
	virtual ~CHealthCheck();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL	IsClose() const { return m_bClose; }
	inline const Parameter &	GetParam() const { return m_Param; }
	inline void			SetProgress(CProgress * iProgress) { m_Progress = iProgress; }
public:
	void				Open();
	void				Close();
	inline void			SetParam(const Parameter & iParam) { m_Param = iParam; }
#pragma endregion


#pragma region Memeber Variable
private:
	BOOL				m_bClose;
	Parameter			m_Param;
	CProgress *			m_Progress;
#pragma endregion
};

		}
	}
}