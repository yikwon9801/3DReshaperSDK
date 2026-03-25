#pragma once

#include <map>
#include <list>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;

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

		namespace XML
		{
			using namespace Kernel::String;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CBoostXmlDocument)
{
#pragma region Type Definition
public:
	typedef boost::property_tree::ptree	Node;
	typedef CBoostXmlElement::String	String;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CBoostXmlDocument();
	virtual ~CBoostXmlDocument();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

public:
	CBoostXmlElement	CreateRoot(const String & iName);
	CBoostXmlElement	GetRoot();

	const BOOL			Load(const String & iFileName);
	const BOOL			Load(CHAR * iBuffer);
	void				Save(const String & iFileName);
	void				Clear();

protected:
	virtual const BOOL	CopyFrom(const CBoostXmlDocument & iXmlDocument);

#pragma region Memeber Variable
//protected:
public:
	Node				m_root;
#pragma endregion
};

RsDEFINE_DLL_CLASS(CXmlDocument) : public CBoostXmlDocument//protected CBoostXmlDocument
{
#pragma region Construction & Destruction
public:
	CXmlDocument();
	virtual ~CXmlDocument();
protected:
	CXmlDocument(const CXmlDocument & iXmlDocument);
#pragma endregion

public:
	const BOOL			Load(CHAR * iBuffer) { return CBoostXmlDocument::Load(iBuffer); }
	const BOOL			Load(LPCTSTR iStream) { return CBoostXmlDocument::Load((LPCSTR)CStringA(iStream)); }
	const BOOL			Load(const CString & iFileName)	{ return CBoostXmlDocument::Load((LPCSTR)CStringA(iFileName)); }
	void				Save(const CString & iFileName) { CBoostXmlDocument::Save((LPCSTR)CStringA(iFileName)); }

protected:
	virtual const BOOL	CopyFrom(const CBoostXmlDocument & iXmlDocument);
public:
	CXmlDocument *		Clone() const;

public:
	CXmlElement			CreateRoot(const CString & iName);
	CXmlElement			GetRoot()	{ return CXmlElement(m_root); }
	CXmlElement			GetChild(LPCTSTR iName);

public:
	const CXmlDocument &	operator = (const CXmlDocument & iXmlDocument);

public:
	typedef map<CString, CXmlDocument *>	MapXmlDocument;
	typedef pair<CString, CXmlDocument *>	PairXmlDocument;
	static CXmlDocument::MapXmlDocument	LoadXMLs(const CHyString & iFilePath);
};
		}
	}
}