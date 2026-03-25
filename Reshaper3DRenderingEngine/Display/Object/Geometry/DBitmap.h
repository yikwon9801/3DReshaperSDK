#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDBitmap) : RsINHERITANCE(CDRectangle)
{
#pragma region Construction & Destruction
public:
	CDBitmap(const BOOL iTransparentBG = FALSE);
	CDBitmap(const CGRectangle & iRectangle, Bitmap * iBitmap, const BOOL iTransparentBG = FALSE);
	CDBitmap(const CDBitmap & iBitmap);
	virtual ~CDBitmap();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL		IsTransparent() const { return m_bTransparentBG; }
#pragma endregion

#pragma region General Function
public:
	void					Release();
	void					Clear();
private:
	void					_Release();
	void					_ReleaseTexture();

public:
	void					Reset(const CGRectangle & iRectangle, Bitmap * iBitmap);
	void					ReBitmap(const CGRectangle & iRectangle, Bitmap * iBitmap);

protected:
	const BOOL				IsEqual(const CDBitmap & iBitmap) const;

private:
	void					_BlackToAlpha(Bitmap * ioBitmap) const;
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
	}RepresentationType;
	virtual const INT		Display() const;
protected:
	const INT				DisplayStandard() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDBitmap *		Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDBitmap &		operator = (const CDBitmap & iBitmap);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDBitmap & iBitmap) const;
	const BOOL				operator != (const CDBitmap & iBitmap) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CTexture *				m_Texture;
	BOOL					m_bTransparentBG;
#pragma endregion
};

		}
	}
}