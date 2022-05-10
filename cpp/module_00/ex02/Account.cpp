
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
	_displayTimestamp();
}

Account::Account( int initial_deposit )
{
	_nbDeposits = initial_deposit;
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
	std::cout << "amount:" << 
	amount:42;deposits:0;withdrawals:0
	std::cout << index:7;amount:16576;created;
	// [19920104_091532] index:0;amount:42;created
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << '[' << (now->tm_year + 1900)
		 << std::setfill('0') << std::setw(2)
         <<  now->tm_mday
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_hour
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_min
		 << std::setfill('0') << std::setw(2)
		 <<  now->tm_sec
		 << std::setfill(' ') << std::setw(0)
         << "] ";
}
