#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDComponentSelect);

		namespace Geometry
		{
			RsDEFINE_CLASS(CDGroup);

			namespace Mesh
			{
				RsDEFINE_CLASS(CDOpenGLTable);
			}
		}

		using namespace Display::Object::Geometry;
		using namespace Display::Object::Geometry::Mesh;
		using namespace Display::View;

RsDEFINE_DLL_CLASS(CDComponent) : RsINHERITANCE(CDObject)
{
	friend class CDGroup;
	friend class CDOpenGLTable;

#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
protected:
	CDComponent();
	CDComponent(LPARAM lParam);
public:
	virtual ~CDComponent();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UCHAR	GetSelected() const { return m_Selected; }
	inline const BOOL	IsSelected() const	{ return m_Selected != 0; }
	inline virtual void	SetSelected(const UCHAR iSelectedOption) { m_Selected = iSelectedOption; }
	inline LPCTSTR		GetName() const { return m_Name; }
	inline void			ChangeName(LPCTSTR lpNewName) { SetName(lpNewName); }
	inline const BOOL	IsAutoDeleteInGroup() const { return m_IsAutoDeleteInGroup; }
	inline void			SetAutoDeleteInGroup(const BOOL iSet = TRUE) { m_IsAutoDeleteInGroup = iSet; }
	inline virtual void	SetVisible(const BOOL iVisible) { CDObject::SetVisible(iVisible); NotiModifiedGeometryOfComponent(); }
protected:
	inline const INT16	GetFrontAndBack() const { return m_FrontAndBack; }
	inline const DWORD	GetComponentId() const { return m_dwComponentID; }
	inline void			SetName(LPCTSTR lpName) { m_Name = lpName; }
protected:
	inline void			SetFrontAndBack(const INT16 IFrontAndBack) { m_FrontAndBack = IFrontAndBack; }
	inline const CVersion &	GetOpenGLVersion() const;

public:
	virtual const DWORD	GetDelegateComponentId() const { return GetComponentId(); }
#pragma endregion

public:
	void				SetMaterial(const BOOL iDrawPicking = FALSE) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const	{ return CBoundingBox(); }
	virtual const CGPointDouble	GetCenterPoint() const	{ return CGPointDouble(); }
	virtual const BOOL	IsSelected(CDComponentSelect & ioComponentSelect) const	{ return FALSE; }
	virtual const BOOL	GetSelectedPoint(const CDOpenGLScene & iScene, const CPoint & iPoint, CGPointDouble & oSelectedPoint) const { return FALSE; }

#pragma region Visible
public:
	virtual void		Show();
	virtual void		Hide();
#pragma endregion

#pragma region Notification
	const INT			NotiModifiedGeometryOfComponent();
#pragma endregion

#pragma region Display
public:
	virtual const INT	DisplayForPicking(const UCHAR iOption, const DWORD iComponentID) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Static Function
public:
	static CDComponent *	NewComponent(const UINT iObjectType, LPARAM lParam = NULL);
	static const CDComponent *	GetComponentById(const CTableList<const CDComponent *> & iTableComponents, const UINT iComponentId);
#pragma endregion

#pragma region Macro for Component
protected:
#define ENABLE_RESCALE_NORMALIZE()											\
		if (GetOpenGLVersion().GetMajor() < 1) ::glEnable(GL_NORMALIZE);	\
		else ::glEnable(GL_RESCALE_NORMAL);
#define DISABLE_RESCALE_NORMALIZE()											\
		if (GetOpenGLVersion().GetMajor() < 1)	::glDisable(GL_NORMALIZE);	\
		else ::glDisable(GL_RESCALE_NORMAL);
#define INITIALIZE_TRANSPARENCY(classtype)																	\
	int MemIsBlendActivate, MemBlendDist, MemBlendSrc, MemDepthMask, MemFrontAndBack(GetFrontAndBack());	\
	::glGetIntegerv(GL_BLEND, &MemIsBlendActivate);	::glGetIntegerv(GL_BLEND_DST, &MemBlendDist);			\
	::glGetIntegerv(GL_BLEND_SRC, &MemBlendSrc);	::glGetIntegerv(GL_DEPTH_WRITEMASK, &MemDepthMask);		\
	MemFrontAndBack = GetFrontAndBack();																	\
	if (IsTransparency())		const_cast<classtype *>(this)->SetFrontAndBack(0);
#define BEGIN_TRANSPARENCY(classtype)																		\
	if (IsTransparency())	{	::glDepthMask(GL_FALSE);	::glEnable(GL_BLEND);							\
		::glEnable(GL_ALPHA_TEST); ::glAlphaFunc(GL_GREATER, 0.0);											\
		::glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	}
#define END_TRANSPARENCY(classtype)																			\
	if (IsTransparency())	{	::glBlendFunc(MemBlendSrc, MemBlendDist);									\
		if (!MemIsBlendActivate)	::glDisable(GL_BLEND);													\
		::glDepthMask(MemDepthMask);																		\
		const_cast<classtype *>(this)->SetFrontAndBack(MemFrontAndBack);									\
	}
#define BEGIN_CLIPPING(nIndex)																				\
	const INT iClipPlane = GetClippingType(nIndex);															\
	if (IsClipping(nIndex)) {																				\
		::glEnable(iClipPlane);																				\
		const ClippingPlane & ClipPlane = GetClippingPlane(nIndex);											\
		const GLdouble eq[] = { ClipPlane.Normal.GetX(), ClipPlane.Normal.GetY(),ClipPlane.Normal.GetZ(),	\
		CVector(CGPointDouble(0,0,0) - ClipPlane.Point)*ClipPlane.Normal };									\
		::glClipPlane(iClipPlane, eq);																		\
	}
#define END_CLIPPING()																						\
	::glDisable(iClipPlane);
#pragma endregion

#pragma region Memeber Variable
protected:
	CDGroup *			m_Group;
private:
	CDMaterial			m_Material;
	CString				m_Name;
private:
	UCHAR				m_Selected;
	INT16				m_FrontAndBack;
private:
	DWORD				m_dwComponentID;
	BOOL				m_IsAutoDeleteInGroup;
#pragma endregion
};

	}
}