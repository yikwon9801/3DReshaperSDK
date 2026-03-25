#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

			namespace Mesh
			{
				RsDEFINE_CLASS(CDOpenGLDisplay);
				RsDEFINE_CLASS(CDOpenGLDataList);
				RsDEFINE_CLASS(CDOpenGLTable);

				using namespace Kernel::Object::Geometry;

#define DECLARE_GLOBALCHECKVARIABLE(classname)				\
	RsDEFINE_DLL_CLASS(classname){							\
	public:													\
	classname();											\
	~classname();	};

	DECLARE_GLOBALCHECKVARIABLE(CColorPickingInstance)
	DECLARE_GLOBALCHECKVARIABLE(CColorPickingForSelectionInstance)

#define BEGIN_COLORPICKINGMODE()	{	CColorPickingInstance mode;
#define BEGIN_COLORPICKINGMODEFORSELECT()	{	CColorPickingForSelectionInstance mode;
#define END_COLORPICKINGMODE()		}

RsDEFINE_DLL_CLASS(CDPolyhedron) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDPolyhedron();
	CDPolyhedron(CGPolyhedron * iPolyhedron);
	CDPolyhedron(const CDPolyhedron & rhs);
	virtual ~CDPolyhedron();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolyhedron *	GetPolyhedron() const {	return m_Polyhedron; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	void					SetPolyhedron(CGPolyhedron * iPolyhedron);
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) {	m_LineWidth = iLineWidth; }
#pragma endregion

#pragma region CAD Function
public:
	const DOUBLE			GetVolume() const {	return m_Polyhedron ? m_Polyhedron->GetVolume() : 0.; }
#pragma endregion

#pragma region Selection
public:
	const UINT				SelectFacesInLine(const CVector & iDirection, const CGMultiLine & iMultiLine, const BOOL iDeselectAll = FALSE) const;
	void					DeselectFaces();
	void					DeselectVertices();
#pragma endregion

#pragma region General Function
public:
	void					Release();
private:
	void					_ReleasePolyhedron();
	void					_ReleaseOpenGLTable();

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

	void					CalculateBoundingBox(CBoundingBox & oBoundingBox, const CMatrix3x4 & iMatrix) const;
#pragma endregion

#pragma region GPU Memory
public:
	typedef enum	{
		DataTypeInMem_DataList,
		DataTypeInMem_VBO,
	}DataTypeInMemForDraw;
	void					SetDataTypeInMemForDraw(const DataTypeInMemForDraw iDrawMode);
private:
	const CDPolyhedron::DataTypeInMemForDraw	_GetDataTypeInMemForDraw() const;
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

#pragma region Display
public:
	void					ReCreateOpenGLTable();
private:
	void					_RefreshOpenGLTable(const UINT nRefreshType);
public:
	typedef enum	{
		REP_STANDARD,
		REP_POINT,
		REP_FLAT,
		REP_WIRE,
		REP_SMOOTH,
		REP_FLATWIRE,
		REP_SMOOTHWIRE,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	virtual const INT		DisplayStandard() const;
	virtual const INT		DisplayPoint() const;
	virtual const INT		DisplayFlat() const;
	virtual const INT		DisplayWire() const;
	virtual const INT		DisplaySmooth() const;
	virtual const INT		DisplayFlatWire() const;
	virtual const INT		DisplaySmoothWire() const;

	virtual const INT		DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDPolyhedron *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDPolyhedron &	operator = (const CDPolyhedron & iPolyhedron);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPolyhedron *			m_Polyhedron;
	CDOpenGLDisplay *		m_OpenGLTable;
	DataTypeInMemForDraw	m_DrawMode;
	DOUBLE					m_PointSize;
	DOUBLE					m_LineWidth;
#pragma endregion
};

			}
		}
	}
}