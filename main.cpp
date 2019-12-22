#include "Header.h"
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
	size_t *arr = new size_t[1]; 
	std::map<std::string, Worker*> inst; //Workers storage
	inst["Read"] = new Read;
	inst["Write"] = new Write;
	inst["Sort"] = new Sort;
	inst["Grep"] = new Grep;
	inst["Replace"] = new Replace;
	inst["Dump"] = new Dump;

	std::map<size_t,pair<Worker*,string>>programm;

	//создаем класс, позволяющий записывать данные в файл;
	int k = 0;
	std::string path = "Command.txt";
	Parser parser(path);
	parser.OpenFile(); //open может как открыть имеющийся файл по указанному маршруту, так и создать новый, так myFile просто появится у нас.
	try
	{
		if (!parser.OpenInstruction())
		std::cout << " Ups... something went wrong" << std :: endl;
		else
		{
			int i = 0;
			try
			{
				while (!parser.endOfInstruction())
				{
					std::string str;
					str = parser.get_line();
					if (str != "csed")
					{
						size_t q = parser.get_com_num(str);
						std::string trip = parser.get_com_name(str);
						try {
							programm.at(q); //ищем элемент в контейнере с таким ключом 
							MyError Equalnums;
							throw Equalnums;
						}
						catch(MyError const& a)
						{
							throw a;
						}
						catch (std::out_of_range)
						{
							programm[q] = pair<Worker*,string>(inst[trip], str);
						}						
						//programm[0].first //worker*
						//programm[0].second //argument
					}
					else
					{
						while (!parser.endOfInstruction())
						{
							std::string trin;
							trin = parser.get_line();
							size_t n, num, ptr;
							size_t w = trin.size();
							size_t length = w / 3 + 2;
							parser.set_numbers(length);
							delete[] arr;
							arr = nullptr;
							arr = new size_t[length];
							while (trin.size() >= 1 )  //std::string::npos
							{						
								arr[k] = parser.get_com_arr(trin);
								k++;
								//else trin = trin.substr(0);
							}					
						}
					}
					i++;
				}
			}
			catch (std::exception const& Er)
			{
				std::cout << Er.what() << "\n";
			}			
		}
	} 
	catch (std::exception const& Er)
	{
		std::cout << Er.what() << "\n";
	}
	catch(...)
	{
			std::cout << "Unknown ERROR" << "\n";
	}
	parser.CloseFile();
	
	/*try
	{
		size_t n = parser.Get_numbers();
		for (int j = 0; j < n;j++)
		{
			pair<Worker*, std::string>& s = programm[arr[k]];
			s.first->TO_DO(s.second);
		}
	}
	catch (std::exception const& Er)
	{
		std::cout << Er.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Unknown ERROR" << "\n";
	}*/
	
	
	delete inst["Read"];
	delete inst["Write"];
	delete inst["Sort"];
	delete inst["Grep"];
	delete inst["Replace"];
	delete inst["Dump"];
	delete[] arr; 
	std::cout << "Good bye!";
}
