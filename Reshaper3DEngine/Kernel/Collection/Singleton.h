#pragma once

namespace Kernel
{

	namespace Collection
	{

template<class T> class CSingleton
{
private:
	CSingleton(void)	{};
public:
	static T & GetInstance()
	{
		static T uniqueInstance;
		return uniqueInstance;
	}
};

#define DEFINE_SINGLETON(ModelType,UseType)		typedef CSingleton<ModelType>	UseType;

}
}