#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDRectangle) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDRectangle();
	CDRectangle(const CGRectangle & iRectangle);
	CDRectangle(const CDRectangle & rhs);
	virtual ~CDRectangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline const CGRectangle &	GetRectangle() const { return m_Rectangle; }
public:
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
	inline void				SetRectangle(const CGRectangle & iRectangle) { m_Rectangle = iRectangle; }
#pragma endregion

protected:
	const BOOL				IsEqual(const CDRectangle & iRectangle) const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_FACE,
	}RepresentationType;
	virtual const INT		Display() const;
protected:
	const INT				DisplayLine() const;
	const INT				DisplayFace() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDRectangle *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

public:
	const CBoundingBox		GetBoundingBox() const { return m_Rectangle.GetBoundingBox(); }

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDRectangle &		operator = (const CDRectangle & iRectangle);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDRectangle & iRectangle) const;
	const BOOL				operator != (const CDRectangle & iRectangle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGRectangle				m_Rectangle;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}