#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
	}

	namespace Interface
	{
		using namespace Kernel::String;

RsINTERFACE(IINIObject)
{
public:
	virtual const BOOL			ReadIni()				= 0;
	virtual const BOOL			WriteIni(BOOL bCreate = FALSE)	= 0;
};

	}
}