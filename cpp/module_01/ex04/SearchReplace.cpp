#include "SearchReplace.hpp"

SearchReplace::SearchReplace()
{

}

SearchReplace::~SearchReplace()
{
	if (_file_in.is_open())
		_file_in.close();
	if (_file_out.is_open())
		_file_out.close();
}

void SearchReplace::setSearch(const std::string &search)
{
	_search = search;
}

void SearchReplace::setReplace(const std::string &replace)
{
	_replace = replace;
}

void SearchReplace::setFileName(const std::string &filename)
{
	std::string filenameout = filename + ".replace";

	_file_in.open(filename.c_str(), std::ios_base::in);
	if (!_file_in.is_open())
	{
		throw OpenFileException().setFileName(filename);
	}
	_file_out.open(filenameout.c_str(), std::ios_base::out|std::ios_base::trunc);
	if (!_file_out.is_open())
	{
		throw OpenFileException().setFileName(filenameout);
	}
}

void SearchReplace::replace( void )
{
	std::string line;
	int pos;
	int last;

	if (! _file_in.is_open() || ! _file_out.is_open())
		return ;

	while (!_file_in.eof())
	{
		std::getline(_file_in, line);
		std::cout << " << " << line << std::endl;
		std::cout << " >> ";
		pos = -1;
		last = 0;
		do
		{
			pos = line.find(_search, pos + 1);
			if (pos > -1)
			{
				std::cout << line.substr(last, pos - last);
				std::cout << ANSI_COLOR_RED;
				std::cout << _replace;
				std::cout << ANSI_COLOR_RESET;

				line.erase(pos, _search.length());
				line.insert(pos, _replace);

				last = pos + _replace.length();

			}
		} while (pos > -1);

		std::cout << line.substr(last, line.length() - last) << std::endl;

		_file_out << line << std::endl;
	}
	_file_in.close();
	_file_out.close();	
}