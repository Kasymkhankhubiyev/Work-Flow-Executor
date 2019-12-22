#ifndef Work_flow_class_H 
#define Work_flow_class_H
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
	static std::string* resource;
public:
	virtual void TO_DO() = 0;
};
class Read : public Worker
{
	int m_Read_ind;
public:
	Read();

	void TO_DO()
	{}
};
class Write : public Worker
{
	int m_Write_ind;
public:
	void TO_DO()
	{}
};
class Sort : public Worker
{
	int m_Sort_ind;
public:
	void TO_DO()
	{}
};
class Grep : public Worker
{
	int m_Grep_ind;
public:
	void TO_DO()
	{}
};
class Replace : public Worker
{
	int m_Replace_ind;
public:
	void TO_DO()
	{}
};
class Dump : public Worker
{
	int m_Dump_ind;
public:
	void TO_DO()
	{}
};
#endif//

