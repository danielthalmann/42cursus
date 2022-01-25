#!/bin/bash
if [ "$(eval uname)" == "Linux" ]
then
        CHECKER=./checker_linux
else
        CHECKER=./checker_Mac
fi
arg=`python3 ../tests/gen.py`; ./push_swap $arg | $CHECKER $arg
arg=`python3 ../tests/gen.py`; ./push_swap $arg | wc -l

