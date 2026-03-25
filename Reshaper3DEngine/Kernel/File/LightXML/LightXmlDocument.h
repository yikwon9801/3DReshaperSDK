#pragma once

#include <map>
#include <list>

using namespace std;

namespace tinyxml2
{
	RsDEFINE_CLASS(XMLDocument);
}

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CUtil);
	}

	namespace File
	{

		namespace LightXML
		{
			using namespace Kernel::String;
			using namespace Kernel::Util;
			
RsDEFINE_DLL_CLASS(CLightXmlDocument) : public tinyxml2::XMLDocument
{
#pragma region Type Definition
public:
	typedef map<CString, CLightXmlDocument *>	MapXmlDocument;
	typedef pair<CString, CLightXmlDocument *>	PairXmlDocument;
#pragma endregion

#pragma region Construction & Destruction
public:
	CLightXmlDocument();
	virtual ~CLightXmlDocument();
protected:
	CLightXmlDocument(const CLightXmlDocument & iXmlDocument);
#pragma endregion

#pragma region General Function
public:
	const BOOL			Load(CHAR * iBuffer);
	const BOOL			Load(LPCTSTR iFilePath);
	const BOOL			Load(const CString & iFileName);
	FILE*				LoadW(const CString & iFileName);
	const BOOL			Save(CStringA& oXmlText);
	const BOOL			Save(const CString & iFileName);
	const BOOL			SaveW(const CString & iFileName);
public:
	LightXmlElement*	CreateRoot(const CString & iName);
	LightXmlElement*	GetRoot() { return m_pRootNode; }
	LightXmlElement*	GetChild(LPCTSTR iName);
	LightXmlElement*    CreateElement(CStringA iName);

#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CLightXmlDocument & iXmlDocument);
public:
	CLightXmlDocument *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CLightXmlDocument &	operator = (const CLightXmlDocument & iXmlDocument);
#pragma endregion

#pragma region Static fuction
public:
	static CLightXmlDocument::MapXmlDocument	LoadXMLs(const CHyString & iFilePath);
#pragma endregion

#pragma region Memeber Variable
public:
	LightXmlElement*		m_pRootNode;
#pragma endregion
};
		}
	}
}