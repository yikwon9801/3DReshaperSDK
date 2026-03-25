#pragma once

namespace Display
{

	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{

		namespace Geometry
		{
			using namespace Display::View;

RsDEFINE_DLL_CLASS(CDManipulator) : RsINHERITANCE(CDComponent3D)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CDManipulator(CDPolyhedron * ioPolyhedron, CDOpenGLScene * iScene);
	CDManipulator(const CDManipulator & rhs);
public:
	virtual ~CDManipulator();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetManiType() const	{ return m_ManiType; }
protected:
	inline const DOUBLE		GetGlobalTranslationPointSize() const	{ return m_GlobalTranslationPointSize; }
	inline const DOUBLE		GetTranslationLineWidth() const	{ return m_TranslationLineWidth; }
	inline const DOUBLE		GetRotationLineWidth() const	{ return m_RotationLineWidth; }
	inline const DOUBLE		GetScalePointSize() const	{ return m_ScalePointSize; }
	inline const BOOL		IsManiType(const UINT iType) const	{ return (m_ManiType & iType) == iType; }
public:
	inline void				SetManiType(const UINT iType)	{ m_ManiType = iType; }
#pragma endregion

protected:
	void					ChangeRadius(const DOUBLE iRadius);

	void					Initialize();

private:
	CDComponent *			_GetSelectedControlComponent(CDComponentSelect & ioCompSelect, UINT16 & oTransType);

#pragma region Mouse Event
public:
	void					MouseLButtonDown(const UINT iFlags, const CPoint & iPoint);
	void					MouseLButtonUp(const UINT iFlags, const CPoint & iPoint);
	void					MouseMove(const UINT iFlags, const CPoint & iPoint);
#pragma endregion

#pragma region Display
public:
	enum	{
		NONE = 0x00, TRANSLATE = 0x01, ROTATE = 0x02, SCALE = 0x04, SPHERE_ROTATE = 0x08,
		BASETYPE = TRANSLATE | ROTATE | SCALE,
		ALLTYPE = BASETYPE | SPHERE_ROTATE
	};
	typedef enum	{
		REP_STANDARD,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayStandard() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDManipulator *	Clone() const;
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
	const CDManipulator &	operator = (const CDManipulator & iManipulator);
#pragma endregion

#pragma region Memeber Variable
protected:
	CDPolyhedron *			m_Polyhedron;
	const CDOpenGLScene *	m_Scene;

private:
	CGAxisSystem			m_LocalAxisSystem;
	UINT					m_ManiType;

private:
	DOUBLE					m_GlobalTranslationPointSize;
	DOUBLE					m_TranslationLineWidth;
	DOUBLE					m_RotationLineWidth;
	DOUBLE					m_ScalePointSize;
private:
	CDLine					m_Translation[3];
	CDCircle				m_Rotation[3];
	CDPoint					m_Scale[6];
	CDSphere				m_GlobalRotaion;

	CDPoint					m_CenterPoint;
	CDPoint					m_RotationPoint[12];
#pragma endregion
};

		}
	}
}