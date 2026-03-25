#pragma once

namespace Kernel
{
	namespace File
	{

RsDEFINE_DLL_CLASS(CMemoryStreamRead) : RsINHERITANCE(CMemoryStreamObject)
{
#pragma region Construction & Destruction
public:
	CMemoryStreamRead(BYTE iStreamBuffer[]);
	virtual ~CMemoryStreamRead();
#pragma endregion

#pragma region General Function
public:

#pragma endregion

#pragma region Operator Declaration
public:
	template <class _type> const INT operator >> (_type & iData)
	{
		return ReadByte((BYTE *)&iData, sizeof(_type));
	}
#pragma endregion
};

	}
}