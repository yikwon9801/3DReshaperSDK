#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDCube) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCube(const CGCube & iCube);
	CDCube(const CDCube & rhs);
	virtual ~CDCube();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCube &	GetCube() const	{ return m_Cube; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
#pragma endregion

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

protected:
	const BOOL				IsEqual(const CDCube & iCube) const;

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
	virtual CDCube *			Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCube &			operator = (const CDCube & iCube);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDCube & iCube) const;
	const BOOL				operator != (const CDCube & iCube) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGCube					m_Cube;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}