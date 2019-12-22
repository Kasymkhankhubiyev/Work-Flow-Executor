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
void Parser::set_numbers(size_t& a)
{
	m_ind = a;
}
size_t Parser::Get_numbers()
{
	return m_ind;
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
void Read::TO_DO(std::string& str)
{
	m_fin.open(str, std::ofstream::app);
	if (!m_fin.is_open())
	{
		std::cout << "file cannot be read" << "/n";
	}
	else
	{
		try
		{
			if (my_ind == 0)
				throw "not good";
		}
		catch (const char* exception)
		{
			std::cout << "Warning! The last text was not saved. Do you want to continue?"
				<< "\n" << "1 - yess, 2 - no";
			size_t n; 
			std::cin >> n;
			if (n == 1)
				throw 1.0;
			else
			{
				m_fin.close();
				MyError Exception;
			}
		}
		catch (double)
		{
			my_ind = 0;
			while (!m_fin.eof())
			{
				std::string line;
				std::getline(m_fin, line);
				m_vect.push_back(line);
			}
		}		
	}
	m_fin.close();
}
void Write::TO_DO(std::string& str)
{
	m_fin1.open(str, std::ofstream::app);
	if (!m_fin1.is_open())
	{
		std::cout << "file cannot be read" << "/n";
	}
	else
	{
		my_ind = 1;
		size_t n = m_vect.size();
		for (int i = 0; i < n; i++)
		{
			m_fin1 << m_vect[i] << "\n";
		}
	}
	m_fin1.close();
}
void Sort::TO_DO(std::string& str)
{
	my_ind = 0;
	std::sort(m_vect.begin(), m_vect.end());
}
void Replace::TO_DO(std::string& str)
{
	std::vector<std::string>args;
	try
	{
		if (str.size() <= 1)
		{
			throw "No arguments";
		}			
		else
			throw 1.0;	
	}
	catch (const char* exception)
	{
		std::cout << " No arguments is given. This command cannot be done." << std::endl;
	}
	catch(double)
	{
		while (str.size() >= 1)  //std::string::npos
		{
			std::string token;
			std::string delimeter = " ";
			token = str.substr(0, str.find(delimeter));
			args.push_back(token);
			size_t n = token.size();
			int m = str.size();
			int q = m - n - 1;
			if (q > 0)
				str = str.substr(n + 1);
			else str.clear();
		}
		size_t n = m_vect.size();
		for (int i = 0; i < n; i++)
		{
			std::string trr = m_vect[i]; //нужно как-то поменять. 
			//trr.replace()
		}
	}
}
void Grep::TO_DO(std::string& str)
{
	my_ind = 0;
	size_t n = m_vect.size();
	std::vector<std::string>notes;
	for (int i = 0;i < n;i++)
	{		
		std::string token;
		std::string delimeter = " ";
		size_t n = m_vect[i].find(str, 0);
		if (n != std::string::npos)
			notes.push_back(m_vect[i]);
		else m_vect[i].clear();
	}
	m_vect.clear();
	for (int j = 0; j < notes.size(); j++)
	{
		m_vect.push_back(notes[j]);
	}
}
