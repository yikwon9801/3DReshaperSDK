#pragma once

namespace Display
{
	namespace Object
	{

RsDEFINE_DLL_CLASS(CDMaterial) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CDMaterial();
	CDMaterial(const CDMaterial & rhs);
	virtual ~CDMaterial();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const FLOAT	GetAmbiant() const { return m_MatAmbiant; }
	inline const FLOAT	GetDiffuse() const { return m_MatDiffuse; }
	inline const FLOAT	GetSpecular() const { return m_MatSpecular; }
	inline const FLOAT	GetShininess() const { return m_MatShininess; }
	inline const FLOAT	GetEmission() const { return m_MatEmission; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDMaterial *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDMaterial &	operator = (const CDMaterial & iMaterial);
#pragma endregion

#pragma region Memeber Variable
private:
	FLOAT				m_MatAmbiant;
	FLOAT				m_MatDiffuse;
	FLOAT				m_MatSpecular;
	FLOAT				m_MatShininess;
	FLOAT				m_MatEmission;
#pragma endregion
};

	}
}