#!/bin/zsh

GREEN="\033[32m"
YELLOW="\033[0;33m"
RED="\033[0;31m"
BLUE="\033[0;34m"
MUTED="\033[1;30m"
RESET="\033[0m"
BOLD="\033[1m"

PHILO=../philo/philo

do_philo()
{
	echo -e "${RESET} ${RED}=> ${YELLOW} ${PHILO} $*"
	echo -n "${RESET} ${BLUE}"
	ARG=$*
	RET=`${PHILO} $*`
	echo ${RET}
}

# 1 800 200 200 (die)
# 5 800 200 200 (no die)
# 5 800 200 200 10 (stop after each philo eat 10 times)
# 4 410 200 200 (no die)
# 4 310 200 200 (die)

do_philo 1 800 200 200
do_philo 4 310 200 200
