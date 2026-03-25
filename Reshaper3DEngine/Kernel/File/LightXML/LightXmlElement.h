#pragma once
#pragma once

#include <list>

using namespace std;

namespace tinyxml2
{
	RsDEFINE_CLASS(XMLElement);
}

namespace Kernel
{
	namespace File
	{
		namespace LightXML
		{
			using namespace tinyxml2;

			typedef tinyxml2::XMLElement	LightXmlElement;
			//typedef tinyxml2::XMLElement	TinyXmlElement;

			/*RsDEFINE_DLL_CLASS(LightXmlElement)
			{
			public:
				LightXmlElement(TinyXmlElement& element);
				LightXmlElement(TinyXmlElement* element);
				~LightXmlElement();

			#pragma region Setter & Getter function
			public:
				const CString	GetName() const; 
				const CString	GetData() const;
			#pragma endregion

			public:
				LightXmlElement*		AddChild(const CString & iName);
				LightXmlElement*		GetChild(const CString iPath);
				const BOOL				IsChild(const CString iName);
				LightXmlElement*		GetChilds();

				CString GetAttribute(const CString iName);
				void SetAttribute(const CString iName, const CString iValue);

				TinyXmlElement* FirstChildElement();
				TinyXmlElement* NextSiblingElement();
				int IntText();
				double DoubleText();
				float FloatText();

				TinyXmlElement* GetNode() { return m_Element; }

				const char* Attribute(CStringA attrName);

			private:
				TinyXmlElement* m_Element;
			};*/
		}
	}
}