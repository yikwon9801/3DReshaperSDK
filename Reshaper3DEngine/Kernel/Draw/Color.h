#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Draw
	{
		using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CColor) : RsIMPLEMENT(CDataObject)
{
#pragma region Construction & Destruction
public:
	CColor();
	CColor(const DWORD iColor);
	CColor(const CColor & iColor);
	virtual ~CColor();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DWORD		GetColor() const { return m_Color; }
protected:
	inline void				SetColor(const DWORD iColor) { m_Color = iColor; }
#pragma endregion

public:
	const COLORREF			ToRGB() const;
	void					ToFloat(FLOAT & oR, FLOAT & oG, FLOAT & oB) const;
protected:
	const BOOL				IsEqual(const CColor & iColor) const;

#pragma region Abstract fuction of IDataObject
public:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CColor *		Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CColor &			operator = (const CColor & iColor);
	const BOOL				operator == (const CColor & iColor) const;
	const BOOL				operator != (const CColor & iColor) const;
#pragma endregion

#pragma region Static Function
public:
	static const DWORD		ConvertTo(const BYTE R, const BYTE G, const BYTE B);
	static const COLORREF	ConvertTo(const DWORD iColor);
	static const DWORD		ConvertFromValue(const UINT iValue);
	static const UINT		ConvertToUINTFromRGB(const BYTE R, const BYTE G, const BYTE B);
	static const UINT		ConvertToUINTFromRGB(const BYTE iColor[]);
	static void				ConvertToFloatArrayFromUINT(const UINT iColor, FLOAT & R, FLOAT & G, FLOAT & B);
	static void				ConvertToFloatArrayFromUINT(const UINT iColor, FLOAT oColor[]);
	static void				ConvertToBYTEFromUINT(const UINT iColor, BYTE oColor[]);
	static const CColor		Random();
	static const CColor		Random(const UINT8 iMin, const UINT8 iMax);
#pragma endregion

#pragma region Memeber Variable
private:
	DWORD					m_Color;
#pragma endregion
};

	}
}