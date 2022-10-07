#!/bin/bash
# $1 Test Name
# $2 Program to test
# $3 Test number
# $4...($4+ Test number) Input for every test suite
# ($4+ Test number + 1) Expected output for every test suite

# ----------------------------------
# Colors
# ----------------------------------
NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

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
      echo "-${LIGHTGREEN} ✅ Pass${NOCOLOR}"
    else
      echo "-${RED} ❌ Fail${NOCOLOR}"
      echo "${LIGHTGRAY}Real Output:${NOCOLOR}"
      echo $out
      echo "${LIGHTGRAY}Expected Output:${NOCOLOR}"
      echo $3
    fi
  elif [ "$exit_status" = "127" ]
  then
    echo "-${RED} ❌ Fail${NOCOLOR}"
    echo "${LIGHTGRAY}Timeout${NOCOLOR}"
  else
    echo "-${RED} ❌ Fail${NOCOLOR}"
    echo "${LIGHTGRAY}Exit Status:${NOCOLOR} $exit_status"
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

echo "${YELLOW}$test_name:${NOCOLOR}"
for i in $(seq 1 $test_number)
do
  echo "${LIGHTGRAY}Test $i${NOCOLOR}"
  RunTest $program ${input_arr[$i]} ${output_arr[$i]}
done

