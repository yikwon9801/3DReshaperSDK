#pragma once

namespace Display
{

	namespace Object
	{

RsDEFINE_DLL_CLASS(CDBoundingBox) : RsINHERITANCE(CDComponent3D)
{
#pragma region Type Definition
public:
	typedef enum {
		DT_RULERALIGN_TOPLEFT,
		DT_RULERALIGN_TOPRIGHT,
		DT_RULERALIGN_BOTTOMLEFT,
		DT_RULERALIGN_BOTTOMRIGHT,
	}DtRulerAlign;
	typedef enum {
		ShowOrHideText_XCENTER			= 0x0001,
		ShowOrHideText_YCENTER			= 0x0002,
		ShowOrHideText_ZCENTER			= 0x0004,
		ShowOrHideText_ZLOWER			= 0x0008,
		ShowOrHideText_3AXIS_CENTER		= ShowOrHideText_XCENTER | ShowOrHideText_YCENTER | ShowOrHideText_ZCENTER,
	}ShowOrHideText;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDBoundingBox(const CBoundingBox & iBoundingBox);
	CDBoundingBox(const CDBoundingBox & iBoundingBox);
protected:
	CDBoundingBox();
public:
	virtual ~CDBoundingBox();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CBoundingBox &	GetBounding() const	{ return m_BoundingBox; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline const DtRulerAlign	GetRulerLocation() const { return m_RulerLocation; }
	inline const BOOL		IsCheckZAxis() const { return m_CheckZAxis; }
	inline const DOUBLE		GetCriteriaForCheckZAxis() const { return m_CriteriaZBottom; }
public:
	inline void				SetBounding(const CBoundingBox & iBoundingBox) { m_BoundingBox = iBoundingBox; }
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
	inline void				SetGapRuler(const DOUBLE iGap) { m_GapForRuler = iGap; }
	inline void				SetRulerLocation(const DtRulerAlign iLocation) { m_RulerLocation = iLocation; }
	inline void				SetShowHideText(const UINT iShow) { m_TextShowHide = iShow; }
	inline void				SetCheckZAxis(const BOOL iCheck, const DOUBLE iCriteria) { m_CheckZAxis = iCheck;	m_CriteriaZBottom = iCriteria; }
protected:
	inline const UINT		GetFactor() const { return m_Factor; }
public:
	void					SetStipple(const UINT iFactor, const USHORT iPattern);
#pragma endregion

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

protected:
	const BOOL				IsEqual(const CDBoundingBox & iBoundingBox) const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_FACE,
		REP_RULER,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayLine() const;
	const INT				DisplayFace() const;
	const INT				DisplayRuler() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDBoundingBox *	Clone() const;
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
	const CDBoundingBox &	operator = (const CDBoundingBox & iBoundingBox);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDBoundingBox & iBoundingBox) const;
	const BOOL				operator != (const CDBoundingBox & iBoundingBox) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CBoundingBox			m_BoundingBox;
	DOUBLE					m_LineWidth;
	DOUBLE					m_GapForRuler;
	DtRulerAlign			m_RulerLocation;
	UINT					m_TextShowHide;
	BOOL					m_CheckZAxis;
	DOUBLE					m_CriteriaZBottom;

	USHORT					m_Pattern;
	UINT					m_Factor;
#pragma endregion
};

	}
}