#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{

	template<bool, typename T = void>
	struct enable_if
	{ };

	// Partial specialization for true.
	template<typename T>
	struct enable_if<true, T>
	{ 
		typedef T type; 
	};

	template<typename T, T v>
	struct integral_constant
	{
		static const T						value = v;
		typedef T							value_type;
		typedef integral_constant<T, v>   	type;
		operator value_type() { return value; }
	};


	/// The type used as a compile-time boolean with true value.
	typedef integral_constant<bool, true>     true_type;

	/// The type used as a compile-time boolean with false value.
	typedef integral_constant<bool, false>    false_type;
		

	template<typename>
	struct is_integral_helper
	: public false_type { };

	template<>
	struct is_integral_helper<bool>
	: public true_type { };

	template<>
	struct is_integral_helper<char>
	: public true_type { };

	template<>
	struct is_integral_helper<signed char>
	: public true_type { };

	template<>
	struct is_integral_helper<unsigned char>
	: public true_type { };

	template<>
	struct is_integral_helper<wchar_t>
	: public true_type { };

	template<>
	struct is_integral_helper<short>
	: public true_type { };

	template<>
	struct is_integral_helper<unsigned short>
	: public true_type { };

	template<>
	struct is_integral_helper<int>
	: public true_type { };

	template<>
	struct is_integral_helper<unsigned int>
	: public true_type { };

	template<>
	struct is_integral_helper<long>
	: public true_type { };

	template<>
	struct is_integral_helper<unsigned long>
	: public true_type { };

	template<>
	struct is_integral_helper<long long>
	: public true_type { };

	template<>
	struct is_integral_helper<unsigned long long>
	: public true_type { };


	template<typename T>
	struct is_integral
	: public is_integral_helper< T >
	{ };

}

#endif