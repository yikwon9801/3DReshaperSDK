#pragma once

#include <list>
using namespace std;

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDCombination) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCombination();
	CDCombination(const CDCombination & rhs);
	CDCombination(LPARAM lParam);
	virtual ~CDCombination();
#pragma endregion

#pragma region Setter & Getter function
#pragma endregion

#pragma region Child Components
public:
	const BOOL					AddChild(CDComponent3D * iComponent);
#pragma endregion

public:
	virtual const CBoundingBox	GetBoundingBox() const;

#pragma region Display
public:
	virtual const INT			Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDCombination *		Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCombination &		operator = (const CDCombination & iCombination);
	void						operator += (const CVector & iVector);
	void						operator -= (const CVector & iVector);
	void						operator *= (const CMatrix3x3 & iMatrix);
	void						operator *= (const CMatrix3x4 & iMatrix);
protected:

#pragma endregion

#pragma region Memeber Variable
private:
	CDGroup						m_Group;
#pragma endregion
};

		}
	}
}