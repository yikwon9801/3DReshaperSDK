#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IXMLObject);
	}

	namespace File
	{

		namespace XML
		{
			using namespace Kernel::Interface;

#pragma region Macro
#define BEGIN_SAVEELEMENT(document)											\
	ASSERT(document);	if(!document) return;								\
	BOOL bRet = FALSE;														\
	CHyString strValues;
#define END_SAVEELEMENT(AttriName, SetterFunction, Value, TopElementName)	\
	VERIFY(bRet = SetAttributeValueWithAttributeName(AttriName, strValues, TopElementName));	\
	if (!bRet) return;														\
	SetterFunction(Value);													\
	VERIFY(WriteXml());
#pragma endregion

RsDEFINE_DLL_CLASS(CXmlObject) : RsINHERITANCE(IXMLObject)
{
#pragma region Construction & Destruction
protected:
	CXmlObject();
	virtual ~CXmlObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CXmlDocument *	GetXmlDocument() const { return m_xmlDocument; }
	inline LPCTSTR		GetXmlFilePath() const { return m_FilePath; }
public:
	inline void			SetXmlFilePath(LPCTSTR iFilePath) { m_FilePath = iFilePath; }
#pragma endregion

#pragma region General Function
public:
	void				Load(const LPCTSTR iFilePath);
protected:
	void				Release();
private:
	void				Detach();

protected:
	const CString		GetAttributeName(CXmlElement & iElement) const;
	const CString		GetAttributeValue(CXmlElement & iElement) const;
	void				SetAttributeValue(CXmlElement & iElement, const CString iValue);
protected:
	const BOOL			SetAttributeValueWithAttributeName(const CString & iName, const CString & iValue, CXmlElement & iCategoryElment);
	const BOOL			SetAttributeValueWithAttributeName(const CString & iName, const CString & iValue, const CString & iCategory);

public:
	void				Attach(const LPCTSTR iFilePath, CXmlDocument * xmlDocument);
#pragma endregion

#pragma region Memeber Variable
protected:
	CXmlDocument *		m_xmlDocument;
	CString				m_FilePath;
#pragma endregion
};
		}
	}
}