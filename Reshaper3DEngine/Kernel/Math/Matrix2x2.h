#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x3);

		using namespace Kernel::File;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CMatrix2x2) : RsINHERITANCE(CMath)
{
	friend class CGPoint2DDouble;
	friend class CVector2D;
	friend class CMatrix2x3;
#pragma region Construction & Destruction
public:
	CMatrix2x2();
	CMatrix2x2(const CMatrix2x2 & iMatrix);
	CMatrix2x2(const DOUBLE R1[2], const DOUBLE R2[2]);
	CMatrix2x2(const DOUBLE matrix[2][2]);
	virtual ~CMatrix2x2();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetValue(const UINT iIndex1, const UINT iIndex2) const;
	inline void				Get(DOUBLE value[]) const {
		for (UINT ii = 0; ii < 2; ii++)
			for (UINT jj = 0; jj < 2; jj++)
				value[(ii * 2) + jj] = m_Matrix[ii][jj];
	}
public:
	inline void				SetValue(const UINT iIndex1, const UINT iIndex2, const DOUBLE iValue);
	void					SetValue(const DOUBLE iMatrix11, const DOUBLE iMatrix12, const DOUBLE iMatrix21, const DOUBLE iMatrix22);
	void					SetAxis(const UINT16 iColumn, const CVector2D & iAxis);
	const CVector2D			GetRow(const UINT16 iRow) const;
	const CVector2D			GetAxis(const UINT16 iColumn) const;

	void					SetValue(LPCTSTR iString, LPCTSTR iDelimiter);
#pragma endregion

public:
	void					Init(const DOUBLE iMatrix11, const DOUBLE iMatrix12, const DOUBLE iMatrix21, const DOUBLE iMatrix22);
	void					Init();
	void					Null();

public:
	const BOOL				IsIdentity() const;
	const BOOL				IsNull() const;
protected:
	const BOOL				IsEqual(const CMatrix2x2 & iMatrix) const;

#pragma region Mathematic
public:
	void					Identity();

	void					InitRotation(const DOUBLE iAngle);
	void					InitRotation(const CVector2D & iFixed, const CVector2D & iMoved);
	void					InitScale(const CGPoint2DDouble & iPointToScale);
	void					InitScale(const CVector2D & iVectorToScale);
	void					InitScale(const DOUBLE iX, const DOUBLE iY);

	void					Decompose(CVector2D & oScale, CMatrix2x2 & oRotation);
	void					Transpose();
	void					Invert();
	void					Adjoint();
	const DOUBLE			Determinant() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
private:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMatrix2x2 *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMatrix2x2 &		operator = (const CMatrix2x2 & iMatrix);
	const CMatrix2x2		operator + (const DOUBLE iValue) const;
	const CMatrix2x2		operator + (const CMatrix2x2 & iMatrix) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CMatrix2x2 & iMatrix);
	const CMatrix2x2		operator - () const;
	const CMatrix2x2		operator - (const DOUBLE iValue) const;
	const CMatrix2x2		operator - (const CMatrix2x2 & iMatrix) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CMatrix2x2 & iMatrix);
	const CMatrix2x2		operator * (const DOUBLE iValue) const;
	const CMatrix2x2		operator * (const CMatrix2x2 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	const CMatrix2x2		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CMatrix2x2 & iMatrix) const;
	const BOOL				operator != (const CMatrix2x2 & iMatrix) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Matrix[2][2];
#pragma endregion
};

	}
}