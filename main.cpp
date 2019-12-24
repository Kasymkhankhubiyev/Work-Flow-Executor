#include "Header.h"
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;

void main()
{
	size_t *arr = new size_t[1];  //выделяем динамическую память, массив нам понадобится для хранения списка последовательности команд
	std::map<std::string, Worker *> inst; //Workers storage
	inst["Read"] = new Read; //сразу заполняем наш контейнер, каждый указывает на класс обработчика
	inst["Write"] = new Write;
	inst["Sort"] = new Sort;
	inst["Grep"] = new Grep;
	inst["Replace"] = new Replace;

	size_t start_time = clock(); //записываем время начала работы
	
	Worker * pRead = inst["Read"];
	//	inst["Dump"] = new Dump;

	Worker* worker = nullptr;

	std::map<size_t, pair<Worker *, string>>programm;

	//создаем класс, позволяющий записывать данные в файл;
	int k = 0;
	std::string path = "Command.txt"; //название файла с определениями команд и порядком выполнения 
	Parser parser(path);
	parser.OpenFile(); //open может как открыть имеющийся файл по указанному маршруту, так и создать новый, так myFile просто появится у нас.
	try
	{
		if (!parser.OpenInstruction()) //проверяем, открылся ли файл
			std::cout << " Ups... something went wrong" << std::endl;
		else
		{
			int i = 0;
			try //здесь будем бросать искулючения
			{
				while (!parser.endOfInstruction()) //проверка, не закончился ли файл
				{
					std::string str;
					str = parser.get_line(); //получаем строку из файла
					if (str != "csed") //csed - терминатор потока обрабатываемых данных
					{
						size_t q = parser.get_com_num(str); //извлекаем индекс
						std::string trip = parser.get_com_name(str); //извлекаем название
						try {
							programm.at(q); //ищем элемент в контейнере с таким ключом 
							MyError Equalnums; //если элемент с таким ключем существует, бросится исключение одинковых индексов
							throw Equalnums; //если таковой ключ не найдется, тогда бросается исключение аут оф рендж, типа контейнер закончился
						}
						catch (MyError const& a) //ловим исключения одинаковых индексов и выбрасываем их итерации
						{
							throw a;
						}
						catch (std::out_of_range) //если все ок, тогда кладем в контейнер
						{
							worker = nullptr;
							worker = inst.at(trip);
							programm[q] = pair<Worker*, string>(inst[trip], str); //аргументы не разделены, если их несколько,

							std::cout << std::endl;
							//обработка аргументов реализована в классах обработчика
						}
					}
					else //переход к списку порядка выполнения
					{
						while (!parser.endOfInstruction())
						{
							std::string trin;
							trin = parser.get_line(); //получаем строку
							size_t n, num, ptr;
							size_t w = trin.size(); //смотрим ее размер
							size_t length = w / 3 + 1; //определяем количество цифр в строке, т.к. нам известна структура
							parser.set_numbers(length); //кладем значение в Parser
							delete[] arr;
							arr = nullptr;
							arr = new size_t[length]; //обнуляем массив и выделяем нужное количество памяти
							while (trin.size() >= 1)  //std::string::npos
							{
								arr[k] = parser.get_com_arr(trin); //получаем последовательность чисел и записываем в массив
								k++;
								//else trin = trin.substr(0);
							}
						}
					}
					i++;
				}
			}
			catch (std::exception const& Er) //ловим исключение одинаковых чисел
			{
				std::cout << Er.what() << "\n";
			}
		}
	}
	catch (std::exception const& Er)
	{
		std::cout << Er.what() << "\n";
	}
	catch (...) //любые другие исключения
	{
		std::cout << "Unknown ERROR" << "\n";
	}
	parser.CloseFile(); //закрываем файл команд

	try //ставим здесь try, т.к. из цикла могут вылетить исключения, говорящии о некоректности введенных аргументов
	{
		size_t n = parser.Get_numbers();
		for (int j = 0; j < n;j++)
		{
			//pair<Worker*, std::string> s = programm[arr[k]];
			//s.first->TO_DO(s.second);
			programm[arr[j]].first->TO_DO(programm[arr[j]].second); //закручиваем наш обработчик по порядку по массиву
		}
	}
	catch (std::exception const& Er)
	{
		std::cout << Er.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Unknown ERROR" << "\n";
	}
	/*std::string tpr = "in_put.txt";
	inst["Read"]->TO_DO(tpr);
	tpr = "a b";
	inst["Replace"]->TO_DO(tpr);
	tpr = "out_putt.txt";
	inst["Write"]->TO_DO(tpr);*/
	delete inst["Read"]; //зачищаем выделенную память
	delete inst["Write"];
	delete inst["Sort"];
	delete inst["Grep"];
	delete inst["Replace"];
	//delete inst["Dump"];
	delete[] arr; 

	size_t end_time = clock(); //время окончания работы, в конце выводим разницу времен, чтобы оценить затраченное на обработку время.

	std::cout << "It takes " << end_time - start_time << "minutes to work the commands out!   " << std::endl;
	std::cout << "Good bye!";
}
