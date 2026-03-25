#pragma once

namespace Kernel
{

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Draw
	{

		using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CRawImage) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	enum IMAGE_FORMAT_TYPE
	{
		IMAGE_FORMAT_TYPE_MONO8,
		IMAGE_FORMAT_TYPE_BAYER_RG8,
		IMAGE_FORMAT_TYPE_RGB,
	};
#pragma endregion

#pragma region Construction & Destruction
public:
	CRawImage();
	CRawImage(const UINT iWidth, const UINT iHeight, const IMAGE_FORMAT_TYPE iFormat, BYTE * iImage);
	CRawImage(const CRawImage & iImage);
	virtual ~CRawImage();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetWidth() const { return m_Width; }
	inline const UINT		GetHeight() const { return m_Height; }
	inline const IMAGE_FORMAT_TYPE	GetFormat() const { return m_Format; }
	inline const BYTE *		GetImage() const { return m_Image; }
	inline BYTE *			Image() { return m_Image; }
#pragma endregion

#pragma region General Function
public:
	const INT				ToRGB(CRawImage & oImage) const;

	BYTE *					Take();

	const INT				SaveRaw(LPCTSTR lpctFileName);

protected:
	const BOOL				IsEqual(const CRawImage & iImage) const;
	void					Release();

	const UINT				GetStride() const;
	const UINT				GetImageSize() const;
	const UINT				GetBitDepth() const;
	const UINT				GetChannel() const;

	void					Change(const UINT iWidth, const UINT iHeight, const IMAGE_FORMAT_TYPE iFormat, BYTE * iImage);
#pragma endregion

#pragma region Image Processing
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CRawImage *		Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CRawImage &		operator = (const CRawImage & iImage);
	const BOOL				operator == (const CRawImage & iImage) const;
	const BOOL				operator != (const CRawImage & iImage) const;
#pragma endregion

#pragma region Static Function
public:
	static void				ConvertFromBayerRG8ToDemosaicNearestRGGB(const BYTE iSrc[], const UINT iWidth, const UINT iHeight, BYTE oDest[]);
#pragma endregion

#pragma region Memeber Variable
private:
	BYTE *					m_Image;
	UINT					m_Width;
	UINT					m_Height;
	IMAGE_FORMAT_TYPE		m_Format;
#pragma endregion
};

	}
}