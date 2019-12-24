#include "Header.h"



std::vector<std::string> Worker::m_vect;

int Worker::my_ind = 0;

Parser::Parser(std::string link) //конструктор - главная задача открыть файл команд и его обработать
{
	m_parser = link;
}
std::string Parser:: get_link() //получаем название файла
{
	return m_parser;
}
std::string Parser :: get_line() //получаем строку
{
	std::string line;
	std::getline(m_fin, line);
	return line;
}
void Parser::set_numbers(size_t& a) //сохраняем кол-во операций
{
	m_ind = a;
}
size_t Parser::Get_numbers() //извлекаем предстоящее выполнить число операций
{
	return m_ind;
}
size_t Parser::get_com_arr(std::string& line) //извлекаем последовательность выполнения команд
{
	//size_t k = parser.get_com_num(trin);
	std::string token;
	std::string delimeter = "->";
	token = line.substr(0, line.find(delimeter));
	size_t n = token.size();
	size_t num = 0;
	size_t ptr = static_cast<size_t>(stoi(token, &num));
	int h = line.size();
	int c = n;
	if ((h - c - 2) > 0) { line = line.substr(n + 2); }
	else line.clear();
	return ptr;
}
void Parser::OpenFile() //функция открытия файла
{
	m_fin.open(m_parser, std::ofstream::app);
}
bool Parser::OpenInstruction() //если файл открылся возвращает  true
{
	return m_fin.is_open();
}
bool Parser::endOfInstruction() //если конецб говорит false;
{
	return m_fin.eof();
}
/*void Parser::initData(std::vector<std::string source>)
{
	resource = &source;
}*/
size_t Parser::get_com_num(std::string& line) //извлекаем индекс команды
{
	std::string token;
	std::string delimeter = " ";
	token = line.substr(0, line.find(delimeter));
	size_t n = token.size(); 
	line = line.substr(n + 1);
	size_t num = 0;
	size_t ptr = static_cast<size_t>(stoi(token, &num));
	return ptr;
}
std::string Parser:: get_com_name(std::string& line) //извлекаем название команды
{
	std::string token;
	std::string delimeter = " ";
	token = line.substr(0, line.find(delimeter));
	size_t n = token.size();
	int m = line.size();
	int q = m - n - 1;
	if(q>0)
		line = line.substr(n + 1);
	else line.clear();
	return token;
}
void Parser ::get_com_args(std::string& line, std::vector<std::string>& argument) //на случай, если захочется обработать аргументы в Parser,
														//но в этом случаеб передавать аргументы нужно как контейнер вектор std::vector<std::string>arguments
													//я же передаю просто как строку.
{
	if (line.size() >= 1) //проверка на длинуб т.е. есть ли смысл вообще начинать
	{
		while (line.size() >= 1)  //std::string::npos
		{
			std::string token;
			std::string delimeter = " "; //разделитель
			token = line.substr(0, line.find(delimeter)); //извлекаем аргумент
			argument.push_back(token);
			size_t n = token.size();
			int m = line.size();
			int q = m - n - 1;
			if (q > 0)
				line = line.substr(n + 1);
			else line.clear(); //зачищаем
		}
	}
	else argument.push_back("noarguments"); //нету аргументов, здесь можно кинуть исключение
}
void Parser::CloseFile() //закрытие файла
{
	m_fin.close();
}
void Read::TO_DO(std::string& str) //функция действия для чтения
{
	m_index = m_index++;
	m_fin.open(str, std::ofstream::app); //открываемый файл по аргументц
	if (!m_fin.is_open()) //проверка на открытие 
	{
		std::cout << "file cannot be read" << "/n";
	}
	else
	{
		try //кидаем исключения
		{
			if(m_index!=0)
			{	if (my_ind == 0) //у класса Worker есть protected переменная, позволяющая отслеживать, сохранили (записали в файл) мы поток информации (она хранится в 
						//векторе и он protected). Чтение файла и любые изменения зануляют переменную, а запись файла присваивает 1. По умолчанию в начале my_ind=1;
				throw "not good";
			}
			else throw 1.0; //если m_index==0; это значит, что рид использует первый раз! 
		}
		catch (const char* exception) //хотим узнатьб согласен ли пользователь на безвозвратную потерю данных?
		{
			std::cout << "Warning! The last text was not saved. Do you want to continue?"
				<< "\n" << "1 - yess, 2 - no";
			size_t n; 
			std::cin >> n;
			if (n == 1)
				throw 1.0;
			else
			{
				m_fin.close(); //по хорошему здесь нужно записать данные и выйти
				MyError Exception;
			}
		}
		catch (double) // если пользователь согласен потерять данные
		{
			my_ind = 0;
			while (!m_fin.eof())
			{
				std::string line;
				std::getline(m_fin, line);
				m_vect.push_back(line);
			}
			size_t l = m_vect.size();
			std::cout << l << std::endl;
		}	
		
	}
	m_fin.close(); // закрытие файла
}
void Write::TO_DO(std::string& str) //запись данных из вектора
{
	m_fin1.open(str, std::ofstream::app);
	if (!m_fin1.is_open()) //проверка на открытие файла
	{
		std::cout << "file cannot be read" << "/n";
	}
	else
	{
		my_ind = 1; //записываем, а это значит сохраняем потоковую информацию
		size_t n = m_vect.size();
		for (int i = 0; i < n; i++) //тупо записываем в файл
		{
			m_fin1 << m_vect[i] << "\n";
		}
	}
	m_fin1.close(); //а как насчет очисти предыдущей информации???
}
void Sort::TO_DO(std::string& str)
{
	my_ind = 0;
	std::sort(m_vect.begin(), m_vect.end()); //просто сортировка 
}
void Replace::TO_DO(std::string& str) //меняем местами
{
	std::vector<std::string>args;
	try
	{
		if (str.size() <= 1) //проверка на наличие аргументов
		{
			throw "No arguments"; //бросаем char
		}			
		else
			throw 1.0;	//double если все хорошо
	}
	catch (const char* exception)//нет аргументов
	{
		std::cout << " No arguments is given. This command cannot be done." << std::endl;
	}
	catch(double) //все хорошо
	{
		while (str.size() >= 1)  //std::string::npos
		{
			std::string token;
			std::string delimeter = " "; //разделитель
			token = str.substr(0, str.find(delimeter));//находим аргументы
			args.push_back(token);
			size_t n = token.size();
			int m = str.size();
			int q = m - n - 1;
			if (q > 0)
				str = str.substr(n + 1);
			else str.clear();
		}
		size_t n = m_vect.size(); //получаем количество строк
		for (int i = 0; i < n; i++)
		{
			std::string trr = m_vect[i]; //все простоб первый аргумент это символ, который нужно убрать, а второй - тот, что нужно поставить на место первого! 
			//trr.replace()
		}
	}
}
void Grep::TO_DO(std::string& str) //оставляет только строки, указанный символ
{
	my_ind = 0; //показываем, что теперь поток данных не такой как в файле out_putt
	size_t n = m_vect.size();
	std::vector<std::string>notes; //вводим промежуточный контейнер, в него сохраним все строки, содержащий необхоимый символ
	for (int i = 0;i < n;i++)
	{		
		std::string token;
		std::string delimeter = " ";
		size_t n = m_vect[i].find(str, 0);
		if (n != std::string::npos) //проверка, найдется ли хотя бы один символб эта функция ищет до первой встречи в строке, можно найти и все упоминания в строке
			notes.push_back(m_vect[i]);
		else m_vect[i].clear();
	}
	m_vect.clear(); //чистим общий вектор
	for (int j = 0; j < notes.size(); j++)
	{
		m_vect.push_back(notes[j]); //переписываем значения
	}
}
const char *MyError::what() const {
	return "Equal numers of commands\n";
}
