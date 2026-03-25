#pragma once

namespace Display
{

RsDEFINE_DLL_CLASS(CTexture) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CTexture();
	CTexture(Bitmap * iBitmap);
	CTexture(const INT iMinFilter, const INT iMagFilter, Bitmap * iBitmap);
	CTexture(const CTexture & iTexture);
	virtual ~CTexture();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline Bitmap *		GetBitmap() { return m_Bitmap; }
	inline const BOOL	IsPrepared() const { return m_TexutreId > 0; }
public:
	inline void			SetMinMagFilter(const INT iMinFilter, const INT iMagFilter);
#pragma endregion

protected:
	void				Release();
private:
	void				_Release();
	void				_ReleaseTexture();
	void				_ReleaseBitmap();

public:
	void				Bind();
	void				UnBind();

	void				ReBitmap(Bitmap * iBitmap);
protected:
	const UINT			MakeTexture();
	const BOOL			Prepare();

#pragma region Abstract fuction of IDataObject
public:
	virtual CTexture *	Clone() const;
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CTexture &	operator = (const CTexture & iTexture);
#pragma endregion

#pragma region Static Funtions
public:
	static BitmapData *	ExportBitmapData(Bitmap * ioBitmap);
#pragma endregion

#pragma region Memeber Variable
private:
	Bitmap *			m_Bitmap;
	UINT				m_TexutreId;

	INT					m_MinFilter;
	INT					m_MagFilter;
#pragma endregion
};

}