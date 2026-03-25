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

RsDEFINE_DLL_CLASS(CDGridDeepenExtand) : RsINHERITANCE(CDGrid)
{
#pragma region Construction & Destruction
public:
	CDGridDeepenExtand();
	virtual ~CDGridDeepenExtand();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void					SetRepres(const UCHAR iRepres) { CDGrid::SetRepres(iRepres); m_DeepenExtandGrid.SetRepres(iRepres); }
	inline void					SetOrigin(const CGPointDouble & iOrigin) { CDGrid::SetOrigin(iOrigin);	m_DeepenExtandGrid.SetOrigin(iOrigin); }
	inline void					SetSize(const DOUBLE iWidth, const DOUBLE iHeight) { CDGrid::SetSize(iWidth, iHeight); m_DeepenExtandGrid.SetSize(iWidth, iHeight); }
	inline void					SetWidth(const DOUBLE iWidth) { CDGrid::SetWidth(iWidth); m_DeepenExtandGrid.SetWidth(iWidth); }
	inline void					SetHeight(const DOUBLE iHeight) { CDGrid::SetHeight(iHeight); m_DeepenExtandGrid.SetHeight(iHeight); }
	inline void					SetDeepenExtandColor(const COLORREF iColor) { m_DeepenExtandGrid.SetColor(iColor); }
	inline void					SetDeepenExtandLineWidth(const DOUBLE iWidth) { m_DeepenExtandGrid.SetLineWidth(iWidth); }
	inline void					SetDeepenExtandLineSpacing(const DOUBLE iLineSpacing) { m_DeepenExtandGrid.SetLineSpacing(iLineSpacing); }
	inline void					SetDeepenExtandVisible(const BOOL iVisible) { m_DeepenExtandGrid.SetVisible(iVisible); }
#pragma endregion

#pragma region Display
public:
	typedef enum {
		REP_STANDARD ,
	}RepresentationType;
protected:
	virtual const INT			Display() const;
protected:
	const INT					DisplayStarndard() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDGrid *			Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDGridDeepenExtand &	operator = (const CDGridDeepenExtand & iGrid);
#pragma endregion

#pragma region Memeber Variable
private:
	CDGrid						m_DeepenExtandGrid;
#pragma endregion
};


		}
	}
}