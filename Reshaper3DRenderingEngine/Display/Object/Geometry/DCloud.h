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
			}

			using namespace Display::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CDCloud) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCloud();
	CDCloud(CGCloud * iCloud);
	CDCloud(const CGCloud & iCloud);
	CDCloud(const CDCloud & iCloud);
	virtual ~CDCloud();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCloud *	GetCloud() const	{ return m_Cloud; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetCloud(CGCloud * iCloud) { Release(); m_Cloud = iCloud; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
	inline void				SetPoints(const CTableArray<CGVertex> & iPoints) { if (m_Cloud) m_Cloud->SetPoints(iPoints); }
#pragma endregion

public:
	void					Release();
private:
	void					_ReleaseCloud();
	void					_ReleaseOpenGLTable();

#pragma region GPU Memory
private:
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDCloud & iCloud) const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_LINE,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayPoints() const;
	const INT				DisplayLines() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCloud *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCloud &			operator = (const CDCloud & iCloud);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CDCloud & iCloud) const;
	const BOOL				operator != (const CDCloud & iCloud) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGCloud *				m_Cloud;
	CDOpenGLDisplay *		m_OpenGLTable;
	DOUBLE					m_PointSize;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}