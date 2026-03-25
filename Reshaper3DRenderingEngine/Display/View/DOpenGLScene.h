#pragma once

#include <vector>
using namespace std;

namespace Display
{
	namespace Object
	{
		RsDEFINE_CLASS(CDComponent);
		RsDEFINE_CLASS(CDCompModel);

		namespace Geometry
		{
			RsDEFINE_CLASS(CDGroup);
			RsDEFINE_CLASS(CDSceneCoordinateSystem);
			RsDEFINE_CLASS(CDCloud);

			namespace Mesh
			{
				RsDEFINE_CLASS(CDPolyhedron);
			}
		}

		namespace Vision
		{
			RsDEFINE_CLASS(CDCamera);
			RsDEFINE_CLASS(CDLight);
		}
	}

	namespace View
	{
		using namespace Display::Object;
		using namespace Display::Object::Geometry;
		using namespace Display::Object::Geometry::Mesh;
		using namespace Display::Object::Vision;

RsDEFINE_DLL_CLASS(CDOpenGLScene)
{
#pragma region Type Definition
public:
	typedef enum
	{
		DISPLAYOBJECTINSCENE_NONE						= 0x00,
		DISPLAYOBJECTINSCENE_LOCALCOORDINATESYSTEM		= 0x01,
		DISPLAYOBJECTINSCENE_GLOBALCOORDINATESYSTEM		= 0x02,
		DISPLAYOBJECTINSCENE_RULER						= 0x04,
		DISPLAYOBJECTINSCENE_ALL = DISPLAYOBJECTINSCENE_LOCALCOORDINATESYSTEM | DISPLAYOBJECTINSCENE_GLOBALCOORDINATESYSTEM | DISPLAYOBJECTINSCENE_RULER
	}DISPLAYOBJECTINSCENE;

	typedef struct _backgroundpos
	{
		DOUBLE				Win_XMin = 0., Win_YMin = 0., Win_Z = 0;
		DOUBLE				Win_XMax = 0., Win_YMax = 0.;
	}BackGroundPos, *pBackGroundPos;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDOpenGLScene();
	virtual ~CDOpenGLScene();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const COLORREF	GetTopBG() const	{ return m_TopBG; }
	inline const COLORREF	GetBottomBG() const	{ return m_BottomBG; }
	inline const BOOL		IsDisplayMode(const UINT16 iMode) { return m_DisplayMode == iMode; }
	inline const UINT16		GetDisplayMode() const { return m_DisplayMode; }
	inline const BackGroundPos &	GetBackGroundPos() const { return m_BackGroundPos; }
	inline const DOUBLE		GetxPPI() const { return m_xPPI; }
	inline const DOUBLE		GetyPPI() const { return m_yPPI; }
protected:
	inline const UINT		GetRotationType() const { return m_RotationType; }
	inline const UINT		GetRotationMode() const { return m_RotationMode; }
	inline const BOOL		IsRotationMode(const UINT16 iTypeToCheck) const { return m_RotationMode == iTypeToCheck; }
	inline const BOOL		IsSelectedRectangle() const { return IsSelectionMode(SELECTIONMODE_RECTANGLE); }
	inline const BOOL		IsSelectedFree() const { return IsSelectionMode(SELECTIONMODE_FREE); }
	inline const BOOL		IsSelectionMode(const UINT iSelectionMode) const { return m_nSelectionMode == iSelectionMode; }
public:
	void					SetRotationType(const UINT16 iRotationType) { m_RotationType = iRotationType; }
	inline void				SetTopBG(const COLORREF iColor)	{ m_TopBG = iColor; }
	inline void				SetBottomBG(const COLORREF iColor)	{ m_BottomBG = iColor; }
	inline void				SetRotationMode(const UINT16 iRotationMode) { m_RotationMode = iRotationMode; }
	inline void				SetDisplayMode(const UINT16 iMode) { m_DisplayMode = iMode; }
	inline void				SetSelectedRectangle(const BOOL bSet, const CRect iRect) { bSet ? m_nSelectionMode = SELECTIONMODE_RECTANGLE : m_nSelectionMode = SELECTIONMODE_NONE; m_SelectedRectagle = iRect; }
	inline void				AddSelectedFree(CPoint iPoint) { m_nSelectionMode = SELECTIONMODE_FREE; if (!m_SelectedFreeLine.size() || !m_SelectedFreeLine[m_SelectedFreeLine.size() - 1].IsWinPoint(iPoint)) m_SelectedFreeLine.push_back(CWinPointDouble(iPoint)); }
	inline void				ClearSelectedFree() { m_nSelectionMode = SELECTIONMODE_NONE; m_SelectedFreeLine.clear(); }
	inline const CGMultiLine::_WinPointVector &	GetSelectedWinFreeLine() const { return m_SelectedFreeLine; }
	inline void				SetReUseSizeBitMapFontListBase(const BOOL iSet = TRUE) { m_bReUseSizeBitMapFontListBase = iSet; }
	inline void				SetDisplayedObjectInScene(const DISPLAYOBJECTINSCENE iDisplay) { m_DisplayedObjectInScene = iDisplay; }

public:
	inline void				InitCameraPosition(const CGPointDouble & iPosition, const CVector & iUp, const CVector & iView, const DOUBLE iZoom) { m_Camera.InitCameraPosition(iPosition, iUp, iView, iZoom); }
#pragma endregion

#pragma region General Function
public:
	const CGMultiLine		GetSelectedFreeLine() const;

	void					AttachCompModel(CDCompModel & iCompModel);
	void					DetachCompModel(CDCompModel & iCompModel);
private:
	void					_ReleaseAttachedCompModels();
#pragma endregion

#pragma region Notification
public:
	const INT				NotiModifiedGeometryOfComponent();
#pragma endregion

#pragma region Component
public:
	void					HideAllComponents();
	const CTableList<CDComponent *>	GetVisibleComponents(const UINT iOption) const;
#pragma endregion

#pragma region Camera
public:
	const CDCamera &		GetCamera() const;

	void					PanCameraWithWinPosition(const CPoint & iDeparture, const CPoint & iArrival);
	void					PanCamera(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	void					PanCamera(const CVector & iTranslate);
	void					RotateCameraWithWinPosition(const CGPointDouble & iCenterPoint, const CPoint & iDeparture, const CPoint & iArrival);
	void					ZoomCameraWithWinPosition(const CPoint & iPosition, const SHORT iDelta);
	const DOUBLE			GetPredictedZoomFactor(const SHORT iDelta) const;

public:
	void					FitModelView(const CBoundingBox & iBoundingBox, const DOUBLE iOffsetDistance = 0.);
	void					FitModelViewScale(const CBoundingBox & iDimension, const DOUBLE iScale = 1.);
	void					ZoomView(const CGPointDouble & iCameraPosition, const DOUBLE iZoomFactor);

	void					InitialView();
private:
	const DOUBLE			GetZoomFactorFromZoomDelta(const SHORT iDelta) const;

#pragma endregion

#pragma region Position
public:
	const CGPointDouble		Get3DCoordnatePointFromWinPosition(const CPoint & iPoint) const;
	const CGPointDouble		Get3DCoordnatePointDuringRenderingScene(const CPoint & iPoint, const DOUBLE iDepth) const;
#pragma endregion

#pragma region Font Bitmap
public:
	const UINT				GetBitMapFontListBase() const	{ return m_BitMapFontListBase; }
	const UINT				GetBitMapFontListBaseVertically() const	{ return m_BitMapFontListBaseVertically; }
	const INT				GetSizeBitMapFontListBase() const	{ return m_SizeBitMapFontListBase; }
private:
	void					_CreateFontBitmap(const LONG end = 256, const UINT matrixTransformationAffected = 0);
#pragma endregion

#pragma region Bitmap
public:
	CExtBitmap *			ScreenShotModel(const CDPolyhedron & iPolyhedron, const UINT iWidth, const UINT iHeight) const;
	CExtBitmap *			ScreenShotModel(const CTableList<const CDComponent *> & iTableComponents, const UINT iWidth, const UINT iHeight) const;
#pragma endregion

#pragma region Context for Window
public:
	void					Attach(CDC * pDC);
	void					Detach();

	void					Resize(const USHORT iWidth, const USHORT iHeight);
	const BOOL				IsReady() const;

	void					SetDeviceContext(CDC * pDC);
	CDC *					GetDC();

	const BOOL				GetZOrder(const CDGroup & iGroup, CDGroup & oComponents) const;
protected:
	CDC *					GetDeviceContext();
	const BOOL				SetupGLContext(const BOOL ibSetupPixelFormat);
	const INT				SetupPixelFormat(HDC iHdc);

	void					GetDisplayGroup(CDGroup & oGeneral, CDGroup & oTransparency);
private:
	void					_SetupViewport(const USHORT iWidth, const USHORT iHeight);
	void					_CalcBackgroundSize();
	void					_InitLight();

	void					_CalculateSceneOrigin();
	CDGroup &				_GetGroupForDisplay(const UINT16 iLayer);
	CDGroup &				_GetGroup2DForDisplay(const UINT16 iLayer);
#pragma endregion

#pragma region Pick Components
public:
	const CTableList<CDPolyhedron *>	GetSelectedPolyhedrons(const CTableList<const CDPolyhedron *> & iPolyhedronsToPick, const CRect & iSelectedRect) const;
	const CDPolyhedron *	GetSelectedPolyhedron(const CTableList<const CDPolyhedron *> & iPolyhedronsToPick, const CPoint & iPoint, CGPointDouble * oProjectedPoint = NULL, INT * oProjectedFace = NULL) const;
	const INT				GetSelectedPoint(const CDPolyhedron & iPolyhedron, const CPoint & iPoint, CGPointDouble & oSelectedPoint, INT & oProjectedFace, const CMatrix3x4 *const iMatrix = NULL) const;
	const INT				GetSelectedPickedIndex(const CDComponent & iComponent, const CPoint & iPoint, INT & oResult) const;

	const CDComponent *		GetSelectedComponent(const CTableList<const CDComponent *> & iComponentToPick, const CPoint & iPoint, CGPointDouble * oProjectedPoint = NULL) const;
	const CTableList<const CDComponent *>	GetSelectedComponents(const CTableList<const CDComponent *> & iComponentsToPick, const CRect & iSelectedRect) const;
	const CTableList<const CDComponent *>	GetSelectedComponents(const CTableList<const CDComponent *> & iComponentsToPick, const CGMultiLine::_WinPointVector & iSelectedLine) const;
#pragma endregion

#pragma region Display
public:
	const BOOL				AddComponent(CDComponent * iComponent);
	const BOOL				AddComponentInBaseModelLayer(CDComponent * iComponent);
	const BOOL				AddComponentInFixedOrderModelLayer(CDComponent * iComponent);
	const BOOL				AddComponentInToolLayerLayer(CDComponent * iComponent);
	const BOOL				DeleteComponent(CDComponent * iComponent);
	void					DeleteAllComponents();
	void					DeleteAllTemporaryComponents();
	const BOOL				RemoveComponent(const CDComponent * iComponent);

protected:
	const BOOL				AddComponent(CDComponent * iComponent, const INT iLayer);

public:
	virtual const INT		RenderScene();
protected:
	void					DisplayRotateCenterPoint();

	virtual void			DisplayCoordinateSystem();
	virtual void			DisplayGroup();
	virtual void			Display2DGroup();
	virtual void			DisplayRotationLine();
	virtual void			ClearColorBackground();
	virtual void			DisplaySelectionLine();
private:
	void					_DisplayRotationLine(const UINT16 iType);
	void					_DisplaySelectedRectangle();
	void					_DisplaySelectedFreeLine();
#pragma endregion

#pragma region Memeber Variable
public:
	enum {
		RotationMode_None,
		RotationMode_3DRotateOriginOfCoordinates,
		RotationMode_2DRotateArroundViewCenter,
	};
	enum {
		RotationType_Basic,
		RotationType_FromOriginPlane,
		RotationType_RotationCenterFromOriginPlane,
	};
#define NUMBEROFLAYER		4
	enum {
		NormalLayer,
		BaseModelLayer,
		FixedOrderModelLayer,
		ToolLayer,
	};
	enum {
		DisplayMode_Normal,
		DisplayMode_Temporary,
	};
	enum {
		SELECTIONMODE_NONE,
		SELECTIONMODE_RECTANGLE,
		SELECTIONMODE_FREE,
	};
private:
	CDGroup					m_DisplayLayers[NUMBEROFLAYER];
	CDGroup					m_TmpDisplayLayers[NUMBEROFLAYER];
	CDGroup					m_Display2DLayers[NUMBEROFLAYER];
	CDGroup					m_TmpDisplay2DLayers[NUMBEROFLAYER];
	UINT16					m_DisplayMode;

	CCriticalSection		m_CSDisplay;
	CSingleLock				m_LockDisplay;

private:
	typedef list<CDCompModel *>	CompModelList;
	CompModelList			m_AttachedCompModels;

private:
	CDC *					m_DeviceContext;
	HDC						m_hDC;
	HGLRC					m_hGLRC;

	COLORREF				m_TopBG;
	COLORREF				m_BottomBG;
	DOUBLE					m_xPPI;
	DOUBLE					m_yPPI;

	DISPLAYOBJECTINSCENE	m_DisplayedObjectInScene;

	UINT					m_BitMapFontListBase;
	UINT					m_BitMapFontListBaseVertically;
	INT						m_SizeBitMapFontListBase;
	BOOL					m_bReUseSizeBitMapFontListBase;
#define NUMBEROFCHARACTER	65536
	FLOAT					m_WidthChar[NUMBEROFCHARACTER];
	
	BackGroundPos			m_BackGroundPos;

	UINT16					m_RotationMode;
	UINT16					m_RotationType;
	CGPointDouble			m_RotateCenterPoint;

private:
	CDSceneCoordinateSystem	m_CoordinateSystem;

	CRect					m_SelectedRectagle;
	CGMultiLine::_WinPointVector	m_SelectedFreeLine;
	UINT					m_nSelectionMode;

private:
#define NUMBEROFLIGHTS		8
	CDLight					m_Light[NUMBEROFLIGHTS];
	CDCamera				m_Camera;
#pragma endregion
};

	}
}