#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGVertex2D);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Collection;

RsDEFINE_DLL_CLASS(CGCloud2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCloud2D();
	CGCloud2D(const CGCloud2D & iCloud);
	virtual ~CGCloud2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetCount() const { return (UINT)m_Points.Size(); }
	inline const CTableArray<CGVertex2D> &	GetPoints() const { return m_Points; }
	inline CTableArray<CGVertex2D> &	Points() { return m_Points; }
public:
	inline void				SetPoints(const CTableArray<CGVertex2D> & iPoints) { m_Points = iPoints; }
	inline void				SetPoints(const CTableList<CGVertex2D> & iPoints);
#pragma endregion

#pragma region General Function
public:
	void					Clear() { m_Points.Clear(); }

public:
	const DOUBLE			GetLongestDistance(const CGPoint2DDouble & iCriteria, CGVertex2D * oLongestPoint = NULL);
	const CGPoint2DDouble	GetLongestPoint(const CVector2D & iDirection, CGPoint2DDouble * iCriteria = NULL) const;

protected:
	const BOOL				IsEqual(const CGCloud2D & iCloud) const;

public:
	const CGPoint2DDouble		GetCeneroid() const;

public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Function
public:
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGCloud2D *		Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
private:
	const INT				ReadVertices(CFileReadObject & file, CProgress * iProgress);
	const INT				SaveVertices(CFileWriteObject & file, CProgress * iProgress);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCloud2D &		operator = (const CGCloud2D & iCloud);
	const CGCloud2D			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGCloud2D			operator - () const;
	const CGCloud2D			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGCloud2D			operator * (const DOUBLE iValue) const;
	const CGCloud2D			operator * (const CMatrix2x2 & iMatrix) const;
	const CGCloud2D			operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGCloud2D			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCloud2D & iCloud) const;
	const BOOL				operator != (const CGCloud2D & iCloud) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		GetLongestDistance(const CTableArray<CGVertex2D> & iVertices, const CGVertex2D & iVertex, CGVertex2D * iLongestVertex = NULL);
#pragma endregion

#pragma region Memeber Variable
private:
	CTableArray<CGVertex2D>	m_Points;
#pragma endregion
};

		}
	}
}