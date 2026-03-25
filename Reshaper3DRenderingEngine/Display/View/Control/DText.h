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
		}
	}

	namespace View
	{
		namespace Control
		{
			using namespace Kernel::Object::Geometry;
			using namespace Display::View;
			using namespace Display::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CDText) : RsINHERITANCE(CDViewObject)
{
#pragma region Construction & Destruction
public:
	enum
	{
		ALIGN_TOP		= 0x00010000,
		ALIGN_BOTTOM	= 0x00020000,
		ALIGN_VCENTER	= 0x00030000,
		ALIGN_RIGHT		= 0x00000001,
		ALIGN_LEFT		= 0x00000002,
		ALIGN_HCENTER	= 0x00000003,
	};
#pragma endregion

#pragma region Construction & Destruction
public:
	CDText(const CGPointDouble & iPosition, const LPCTSTR lpctText, CDOpenGLScene * iScene);
	CDText(const CGPointDouble & iPosition, const LPCTSTR lpctText, const CVector & iDirection, CDOpenGLScene * iScene);
	CDText(const CDText & rhs);
	virtual ~CDText();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPosition() const { return m_Position; }
	inline const CString &		GetText() const { return m_Text; }
	inline const UINT			GetFontPixelSize() const { return m_FontPixelSize; }
	inline const UINT			GetFontSize() const { return m_FontSize; }
	inline const BOOL			IsBold() const { return m_Bold; }
	inline const CGRectangle &	GetDisplayingRectangle() const { return m_Rectangle; }
	inline const CTexture *		GetTexture() const { return m_Texture; }
public:
	inline void					SetPosition(const CGPointDouble & iPosition) { m_Position = iPosition; }
	inline void					SetFontPixelSize(const UINT iSize) { m_FontPixelSize = iSize; }
	inline void					SetFontSize(const UINT iSize) { m_FontSize = iSize; }
	inline void					SetBold(const BOOL bBold = TRUE) { m_Bold = bBold; }
	inline void					SetAlign(const UINT iAlign) { m_Align = iAlign; }
	inline void					SetText(LPCTSTR iText) { m_Text = iText; }
protected:
	inline const UINT			GetAlign() const { return m_Align; }
	inline const CVector &		GetDirection() const { return m_Direction; }
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_TEXTURE,
	}RepresentationType;
public:
	virtual const INT			Display() const;
protected:
	virtual const INT			DisplayStandard() const;
	virtual const INT			DisplayTexture() const;
#pragma endregion

public:
	void						CreateTexture();
protected:
	

	void						CalculateDisplayingRectangle();

public:
	void						Release();
private:
	void						_Release();
	void						_ReleaseTexture();

#pragma region GPU Memory
private:
	CDOpenGLDisplay *			_GetRenderObject(const UINT16 iRepres);
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDText *			Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file);
	virtual const INT			SaveBin(CFileWriteObject & file);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDText &				operator = (const CDText & iText);
	void						operator *= (const CMatrix3x3 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble				m_Position;
	CGRectangle					m_Rectangle;
	CVector						m_Direction;
	CString						m_Text;
	CTexture *					m_Texture;
	UINT						m_FontPixelSize;
	BOOL						m_Bold;
	UINT						m_Align;
	UINT						m_FontSize;
#pragma endregion
};

		}
	}
}