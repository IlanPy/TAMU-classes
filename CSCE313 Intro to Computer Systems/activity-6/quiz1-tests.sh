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
remake
echo -e "\nTesting :: Compilation\n"
echo -e "  ${GREEN}Test One Passed${NC}"
SCORE=$(($SCORE+5))

remake
echo -e "\nVerify that ./sort runs as child\n"
timeout 10 strace -e trace=execve -f -o trace.tst ./main -a &> /dev/null
counts=$(grep -c 'execve("./sort", \["./sort", "-r", "[0-9]\{1,4\}", "-w", "[0-9]\{1,4\}", "-a"\]' trace.tst)
if [ "$counts" -ne 1 ]; then
    echo "  Servers do not run as children - can't test with script"
    echo -e "  ${RED}Failed${NC}"
    exit 1
else
    echo -e "  ${GREEN}Test Two Passed${NC}"
    SCORE=$(bc -l <<< "$SCORE+5")
fi

remake
echo -e "\nTesting :: Correct output for descending order ./main \n"
RES=$(. ./test-files/test_descending.txt)
output=$(./main 2>/dev/null)
if echo "$output" | grep -F -- "${RES}" | wc -l | grep -qE "5" && echo "$output" | grep -q "GOOG"; then
    echo -e "  ${GREEN}Test Three Passed${NC}"
    SCORE=$(($SCORE+10))
else
    echo -e "  ${RED}Failed${NC}"
fi

echo -e "\nTesting :: Correct output for ./main -a\n"
RES=$(. ./test-files/test_ascending.txt)
output2=$(./main -a 2>/dev/null)
if echo "$output2" | grep -F -- "${RES}" | wc -l | grep -qE "5" && echo "$output2" | grep -q "SUNW"; then
    echo -e "  ${GREEN}Test Four Passed${NC}"
    SCORE=$(($SCORE+10))
else
    echo -e "  ${RED}Failed${NC}"
fi


# print score and delete executable
echo -e "\nSCORE: ${SCORE}/30\n"
make -s clean

exit 0
