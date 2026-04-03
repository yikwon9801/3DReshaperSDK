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

			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CMath);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CVector2D);

		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CMatrix2x3) : RsINHERITANCE(CMath)
{
	friend class CGPoint2DDouble;
	friend class CVector2D;
	friend class CGPolyhedron;
#pragma region Construction & Destruction
public:
	CMatrix2x3();
	CMatrix2x3(const CVector2D & iVector);
	CMatrix2x3(const CMatrix2x2 & iMatrix);
	CMatrix2x3(const CMatrix2x2 & iMatrix, const CVector2D & iVector);
	CMatrix2x3(const CMatrix2x3 & iMatrix);
	CMatrix2x3(const DOUBLE iMatrix[MATRIX_3X3]);
	virtual ~CMatrix2x3();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CMatrix2x2 &	GetMatrix2x2() const { return m_Matrix2x2; }
	inline const CVector2D &	GetVector() const { return m_Vector; }
	inline void				Get(DOUBLE matrix2x2[], DOUBLE translate[]) const { m_Matrix2x2.Get(matrix2x2); m_Vector.Get(translate); }
public:
	void					SetColumn(const UINT16 iColumn, const CVector2D & iValue);
	void					SetTranslation(const CVector2D & iTranslation);
#pragma endregion

public:
	void					Init();
	void					GetMatrix(DOUBLE oMatrix[MATRIX_3X3]) const;
	const BOOL				IsIdentity() const;
protected:
	void					Init(const DOUBLE iMatrix[MATRIX_3X3]);

	const BOOL				IsEqual(const CMatrix2x3 & iMatrix) const;

#pragma region Mathematic
public:
	void					InitTranslation(const CVector2D & iTranslation);
	void					InitRotation(const DOUBLE iAngle);
	void					InitRotation(const CVector2D & iFixed, const CVector2D & iMoved);
	void					InitRotation(const CGPoint2DDouble & iCenter, const DOUBLE iAngle);
	void					InitRotation(const CGPoint2DDouble & iCenter, const CVector2D & iFixed, const CVector2D & iMoved);
	void					InitScale(const CVector2D & iVectorToScale);
	void					InitScale(const DOUBLE iX, const DOUBLE iY);
	void					InitScale(const CGPoint2DDouble & iCenter, const CVector2D & iVectorToScale);
	void					InitScale(const CGPoint2DDouble & iCenter, const DOUBLE iX, const DOUBLE iY);

	void					Invert();
	const DOUBLE			Determinant() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
private:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMatrix2x3 *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMatrix2x3 &		operator = (const CMatrix2x3 & iMatrix);
	const CMatrix2x3 &		operator = (const CMatrix2x2 & iMatrix);
	const CMatrix2x3 &		operator = (const CVector2D & iVector);
	const CMatrix2x3		operator + (const DOUBLE iValue) const;
	const CMatrix2x3		operator + (const CVector2D & iVector) const;
	const CMatrix2x3		operator + (const CMatrix2x2 & iMatrix) const;
	const CMatrix2x3		operator + (const CMatrix2x3 & iMatrix) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CVector2D & iVector);
	void					operator += (const CMatrix2x2 & iMatrix);
	void					operator += (const CMatrix2x3 & iMatrix);
	const CMatrix2x3		operator - () const;
	const CMatrix2x3		operator - (const DOUBLE iValue) const;
	const CMatrix2x3		operator - (const CVector2D & iVector) const;
	const CMatrix2x3		operator - (const CMatrix2x2 & iMatrix) const;
	const CMatrix2x3		operator - (const CMatrix2x3 & iMatrix) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CMatrix2x2 & iMatrix);
	void					operator -= (const CMatrix2x3 & iMatrix);
	const CMatrix2x3 		operator * (const CMatrix2x2 & iMatrix) const;
	const CMatrix2x3 		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const BOOL				operator == (const CMatrix2x3 & iMatrix) const;
	const BOOL				operator != (const CMatrix2x3 & iMatrix) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CMatrix2x2				m_Matrix2x2;
	CVector2D				m_Vector;
#pragma endregion
};

	}
}