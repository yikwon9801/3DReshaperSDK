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

			namespace Print
			{

				using namespace Display::View::Control;

RsDEFINE_DLL_CLASS(CDGasFlowDirection) : RsINHERITANCE(CDArrow2D)
{
#pragma region Type Definition
public:
	typedef enum
	{
		DISPLAY_SIDE_RIGHT	,
	}DISPLAY_SIDE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDGasFlowDirection();
	CDGasFlowDirection(const CDGasFlowDirection & iDirection);
	virtual ~CDGasFlowDirection();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const COLORREF	GetTextColor() const { return m_TextColor; }
	inline const CBoundingBox2D &	GetField() const { return m_Field; }
	inline const DOUBLE		GetAngle() const { return m_Angle; }
	inline const UINT		GetNumberOfArrows() const { return m_NumberOfArrows; }
	inline const DISPLAY_SIDE	GetDisplaySide() const { return m_Side; }
public:
	inline void				SetField(const CBoundingBox2D & iField) { m_Field = iField; }
	inline void				SetAngle(const DOUBLE iAngle) { m_Angle = iAngle; }
public:
	void					SetText(LPCTSTR lpctStr);
	void					SetTextColor(const COLORREF iColor);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDGasFlowDirection & iDirection) const;

private:
	void					_ReleaseText();

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
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDGasFlowDirection *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDGasFlowDirection &	operator = (const CDGasFlowDirection & iDirection);
	const BOOL				operator == (const CDGasFlowDirection & iDirection) const;
	const BOOL				operator != (const CDGasFlowDirection & iDirection) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CDText *				m_DText;
	COLORREF				m_TextColor;
	CBoundingBox2D			m_Field;
	DOUBLE					m_Angle;
	const UINT				m_NumberOfArrows;
	DISPLAY_SIDE			m_Side;
#pragma endregion
};

			}
		}
	}
}