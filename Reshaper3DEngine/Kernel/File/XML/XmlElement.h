#pragma once

#include <list>
using namespace std;

#include <boost\property_tree\ptree.hpp>

namespace Kernel
{
	namespace File
	{

		namespace XML
		{

RsDEFINE_DLL_CLASS(CBoostXmlElement)
{
#pragma region Type Definition
public:
	typedef boost::property_tree::ptree				Node;
	typedef boost::property_tree::ptree::iterator	NodeItr;
	typedef boost::property_tree::ptree::key_type	NodeKey;
	typedef NodeKey									String;
#pragma endregion

#pragma region Construction & Destruction
public:
	CBoostXmlElement(Node & element);
	CBoostXmlElement(const String & name, Node & element);
	virtual ~CBoostXmlElement();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

public:
	const CBoostXmlElement::String &	GetData() const;
	void				SetData(const String & iString);

	void				GetAttribute(const String & iName, String & oValue) const;
	void				SetAttribute(const String & iName, const String & iValue);
	template<class _type> const _type GetAttribute(const String & iName) const
	{
		String temp = Keyword_XmlAttri;
		temp += iName;
		return m_Node.get<_type>(temp.c_str());
	}
	template<class _type> void SetAttribute(const String & iName, const _type iValue)
	{
		String temp = Keyword_XmlAttri;
		temp += iName;
		m_Node.put<_type>(temp.c_str(), iValue);
	}
	CBoostXmlElement	AddChild(const String & iName);
	void				RemoveChild(const String & iName);
	CBoostXmlElement	FindChild(const String & iPath);

	RsDEFINE_DLL_CLASS(Iterator)
	{
	public:
		Iterator(NodeItr iBeg, NodeItr iEnd);
		const BOOL		HasNext();
		CBoostXmlElement	GetNext();
	private:
		NodeItr itr, end;
	};
	Iterator			GetChilds();

#pragma region Memeber Variable
protected:
	Node &				m_Node;
	String				m_Name;
#pragma endregion
};

#pragma region "boost xml keyword"
const CBoostXmlElement::String Keyword_XmlAttri = "<xmlattr>.";
#pragma endregion

RsDEFINE_DLL_CLASS(CXmlElement) : protected CBoostXmlElement
{
public:
	typedef CBoostXmlElement::Iterator	Iterator;
#pragma region Construction & Destruction
public:
	CXmlElement(CBoostXmlElement::Node & element);
	virtual ~CXmlElement();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CString	GetName() const	{ return CString(m_Name.c_str()); }
	inline const CString	GetData() const { return CString(m_Node.data().c_str()); }
#pragma endregion

public:
	CXmlElement				AddChild(const CString & iName);
	CXmlElement				GetChild(const CString iPath);
	const BOOL				IsChild(const CString iName);
	Iterator				GetChilds();

	template<class _type> const _type GetAttribute(const CString iName) const
	{
		CStringA strName(iName);
		CBoostXmlElement::String Name = (LPCSTR)strName;
		return CBoostXmlElement::GetAttribute<_type>(Name);
	}
	template<class _type> void SetAttribute(const CString iName, const _type iValue)
	{
		CStringA strName(iName);
		CBoostXmlElement::String Name = (LPCSTR)strName;
		CBoostXmlElement::SetAttribute<_type>(Name, iValue);
	}
	void					SetAttributeValueWithAttributeName(const CString & iName, const CString & iValue);
};
		}
	}
}