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
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGVertex);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Collection;

RsDEFINE_DLL_CLASS(CGCloud) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCloud();
	CGCloud(const CGCloud & iCloud);
	virtual ~CGCloud();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetCount() const { return (UINT)m_Points.Size(); }
	inline const CTableArray<CGVertex> &	GetPoints() const { return m_Points; }
public:
	inline void				SetPoints(const CTableArray<CGVertex> & iPoints) { m_Points = iPoints; }
	inline void				SetPoints(const CTableList<CGVertex> & iPoints);
#pragma endregion

#pragma region General Function
public:
	void					Clear() { m_Points.Clear(); }

public:
	const DOUBLE			GetLongestDistance(const CGPointDouble & iCriteria, CGVertex * oLongestPoint = NULL);
	const CGPointDouble		GetLongestPoint(const CVector & iDirection, CGPointDouble * iCriteria = NULL) const;

	void					ProjectToPlane(const CVector & iDirection, const CGPointDouble & iCriteria);
protected:
	const BOOL				IsEqual(const CGCloud & iCloud) const;

public:
	const CGPointDouble		GetCeneroid() const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Function
public:
	const BOOL				ConvexHull(CGMultiLine & oConvexHull) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGCloud *		Clone() const;
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
	const CGCloud &			operator = (const CGCloud & iCloud);
	const CGCloud			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGCloud			operator - () const;
	const CGCloud			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGCloud			operator * (const DOUBLE iValue) const;
	const CGCloud			operator * (const CMatrix3x3 & iMatrix) const;
	const CGCloud			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGCloud			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCloud & iCloud) const;
	const BOOL				operator != (const CGCloud & iCloud) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		GetLongestDistance(const CTableArray<CGVertex> & iVertices, const CGVertex & iVertex, CGVertex * iLongestVertex = NULL);
#pragma endregion

#pragma region Memeber Variable
private:
	CTableArray<CGVertex>	m_Points;
#pragma endregion
};

		}
	}
}