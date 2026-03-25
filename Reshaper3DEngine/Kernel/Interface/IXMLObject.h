#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
	}

	namespace File
	{
		namespace XML
		{
			RsDEFINE_CLASS(CXmlDocument);
		}
	}

	namespace Interface
	{
		using namespace Kernel::String;
		using namespace Kernel::File::XML;

RsINTERFACE(IXMLObject)
{
public:
	virtual const BOOL			ReadXml()				= 0;
	virtual const BOOL			WriteXml()				= 0;
};

	}
}