#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Primitive
	{
		RsDEFINE_CLASS(CPrimitive);
	}

	namespace Interface
	{
		using namespace Kernel::Primitive;

RsINTERFACE(IPrimitive)
{
public:
	virtual const BOOL		CopyFrom(const CPrimitive & iObjToCopy) = 0;
	virtual CPrimitive *	Clone() const = 0;
};

	}
}