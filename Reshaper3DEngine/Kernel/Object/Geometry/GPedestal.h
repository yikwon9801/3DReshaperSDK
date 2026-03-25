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
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CGPedestal) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	enum { TYPE_RECTANGLE, TYPE_CIRCLE, TYPE_ELLIPSE, TYPE_BOTTOMOUTLINE, TYPE_SILHOUETTE };
#pragma endregion

#pragma region Construction & Destruction
public:
	CGPedestal(const CGPolyhedron & iPolyhedron, const UINT16 iType, const DOUBLE iHeight = 1., const DOUBLE iGroundZ = 0., const DOUBLE iOffset = 0.);
	CGPedestal(const CGPedestal & iPedestal);
	virtual ~CGPedestal();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolyhedron &	GetPolyhedron() const { return m_Polyhedron; }
	inline const UINT16	GetType() const { return m_Type; }
	inline const DOUBLE GetHeight() const { return m_Height; }
	inline const DOUBLE GetGroundZ() const { return m_GroundZ; }
	inline const DOUBLE	GetOffset() const { return m_Offset; }
public:
	inline void			SetType(const UINT16 iType) { m_Type = iType; }
	inline void			SetGroundZ(const DOUBLE iGroundZ) { m_GroundZ = iGroundZ; }
	inline void			SetOffset(const DOUBLE iOffset) { m_Offset = iOffset; }
#pragma endregion

protected:
	const BOOL			IsEqual(const CGPedestal & iPedestal) const;

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void		Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGPedestal *	Clone() const;
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPedestal &	operator = (const CGPedestal & iPedestal);
	const BOOL			operator == (const CGPedestal & iPedestal) const;
	const BOOL			operator != (const CGPedestal & iPedestal) const;
#pragma endregion

#pragma region Memeber Variable
private:
	const CGPolyhedron &	m_Polyhedron;
	UINT16				m_Type;
	DOUBLE				m_Height;
	DOUBLE				m_GroundZ;
	DOUBLE				m_Offset;
#pragma endregion
};

		}
	}
}