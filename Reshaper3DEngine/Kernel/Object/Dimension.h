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
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGRectangle);
		}

		RsDEFINE_CLASS(CBoundingBox);

		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::File::LightXML;


RsDEFINE_DLL_CLASS(CDimension) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CDimension();
	CDimension(const DOUBLE iWidth, const DOUBLE iDepth, const DOUBLE iHeight);
	CDimension(const CDimension & iDimension);
	CDimension(const CBoundingBox & iBoundingBox);
	CDimension(const INT iValue);
	virtual ~CDimension();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetWidth() const	{ return m_Width; }
	inline const DOUBLE		GetDepth() const	{ return m_Depth; }
	inline const DOUBLE		GetHeight() const	{ return m_Height; }
	inline const DOUBLE		GetWidthPerPixel(const UINT iCountOfPixel) const { return m_Width / (DOUBLE)iCountOfPixel; }
	inline const DOUBLE		GetDepthPerPixel(const UINT iCountOfPixel) const { return m_Depth / (DOUBLE)iCountOfPixel; }
	inline const DOUBLE		GetHeightPerPixel(const UINT iCountOfPixel) const { return m_Height / (DOUBLE)iCountOfPixel; }
public:
	void					ChangeDimension(const DOUBLE iWidth, const DOUBLE iDepth, const DOUBLE iHeight);
#pragma endregion

#pragma region General Function
public:
	const CGRectangle		GetBottom() const;
	const CGRectangle		GetTop() const;

	const CGRectangle		GetRectangle2D(const DOUBLE iZ = 0.) const;
	const DOUBLE			GetLongestLength() const;
	const DOUBLE			GetLongestLength2D() const;

protected:
	const BOOL				IsEqual(const CDimension & iDimension) const;
#pragma endregion

#pragma region CAD Functions
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	const BOOL				CopyFrom(const CBoundingBox & iBoundingBox);
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDimension *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);

	virtual const INT		ReadXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);
	virtual const INT		SaveXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);

	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDimension &		operator = (const CDimension & iDimension);
	const CDimension &		operator = (const CBoundingBox & iBoundingBox);
	const CDimension &		operator = (const INT iValue);
	const BOOL				operator == (const CDimension & iDimension) const;
	const BOOL				operator != (const CDimension & iDimension) const;
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Width, m_Depth, m_Height;
#pragma endregion
};

	}
}