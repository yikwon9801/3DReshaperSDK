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
			using namespace Display::View::Control;

RsDEFINE_DLL_CLASS(CDArrow2D) : RsINHERITANCE(CDComponent2D)
{
#pragma region Construction & Destruction
public:
	CDArrow2D();
	CDArrow2D(const CVector2D & iDirection);
	CDArrow2D(const CDArrow2D & iArrow);
	virtual ~CDArrow2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CVector2D &	GetDirection() const { return m_Direction; }
	inline const DOUBLE		GetLength() const { return m_Length; }
	inline const DOUBLE		GetWidth() const { return m_Width; }
	inline const CGPoint2DDouble &	GetOrigin() const { return m_Origin; }
	inline const BOOL		IsBoth() const { return m_Both; }
public:
	inline void				SetDirection(const CVector2D & iDirection) { m_Direction = iDirection; }
	inline void				SetLength(const DOUBLE iLength) { m_Length = iLength; }
	inline void				SetWidth(const DOUBLE iWidth) { m_Width = iWidth; }
	inline void				SetOrigin(const CGPoint2DDouble & iOrigin) { m_Origin = iOrigin; }
	inline void				SetBoth(const BOOL iBoth) { m_Both = iBoth; }
	inline void				SetBoundaryColor(const UINT iColor) { m_BoundaryColor = iColor; }
#pragma endregion

protected:
	const BOOL				IsEqual(const CDArrow2D & iArrow) const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_FACE,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayStandard() const;
	const INT				DisplayFace() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDArrow2D *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDArrow2D &		operator = (const CDArrow2D & iArrow);
	const BOOL				operator == (const CDArrow2D & iArrow) const;
	const BOOL				operator != (const CDArrow2D & iArrow) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CVector2D				m_Direction;
	DOUBLE					m_Length, m_Width;
	BOOL					m_Both;
	CGPoint2DDouble			m_Origin;
	COLORREF				m_BoundaryColor;
#pragma endregion
};

		}
	}
}