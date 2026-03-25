#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPolygons2D);
		}
	}

	namespace Interface
	{
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsINTERFACE(IPatternObject)
{
public:
	virtual const INT			GetPolygons(CGPolygons2D & oPolygons) const	= 0;
};

	}
}