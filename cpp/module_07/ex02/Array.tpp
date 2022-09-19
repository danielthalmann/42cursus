
#define CLASSNAME "Array<>"

template <typename T>
Array<T>::Array( void ) : _size(0)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_size = 0;
	_values = NULL;
}

template <typename T>
Array<T>::Array(size_t size)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_values = new T[size]();
	_size = size;
}

template <typename T>
Array<T>::Array(Array &array)
{
	(*this) = (array);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

template <typename T>
Array<T>::~Array()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	if (_size > 0)
		delete [] _values;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &array)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	if (_size > 0)
		delete [] _values;
	
	_size = array._size;
	_values = new T[_size]();

	for (size_t i = 0; i < _size; i++)
		(_values[i]) = (array._values[i]);

	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= _size) {
		throw Array<T>::OutOfLimitException();
    }

	return _values[i];
}

template <typename T>
int Array<T>::size()
{
	return _size;
}