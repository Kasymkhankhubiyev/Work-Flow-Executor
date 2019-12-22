#include "Header.h"

#include <cstring>
#include <sstream>

using namespace std;



int main()
{
	size_t*arr = new size_t[100]; 
	std::map<std::string, Worker*> inst; //Workers storage
	inst["Read"] = new Read();
	inst["Write"] = new Write();
	inst["Sort"] = new Sort();
	inst["Grep"] = new Grep();
	inst["Replace"] = new Replace();
	inst["Dump"] = new Dump();

	std::vector<std::string>method;
	std::vector<std::string>argument;

	//std::string * resource = new string; 

	std::map<size_t,pair<Worker*,vector<string>>>programm;

	//создаем класс, позволяющий записывать данные в файл;
	int k = 0;
	std::string path = "Command.txt";
	Parser parser(path);
	parser.OpenFile(); //open может как открыть имеющийся файл по указанному маршруту, так и создать новый, так myFile просто появится у нас.
	if (!parser.OpenInstruction())
		std::cout << " Ups... something went wrong" << std :: endl;
	else
	{
		int i = 0;
		while (!parser.endOfInstruction())
		{
			std::string str;
			str = parser.get_line();
			if (str != "csed")
			{
				size_t q = parser.get_com_num(str);
				std::string trip = parser.get_com_name(str);
				method.push_back(trip);
				if(inst[trip] == nullptr)
				{
					//compare_df(inst, trip);
					//нужно создать новый элемент, иначе пропустить все остальное, вообще, например, сортировку можно вызвать несколько раз, сначала один аргумент,
					//потом другой, не совсем понятно. когда ставить сравнение, с другой стороны, мы же не будем несколько раз куда-то указывать, думаю,
				// вполне достточно проверить самый простой случай.
				}
				//parser.get_com_args(str,argument); //вообще можно не разделять аргументы
				programm[q] = pair<Worker*,vector<string>>(inst[trip], str);
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
	parser.CloseFile();
	//теперь нужно все распихать по контейнерам.
	delete inst["Read"];
	delete inst["Write"];
	delete inst["Sort"];
	delete inst["Grep"];
	delete inst["Replace"];
	delete inst["Dump"];
	cout << "Good bye!";
}
