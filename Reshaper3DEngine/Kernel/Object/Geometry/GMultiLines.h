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

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
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
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			using namespace Kernel::File;
			using namespace Kernel::Collection;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CGMultiLines) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<CGMultiLine *>	_MultiLineVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGMultiLines();
	CGMultiLines(const _MultiLineVector & iMultiLines, const BOOL iClone = TRUE);
	CGMultiLines(const CTableList<CGMultiLine *> & iMultiLines, const BOOL iClone = TRUE);
	CGMultiLines(const CGMultiLines & iMultiLines);
	virtual ~CGMultiLines();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGMultiLines::_MultiLineVector	&	GetMutiLines() const { return m_MultiLines; }
#pragma endregion

#pragma region General Function
public:
	const UINT				GetPointCount() const;
	const UINT				GetLineCount() const;
	const BOOL				IsClosed() const;

protected:
	void					Release();
	void					ReleaseMultiLines();
public:
	void					Clear();

	void					AddMultiLines(const _MultiLineVector & iMultiLines, const BOOL iClone = TRUE);
	void					AddMultiLines(const CTableList<CGMultiLine *> & iMultiLines, const BOOL iClone = TRUE);
	void					AddMultiLine(CGMultiLine * iMultiLine, const BOOL iClone = TRUE);

	const CTableList<CGMultiLine *>	Take();
	const CGMultiLines::_MultiLineVector	Take2();
	void					Put(CTableArray<CGMultiLines *> & ioTableMultiLines);

	void					Get(CTableArray<CGVertex *> & oPoints, CTableArray<UINT> * iSeperator = NULL);
	void					Get(CTableArray<CTableArray<CGVertex *>> & oPointLists);

	void					Close();
	void					Open();

protected:
	const BOOL				IsEqual(const CGMultiLines & iMultiLines) const;
#pragma endregion

#pragma region CAD Functions
public:
	const INT				Reduce(const DOUBLE iMinLength);
	const INT				Reduce2(const DOUBLE iMinLength);
	const INT				Simplify();
	void					NudgeSharedPoint();

	void					UnionAndOffset(const DOUBLE iOffsetDistance = 0, const UINT16 iOption = 0);
	void					Union();
	void					Intersect(const CGMultiLines & iMultiLines);
	void					Difference(const CGMultiLines & iMultiLines);
	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption = 0);

	CGPolyhedron *			Reconstruct2D() const;
	CGPolyhedron *			Reconstruct2D(const DOUBLE iHeight) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGMultiLines *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
private:
	void					_CopyMultiLines(const _MultiLineVector & iMultiLines);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGMultiLines &	operator = (const CGMultiLines & iMultiLines);
	const CGMultiLines		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGMultiLines		operator - () const;
	const CGMultiLines		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGMultiLines		operator * (const DOUBLE iValue) const;
	const CGMultiLines		operator * (const CMatrix3x3 & iMatrix) const;
	const CGMultiLines		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGMultiLines		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGMultiLines & iMultiLines) const;
	const BOOL				operator != (const CGMultiLines & iMultiLines) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	_MultiLineVector		m_MultiLines;
#pragma endregion
};

		}
	}
}