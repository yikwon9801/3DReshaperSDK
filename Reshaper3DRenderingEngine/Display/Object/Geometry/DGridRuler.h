#pragma once

namespace Display
{
	namespace View
	{
		namespace Control
		{
			RsDEFINE_CLASS(CDText);
		}
	}

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDGridRuller) : RsINHERITANCE(CDMultiLines)
{
#pragma region Construction & Destruction
public:
	CDGridRuller();
	CDGridRuller(const CBoundingBox & iBoundingBox, const DOUBLE iBottomThickness = 0., const DOUBLE iLineSpacing = 10., const DOUBLE iTextSpacing = 20.);
	CDGridRuller(const CDGridRuller & iGrid);
	virtual ~CDGridRuller();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const COLORREF		GetTextColor() const { return m_TextColor; }
public:
	void						SetTextColor(const COLORREF iColor) { m_TextColor = iColor; }
public:
	virtual void				SetParam(LPARAM lParam);
#pragma endregion

public:
	void						Release();

	void						CreateText();

private:
	void						_Release();
	void						_ReleaseText();

private:
	void						_CreateGrid(const CBoundingBox & iDimension, const DOUBLE iBottomThickness, const DOUBLE iLineSpacing, const DOUBLE iTextSpacing);

public:
	virtual const CBoundingBox	GetBoundingBox() const;

#pragma region Display
public:
	typedef enum {
		REP_STANDARD ,
		REP_INCLUDETEXT,
	}RepresentationType;
protected:
	virtual const INT			Display() const;
protected:
	const INT					DisplayStarndard() const;
	const INT					DisplayIncludeText() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDGridRuller *		Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
private:
	void						_CopyText(const CTableArray<CDText *> & iTextArray);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDGridRuller &		operator = (const CDGridRuller & iGrid);
	void						operator += (const CVector & iVector);
	void						operator -= (const CVector & iVector);
	void						operator *= (const CMatrix3x3 & iMatrix);
	void						operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
	CTableArray<CDText *>		m_TextArray;
	COLORREF					m_TextColor;
#pragma endregion
};


		}
	}
}