#pragma once

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
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
			using namespace Kernel::String;
			using namespace Kernel::File;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CQuadraticEquation) : RsINHERITANCE(CEquation)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CQuadraticEquation();
	CQuadraticEquation(const CQuadraticEquation & iEquation);
	virtual ~CQuadraticEquation();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void				Init(const DOUBLE iA, const DOUBLE iB, const DOUBLE iC) { _A = iA; _B = iB; _C = iC; }
public:
	void					Init(const CGPoint2DDouble & iP1, const CGPoint2DDouble & iP2, const CGPoint2DDouble & iP3);
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CQuadraticEquation & iEquation) const;
#pragma endregion

#pragma region Mathematic
public:
	const CGPoint2DDouble	GetVertex() const;
	const DOUBLE			Y(const DOUBLE iX) const;
	const DOUBLE			X(const DOUBLE iY, const BOOL iPositive = TRUE) const;
#pragma endregion

#pragma region Abstract fuction of IEquation
public:
	const CHyString			GetFormulaText() const;
	const DOUBLE			YValue(const DOUBLE iX) const { return Y(iX); }
	const DOUBLE			XValue(const DOUBLE iY) const { return X(iY); }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CQuadraticEquation *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CQuadraticEquation &		operator = (const CQuadraticEquation & iEquation);
	const BOOL				operator == (const CQuadraticEquation & iEquation) const;
	const BOOL				operator != (const CQuadraticEquation & iEquation) const;
#pragma endregion

#pragma region Static Function
public:
	static void				Formula(const DOUBLE iX1, const DOUBLE iY1, const DOUBLE iX2, const DOUBLE iY2, const DOUBLE iX3, const DOUBLE iY3, DOUBLE & oA, DOUBLE & oB, DOUBLE & oC);
#pragma endregion

#pragma region Memeber Variable
private:
	union {
		struct { DOUBLE _A, _B, _C; };
		DOUBLE _val[3];
	};
#pragma endregion
};
		}
	}
}