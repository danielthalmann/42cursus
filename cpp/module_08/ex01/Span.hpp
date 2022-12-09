#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

class Span
{
public:
	Span();
	Span(unsigned int size);
	Span(Span &span);
	virtual ~Span();
	Span &operator=(const Span &span);

	void addNumber (int n);
	template <class T>
	void addNumber (T begin, T end);

	int shortestSpan( void );
	int longestSpan( void );

	class iterator {
		std::vector<int>::iterator _iter;
    public:
        explicit iterator(std::vector<int>::iterator iter) : _iter(iter) {}
        iterator& operator++() { _iter++; return *this; }
        iterator operator++(int) {iterator retval = *this; ++(*this); return retval; }
        bool operator==(iterator other) const {return _iter == other._iter;}
        bool operator!=(iterator other) const {return !(*this == other);}
        int operator*() const {return *_iter;}
        iterator& operator=(unsigned int value) { *_iter = value; return *this; }
    };
    iterator begin() {return iterator(_array.begin()); }
    iterator end() {return iterator(_array.end()); }

private:

	std::vector<int> _array;
//	unsigned int _size_limit;

};

template <class T>
void Span::addNumber (T begin, T end)
{
	for (T iter = begin; 
		iter != end; 
		++iter ) {
		this->addNumber (*iter);
	}

};


#endif