#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDPedestal) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDPedestal(const CGPolyhedron * iPolyhedron);
	CDPedestal(const CDPedestal & iPedestal);
	virtual ~CDPedestal();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPedestal *	GetPedestal() const { return m_Pedestal; }
public:
	void				SetPedestal(const CGPolyhedron * iPolyhedron, const UINT16 iType);
	void				SetPolyhedron(const CGPolyhedron * iPolyhedron);
	void				SetType(const UINT16 iType);
#pragma endregion

#pragma region General Function
public:
	void				Release();
protected:
	void				ReleasePedestal();
private:
	void				_Release();

public:
	void				CreatePedestal(const CGPolyhedron * iPolyhedron);
	const BOOL			CreateShape(); 

protected:
	const BOOL			IsEqual(const CDPedestal & iPedestal) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Function
public:
	const DOUBLE		GetVolume() const;
#pragma endregion

#pragma region Display
public:
	virtual const INT	Display() const;
	virtual const INT	DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDPedestal *	Clone() const;
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDPedestal &	operator = (const CDPedestal & iPedestal);
	void				operator += (const CVector & iVector);
	void				operator -= (const CVector & iVector);
	void				operator += (const CVector2D & iVector);
	void				operator -= (const CVector2D & iVector);
	const BOOL			operator == (const CDPedestal & iPedestal) const;
	const BOOL			operator != (const CDPedestal & iPedestal) const;
#pragma endregion

#pragma region Memeber Variable
private:
	struct Internal;
	auto_ptr<Internal>	m_Internal;
private:
	CGPedestal *		m_Pedestal;
	CGPolyhedron *		m_Polyhedron;
#pragma endregion
};

		}
	}
}