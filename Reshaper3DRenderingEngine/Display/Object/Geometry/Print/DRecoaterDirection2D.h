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

RsDEFINE_DLL_CLASS(CDRecoaterDirection) : RsINHERITANCE(CDArrow2D)
{
#pragma region Type Definition
public:
	typedef enum {
		AXIS_ONEWAY_XMIN,
		AXIS_ONEWAY_XMAX,
		AXIS_ONEWAY_YMIN,
		AXIS_ONEWAY_YMAX,
		AXIS_BOTHWAY_XMIN,
		AXIS_BOTHWAY_XMAX,
		AXIS_BOTHWAY_YMIN,
		AXIS_BOTHWAY_YMAX,
	}AXIS_WAY;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDRecoaterDirection();
	CDRecoaterDirection(const AXIS_WAY iWayType);
	CDRecoaterDirection(const CDRecoaterDirection & iDirection);
	virtual ~CDRecoaterDirection();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const COLORREF	GetTextColor() const { return m_TextColor; }
	inline const CGPoint2DDouble &	GetPosition() const { return m_Position; }
protected:
	const CVector2D			ToDirection(const AXIS_WAY iWayType) const;
	const BOOL				IsBoth(const AXIS_WAY iWayType) const;
public:
	inline void				SetPosition(const CGPoint2DDouble & iPosition) { m_Position = iPosition; }
public:
	void					SetText(LPCTSTR lpctStr);
	void					SetTextColor(const COLORREF iColor);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDRecoaterDirection & iArrow) const;

	const CGPoint2DDouble	GetPositionForText(const AXIS_WAY iWayType) const;

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
	virtual CDRecoaterDirection *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDRecoaterDirection &	operator = (const CDRecoaterDirection & iDirection);
	const BOOL				operator == (const CDRecoaterDirection & iDirection) const;
	const BOOL				operator != (const CDRecoaterDirection & iDirection) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CDText *				m_DText;
	COLORREF				m_TextColor;
	CGPoint2DDouble			m_Position;
	AXIS_WAY				m_Axis;	// x : 0, y : other
#pragma endregion
};

			}
		}
	}
}