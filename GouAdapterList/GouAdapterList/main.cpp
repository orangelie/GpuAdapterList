#include "GpuAdapterList.h"

int main()
{
	try
	{
		std::unique_ptr<GpuAdapterConfirmer> gpuAdaterConfirmer(new GpuAdapterConfirmer);

		for (;;)
		{
			system("cls");
			std::cout << "[1] Gpu 확인" << std::endl;
			std::cout << "[2] Gpu 목록화" << std::endl;
			std::cout << "[3] 종료" << std::endl;

			int ascii = _getch();
			if (ascii == '1')
			{
				system("cls");
				std::cout << "확인된 디바이스: " << gpuAdaterConfirmer->ReadAvailableAdpater() << std::endl;
				std::cout << "활성화 여부: " << std::boolalpha << gpuAdaterConfirmer->CompareAdapterTo() << std::endl;

				{
					int _ = _getch();
				}
			}
			else if (ascii == '2')
			{
				system("cls");
				auto gpuList = gpuAdaterConfirmer->ListAdapters();

				for (size_t i = 0; i < gpuList.size(); ++i)
				{
					std::cout << i << ". " << gpuList[i] << std::endl;
				}

				gpuAdaterConfirmer->WriteAvailableAdpater(gpuList[_getch() - 48]);
			}
			else if (ascii == '3')
			{
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		MessageBoxA(0, e.what(), "# Warning #", MB_OK);
		return -1;
	}

	return 0;
}