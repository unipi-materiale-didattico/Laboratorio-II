#!/bin/bash
# $1 Test Name
# $2 Program to test
# $3 Test number
# $4...($4+ Test number) Input for every test suite
# ($4+ Test number + 1) Expected output for every test suite

# ----------------------------------
# Colors
# ----------------------------------
NOCOLOR='\e[0m'
RED='\e[0;31m'
GREEN='\e[0;32m'
ORANGE='\e[0;33m'
BLUE='\e[0;34m'
PURPLE='\e[0;35m'
CYAN='\e[0;36m'
LIGHTGRAY='\e[0;37m'
DARKGRAY='\e[1;30m'
LIGHTRED='\e[1;31m'
LIGHTGREEN='\e[1;32m'
YELLOW='\e[1;33m'
LIGHTBLUE='\e[1;34m'
LIGHTPURPLE='\e[1;35m'
LIGHTCYAN='\e[1;36m'
WHITE='\e[1;37m'

# $1 The program to test
# $2 The program input
# $3 The assertion
RunTest(){
  out=$(echo "$2" | $1)
  exit_status=$?
  if [ "$exit_status" = 0 ]
  then
    DIFF=$(diff <(echo "$3") <(echo "$out"))
    if [ "$DIFF" = "" ]
    then
      echo -e "-${LIGHTGREEN} ✅ Pass${NOCOLOR}"
    else
      echo -e "-${RED} ❌ Fail${NOCOLOR}"
      echo -e "${LIGHTGRAY}Real Output:${NOCOLOR}"
      echo $out
      echo -e "${LIGHTGRAY}Expected Output:${NOCOLOR}"
      echo $3
    fi
  elif [ "$exit_status" = "127" ]
  then
    echo -e "-${RED} ❌ Fail${NOCOLOR}"
    echo -e "${LIGHTGRAY}Timeout${NOCOLOR}"
  else
    echo -e "-${RED} ❌ Fail${NOCOLOR}"
    echo -e "${LIGHTGRAY}Exit Status:${NOCOLOR} $exit_status"
  fi
}

declare -a input_arr
declare -a output_arr
test_name=$1
program=$2
test_number=$3
shift 3

for i in $(seq 1 $test_number)
do
  input_arr[$i]=$1
  shift 1
done

for i in $(seq 1 $test_number)
do
  output_arr[$i]=$1
  shift 1
done

echo -e "${YELLOW}$test_name:${NOCOLOR}"
for i in $(seq 1 $test_number)
do
  echo -e "${LIGHTGRAY}Test $i${NOCOLOR}"
  RunTest $program ${input_arr[$i]} ${output_arr[$i]}
done

