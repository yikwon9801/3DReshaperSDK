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

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Object
	{
		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;

			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGText) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGText();
	CGText(LPCTSTR iText);
	CGText(const CGText & rhs);
	virtual ~CGText();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CString	GetText() const { return m_Text; }
	inline const CMatrix3x4	GetMatrix() const { return m_Matrix; }
public:
	inline void				SetText(LPCTSTR iText) { m_Text = iText; }
#pragma endregion

#pragma region General Function
public:

protected:
	const BOOL				IsEqual(const CGText & iText) const;
#pragma endregion

#pragma region CAD Functions
public:
	void					ToPolygons(LPCTSTR iFontName, const UINT iFontSize, CGPolygons2D & oPolygon) const;
	void					ToPolygons(LPCTSTR iFontName, const UINT iFontSize, CGPolygons & oPolygon) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGText *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGText &			operator = (const CGText & iText);
	const CGText			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGText			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGText 			operator * (const CMatrix3x3 & iMatrix) const;
	const CGText 			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CGText & iText) const;
	const BOOL				operator != (const CGText & iText) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CString					m_Text;
	CMatrix3x4				m_Matrix;
#pragma endregion
};

		}
	}
}