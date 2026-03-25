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
				RsDEFINE_CLASS(CGEdge);
				RsDEFINE_CLASS(CGPolyhedron);

				using namespace Kernel::File;
				using namespace Kernel::Math;
				using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGFace) : RsINHERITANCE(CGeometryObject)
{
	friend class CGPolyhedron;
#pragma region Type Definition
public:
	typedef enum
	{
		FaceAttribute_None = 0x00,
		FaceAttribute_Select = 0x01,
	}FACEATTRIBUTE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGFace();
	CGFace(const UINT v1, const UINT v2, const UINT v3, const CVector & iNormal);
	CGFace(const CGFace & rhs);
	virtual ~CGFace();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CVector &	GetNormal() const { return m_Normal; }
	inline const UINT		GetIndexOfVertex(const UINT16 nIndex) const { ASSERT(nIndex < 3); return m_Indices[nIndex]; }
	inline void				GetEdge(const UINT16 nIndex, UINT16 & oFirst, UINT16 & oSecond) const { UINT16 nNextIndex = nIndex;	if (nIndex >= 2) nNextIndex = 0; else ++nNextIndex; oFirst = m_Indices[nIndex]; oSecond = m_Indices[nNextIndex]; }
	inline const INT		GetAdjacent(const UINT16 nIndex) const { ASSERT(nIndex < 3); return m_adjacent[nIndex]; }
	inline const UINT		GetAttribute() const { return m_Attribute; }

	inline void				Init(const UINT v1, const UINT v2, const UINT v3, const CVector & iNormal) { SetIndices(v1, v2, v3); SetNormal(iNormal); }
	inline void				SetIndices(const UINT v1, const UINT v2, const UINT v3) { m_Indices[0] = v1; m_Indices[1] = v2; m_Indices[2] = v3; }
	inline void				SetNormal(const CVector & iNormal) { m_Normal = iNormal; }
	inline void				SetNormal(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { m_Normal.SetCoordinate(iX, iY, iZ); }
	inline void				SetAdjacent(const UINT16 nIndex, INT iAdjacent) { m_adjacent[nIndex] = iAdjacent; }
	inline void				SetAttribute(const UINT16 iAttri) { m_Attribute = iAttri; }
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsValid() const { return m_Indices[0] != m_Indices[1] && m_Indices[1] != m_Indices[2] && m_Indices[2] != m_Indices[0]; }
	const BOOL				IsDuplicate(const CGFace & iFace) const;
	inline const BOOL		IsClosed() const { return !GetContourCount(); }
	inline const BOOL		ContainFace(const INT iFace) { return _adjacent1 == iFace || _adjacent2 == iFace || _adjacent3 == iFace; }

public:
	void					Invert();

	const BOOL				IsEqual(const CGFace & iFace) const;
	const BOOL				IsConnectableEdge(const INT iEdgeV1, const INT iEdgeV2) const;

	const UINT				GetContourCount() const;
#pragma endregion

#pragma region Abstract fuction of CDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGFace *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGFace &			operator = (const CGFace & iFace);
	const BOOL				operator == (const CGFace & iFace) const;
	const BOOL				operator != (const CGFace & iFace) const;
	const CGFace			operator * (const CMatrix3x3 & iMatrix) const;
	const CGFace			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const UINT				operator [] (const INT nIndex) const;
#pragma endregion

#pragma region Memeber Variable
private:
	union {
		struct { UINT _idx1, _idx2, _idx3; };
		UINT m_Indices[3];
	};
	CVector					m_Normal;
	union {
		struct { INT _adjacent1, _adjacent2, _adjacent3; };
		INT m_adjacent[3];
	};
	UINT16					m_Attribute;
#pragma endregion
};

			}
		}
	}
}