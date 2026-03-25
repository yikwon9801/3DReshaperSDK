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

RsDEFINE_DLL_CLASS(CDMultiLine) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDMultiLine();
	CDMultiLine(const CDMultiLine & iMultiLine);
	CDMultiLine(const CGMultiLine & iLine);
	virtual ~CDMultiLine();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGMultiLine &	GetMultiLine() const	{ return m_MultiLine; }
	inline const DOUBLE		GetLineWidth() const	{ return m_LineWidth; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const COLORREF	GetTextColor() const	{ return m_TextColor; }
public:
	inline void				SetMultiLine(const CGMultiLine & iMultiLine) { m_MultiLine = iMultiLine; }
	inline void				SetLineWidth(const DOUBLE width)	{ m_LineWidth = width; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
protected:
	inline const UINT		GetFactor() const { return m_Factor; }
protected:
	inline void				SetMultiLine(const CGCircle & iCircle)	{ iCircle.ToMultiLine(m_MultiLine); }
public:
	void					SetText(LPCTSTR lpctStr);
	void					SetTextColor(const COLORREF iColor);
	void					SetStipple(const UINT iFactor, const USHORT iPattern);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDMultiLine & iMultiLine) const;

private:
	void					_ReleaseText();

#pragma region Fuction of CDComponent
public:
	virtual const BOOL		IsSelected(CDComponentSelect & ioComponentSelect) const;
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_POINTS,
		REP_MULTILINEWITHPOINTS,
		REP_STANDARDINCLUDETEXT,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	virtual const INT		DisplayLines() const;
	virtual const INT		DisplayPoints() const;
	virtual const INT		DisplayLinesWithPoints() const;
	virtual const INT		DisplayStandardIncludeText() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDMultiLine *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDMultiLine &		operator = (const CDMultiLine & iMultiLine);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDMultiLine & iMultiLine) const;
	const BOOL				operator != (const CDMultiLine & iMultiLine) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGMultiLine				m_MultiLine;
	DOUBLE					m_LineWidth;
	DOUBLE					m_PointSize;
	USHORT					m_Pattern;
	UINT					m_Factor;
	CDText *				m_DText;
	COLORREF				m_TextColor;
#pragma endregion
};

		}
	}
}