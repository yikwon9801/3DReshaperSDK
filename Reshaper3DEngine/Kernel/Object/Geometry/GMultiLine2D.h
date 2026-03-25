#pragma once

#include <vector>
using namespace std;

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
			RsDEFINE_CLASS(CGMultiLine);

			using namespace Kernel::File;
			using namespace Kernel::Collection;
			using namespace Kernel::Math;
			using namespace Kernel::Util;


RsDEFINE_DLL_CLASS(CGMultiLine2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<CGVertex2D>		_Vertex2DVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGMultiLine2D();
	CGMultiLine2D(const CGMultiLine2D & iMultiLine);
	CGMultiLine2D(const CGMultiLine & iMultiLine);
	virtual ~CGMultiLine2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGMultiLine2D::_Vertex2DVector &	GetVertices() const	{ return m_Vertices; }
	
	const CGVertex2D &		GetVertex(const INT nIndex) const;

	const CGVertex2D &		First() const;
	const CGVertex2D &		Last() const;
public:
	inline void				SetVertices(const _Vertex2DVector & iVertices)	{ m_Vertices = iVertices; }
	const BOOL				InsertLast(const CGPointDouble & Point);
	const BOOL				InsertLast(const CGPoint2DDouble & Point);
#pragma endregion

public:
	const UINT				GetCount() const;
	const BOOL				IsExist(const INT nIndex) const;
	const BOOL				IsClosed() const;

	void					Get(CTableArray<CGVertex2D *> & oPoints);
protected:
	const BOOL				IsEqual(const CGMultiLine2D & iMultiLine) const;

public:
	void					RemoveAllPoints();
	void					Clear();
protected:
	void					Release();

public:
	void					Close();
	void					Open();

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGMultiLine2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const CGMultiLine & iMultiLine);
private:
	void					_CopyVertices(const CGMultiLine2D::_Vertex2DVector & iVertices);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
protected:
	const INT				ReadPoints(CFileReadObject & file);
	const INT				SavePoints(CFileWriteObject & file);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGMultiLine2D &	operator = (const CGMultiLine2D & iMultiLine);
	const CGMultiLine2D &	operator = (const CGMultiLine & iMultiLine);
	const CGMultiLine2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGMultiLine2D		operator - () const;
	const CGMultiLine2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGMultiLine2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGMultiLine2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGMultiLine2D & iMultiLine) const;
	const BOOL				operator != (const CGMultiLine2D & iMultiLine) const;
	CGVertex2D &			operator [] (const INT nIndex);
#pragma endregion

#pragma region Static fuction
public:
	static CGPolyhedron *	CreateMeshWithLines(const CTableArray<CGMultiLine *> & iLines, const CGPointDouble * iTopPoint = NULL, const CGPointDouble * iBottomPoint = NULL);
#pragma endregion

#pragma region Memeber Variable
protected:
	_Vertex2DVector			m_Vertices;
#pragma endregion
};

		}
	}
}