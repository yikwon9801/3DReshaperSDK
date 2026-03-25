#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IEquation);
	}

	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Math
	{
		namespace Equation
		{
			using namespace Kernel::Interface;
			using namespace Kernel::File;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CEquation) : RsINHERITANCE(CMath), RsIMPLEMENT(IEquation)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
protected:
	CEquation();
	virtual ~CEquation();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CEquation & iEquation) const;
#pragma endregion

#pragma region Mathematic
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
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
	const CEquation &		operator = (const CEquation & iEquation);
	const BOOL				operator == (const CEquation & iEquation) const;
	const BOOL				operator != (const CEquation & iEquation) const;
#pragma endregion

#pragma region Static Function
public:
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};
		}
	}
}