#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

simple_test() {
    local ARGS="$@"

    if [ $# -eq 0 ]; then
        printf "%-20s | %-6s | %3s moves\n" "No arguments" "OK" "0"
        return
    fi
    local MOVES=$(./push_swap $ARGS)
    local MOVE_COUNT
    local RESULT
    if [ -z "$MOVES" ]; then
        RESULT=$(echo -n "" | ./checker $ARGS)
        MOVE_COUNT=0
    else
        RESULT=$(echo "$MOVES" | ./checker $ARGS)
        MOVE_COUNT=$(echo "$MOVES" | wc -l)
    fi
    local COLOR=""
    if [ "$RESULT" = "OK" ]; then
        COLOR=$GREEN
    elif [ "$RESULT" = "KO" ]; then
        COLOR=$RED
    else
        COLOR=$YELLOW
    fi
    printf "%-20s | ${COLOR}%-6s${NC} | %3s moves\n" "$ARGS" "$RESULT" "$MOVE_COUNT"
}

test_invalid() {
    local T_NAME="$1"
    shift
    local T_ARGS="$@"

    ./push_swap $T_ARGS 2>/dev/null
    local EXIT_CODE=$?
    if [ $EXIT_CODE -ne 0 ]; then
        printf "(%-15s): %-25s | ${GREEN}PASS${NC}\n" "$T_NAME" "$T_ARGS"
    else
        printf "(%-15s): %-25s | ${RED}FAIL${NC}\n" "$T_NAME" "$T_ARGS"
    fi
}

test_moves() {
    local size=$1
    local max_moves=$2
    local count=0
    local total_moves=0
    local failed_tests=0

    echo "Testing $size elements (max $max_moves moves)..."
    for i in {1..100}; do
        ARG=$(seq 1 $size | shuf | tr '\n' ' ')
        MOVES=$(./push_swap $ARG | wc -l)
        total_moves=$((total_moves + MOVES))
        if [ $MOVES -gt $max_moves ]; then
            echo "  ${RED}Too many moves: $MOVES (limit: $max_moves)${NC}"
            failed_tests=$((failed_tests + 1))
        fi
        count=$((count + 1))
    done

    local avg=$((total_moves / count))
    if [ $failed_tests -eq 0 ]; then
        echo "  ${GREEN}✓ Average moves for size $size: $avg${NC}"
    else
        echo "  ${RED}✗ Average moves for size $size: $avg ($failed_tests failures)${NC}"
    fi
}

test_valgrind() {
    local ARGS="$@"
    local TEST_NAME="${ARGS// /_}"

    if [ ${#TEST_NAME} -gt 20 ]; then
        TEST_NAME="${TEST_NAME:0:17}..."
    fi

    echo "Testing with Valgrind: $ARGS"
    ./push_swap $ARGS >/dev/null 2>/dev/null
    local PUSH_EXIT=$?

    if [ $PUSH_EXIT -ne 0 ]; then
        local VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all \
                               --track-origins=yes --error-exitcode=1 \
                               ./push_swap $ARGS 2>&1)
        if echo "$VALGRIND_OUTPUT" | grep -q "All heap blocks were freed"; then
            printf "%-20s: ${GREEN}PASS${NC} (Error handled cleanly)\n" "$TEST_NAME"
        else
            printf "%-20s: ${RED}LEAK${NC} (Memory leaks in error case)\n" "$TEST_NAME"
        fi
    else
        local VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all \
                               --track-origins=yes --error-exitcode=1 \
                               ./push_swap $ARGS 2>&1)
        local EXIT_CODE=$?
        if echo "$VALGRIND_OUTPUT" | grep -q "ERROR SUMMARY: 0 errors"; then
            if echo "$VALGRIND_OUTPUT" | grep -q "All heap blocks were freed"; then
                printf "%-20s: ${GREEN}PASS${NC} (No leaks, no errors)\n" "$TEST_NAME"
            else
                printf "%-20s: ${YELLOW}LEAK${NC} (Memory leaks detected)\n" "$TEST_NAME"
            fi
        else
            printf "%-20s: ${RED}FAIL${NC} (Memory errors detected)\n" "$TEST_NAME"
            echo "$VALGRIND_OUTPUT" | grep -E "(Invalid|ERROR SUMMARY|lost:|LEAK SUMMARY)"
        fi
    fi
}

quick_performance_test() {
    echo "${BLUE}Quick performance check...${NC}"
    local moves_3=$(./push_swap 3 2 1 | wc -l)
    if [ $moves_3 -le 3 ]; then
        echo "  ${GREEN}✓ 3 elements: $moves_3 moves (≤3)${NC}"
    else
        echo "  ${RED}✗ 3 elements: $moves_3 moves (>3)${NC}"
    fi
    local moves_5=$(./push_swap 5 4 3 2 1 | wc -l)
    if [ $moves_5 -le 12 ]; then
        echo "  ${GREEN}✓ 5 elements: $moves_5 moves (≤12)${NC}"
    else
        echo "  ${RED}✗ 5 elements: $moves_5 moves (>12)${NC}"
    fi
}

echo "${BLUE}========== SIMPLE TESTS ==========${NC}"
printf "%-20s | %-6s | %-8s\n" "Arguments" "Result" "Moves"
echo "------------------------------------"
simple_test 2 1 3
simple_test 1 5 2 4 3
simple_test 1
simple_test 1 2
simple_test 2 1
simple_test 9 8 7 6 5 4 3 2 1
simple_test
echo

echo "${BLUE}========== INVALID TESTS ==========${NC}"
test_invalid "Alpha chars" "2 1 three"
test_invalid "Duplicates" 1 2 1 2
test_invalid "Over INT_MAX" 2147483648
test_invalid "Under INT_MIN" -2147483649
test_invalid "Empty string" ""
test_invalid "Only spaces" "   "
echo

quick_performance_test
echo

echo "${BLUE}========== BENCHMARK TESTS ==========${NC}"
test_moves 100 1100
test_moves 500 8500
echo

echo "${BLUE}========== VALGRIND TESTS ==========${NC}"
test_valgrind 2 1 3
test_valgrind 1 5 2 4 3
test_valgrind 1
test_valgrind 1 2
test_valgrind 9 8 7 6 5 4 3 2 1

echo
echo "${BLUE}========== VALGRIND ERROR CASES ==========${NC}"
test_valgrind "2 1 three"
test_valgrind 1 2 1 2
test_valgrind 2147483648
test_valgrind -2147483649
test_valgrind ""

echo
echo "${GREEN}========== ALL TESTS COMPLETED ==========${NC}"
