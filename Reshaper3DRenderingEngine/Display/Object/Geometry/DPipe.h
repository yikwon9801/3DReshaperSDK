#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDPipe) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDPipe();
	CDPipe(const CGPipe & iPipe);
	CDPipe(const CDPipe & iPipe);
	virtual ~CDPipe();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPipe &	GetPipe() const { return m_Pipe; }
public:
	inline void				SetCylinder(const CGPipe & iPipe) { m_Pipe = iPipe; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CDPipe & iPipe) const;

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
	virtual CDPipe *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDPipe &			operator = (const CDPipe & iPipe);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CDPipe & iPipe) const;
	const BOOL				operator != (const CDPipe & iPipe) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGPipe					m_Pipe;
#pragma endregion
};

		}
	}
}