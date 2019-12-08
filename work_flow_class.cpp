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
int Parser::get_com_num()
{
	return m_ind;
}
std::string Parser:: get_con_name()
{
	return m_com;
}
std::string Parser ::get_com_atg()
{
	return m_arg;
}
void Parser::CloseFile()
{
	m_fin.close();
}
Read::Read()
{
	m_Read_ind = 1;
}
