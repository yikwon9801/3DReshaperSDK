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
	}

	namespace Object
	{

		namespace Geometry
		{

			namespace Mesh
			{
				RsDEFINE_CLASS(CGFace);
				RsDEFINE_CLASS(CGPolyhedron);

				using namespace Kernel::File;
				using namespace Kernel::Math;
				using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGEdge) : RsINHERITANCE(CGeometryObject)
{
	friend class CGFace;
	friend class CGPolyhedron;
#pragma region Construction & Destruction
public:
	CGEdge();
	CGEdge(const INT v1, const INT v2);
	CGEdge(const INT v1, const INT v2, const INT f);
	CGEdge(const INT v1, const INT v2,const INT f1, const INT f2);
	CGEdge(const CGEdge & iEdge);
	virtual ~CGEdge();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const INT		GetVertexIndex1() const { return _vertexidx1; }
	inline const INT		GetVertexIndex2() const { return _vertexidx2; }
	inline const INT		GetFaceIndex1() const { return _faceidx1; }
	inline const INT		GetFaceIndex2() const { return _faceidx2; }
	inline const INT		GetFaceIndex(const INT iIndex) const { return m_FaceIndex[iIndex]; }
	inline void				First(const INT v1, const INT v2, const INT f) { _vertexidx1 = v1; _vertexidx2 = v2; _faceidx1 = f; _faceidx2 = -1;	}
	inline void				Second(const INT f) { ASSERT(_faceidx1 != -1); ASSERT(_faceidx2 == -1); _faceidx2 = f; }
	inline const BOOL		IsSatisfied() const { return _faceidx1 != -1 || _faceidx2 != -1; }
	inline const BOOL		IsOnBoarder() const { return (_faceidx1 != -1 && _faceidx2 == -1) || (_faceidx1 == -1 && _faceidx2 != -1); }
#pragma endregion
public:
	void					Init(const INT v1, const INT v2, const INT f1 = -1, const INT f2 = -1);

public:
	const BOOL				IsEqual(const CGEdge & iEdge) const;

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of CDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGEdge *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGEdge &			operator = (const CGEdge & iEdge);
	const BOOL				operator == (const CGEdge & iEdge) const;
	const BOOL				operator != (const CGEdge & iEdge) const;
	const UINT				operator [] (const INT nIndex) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	union {
		struct { INT _vertexidx1, _vertexidx2; };
		INT m_VertexIndex[2];
	};
	union {
		struct { INT _faceidx1, _faceidx2; };
		INT m_FaceIndex[2];
	};
#pragma endregion
};

			}
		}
	}
}