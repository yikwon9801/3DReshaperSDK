#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CDPoint);
		}

		namespace Vision
		{
			using namespace Display::Object::Geometry;

RsDEFINE_DLL_CLASS(CDCamera) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCamera();
	CDCamera(const CDCamera & rhs);
	virtual ~CDCamera();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetZoomFactor() const	{ return m_Camera.GetZoomFactor(); }
	inline const BOOL		IsPerpective() const	{ return m_bPerspective; }
	inline const BOOL		IsOrthogonal() const	{ return !IsPerpective(); }
public:
	inline const USHORT		GetWidth() const	{ return m_Camera.GetWidth(); }
	inline const USHORT		GetHeight() const	{ return m_Camera.GetHeight(); }
	inline const CRect		GetVisibleRect() const { return m_Camera.GetVisibleRect(); }
	inline const CGPointDouble &	GetOriginPosition() const	{ return m_Camera.GetOriginPosition(); }
	inline const CGPointDouble &	GetPosition() const { return m_Camera.GetPosition(); }
	inline const DOUBLE		GetPPI() const	{ return m_PPI; }
	inline const CVector	GetViewDirection() const;
	inline const CMatrix3x4	GetCameraMatrix() const { return m_Camera.GetLocalMatrix(); }
public:
	inline void				SetWindowSize(const USHORT iWidth, const USHORT iHeight)	{ m_Camera.SetWindowSize(iWidth, iHeight); }
	inline void				SetOriginPosition(const CGPointDouble & iPosition)	{ m_Camera.SetOriginPosition(iPosition); }
	inline void				SetPPI(const DOUBLE iPPI)	{ m_PPI = iPPI; }

	inline void				SetPosition(const CGPointDouble & iPosition)	{ m_Camera.SetPosition(iPosition); }
	inline void				SetZoomFactor(const DOUBLE & iZoomFactor)	{ m_Camera.SetZoomFactor(iZoomFactor); }

	inline void				SetRestriction(const USHORT iXmin, const USHORT iYmin, const USHORT iXmax, const USHORT iYmax) { m_Camera.SetRestriction(iXmin, iYmin, iXmax, iYmax); }
public:
	inline void				InitTopView() { m_Camera.InitTopView(); }
	inline void				InitBottomView() { m_Camera.InitBottomView(); }
	inline void				InitFrontView() { m_Camera.InitFrontView(); }
	inline void				InitBackView() { m_Camera.InitBackView(); }
	inline void				InitRightView() { m_Camera.InitRightView(); }
	inline void				InitLeftView() { m_Camera.InitLeftView(); }
	inline void				InitCameraPosition(const CGPointDouble & iPosition, const CVector & iUp, const CVector & iView, const DOUBLE iZoom) { m_Camera.InitCameraPosition(iPosition, iUp, iView, iZoom); }
#pragma endregion

public:
	const CGPointDouble		Get3DCoordnatePointFromWinPosition(const CPoint & iPosition) const;

#pragma region Moving
public:
	inline void				SetCameraRotation(const CMatrix3x3 & iMatrix) { m_Camera.SetCameraRotation(iMatrix); }
public:
	const DOUBLE			GetPredictedZoomFactor(const DOUBLE iFactor) const;
	const DOUBLE			GetZoomFactorToFit(const CBoundingBox & iDimension, CVector2D * iTranslate = NULL, const BOOL iRestruction = FALSE) const;
	void					GetZoomFactorToFitExceptRestriction(const CBoundingBox & iDimension, CVector2D & oTranslate, DOUBLE & oFactor) const;
	const CGPointDouble		GetCenterPosition() const;
	void					SetCenterPosition(const CGPointDouble & iPosition);

	void					ZoomFit(const CBoundingBox & iDimension, const DOUBLE iOffsetDistance = 20.);
	void					FitModelViewScale(const CBoundingBox & iDimension, const DOUBLE iScale = 1.);
	void					InitCamera();

	void					Pan(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	void					Pan(const CVector & iTranslate);
	void					Rotate(const UINT iType, const CGPointDouble & iCenterPoint, const CGPointDouble & iDeparture, const CGPointDouble & iArrival, const DOUBLE iDistPerPixel = 0.);
	void					RotatePlane(const CVector & iFixed, const CVector & iMoved);
	void					Zoom(const CPoint & iClickedPoint, const DOUBLE iFactor);
	void					Zoom(const CGPointDouble & iCameraPosition, const DOUBLE iZoomFactor);
#pragma endregion

#pragma region OpenGL Function
public:
	void					Project() const;
	typedef enum { ORTHOVOLUME_LEFT, ORTHOVOLUME_RIGHT, ORTHOVOLUME_TOP, ORTHOVOLUME_BOTTOM, ORTHOVOLUME_NEAR, ORTHOVOLUME_FAR } ORTHOVOLUME;
	const DOUBLE			GetOrthoVolume(const CDCamera::ORTHOVOLUME typeToKnow) const;
private:
	void					_glOrthogonal() const;
	void					_glLookAt() const;
#pragma endregion

#pragma region Display
public:
	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCamera *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCamera &		operator = (const CDCamera & iCamera);
	void					operator += (const CVector & iVector);
	void					operator += (const CVector2D & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
	CCamera					m_Camera;
	DOUBLE					m_PPI;

	BOOL					m_bPerspective;
#pragma endregion
};
		}
	}
}