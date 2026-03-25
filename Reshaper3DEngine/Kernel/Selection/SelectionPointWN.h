#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGMultiLine2D);
			RsDEFINE_CLASS(CGMultiLine);
		}
	}

	namespace Selection
	{
		using namespace Kernel::Object::Geometry;
		
RsDEFINE_DLL_CLASS(CSelectionPointWN) : RsINHERITANCE(CSelectionPoint)
{
#pragma region Construction & Destruction
public:
	CSelectionPointWN(const CTableArray<CGVertex> & iVertices);
	CSelectionPointWN(const CSelectionPointWN & iSelectionPoint);
	virtual ~CSelectionPointWN();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual CSelectionPointWN *	Clone() const;
#pragma endregion

private:
	virtual const BOOL	_IsInLine(const CGPoint2DDouble & iPointToTest, const CGMultiLine2D & iMultiLineToSelect) const;

#pragma region Operator Declaration
public:
	const CSelectionPointWN &	operator = (const CSelectionPointWN & iSelectionPoint);
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