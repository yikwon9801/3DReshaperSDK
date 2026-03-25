#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDCylinder) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCylinder();
	CDCylinder(const CGCylinder & iCylinder);
	CDCylinder(const CDCylinder & iCylinder);
	virtual ~CDCylinder();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCylinder &	GetCylinder() const	{ return m_Cylinder; }
public:
	inline void				SetCylinder(const CGCylinder & iCylinder)	{ m_Cylinder = iCylinder; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CDCylinder & iCylinder) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetVolume() const;
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
	}RepresentationType;

	virtual const INT		Display() const;
	virtual const INT		DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
protected:
	const INT				DisplayStandard() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCylinder *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCylinder &		operator = (const CDCylinder & iCircle);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CDCylinder & iCircle) const;
	const BOOL				operator != (const CDCylinder & iCircle) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGCylinder				m_Cylinder;
#pragma endregion
};

		}
	}
}