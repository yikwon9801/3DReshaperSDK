#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Device
	{
	}

	namespace Interface
	{
		using namespace Kernel::Device;

RsINTERFACE(IDeviceObject)
{
public:
	virtual const INT			Attach() = 0;
	virtual const INT			Detach() = 0;
	virtual const BOOL			IsReady() const = 0;
};

	}
}