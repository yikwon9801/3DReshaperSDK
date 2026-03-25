#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDHexahedron) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDHexahedron();
	CDHexahedron(const CGHexahedron & iHexahedron);
	CDHexahedron(const CDHexahedron & iHexahedron);
	virtual ~CDHexahedron();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void				SetHexahedron(const CGHexahedron & iHexahedron) { m_Hexahedron = iHexahedron; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CDHexahedron & iHexahedron) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Function
public:
	const DOUBLE			GetVolume() const;
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_LINE,
		REP_STANDARDWITHLINE,
		REP_FACE,
	}RepresentationType;
	virtual const INT		Display() const;
	virtual const INT		DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
protected:
	const INT				DisplayStandard() const;
	const INT				DisplayLine() const;
	const INT				DisplayStandardWithLine() const;
	const INT				DisplayFace() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDHexahedron *	Clone() const;
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
	const CDHexahedron &	operator = (const CDHexahedron & iHexahedron);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDHexahedron & iHexahedron) const;
	const BOOL				operator != (const CDHexahedron & iHexahedron) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGHexahedron			m_Hexahedron;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}