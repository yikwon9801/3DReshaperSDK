#pragma once

#include <list>
using namespace std;

namespace Display
{

	namespace Object
	{
		
		namespace Geometry
		{

			namespace Mesh
			{
			}

			using namespace Display::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CDGroup) : RsINHERITANCE(CDComponent)
{
	friend class CDComponent;

public:
	typedef list<CDComponent *>	_ComponentList;

#pragma region Construction & Destruction
public:
	CDGroup();
	CDGroup(const CDGroup & iGroup);
	virtual ~CDGroup();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline _ComponentList	GetComponents() const { return m_CompList; }
	inline const UINT		GetCount() const { return (UINT)m_CompList.size(); }
private:
	inline const BOOL		IsAllowDeleteObject() const { return m_bAllowDeleteObjects; }
public:
	inline void				SetAllowDeleteObject(const BOOL bSet = TRUE);
private:
	void					_CopyComponent(const _ComponentList & iCompList);
#pragma endregion

public:
	void					Release();
	void					DeleteAll();

	virtual const CBoundingBox 	GetBoundingBox() const;
	const CBoundingBox		GetBoundingBoxForVisibleComponent() const;

public:
	const BOOL				Contain(CDComponent * iComponent) const;

	const BOOL				AddComponent(CDComponent * iComponent);
	const BOOL				DeleteComponent(CDComponent * iComponent);
	const BOOL				RemoveComponent(const CDComponent * iComponent);

#pragma region Display
public:
	void					HideComponent();
	void					ShowComponent();
public:
	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDGroup *		Clone() const;
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
	const CDGroup &			operator = (const CDGroup & iGroup);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
protected:
	_ComponentList			m_CompList;
private:
	BOOL					m_bAllowDeleteObjects;
#pragma endregion
};

		}
	}
}