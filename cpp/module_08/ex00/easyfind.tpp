

template < typename T>
typename T::iterator easyfind(T &lst, int value)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "easyfind " << "\x1b[0m" << std::endl;
	#endif
	
	typename T::iterator first = lst.begin();

    for (; first != lst.end(); ++first) {
        if (*first == value) {
            return first;
        }
    }
    
	throw NotFoundException();

};

std::map<int, int>::iterator easyfind(std::map<int, int> &lst, int value)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "easyfind " << "\x1b[0m" << std::endl;
	#endif

    for (std::map<int, int>::iterator first = lst.begin();
			 first != lst.end(); 
			 ++first) {
        if (first->second == value) {
            return first;
        }
    }
    
	throw NotFoundException();

};
