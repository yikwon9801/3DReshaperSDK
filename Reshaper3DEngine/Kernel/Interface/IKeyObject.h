#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CKeyString);
	}

	namespace Interface
	{

		using namespace Kernel::String;

#define		KEY_DELIMETER		_T("~@")
#define		EMPTY_KEY			_T("empty")

RsINTERFACE(IKeyObject)
{
public:
	virtual const CKeyString	MakeKey() const		= 0;
};

	}
}