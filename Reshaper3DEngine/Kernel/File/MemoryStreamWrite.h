#pragma once

#include "HyDataTagType.h"

namespace Kernel
{
	namespace File
	{

RsDEFINE_DLL_CLASS(CMemoryStreamWrite) : RsINHERITANCE(CMemoryStreamObject)
{
#pragma region Construction & Destruction
public:
	CMemoryStreamWrite(BYTE iStreamBuffer[]);
	virtual ~CMemoryStreamWrite();
#pragma endregion

#pragma region Operator Declaration
public:
	template <class _type> const INT operator << (const _type iData)
	{
		return WriteByte((BYTE *)&iData, sizeof(_type));
	}
#pragma endregion
};

	}
}