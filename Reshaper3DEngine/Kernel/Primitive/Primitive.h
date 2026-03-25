#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_CLASS(IPrimitive);
	}

	namespace Primitive
	{
		using namespace Kernel::Interface;

RsDEFINE_DLL_CLASS(CPrimitive) : RsIMPLEMENT(IPrimitive)
{
#pragma region Construction & Destruction
protected:
	CPrimitive();
	CPrimitive(const CPrimitive & iPrimitive);
	virtual ~CPrimitive();
#pragma endregion

#pragma region Setter & Getter function
#pragma endregion

#pragma region Abstract fuction of IPrimitive
protected:
	virtual const BOOL		CopyFrom(const CPrimitive & iObjToCopy);
private:
	virtual CPrimitive *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
protected:
	const CPrimitive &		operator = (const CPrimitive & iPrimitive);
#pragma endregion

#pragma region Static fuction
#pragma endregion

#pragma region Memeber Variable
#pragma endregion
};



	}
}