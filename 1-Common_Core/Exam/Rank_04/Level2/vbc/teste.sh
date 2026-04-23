#!/bin/bash

EXEC=./vbc

run_test() {
    input="$1"
    expected="$2"
    code="$3"

    output=$($EXEC "$input" 2>&1)
    status=$?

    valgrind_output=$(valgrind --leak-check=full --error-exitcode=42 \
        $EXEC "$input" 2>&1 >/dev/null)
    vg_status=$?

    if [ "$output" = "$expected" ] && [ $status -eq $code ]; then
        echo "✅ PASS: test \"$input\" : Expected [$expected] Got [$output]"
    else
        echo "❌ FAIL: \"$input\""
        echo "   Expected: [$expected] exit status [$code]"
        echo "   Got     : [$output] exit status [$status]"
    fi

    if [ $vg_status -eq 42 ]; then
        echo "⚠️  LEAK detected in test \"$input\""
    fi
}

echo "Running tests..."
echo "-----------------------------"

# VALID TESTS
echo ""
echo "Valid tests!"
echo ""

run_test "1" "1" "0"
run_test "2+3" "5" "0"
run_test "3*4+5" "17" "0"
run_test "3+4*5" "23" "0"
run_test "(3+4)*5" "35" "0"
run_test "1+2+3+4+5" "15" "0"
run_test "(1)" "1" "0"
run_test "(((((((3)))))))" "3" "0"
run_test "(1+2)*3" "9" "0"
run_test "1+1*(2*0)" "1" "0"

# ERROR TESTS
echo ""
echo "Invalid tests!"
echo ""

run_test "1+" "Unexpected end of input" "1"
run_test "1+2)" "Unexpected token ')'" "1"
run_test "((1+3)*12+(3*(2+6))" "Unexpected token '2'" "1"

echo "-----------------------------"
echo "Done."