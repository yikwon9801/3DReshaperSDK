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

RsDEFINE_DLL_CLASS(CDSceneCoordinateSystem) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDSceneCoordinateSystem(LPARAM lParam);
	CDSceneCoordinateSystem(const CDSceneCoordinateSystem & rhs);
	virtual ~CDSceneCoordinateSystem();
#pragma endregion

#pragma region Setter & Getter function
public:
	const DOUBLE			GetCoordLineLength() const;
public:
	void					SetCoordLineLength(const DOUBLE iLength);
#pragma endregion

#pragma region Display
public:
	virtual const INT		Display() const;
	virtual const INT		DisplayGlobal() const;
	virtual const INT		DisplayCorner() const;
	virtual const INT		DisplayRuler() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDSceneCoordinateSystem *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDSceneCoordinateSystem &	operator = (const CDSceneCoordinateSystem & iCoordinateSystem);
#pragma endregion

#pragma region Memeber Variable
private:
	CDCoordinateSystem		m_GlobalCoordinateSystem;
	CDCoordinateSystem		m_CornerCoordinateSystem;
	CDRuler					m_Ruler;
	DOUBLE					m_Length;
#pragma endregion
};

		}
	}
}