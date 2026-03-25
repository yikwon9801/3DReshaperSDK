#pragma once

namespace Display
{

	namespace Interface
	{

RsINTERFACE(ISelectComponent)
{
public:
	virtual const INT		Select(const CPoint & iPosition) const = 0;
protected:
	virtual const INT		OnSelect(const UINT iColorPicker) const = 0;
};

	}
}