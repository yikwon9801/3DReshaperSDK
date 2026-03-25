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

RsDEFINE_DLL_CLASS(CDGrid) : RsINHERITANCE(CDComponent2D)
{
#pragma region Construction & Destruction
protected:
	CDGrid();
	virtual ~CDGrid();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetOrigin() const { return m_Origin; }
	inline const DOUBLE			GetLineWidth() const { return m_LineWidth; }
	inline const DOUBLE			GetWidth() const { return m_Width; }
	inline const DOUBLE			GetHeight() const { return m_Height; }
	inline const DOUBLE			GetLineSpacing() const { return m_LineSpacing; }
public:
	inline void					SetOrigin(const CGPointDouble & iOrigin) { m_Origin = iOrigin; }
	inline void					SetLineWidth(const DOUBLE iWidth) { m_LineWidth = iWidth; }
	inline void					SetSize(const DOUBLE iWidth, const DOUBLE iHeight) { m_Width = iWidth; m_Height = iHeight; }
	inline void					SetWidth(const DOUBLE iWidth) { m_Width = iWidth; }
	inline void					SetHeight(const DOUBLE iHeight) { m_Height = iHeight; }
	inline void					SetLineSpacing(const DOUBLE iLineSpacing) { m_LineSpacing = iLineSpacing; }
#pragma endregion

#pragma region Display
public:
	typedef enum {
		REP_STANDARD ,
	}RepresentationType;
public:
	virtual const INT			Display() const;
//protected:
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
	const CDGrid &				operator = (const CDGrid & iGrid);
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE						m_LineWidth;
	DOUBLE						m_Width, m_Height;
	DOUBLE						m_LineSpacing;
	CGPoint2DDouble				m_Origin;
#pragma endregion
};


		}
	}
}