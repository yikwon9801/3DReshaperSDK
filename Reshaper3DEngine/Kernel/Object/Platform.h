#pragma once

namespace Kernel
{

	namespace Object
	{

RsDEFINE_DLL_CLASS(CPlatform) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CPlatform(const CDimension & iDimension);
	CPlatform(const CPlatform & iPlatform);
	virtual ~CPlatform();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CDimension &	GetDimension() const { return m_Dimension; }
public:
	inline void				SetDimension(const CDimension & iDimension) { m_Dimension = iDimension; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CPlatform & iPlatform) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPlatform *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CPlatform &		operator = (const CPlatform & iPlatform);
	const BOOL				operator == (const CPlatform & iPlatform) const;
	const BOOL				operator != (const CPlatform & iPlatform) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CDimension				m_Dimension;
#pragma endregion
};

	}
}