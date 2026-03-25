#pragma once

#include <list>
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

	namespace Position
	{
		namespace Window
		{
			RsDEFINE_CLASS(CWinPointDouble);
		}
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
			using namespace Kernel::Position::Window;

RsDEFINE_DLL_CLASS(CGMultiLine) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<CWinPointDouble>	_WinPointVector;
	typedef vector<CGPointDouble>	_PointVector;
	typedef vector<CGVertex>		_VertexVector;
	typedef list<CGVertex *>		_VertexList;
	typedef vector<CGMultiLine *>	_MultiLineVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGMultiLine();
	CGMultiLine(const _WinPointVector & iMultiLine);
	CGMultiLine(const _PointVector & iMultiLine);
	CGMultiLine(const vector<Coordinate2D> & iMultiLine);
	CGMultiLine(const CGMultiLine & rhs);
	virtual ~CGMultiLine();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGMultiLine::_VertexVector &	GetVertices() const	{ return m_Vertices; }
	inline CGMultiLine::_VertexVector &	Vertices() { return m_Vertices; }
	inline const UINT		GetCount() const { return (UINT)m_Vertices.size(); }
	
	const CGVertex &		GetVertex(const INT nIndex) const;

	const CGVertex &		First() const;
	const CGVertex &		Last() const;
public:
	inline void				SetVertices(const _VertexVector & iVertices)	{ m_Vertices = iVertices; }
	const BOOL				InsertLast(const CGPointDouble & Point);
	const BOOL				InsertLast(const CGPoint2DDouble & Point);
	const BOOL				InsertLast(const Coordinate2D & Point);
	const BOOL				InsertLast(const DOUBLE iX = 0., const DOUBLE iY = 0., const DOUBLE iZ = 0.);
	const BOOL				InsertLast(const CGPointInt & Point, const DOUBLE iScale = 1.);
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsExist(const INT nIndex) const;
	const BOOL				IsClosed() const;

	void					Get(CTableArray<CGVertex *> & oPoints);
protected:
	const BOOL				IsEqual(const CGMultiLine & iMultiLine) const;

public:
	void					RemoveAllPoints();
	void					Clear();
protected:
	void					Release();

public:
	void					Close();
	void					Open();

	const BOOL				ChangeFirstPoint(const UINT iIndex);

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const CGVertex *		GetClosest(const CGPointDouble & iPoint, INT * oIndex = NULL) const;
	const CGVertex *		Get2DClosest(const CGPointDouble & iPoint, INT * oIndex = NULL) const;

	const CGPointDouble		Project(const CGPointDouble & iPointToProject, const CVector * iDirection = NULL) const;
	void					ProjectOnPlane(const CVector & iDirection, const CGPointDouble & iCriteria);
	void					ProjectOnPlane(const CVector & iDirection);

	const INT				Reduce(const DOUBLE iMinLength);
	const INT				Reduce2(const DOUBLE iMinLength);
	const INT				Simplify(const DOUBLE iAngleToRemove = 0.);
	void					NudgeSharedPoint();

	void					Offset(const DOUBLE iOffsetDistance, const UINT16 iOption = 0);
	void					Intersect(const CGMultiLine & iMultiLine);

	CGPolyhedron *			Reconstruct2D(const UINT16 iType = 0) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGMultiLine *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	const BOOL				CopyFrom(const _WinPointVector & iMultiLine);
	const BOOL				CopyFrom(const _PointVector & iMultiLine);
	const BOOL				CopyFrom(const vector<Coordinate2D> & iMultiLine);
private:
	void					_CopyVertices(const CGMultiLine::_VertexVector & iVertices);
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
	const CGMultiLine &		operator = (const CGMultiLine & iMultiLine);
	const CGMultiLine &		operator = (const _WinPointVector & iMultiLine);
	const CGMultiLine &		operator = (const _PointVector & iMultiLine);
	const CGMultiLine &		operator = (const vector<Coordinate2D> & iMultiLine);
	const CGMultiLine		operator + (const CVector & iVector) const;
	const CGMultiLine		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector & iVector);
	void					operator += (const CVector2D & iVector);
	const CGMultiLine		operator - () const;
	const CGMultiLine		operator - (const CVector & iVector) const;
	const CGMultiLine		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector & iVector);
	void					operator -= (const CVector2D & iVector);
	const CGMultiLine		operator * (const DOUBLE iValue) const;
	const CGMultiLine		operator * (const CMatrix3x3 & iMatrix) const;
	const CGMultiLine		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGMultiLine		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGMultiLine & iMultiLine) const;
	const BOOL				operator != (const CGMultiLine & iMultiLine) const;
	CGVertex &				operator [] (const INT nIndex);
#pragma endregion

#pragma region Static fuction
public:
	static CGPolyhedron *	CreateMeshWithLines(const CTableArray<CGMultiLine *> & iLines, const CGPointDouble * iTopPoint = NULL, const CGPointDouble * iBottomPoint = NULL);
	static CGPolyhedron *	CreateMeshWithTwoLines(const CGMultiLine & iLine1, const CGMultiLine & iLine2); 
	static void				GetUpperLowerPoint(const _WinPointVector & iMultiLine, CPoint & oUpperPoint, CPoint & oLowerPoint);
	static const DOUBLE		Area(const _WinPointVector & iMultiLine);
#pragma endregion

#pragma region Memeber Variable
protected:
	_VertexVector			m_Vertices;
#pragma endregion
};

		}
	}
}