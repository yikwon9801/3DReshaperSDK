#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Object
	{

		namespace Print
		{

			using namespace Kernel::File;

RsDEFINE_DLL_CLASS(CSlice) : RsINHERITANCE(CBaseObject), RsIMPLEMENT(IKeyObject)
{
#pragma region Type Definition
public:
	typedef enum {
		SMOOTHINGBITMAP_INTERPOLATION_NONE = 0,
		SMOOTHINGBITMAP_INTERPOLATION_X2,
		SMOOTHINGBITMAP_INTERPOLATION_X3,
		SMOOTHINGBITMAP_INTERPOLATION_X4,
		SMOOTHINGBITMAP_INTERPOLATION_X5,
		SMOOTHINGBITMAP_INTERPOLATION_X6,
	}SMOOTHINGBITMAP_INTERPOLATION;
#pragma endregion

#pragma region Construction & Destruction
public:
	CSlice(const LPCTSTR iName, const SMOOTHINGBITMAP_INTERPOLATION iInterpolation);
	CSlice(const CSlice & iSlice);
	virtual ~CSlice();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CString	GetName() const	{ return m_Name; }
	inline const SMOOTHINGBITMAP_INTERPOLATION	GetInterpolation() const	{ return m_Interpolation; }
public:
	inline void				SetName(const CString iName)	{ m_Name = iName; }
	inline void				SetInterpolation(const SMOOTHINGBITMAP_INTERPOLATION iInterpolation)	{ m_Interpolation = iInterpolation; }
	const UINT				GetScale() const;
#pragma endregion

#pragma region Abstract fuction of IKeyObject
public:
	virtual const CKeyString	MakeKey() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlice *		Clone() const;
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
	const CSlice &			operator = (const CSlice & iSlice);
#pragma endregion

#pragma region Memeber Variable
private:
	CString					m_Name;
	SMOOTHINGBITMAP_INTERPOLATION	m_Interpolation;
#pragma endregion
};

		}
	}
}