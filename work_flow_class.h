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
	std::ifstream m_fin;
	size_t m_ind;
	std::string m_com;
	std::string m_arg;
public:
	Parser(std::string link);
	/*string get_line()
	{
		std::string str;
		return getline(m_fin, str);
	}*/
	std::string get_link();

	std::string get_line();

	void set_numbers(size_t& a);

	size_t Get_numbers();

	void get_next_comm(std::string line);

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
class Worker
{
	//static std::string* resource;
	std::string m_str;
protected:
	static std::vector<std::string> m_vect;	
	static int my_ind;
public:
	
	virtual void TO_DO(std::string& str) = 0;
};
class Read : public Worker
{
	int m_Read_ind;
	std::ifstream m_fin;
public:
	Read();
	void TO_DO(std::string& str);
};
class Write : public Worker
{
	std::ofstream m_fin1;
	int m_Write_ind;
public:
	void TO_DO(std::string& str);
};
class Sort : public Worker
{
	int m_Sort_ind;
public:
	void TO_DO(std::string& str);
};
class Grep : public Worker
{
	int m_Grep_ind;
public:
	void TO_DO(std::string& str);
};
class Replace : public Worker
{
	int m_Replace_ind;
public:
	void TO_DO(std::string& str);
};
class Dump : public Worker
{
	int m_Dump_ind;
public:
	void TO_DO(std::string& str);
};
class MyError : std::exception {
	const char* what() const;
};
#endif//


