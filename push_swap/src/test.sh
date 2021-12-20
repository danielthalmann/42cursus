#!/bin/sh

arg=`python3 ../tests/gen.py`; ./push_swap $arg | ./checker_linux $arg

