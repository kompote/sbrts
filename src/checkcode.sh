#!/bin/sh
CPPCFLAGS='--enable=all -q'

echo -e '\e[36m\e[1m'
echo -e 'Checking [core]...'
echo -e '\e[0m\e[35m'
cppcheck $CPPCFLAGS core/ 
echo -e '\e[36m\e[1m'
echo -e 'Checking [engine]...'
echo -e '\e[0m\e[35m'
cppcheck $CPPCFLAGS engine/ 
echo -e '\e[36m\e[1m'
echo -e 'Checking [utils]...'
echo -e '\e[0m\e[35m'
cppcheck $CPPCFLAGS utils/ 
echo -e '\e[36m\e[1m'
echo -e 'Checking DONE'
echo -e '\e[0m'
