#pragma once

namespace Display
{

	namespace Interface
	{

RsINTERFACE(IDisplay)
{
public:
	virtual const INT		Display() const = 0;
};

	}
}