#include "Header.h"


Parser::Parser(std::string link)
{
	m_parser = link;
}
std::string Parser:: get_link()
{
	return m_parser;
}
std::string Parser :: get_line()
{
	std::string line;
	std::getline(m_fin, line);
	return line;
}
void Parser :: get_next_comm(std::string line)
{
	std::string str;
	char ch;
	m_fin.get(ch);
	int n = ch;
	m_ind = n;
	m_fin >> str;
	m_com = str;
	m_fin >> str;
	m_arg = str;
	str = "";
}
size_t Parser::get_com_arr(std::string& line)
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
void Parser::OpenFile()
{
	m_fin.open(m_parser, std::ofstream::app);
}
bool Parser::OpenInstruction()
{
	return m_fin.is_open();
}
bool Parser::endOfInstruction()
{
	return m_fin.eof();
}
size_t Parser::get_com_num(std::string& line)
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
std::string Parser:: get_com_name(std::string& line)
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
void Parser ::get_com_args(std::string& line, std::vector<std::string>& argument)
{
	if (line.size() >= 1)
	{
		while (line.size() >= 1)  //std::string::npos
		{
			std::string token;
			std::string delimeter = " ";
			token = line.substr(0, line.find(delimeter));
			argument.push_back(token);
			size_t n = token.size();
			int m = line.size();
			int q = m - n - 1;
			if (q > 0)
				line = line.substr(n + 1);
			else line.clear(); 
			

			//else trin = trin.substr(0);
		}
	}
	else argument.push_back("noarguments");
}
void Parser::CloseFile()
{
	m_fin.close();
}
Read::Read()
{
	m_Read_ind = 1;
}
