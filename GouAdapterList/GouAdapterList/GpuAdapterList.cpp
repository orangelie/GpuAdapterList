#include "GpuAdapterList.h"

GpuAdapterConfirmer::GpuAdapterConfirmer()
{
	CreateDXGIFactory1(IID_PPV_ARGS(mFactory.GetAddressOf()));
}

GpuAdapterConfirmer::~GpuAdapterConfirmer()
{
}

bool GpuAdapterConfirmer::CompareAdapterTo()
{
	std::string cmpAdapter;
	std::ifstream reader("adapter.txt");

	if (reader.is_open())
	{
		std::string tempString;

		reader >> cmpAdapter;
		for (; !reader.eof();)
		{
			reader >> tempString;
			cmpAdapter += " " + tempString;
		}

		reader.close();
	}
	else
	{
		return false;
	}

	auto gpuList = ListAdapters();

	for (size_t i = 0; i < gpuList.size(); ++i)
	{
		if (gpuList[i] == cmpAdapter)
		{
			return true;
		}
	}

	return false;
}

std::vector<std::string> GpuAdapterConfirmer::ListAdapters()
{
	std::vector<std::string> adapterList;
	IDXGIAdapter1* adapter;

	for (UINT i = 0; mFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND;++i)
	{
		DXGI_ADAPTER_DESC1 adapterDesc = {};
		adapter->GetDesc1(&adapterDesc);

		adapterList.push_back(std::wstring_convert<std::codecvt_utf8<WCHAR>, WCHAR>().to_bytes(adapterDesc.Description));
	}

	return adapterList;
}

void GpuAdapterConfirmer::WriteAvailableAdpater(const std::string& lWriteAdapter)
{
	std::ofstream writer("adapter.txt");

	if (writer.is_open())
	{
		writer << lWriteAdapter;
		writer.close();
	}
}

std::string GpuAdapterConfirmer::ReadAvailableAdpater() const
{
	std::string cmpAdapter;
	std::ifstream reader("adapter.txt");

	if (reader.is_open())
	{
		std::string tempString;

		reader >> cmpAdapter;
		for (; !reader.eof();)
		{
			reader >> tempString;
			cmpAdapter += " " + tempString;
		}

		reader.close();
	}

	return cmpAdapter;
}