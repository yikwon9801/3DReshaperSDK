#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{
		using namespace Display::View;

RsDEFINE_DLL_CLASS(CDComponentSelect) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CDComponentSelect(const CPoint & iClickedPosition, const CDOpenGLScene * iScene);
	CDComponentSelect(const CDComponentSelect & iComponentSelect);
	virtual ~CDComponentSelect();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CVector	GetViewDirection() const	{ return m_Scene->GetCamera().GetViewDirection(); }
	inline const CGPointDouble &	GetClickedPoint() const	{ return m_ClickedPoint; }
	const DOUBLE			GetPPI() const	{ return m_Scene->GetCamera().GetPPI(); }
	inline const CGeometryObject *	GetBufferGeometry() const	{ return m_Buffer; }
public:
	void					SetBufferGeometry(const CGeometryObject & iGeometry);
#pragma endregion

public:
	const CGPointDouble		GetProjectingPoint(const DOUBLE iDistanceToMove = -100.) const;

protected:
	void					ReleaseBufferGeometry();
private:
	void					_Release();

#pragma region Abstract fuction of IDataObject
public:
	virtual CDComponentSelect *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CDComponentSelect &	operator = (const CDComponentSelect & iComponentSelect);
#pragma endregion

#pragma region Memeber Variable
private:
	const CDOpenGLScene *	m_Scene;
	CGeometryObject *		m_Buffer;
private:
	CPoint					m_WinClickedPosition;
	CGPointDouble			m_ClickedPoint;
#pragma endregion
};

	}
}