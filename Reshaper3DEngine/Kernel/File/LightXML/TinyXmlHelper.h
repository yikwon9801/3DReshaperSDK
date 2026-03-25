#pragma once

namespace tinyxml2
{
RsDEFINE_DLL_CLASS(TinyXmlHelper)
{
public:
	static tinyxml2::XMLElement* FindChildElement(tinyxml2::XMLElement* pParent, const char* pstrName, bool bRecursive = false);
	static tinyxml2::XMLElement* MakeChildElement(tinyxml2::XMLElement* pParent, const char* pstrName);
	static INT CompareModeName(tinyxml2::XMLElement* pNode, const char* pstrName);


};
}