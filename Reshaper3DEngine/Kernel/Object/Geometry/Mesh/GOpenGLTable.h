#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CUtil);
	}
	namespace Collection
	{
		template<typename _DataType> class CTableArray;
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGVertex);

			namespace Mesh
			{
				using namespace Kernel;
				using namespace Kernel::Object::Geometry;
				using namespace Kernel::Collection;
				using namespace Kernel::Draw;
				using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGOpenGLTable)
{
#pragma region Type Definition
public:
	typedef enum
	{
		GENDATATYPE_VERTICES						= 0x0001 ,
		GENDATATYPE_NORMALS							= 0x0002 ,
		GENDATATYPE_COLORS							= 0x0004 ,
		GENDATATYPE_COLORIDS						= 0x0008 ,
		GENDATATYPE_TEXTURE							= 0x0010 ,
		GENDATATYPE_INDICES							= 0x0020 ,
		GENDATATYPE_RENDERVERTEXNORMAL				= GENDATATYPE_VERTICES | GENDATATYPE_NORMALS ,
		GENDATATYPE_RENDERVERTEXCOLOR				= GENDATATYPE_VERTICES | GENDATATYPE_COLORS,
		GENDATATYPE_RENDERVERTEXCOLORID				= GENDATATYPE_VERTICES | GENDATATYPE_COLORIDS,
		GENDATATYPE_RENDERVERTEXTEXTURE				= GENDATATYPE_VERTICES | GENDATATYPE_TEXTURE,
		GENDATATYPE_RENDERVERTEXNORMALCOLOR			= GENDATATYPE_RENDERVERTEXNORMAL | GENDATATYPE_COLORS ,
		GENDATATYPE_RENDERVERTEXNORMALCOLORID		= GENDATATYPE_RENDERVERTEXNORMAL | GENDATATYPE_COLORIDS,
		GENDATATYPE_RENDERVERTEXNORMALINDEX			= GENDATATYPE_RENDERVERTEXNORMAL | GENDATATYPE_INDICES ,
		GENDATATYPE_RENDERVERTEXNORMALCOLORINDEX	= GENDATATYPE_RENDERVERTEXNORMALCOLOR | GENDATATYPE_INDICES ,
	}GenDataType;
	typedef enum
	{
		INTERNALDATATYPE_TABLEPOINTER, 
		INTERNALDATATYPE_STDVECTORPOINTER,
	}InternalDataType;
	typedef enum
	{
		DrawColor_None,
		DrawColor_TwoColor_SelectOrNonSelectFace,
	}DRAWCOLOR;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGOpenGLTable(const CTableArray<CGVertex> & vertices, const CTableArray<CGPoint2DDouble> & textures, const GenDataType iType);
	CGOpenGLTable(const CTableArray<CGVertex *> & vertices, const GenDataType iType);
	CGOpenGLTable(const CTableArray<CGVertex> & vertices, const GenDataType iType);
	CGOpenGLTable(const vector<Coordinate2D> & vertices, const GenDataType iType);
	CGOpenGLTable(const CTableArray<CGVertex> & vertices, const CTableArray<CGFace> & face, const DRAWCOLOR iDrawColor, const GenDataType iType, const BOOL iUseNormalOfVertex = FALSE);
	virtual ~CGOpenGLTable();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline FLOAT *		Vertices() { return m_Vertices.m_Data; }
	inline FLOAT *		Normals() { return m_Normals.m_Data; }
	inline BYTE *		Colors() { return m_Colors.m_Data; }
	inline BYTE *		ColorIds() { return m_ColorIds.m_Data; }
	inline FLOAT *		Texcoords() { return m_Textures.m_Data; }
	inline UINT *		Indices() { return m_Indices.m_Data; }
	inline const UINT	GetVertexCount() const { return m_Vertices.m_Count; }
	inline const UINT	GetNormalCount() const { return m_Normals.m_Count; }
	inline const UINT	GetColorCount() const { return m_Colors.m_Count; }
	inline const UINT	GetColorIdCount() const { return m_ColorIds.m_Count; }
	inline const UINT	GetTexcoordCount() const { return m_Textures.m_Count; }
	inline const UINT	GetIndexCount() const { return m_Indices.m_Count; }
	inline const BOOL	IsGenDataType(const GenDataType iType) const { return CUtil::IsType(m_GenDataType, iType); }
	inline const UINT16	GetDrawColor() const { return m_DrawColor; }
	inline const BOOL	IsDrawColor(const DRAWCOLOR iDrawColor) const { return m_DrawColor == iDrawColor; }
	inline const UINT	GetSelectedStartPosition() const { return m_nSelectedStartPosition; }
#pragma endregion

public:
	void				Release();
	void				Init();

	void				GetData(FLOAT vertices[], FLOAT normals[], UINT indices[], BYTE colorids[], FLOAT textures[], UINT * oSelectedStartPosition = NULL, const BOOL iUseNormalOfVertex = FALSE) const;

protected:
	void				ReleaseInternalData();
	void				GenerateTableVertexData();
	void				CreateBufferData(const UINT iVertexCount, const UINT iFaceCount, const UINT iTextureCount);
	void				PutInternalDatas(const CTableArray<CGVertex *> * iTableVertices, const CTableArray<CGFace *> * iTableFaces, const CTableArray<CGPoint2DDouble *> * iTableTextures, const BOOL iUseNormalOfVertex = FALSE);

#pragma region Memeber Variable
private:
	template <class _type> struct _InternalDataType
	{
		_type *	m_Data;
		UINT m_Count;
	};
	_InternalDataType<FLOAT>	m_Vertices;
	_InternalDataType<FLOAT>	m_Normals;
	_InternalDataType<BYTE>		m_Colors;
	_InternalDataType<BYTE>		m_ColorIds;
	_InternalDataType<FLOAT>	m_Textures;
	_InternalDataType<UINT>		m_Indices;

	GenDataType			m_GenDataType;
	DRAWCOLOR			m_DrawColor;
	UINT				m_nSelectedStartPosition;
private:
	union {
		struct {
			CTableArray<CGVertex *> *			m_TableVertices;
			CTableArray<CGFace *> *				m_TableFaces;
			CTableArray<CGPoint2DDouble *> *	m_TableTexture;
		};
		struct {
			vector<Coordinate2D *> *			m_VectorCoordinate2D;
			void *								m_Padding1;
			void *								m_Padding2;
		};
	};
	InternalDataType	m_InternalDataType;
#pragma endregion
};

			}
		}
	}
}