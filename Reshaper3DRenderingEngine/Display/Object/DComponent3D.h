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

RsDEFINE_DLL_CLASS(CDComponent3D) : RsINHERITANCE(CDComponent)
{
#pragma region Type Definition
public:
	typedef struct _clippingplane
	{
		CVector			Normal;
		CGPointDouble	Point;
	}ClippingPlane, *pClippingPlane;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CDComponent3D();
	CDComponent3D(LPARAM lParam);
	virtual ~CDComponent3D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CMatrix3x4	GetLocalMatrix() const { return m_LocalMatrix; }
	inline void			SetLocalMatrix(const CMatrix3x4 & iLocalMatrix) { m_LocalMatrix = iLocalMatrix; }
	inline void			InitLocalMatrix() { m_LocalMatrix.Init(); }
	inline void			InitTranslationToLocalMatrix(const CVector & iTranslation) { m_LocalMatrix.InitTranslation(iTranslation); }
	inline void			SetTranslationToLocalMatrix(const CVector & iTranslation) { m_LocalMatrix.SetTranslation(iTranslation); }
	inline void			AddTranslationToLocalMatrix(const CVector & iTranslation) { m_LocalMatrix += iTranslation; }
	inline void			MultiplyRotationToLocalMatrix(const CMatrix3x4 & iRotation) { m_LocalMatrix *= iRotation; }

public:
	static void			SetClipPlane(const UINT iType, const CGPointDouble & iPoint, const CVector & iNormal);
protected:
	static const INT	GetClippingType(const UINT16 iType);
	const CDComponent3D::ClippingPlane &	GetClippingPlane(const UINT16 iType) const;
	const BOOL			IsClipping(const UINT16 iType) const;
	void				GetClippingPlane(const ClippingPlane & iClippingPlane, DOUBLE oPlane[]) const;
	void				GetClippingPlane(const CVector & iDirection, const CGPointDouble & iPosition, DOUBLE oPlane[]) const;

public:
	virtual void		ApplyLocalMatrix() {}
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

#pragma region Macro for Component
protected:
#define APPLY_LOCALMATRIX()					\
	if (!m_LocalMatrix.IsIdentity()) {		\
	DOUBLE localmatrix[MATRIX_4X4];			\
	m_LocalMatrix.GetMatrix(localmatrix);	\
	::glMultMatrixd(localmatrix); }
#pragma endregion

protected:
	CMatrix3x4			m_LocalMatrix;
};

	}
}