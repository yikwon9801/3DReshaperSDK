#pragma once

namespace Display
{
	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDTriangle) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDTriangle();
	CDTriangle(const CGTriangle & iTriangle);
	CDTriangle(const CDTriangle & rhs);
	virtual ~CDTriangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline const CGTriangle &	GetTriangle() const { return m_Triangle; }
public:
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
	inline void				SetTriangle(const CGTriangle & iTriangle) { m_Triangle = iTriangle; }
#pragma endregion

protected:
	const BOOL				IsEqual(const CDTriangle & iTriangle) const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_POINT,
		REP_FACE,
		REP_POINTANDFACE_WITHTEXT,
	}RepresentationType;
	virtual const INT		Display() const;
protected:
	const INT				DisplayLine() const;
	const INT				DisplayPoint() const;
	const INT				DisplayFace() const;
	const INT				DisplayPointAndFaceWithText() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDTriangle *	Clone() const;
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
	const CDTriangle &		operator = (const CDTriangle & iTriangle);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDTriangle & iTriangle) const;
	const BOOL				operator != (const CDTriangle & iTriangle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGTriangle				m_Triangle;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}