#pragma once

namespace Display
{
	
	namespace Object
	{

		namespace Geometry
		{

			namespace Print
			{
				RsDEFINE_CLASS(CDPrintObject);
			}

			using namespace Display::Object::Geometry::Print;

RsDEFINE_DLL_CLASS(CDModel) : RsINHERITANCE(CDPrintObject)
{
#pragma region Construction & Destruction
public:
	CDModel();
	CDModel(const CDModel & iModel);
	CDModel(LPARAM lParam);
	virtual ~CDModel();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CDPolyhedron &	GetPolyhedron() const	{ return m_Polyhedron; }
	inline const CGFace &		GetFace(const UINT iFaceIndex) const { return m_Polyhedron.GetPolyhedron()->GetFace(iFaceIndex); }
	inline const CTableArray<CGVertex> &	GetVertices() const { return m_Polyhedron.GetPolyhedron()->GetVertices(); }
	inline const CTableArray<CGFace> &		GetFaces() const { return m_Polyhedron.GetPolyhedron()->GetFaces(); }
protected:
	virtual const DWORD			GetDelegateComponentId() const { return m_Polyhedron.GetDelegateComponentId(); }
public:
	inline void					SetColor(const COLORREF iColor);
	inline void					SetSelColor(const COLORREF iColor);
	inline void					SetRepres(const UCHAR iRepres);
	inline void					SetSelected(const UCHAR iSelectedOption);
	inline void					SetAlpha(const UCHAR alpha);
	inline void					SetVisible(const BOOL iVisible);
	inline void					SetParam(LPARAM lParam);
#pragma endregion

#pragma region General Function
public:
	void						Release();
private:
	void						_Release();

public:
	void						ChangePolyhedron(CGPolyhedron * ioPolyhedron);

	const BOOL					IsSelectedFaces() const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;

	const CBoundingBox			GetPolyhedronBoundingBox() const;
	const CBoundingBox			GetPedestalBoundingBox() const;

protected:
	virtual CDModel *			NewModel() const;

private:
	virtual void				NotiChangeGeometry() {};
#pragma endregion

#pragma region CAD Function
public:
	CDModel *					MakeModelUsingSelectedFaces() const;
	const INT					Compound(const CTableList<const CGPolyhedron *> & iPolyTable, CProgress * iProgress = NULL);
	const INT					Explode(CTableArray<CDModel *> & oTableModels, const CGPolyhedron::ExplodeType iType = CGPolyhedron::EXPLODE_BYFACE, CProgress * iProgress = NULL) const;
	const CVector				Land(const DOUBLE iGroundZ = 0.);
	const INT					RemoveDuplicatedFaces();
	const INT					FixFaceNormals(const UINT iOption);
	const INT					InvertNormal(const UINT iOption);

	const DOUBLE				GetVolume() const;
#pragma endregion

#pragma region Visible
public:
	virtual void				Show();
	virtual void				Hide();
#pragma endregion

#pragma region Local Matrix
public:
	virtual void				ApplyLocalMatrix();
#pragma endregion

#pragma region Selection
public:
	const UINT					SelectFacesInLine(const CVector & iDirection, const CGMultiLine & iMultiLine, const BOOL iDeselectAll = FALSE) const;
	void						DeselectFaces();
	void						DeselectVertices();
#pragma endregion

#pragma region Pedestal
public:
	void						MakePedestal(const UINT16 iType);
	void						OffsetPedestal(const DOUBLE iOffsetDistance);
#pragma endregion

#pragma region File3D Read/Write Model
public:
	const INT					ReadModel(LPCTSTR ilpFileName, CProgress * iProgress = NULL);
	const INT					WriteModel(LPCTSTR ilpFileName, const INT iType, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Display
public:
	void						ReCreateOpenGLTable();
public:
	typedef enum {
		REP_STANDARD	= CDPolyhedron::REP_STANDARD,
		REP_POINT		= CDPolyhedron::REP_POINT,
		REP_WIRE		= CDPolyhedron::REP_WIRE,
		REP_FLAT		= CDPolyhedron::REP_FLAT,
		REP_SMOOTH		= CDPolyhedron::REP_SMOOTH,
		REP_FLATWIRE	= CDPolyhedron::REP_FLATWIRE,
		REP_SMOOTHWIRE	= CDPolyhedron::REP_SMOOTHWIRE,
	}RepresentationType;
public:
	virtual const INT			Display() const;
protected:
	virtual const INT			DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDModel *			Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Abstract fuction of IKeyObject
public:
	virtual const CKeyString	MakeKey() const;
#pragma endregion

#pragma region Abstract fuction of IEditedData
protected:
	virtual const BOOL			ExecuteEditedBeforeData(const CDataObject * iObjectToData, LPARAM lParam = NULL);
	virtual const BOOL			ExecuteEditedAfterData(const CDataObject * iObjectToData, LPARAM lParam = NULL);
#pragma endregion

#pragma region Operator Declaration
public:
	const CDModel &				operator = (const CDModel & iModel);
	void						operator += (const CVector & iVector);
	void						operator -= (const CVector & iVector);
	void						operator *= (const CMatrix3x3 & iMatrix);
	void						operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
	CDPolyhedron				m_Polyhedron;
	CDPedestal					m_Pedestal;
#pragma endregion
};


		}
	}
}