#!/usr/bin/env bash

# function to clean up files and make executables
remake () {
    # echo -e "\ old files and making executables"
    make -s clean
    make -s >/dev/null 2>&1
}


echo -e "To remove colour from tests, set COLOUR to 1 in sh file\n"
COLOUR=0
if [[ COLOUR -eq 0 ]]; then
    ORANGE='\033[0;33m'
    GREEN='\033[0;32m'
    RED='\033[0;31m'
    NC='\033[0m'
else
    ORANGE='\033[0m'
    GREEN='\033[0m'
    RED='\033[0m'
    NC='\033[0m'
fi

SCORE=0


echo -e "\nStart testing"
echo -e "\nTesting :: Compilation\n"
if make; then 
    echo -e "  ${GREEN}Test One Passed${NC}"
    SCORE=$(($SCORE+10))
else
    echo -e "  ${RED}Failed${NC}"
    exit 0
fi

remake
echo -e "\nTesting :: Correct Output 1\n"
./schedule -i test-files/public_test_cases/Task1.csv > test-files/cmd.txt 2>/dev/null
if diff -q test-files/cmd.txt test-files/public_test_cases_output/Task1.txt 2>/dev/null; then
    echo -e "  ${GREEN}Test Two Passed${NC}"
    SCORE=$(($SCORE+15))
else
    echo -e "  ${RED}Failed${NC}"
fi

remake
echo -e "\nTesting :: Correct Output 2\n"
./schedule -i test-files/public_test_cases/Task2.csv > test-files/cmd.txt 2>/dev/null
if diff -q test-files/cmd.txt test-files/public_test_cases_output/Task2.txt 2>/dev/null; then
    echo -e "  ${GREEN}Test Three Passed${NC}"
    SCORE=$(($SCORE+15))
else
    echo -e "  ${RED}Failed${NC}"
fi

remake
echo -e "\nTesting :: Correct Output 3\n"
./schedule -i test-files/public_test_cases/Task3.csv > test-files/cmd.txt 2>/dev/null
if diff -q test-files/cmd.txt test-files/public_test_cases_output/Task3.txt 2>/dev/null; then
    echo -e "  ${GREEN}Test Four Passed${NC}"
    SCORE=$(($SCORE+15))
else
    echo -e "  ${RED}Failed${NC}"
fi

remake
echo -e "\nTesting :: Correct Output 4\n"
./schedule -i test-files/public_test_cases/Task4.csv > test-files/cmd.txt 2>/dev/null
if diff -q test-files/cmd.txt test-files/public_test_cases_output/Task4.txt 2>/dev/null; then
    echo -e "  ${GREEN}Test Five Passed${NC}"
    SCORE=$(($SCORE+5))
else
    echo -e "  ${RED}Failed${NC}"
fi

# print score and delete executable
echo -e "\nSCORE: ${SCORE}/60\n"
make -s clean

exit 0
