#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

typedef struct test_vector
{
	std::string message;
	bool error;
} err_t;


void test_constructor( void );
void test_assign( void );
void test_element_access ( void );
void test_iterrator ( void );
void test_capacity( void );
void test_modifier( void );

#endif

