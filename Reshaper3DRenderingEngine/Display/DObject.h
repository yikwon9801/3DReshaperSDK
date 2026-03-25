#pragma once

#include "Interface/IDisplay.h"

namespace Display
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IDisplay);
	}

	using namespace Kernel::Collection::Object;
	using namespace Display::Interface;

RsDEFINE_DLL_CLASS(CDObject) : RsINHERITANCE(CManagedObject), RsIMPLEMENT(IDisplay)
{
#pragma region Construction & Destruction
protected:
	CDObject();
	CDObject(LPARAM lParam);
	virtual ~CDObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL	IsVisible() const { return m_Visible; }
	inline const BOOL	IsTransparency() const { return GetAlpha() < 255; }
	inline const COLORREF	GetColor() const { return m_Color; }
	inline const COLORREF	GetSelColor() const { return m_SelColor; }
	inline LPARAM		GetParam() { return m_lParam; }
	inline const UCHAR	GetRepres() const { return m_Repres; }
	inline const UCHAR	GetAlpha() const { return m_Alpha; }
public:
	inline void			SetAlpha(const UCHAR alpha) { m_Alpha = alpha; }
	inline void			SetVisible(const BOOL iVisible) { m_Visible = iVisible; }
	inline void			SetColor(const COLORREF iColor) { m_Color = iColor; }
	inline void			SetSelColor(const COLORREF iColor) { m_SelColor = iColor; }
	inline void			SetRepres(const UCHAR iRepres) { m_Repres = iRepres; }
	inline void			SetParam(LPARAM lParam) { m_lParam = lParam; }
#pragma endregion

#pragma region Image
public:
	static const INT	GetEncoderClsid(LPCTSTR iFormat, CLSID & oClsid);
	static CExtBitmap *	CaptureImage(const UINT iWidth, const UINT iHeight);
#pragma endregion

public:
	virtual void		Show();
	virtual void		Hide();

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file);
	virtual const INT	SaveBin(CFileWriteObject & file);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Memeber Variable
private:
	BOOL				m_Visible;
	COLORREF			m_Color;
	COLORREF			m_SelColor;
	UCHAR				m_Alpha;

	UCHAR				m_Repres;

	LPARAM				m_lParam;
#pragma endregion
};

}