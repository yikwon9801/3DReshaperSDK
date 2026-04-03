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
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x4);
		RsDEFINE_CLASS(CEuler);
		RsDEFINE_CLASS(CQuaternion);

		using namespace Kernel::File;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CMatrix3x3) : RsINHERITANCE(CMath)
{
	friend class CGPointDouble;
	friend class CMatrix3x4;
	friend class CQuaternion;
#pragma region Construction & Destruction
public:
	CMatrix3x3();
	CMatrix3x3(const CMatrix3x3 & rhs);
	CMatrix3x3(const DOUBLE R1[3], const DOUBLE R2[3], const DOUBLE R3[3]);
	CMatrix3x3(const DOUBLE matrix[3][3]);
	virtual ~CMatrix3x3();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetValue(const UINT iIndex1, const UINT iIndex2) const;
	inline void				Get(DOUBLE value[]) const {
		for (UINT ii = 0; ii < 3; ii++)
			for (UINT jj = 0; jj < 3; jj++)
				value[(ii * 3) + jj] = m_Matrix[ii][jj];
	}
public:
	inline void				SetValue(const UINT iIndex1, const UINT iIndex2, const DOUBLE iValue);
	void					SetAxis(const UINT16 iColumn, const CVector & iAxis);
	const CVector			GetRow(const UINT16 iRow) const;
	const CVector			GetAxis(const UINT16 iColumn) const;
#pragma endregion

public:
	void					Init(const DOUBLE M11, const DOUBLE M12, const DOUBLE M13, const DOUBLE M21, const DOUBLE M22, const DOUBLE M23, const DOUBLE M31, const DOUBLE M32, const DOUBLE M33);
	void					Init();
	void					Null();

public:
	const BOOL				IsIdentity() const;
	const BOOL				IsNull() const;
protected:
	const BOOL				IsEqual(const CMatrix3x3 & iMatrix) const;

#pragma region Mathematic
public:
	void					Identity();

	void					InitRotation(const CVector & iAxis, const DOUBLE iAngle);
	void					InitRotation(const CVector & iFixed, const CVector & iMoved);
	void					InitRotation2(const CVector & iFixed, const CVector & iMoved);
	void					InitRotation3(const CVector & iFixed, const CVector & iMoved);
	void					InitRotationXAxis(const DOUBLE iAngle);
	void					InitRotationYAxis(const DOUBLE iAngle);
	void					InitRotationZAxis(const DOUBLE iAngle);
	void					InitRotation(const DOUBLE iXAngle, const DOUBLE iYAngle, const DOUBLE iZAngle);
	void					InitRotation(const CEuler & iEuler);
	void					ToRotateCoordSys(const CMatrix3x3 & iMatrix);
	void					InitScale(const CGPointDouble & iPointToScale);
	void					InitScale(const CVector & iVectorToScale);
	void					InitScale(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	void					InitMirror(const CVector & iDirectionToMirror);

	void					Decompose(CVector & oScale, CQuaternion & oRotation);
	void					Decompose(CEuler & oRotation);
	void					Transpose();
	void					Invert();
	const DOUBLE			Determinant() const;
	const CQuaternion		ToQuaternion() const;

	void					OuterProduct(const CVector & iDirection);	// Compute outer product: n * n^T
#pragma endregion

#pragma region Abstract fuction of IDataObject
private:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMatrix3x3 *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMatrix3x3 &		operator = (const CMatrix3x3 & iMatrix);
	const CMatrix3x3		operator + (const DOUBLE iValue) const;
	const CMatrix3x3		operator + (const CMatrix3x3 & iMatrix) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CMatrix3x3 & iMatrix);
	const CMatrix3x3		operator - () const;
	const CMatrix3x3		operator - (const DOUBLE iValue) const;
	const CMatrix3x3		operator - (const CMatrix3x3 & iMatrix) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CMatrix3x3 & iMatrix);
	const CMatrix3x3		operator * (const DOUBLE iValue) const;
	const CMatrix3x3		operator * (const CMatrix3x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	const CMatrix3x3		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CMatrix3x3 & iMatrix) const;
	const BOOL				operator != (const CMatrix3x3 & iMatrix) const;
#pragma endregion

#pragma region Static fuction
public:
	static const CMatrix3x3	RotationMatarixByCoordinateSystem(const CMatrix3x3 & iA, const CMatrix3x3 & iB);
	static const CMatrix3x3	RotationMatarixByCoordinateSystem(const CVector & iAx, const CVector & iAy, const CVector & iAz, const CVector & iBx, const CVector & iBy, const CVector & iBz);
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Matrix[3][3];
#pragma endregion
};

	}
}