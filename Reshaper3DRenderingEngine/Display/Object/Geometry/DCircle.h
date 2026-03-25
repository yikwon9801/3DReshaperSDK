#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDCircle) : RsINHERITANCE(CDMultiLine)
{
#pragma region Construction & Destruction
public:
	CDCircle();
	CDCircle(const CGCircle & iCircle);
	CDCircle(const CDCircle & iCircle);
	virtual ~CDCircle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCircle &	GetCircle() const	{ return m_Circle; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
	inline void				SetCircle(const CGCircle & iCircle)	{ m_Circle = iCircle; SetMultiLine(iCircle); }
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
	}RepresentationType;

	virtual const INT		Display() const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CDCircle & iCircle) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCircle *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCircle &		operator = (const CDCircle & iCircle);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CDCircle & iCircle) const;
	const BOOL				operator != (const CDCircle & iCircle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGCircle				m_Circle;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}