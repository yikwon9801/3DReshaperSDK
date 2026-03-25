#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Interface
	{
		using namespace Kernel::Object;

RsINTERFACE(IDataObject)
{
public:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy) = 0;
	virtual CDataObject *	Clone() const = 0;
};

	}
}