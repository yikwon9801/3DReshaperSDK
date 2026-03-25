#pragma once

namespace tinyxml2
{
	RsDEFINE_CLASS(XMLElement);
}

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
		RsDEFINE_CLASS(CMemoryStreamRead);
		RsDEFINE_CLASS(CMemoryStreamWrite);

		namespace LightXML
		{
			RsDEFINE_CLASS(CLightXmlDocument);
		}
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGRectangle2D);
		}

		RsDEFINE_CLASS(CDimension);
		RsDEFINE_CLASS(CBoundingBox2D);

		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::File::LightXML;


RsDEFINE_DLL_CLASS(CDimension2D) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CDimension2D();
	CDimension2D(const DOUBLE iWidth, const DOUBLE iHeight);
	CDimension2D(const CDimension2D & iDimension);
	CDimension2D(const CDimension & iDimension);
	CDimension2D(const CGPoint2DDouble & iPoint);
	CDimension2D(const CBoundingBox2D & iBoundingBox);
	CDimension2D(const INT iValue);
	virtual ~CDimension2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetWidth() const	{ return m_Width; }
	inline const DOUBLE		GetHeight() const	{ return m_Height; }
	inline const DOUBLE		GetWidthPerPixel(const UINT iCountOfPixel) const { return m_Width / (DOUBLE)iCountOfPixel; }
	inline const DOUBLE		GetHeightPerPixel(const UINT iCountOfPixel) const { return m_Height / (DOUBLE)iCountOfPixel; }
public:
	void					ChangeDimension(const DOUBLE iWidth, const DOUBLE iHeight);
#pragma endregion

#pragma region General Function
public:
	const CGRectangle2D		GetRectangle2D() const;
	const DOUBLE			GetLongestLength() const;

protected:
	const BOOL				IsEqual(const CDimension2D & iDimension) const;
#pragma endregion

#pragma region CAD Functions
public:
	virtual const CBoundingBox2D	GetBoundingBox() const;
	virtual const CGPoint2DDouble	GetCenterPoint() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	const BOOL				CopyFrom(const CBoundingBox2D & iBoundingBox);
	const BOOL				CopyFrom(const CDimension & iDimension);
	const BOOL				CopyFrom(const CGPoint2DDouble & iPoint);
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDimension2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);

	virtual const INT		ReadBinSimple(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBinSimple(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const INT		ReadBinSimple(CMemoryStreamRead & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBinSimple(CMemoryStreamWrite & file, CProgress * iProgress = NULL);

	virtual const INT		ReadXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);
	virtual const INT		SaveXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);

	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDimension2D &	operator = (const CDimension2D & iDimension);
	const CDimension2D &	operator = (const CDimension & iDimension);
	const CDimension2D &	operator = (const CBoundingBox2D & iBoundingBox);
	const CDimension2D &	operator = (const CGPoint2DDouble & iPoint);
	const CDimension2D &	operator = (const INT iValue);
	const BOOL				operator == (const CDimension2D & iDimension) const;
	const BOOL				operator != (const CDimension2D & iDimension) const;
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Width, m_Height;
#pragma endregion
};

	}
}