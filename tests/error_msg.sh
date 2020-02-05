#!/usr/bin/env bash

output="/tmp/test_minishell1"
ref="/bin/tcsh"
my="./mysh"
mkdir -p "$output"

my_output="$output/mysh_output"
tcsh_output="$output/tcsh_output"

passed="0"
failed="0"

i="0"
declare -a com=("./tests/wrongarch" "./tests/a.out" "./tests/divided_by_zero" "./tests/bad_permission" "exitt")
while [ $i -lt 5 ]
do
    echo ${com[$i]} | $my &> $my_output
    echo ${com[$i]} | $ref &> $tcsh_output
    diff $my_output $tcsh_output
    ret=$?
    if [ "$ret" = 0 ]
    then
        echo "PASSED: "
        echo ${com[$i]}
        passed=$[$passed+1]
    else
        echo "FAILED :"
        echo ${com[$i]}
        failed=$[$failed+1]
    fi
    i=$[$i+1]
done

i="0"
declare -a com=("cd double_free" "cd mdr" "cd lol mdr ok" "cd ok")
while [ $i -lt 4 ]
do
    echo ${com[$i]} | $my &> $my_output
    echo ${com[$i]} | $ref &> $tcsh_output
    diff $my_output $tcsh_output
    ret=$?
    if [ "$ret" = 0 ]
    then
        echo "PASSED: "
        echo ${com[$i]}
        passed=$[$passed+1]
    else
        echo "FAILED :"
        echo ${com[$i]}
        failed=$[$failed+1]
    fi
    i=$[$i+1]
done

i="0"
declare -a com=("env lol" "unsetenv" "setenv lol mdr lol" "setenv 1lol" "setenv lol- mdr" "setenv -lol" "setenv _lol")
while [ $i -lt 7 ]
do
    echo ${com[$i]} | $my &> $my_output
    echo ${com[$i]} | $ref &> $tcsh_output
    diff $my_output $tcsh_output
    ret=$?
    if [ "$ret" = 0 ]
    then
        echo "PASSED: "
        echo ${com[$i]}
        passed=$[$passed+1]
    else
        echo "FAILED :"
        echo ${com[$i]}
        failed=$[$failed+1]
    fi
    i=$[$i+1]
done

i="0"
declare -a com=("/bin/ls" "ls -l -a" "\tls\t-l\t-a\t" " ls -l -a " "  \t\t ls\t ")
while [ $i -lt 5 ]
do
    echo -e ${com[$i]} | $my &> $my_output
    echo -e ${com[$i]} | $ref &> $tcsh_output
    diff $my_output $tcsh_output
    ret=$?
    if [ "$ret" = 0 ]
    then
        echo "PASSED: "
        echo ${com[$i]}
        passed=$[$passed+1]
    else
        echo "FAILED :"
        echo ${com[$i]}
        failed=$[$failed+1]
    fi
    i=$[$i+1]
done

echo -e "[\e[34m====\e[39m] \e[1mSynthesis:"
echo -e "| Tested:\e[0m\e[34m" $[$passed+$failed]
echo -e "\e[39m\e[1m| Passing:\e[32m" $passed
echo -e "\e[39m\e[1m| Failing:\e[31m" $failed
echo -e "\e[39m[\e[34m====\e[39m]\e[0m"
