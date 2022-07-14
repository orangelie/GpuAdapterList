#pragma once
#pragma comment(lib, "dxguid")
#pragma comment(lib, "dxgi")

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <locale>
#include <codecvt>

#include <conio.h>
#include <wrl.h>
#include <Windows.h>
#include <dxgi1_4.h>

class GpuAdapterConfirmer
{
public:
	GpuAdapterConfirmer();
	virtual ~GpuAdapterConfirmer();
	GpuAdapterConfirmer& operator=(const GpuAdapterConfirmer&) = delete;
	GpuAdapterConfirmer(const GpuAdapterConfirmer&) = delete;

	bool CompareAdapterTo();
	std::vector<std::string> ListAdapters();
	void WriteAvailableAdpater(const std::string& lWriteAdapter);
	std::string ReadAvailableAdpater() const;

private:
	Microsoft::WRL::ComPtr<IDXGIFactory1> mFactory;

};