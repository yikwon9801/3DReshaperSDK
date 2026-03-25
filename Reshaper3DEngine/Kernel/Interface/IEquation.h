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

RsINTERFACE(IEquation)
{
public:
	virtual const CHyString		GetFormulaText() const = 0;
public:
	virtual const DOUBLE		YValue(const DOUBLE iX) const = 0;
	virtual const DOUBLE		XValue(const DOUBLE iY) const = 0;
};

	}
}