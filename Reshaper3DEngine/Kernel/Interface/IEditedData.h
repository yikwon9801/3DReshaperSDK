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

RsINTERFACE(IEditedData)
{
public:
	virtual const BOOL		ExecuteEditedBeforeData(const CDataObject * iObjectToData, LPARAM lParam = NULL) = 0;
	virtual const BOOL		ExecuteEditedAfterData(const CDataObject * iObjectToData, LPARAM lParam = NULL) = 0;
};

	}
}