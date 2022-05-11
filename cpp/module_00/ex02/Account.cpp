
#include <ctime> 
#include <iostream>
#include <iomanip>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
 	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

	_displayTimestamp();
	std::cout << " account:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;

}

Account::Account( int initial_deposit )
{

	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts++;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";create" << std::endl;

}

Account::Account()
{

}

Account::~Account( void )
{

}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits = deposit;
	Account::_totalNbDeposits += deposit;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_nbWithdrawals = withdrawal;
	return true;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << '[' << (now->tm_year + 1900)
		 << std::setfill('0') << std::setw(2)
		 <<  (now->tm_mon + 1)
		 << std::setfill('0') << std::setw(2)
         <<  now->tm_mday
		 <<  "_"
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_hour
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_min
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_sec
		 << std::setfill(' ') << std::setw(0)
         << "]";
}
