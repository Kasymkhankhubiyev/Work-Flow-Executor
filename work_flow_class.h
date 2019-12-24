#ifndef Work_flow_class_H 
#define Work_flow_class_H
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

//void compare_df(std::map<std::string, Worker*>& inst, std::string& str);

class res
{};
class Parser //анализатор текстовой информации;
{
private:
	std::string m_parser;
	std::ifstream m_fin; //для чтения файла
	size_t m_ind; //для сохранения кол-ва выполняемы действий
	std::string m_com;
	std::string m_arg;
public:
	Parser(std::string link); //конструктор

	std::string get_link();

	std::string get_line();

	void set_numbers(size_t& a);

	size_t Get_numbers();

	void OpenFile();

	bool OpenInstruction();

	bool endOfInstruction();

	size_t get_com_num(std::string& line);

	size_t get_com_arr(std::string& line);

	std::string get_com_name(std::string& line);

	void get_com_args(std::string& line, std::vector<std::string>& argument); 

	void CloseFile();

};
class Validator
{};
class Worker //релизуем через наследование.
{ 
	
	
	std::string m_str;
protected:
	static std::vector<std::string> m_vect;	
	static int my_ind;
public:
	void initData(std::string source);
	virtual void TO_DO(std::string& str) = 0;
};
class Read : public Worker
{
	size_t m_index;
	std::ifstream m_fin;
public:
	Read()
	{
		m_index = 0;
	}
	void TO_DO(std::string& str);
};
class Write : public Worker
{
	std::ofstream m_fin1; //чтобы записывать
public:
	void TO_DO(std::string& str);
};
class Sort : public Worker
{
public:
	void TO_DO(std::string& str);
};
class Grep : public Worker
{
public:
	void TO_DO(std::string& str);
};
class Replace : public Worker
{
	int m_Replace_ind;
public:
	void TO_DO(std::string& str);
};
/*class Dump : public Worker
{
	int m_Dump_ind;
public:
	Dimp() {}
	void TO_DO(std::string& str);
};*/
class MyError : std::exception
{
	const char* what() const;
};
#endif//


