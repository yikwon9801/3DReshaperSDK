#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
	}

	namespace Object
	{

		namespace Geometry
		{

			namespace Mesh
			{
				RsDEFINE_CLASS(CGFace);
				RsDEFINE_CLASS(CGPolyhedron);

				using namespace Kernel::File;
				using namespace Kernel::Math;
				using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CPolyhedronBoolean)
{
#pragma region Type Definition
private:
#pragma endregion

#pragma region Construction & Destruction
public:
	CPolyhedronBoolean(CGPolyhedron & iPolyhedron);
	virtual ~CPolyhedronBoolean();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Execution
public:
#pragma endregion

#pragma region Geometry
public:
	const INT				Difference(const CGPolyhedron & iPolyhedron, void * ioData);
private:
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	struct Internal;
	Internal *				m_Internal;
	CGPolyhedron &			m_Polyhedron;
#pragma endregion
};

			}
		}
	}
}