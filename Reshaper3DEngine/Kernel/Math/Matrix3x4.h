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

			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CMath);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CEuler);
		RsDEFINE_CLASS(CQuaternion);

		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CMatrix3x4) : RsINHERITANCE(CMath)
{
	friend class CGPointDouble;
	friend class CGPolyhedron;
#pragma region Construction & Destruction
public:
	CMatrix3x4();
	CMatrix3x4(const CVector & iVector);
	CMatrix3x4(const CMatrix3x3 & iMatrix);
	CMatrix3x4(const CMatrix3x3 & iMatrix, const CVector & iVector);
	CMatrix3x4(const CMatrix3x4 & iMatrix);
	CMatrix3x4(const DOUBLE iMatrix[MATRIX_4X4]);
	virtual ~CMatrix3x4();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CMatrix3x3 &		GetMatrix3x3() const { return m_Matrix3x3; }
	inline const CVector &	GetVector() const { return m_Vector; }
	inline const CVector2D	GetVector2D() const { return m_Vector.To2D(); }
	inline void				Get(DOUBLE matrix3x3[], DOUBLE translate[]) const { m_Matrix3x3.Get(matrix3x3); m_Vector.Get(translate); }
public:
	const CVector			GetColumn(const UINT16 iColumn) const;
	void					SetColumn(const UINT16 iColumn, const CVector & iValue);
	void					SetTranslation(const CVector & iTranslation);
#pragma endregion

public:
	void					Init();
	void					GetMatrix(DOUBLE oMatrix[MATRIX_4X4]) const;
	const BOOL				IsIdentity() const;
protected:
	void					Init(const DOUBLE iMatrix[MATRIX_4X4]);

	const BOOL				IsEqual(const CMatrix3x4 & iMatrix) const;

#pragma region Mathematic
public:
	void					InitRotation(const CVector & iAxis, const DOUBLE iAngle);
	void					InitRotation(const CVector & iFixed, const CVector & iMoved);
	void					InitRotation(const CGPointDouble & iCenter, const CVector & iAxis, const DOUBLE iAngle);
	void					InitRotation(const CGPointDouble & iCenter, const CVector & iFixed, const CVector & iMoved);
	void					InitRotation(const DOUBLE iXAngle, const DOUBLE iYAngle, const DOUBLE iZAngle);
	void					InitRotation(const CEuler & iEuler);
	void					InitRotation(const CGPointDouble & iCenter, const DOUBLE iXAngle, const DOUBLE iYAngle, const DOUBLE iZAngle);
	void					InitRotation(const CGPointDouble & iCenter, const CEuler & iEuler);
	void					InitScale(const CGPointDouble & iPointToScale);
	void					InitScale(const CVector & iVectorToScale);
	void					InitScale(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	void					InitScale(const CGPointDouble & iCenter, const CGPointDouble & iPointToScale);
	void					InitScale(const CGPointDouble & iCenter, const CVector & iVectorToScale);
	void					InitScale(const CGPointDouble & iCenter, const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	void					InitTranslation(const CVector & iTranslation);

	void					Decompose(CVector & oScale, CQuaternion & oRotation, CVector & oTranslation);
	void					Invert();
	const DOUBLE			Determinant() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
private:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMatrix3x4 *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMatrix3x4 &		operator = (const CMatrix3x4 & iMatrix);
	const CMatrix3x4 &		operator = (const CMatrix3x3 & iMatrix);
	const CMatrix3x4 &		operator = (const CVector & iVector);
	const CMatrix3x4		operator + (const DOUBLE iValue) const;
	const CMatrix3x4		operator + (const CVector & iVector) const;
	const CMatrix3x4		operator + (const CMatrix3x3 & iMatrix) const;
	const CMatrix3x4		operator + (const CMatrix3x4 & iMatrix) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CVector & iVector);
	void					operator += (const CMatrix3x3 & iMatrix);
	void					operator += (const CMatrix3x4 & iMatrix);
	const CMatrix3x4		operator - () const;
	const CMatrix3x4		operator - (const DOUBLE iValue) const;
	const CMatrix3x4		operator - (const CVector & iVector) const;
	const CMatrix3x4		operator - (const CMatrix3x3 & iMatrix) const;
	const CMatrix3x4		operator - (const CMatrix3x4 & iMatrix) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CVector & iVector);
	void					operator -= (const CMatrix3x3 & iMatrix);
	void					operator -= (const CMatrix3x4 & iMatrix);
	const CMatrix3x4 		operator * (const CMatrix3x3 & iMatrix) const;
	const CMatrix3x4 		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CMatrix3x4 & iMatrix) const;
	const BOOL				operator != (const CMatrix3x4 & iMatrix) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CMatrix3x3				m_Matrix3x3;
	CVector					m_Vector;
#pragma endregion
};

	}
}