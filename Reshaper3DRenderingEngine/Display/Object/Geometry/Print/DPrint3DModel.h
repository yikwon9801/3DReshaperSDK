#pragma once

namespace Display
{

	namespace Object
	{
		namespace Vision
		{
			RsDEFINE_CLASS(CDCamera);
		}

		namespace Geometry
		{

			namespace Print
			{
				using namespace Display::Object::Vision;

RsDEFINE_DLL_CLASS(CDPrint3DModel) : RsINHERITANCE(CDCompModel)
{
#pragma region Construction & Destruction
public:
	CDPrint3DModel();
	CDPrint3DModel(CDevicePreference * iDevice, CMaterialPreference * iMaterial, CSlicePreference * iSlice);
	virtual ~CDPrint3DModel();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline CDevicePreference *		GetDevicePreference() { return m_Device; }
	inline CMaterialPreference *	GetMaterialPreference() { return m_Material; }
	inline CSlicePreference *		GetSlicePreference() { return m_Slice; }
#pragma endregion

public:
	void					SetCurScene(CDOpenGLScene * iScene);

protected:
	void					Release();

#pragma region Preference
public:
	inline const CDevicePreference *	GetDevicePreference() const	{ return m_Device; }
	inline const CMaterialPreference *	GetMaterialPreference() const { return m_Material; }
	inline const CSlicePreference *		GetSlicePreference() const { return m_Slice; }
#pragma endregion

#pragma region Model
public:
	const BOOL				AddComponent(CDComponent * iComponent);
	const BOOL				DeleteComponent(CDComponent * iComponent);
	void					DeleteAllComponents();
	void					DeleteAllTemporaryComponents();
	const BOOL				RemoveComponent(const CDComponent * iComponent);

	void					AddBaseComponent(CDComponent * iComponent);
	void					AddFixedOrderComponent(CDComponent * iComponent);
	void					AddToolComponent(CDComponent * iComponent);
#pragma endregion

#pragma region Camera
public:
	const CDCamera &		GetCamera() const;
#pragma endregion

private:
	CDevicePreference *		m_Device;
	CMaterialPreference *	m_Material;
	CSlicePreference *		m_Slice;
};

			}
		}
	}
}