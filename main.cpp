#include "Header.h"

#include <cstring>
#include <sstream>

using namespace std;

void get_next_command(std::string line) //index, name, arg
{

}

int main()
{
	std::map<std::string, Worker*> inst; //Workers storage
	inst["Read"] = new Read();
	inst["Write"] = new Write();
	inst["Sort"] = new Sort();
	inst["Grep"] = new Grep();
	inst["Replace"] = new Replace();
	inst["Dump"] = new Dump();

	std::vector<std::string>method;

	std::string * resource = new string; 

	std::map<size_t,pair<Worker*, vector<string>>>programm;

	 //создаем класс, позволяющий записывать данные в файл;
	 
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
			method.push_back(str);
			i++;
		}
	}
	parser.CloseFile();

	int vector_size = method.size();
	for (int j = 0; j < vector_size; j++)
	{
		std::string command = method[j]; // get command line
		// реализуем метод считвания символов строки"
		
	}

	cout << "Now, let's print out the vector";
	
	for (int k = 0; k < vector_size; k++)
	{
		cout << method[k] << '\n';
	}
	cout << "Good bye!";
}
