#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test configurations
SIZES=(5000 10000 15000 20000)
TYPES=("ascending" "descending" "random")

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

echo "=========================================="
echo "  Testing All DAA Assignments"
echo "=========================================="
echo ""

# Function to test an assignment
test_assignment() {
    local assignment_dir=$1
    local cpp_file=$2
    local assignment_name=$3
    
    echo "${YELLOW}Testing $assignment_name...${NC}"
    echo "----------------------------------------"
    
    cd "$assignment_dir" || exit 1
    
    # Compile the C++ program
    echo "Compiling $cpp_file..."
    if g++ -o a.out "$cpp_file" 2>/dev/null; then
        echo -e "${GREEN}✓ Compilation successful${NC}"
    else
        echo -e "${RED}✗ Compilation failed${NC}"
        cd ..
        return 1
    fi
    
    # Test each input type
    for type in "${TYPES[@]}"; do
        echo ""
        echo "Testing $type inputs:"
        
        # Test each size
        for size in "${SIZES[@]}"; do
            TOTAL_TESTS=$((TOTAL_TESTS + 1))
            
            # Modify Python script to use current size
            input_file="${type}_${size}.txt"
            if [ -f "${type}.py" ]; then
                # Create a temporary copy and update n value
                # Use a temp directory to avoid import conflicts (especially for random.py)
                temp_dir=$(mktemp -d)
                cp "${type}.py" "${temp_dir}/${type}.py"
                if [[ "$OSTYPE" == "darwin"* ]]; then
                    sed -i '' "s/^n=[0-9]*/n=$size/" "${temp_dir}/${type}.py"
                else
                    sed -i "s/^n=[0-9]*/n=$size/" "${temp_dir}/${type}.py"
                fi
                # Run from temp directory to avoid circular imports
                (cd "$temp_dir" && python3 -B "${type}.py" > /dev/null 2>&1)
                # Move generated file back if it exists
                if [ -f "${temp_dir}/${input_file}" ]; then
                    mv "${temp_dir}/${input_file}" "./${input_file}"
                fi
                rm -rf "$temp_dir"
            else
                echo -e "  ${RED}✗ ${type}.py not found${NC}"
                FAILED_TESTS=$((FAILED_TESTS + 1))
                continue
            fi
            
            # Check if input file exists
            if [ ! -f "$input_file" ]; then
                echo -e "  ${RED}✗ $input_file not found${NC}"
                FAILED_TESTS=$((FAILED_TESTS + 1))
                continue
            fi
            
            # Run the program
            if ./a.out < "$input_file" > /tmp/test_output.txt 2>&1; then
                # Check if output contains "Time taken"
                if grep -q "Time taken" /tmp/test_output.txt; then
                    time_taken=$(grep "Time taken" /tmp/test_output.txt | awk '{print $4}')
                    echo -e "  ${GREEN}✓ Size $size: Time = $time_taken${NC}"
                    PASSED_TESTS=$((PASSED_TESTS + 1))
                else
                    echo -e "  ${RED}✗ Size $size: No time output${NC}"
                    FAILED_TESTS=$((FAILED_TESTS + 1))
                fi
            else
                echo -e "  ${RED}✗ Size $size: Execution failed${NC}"
                FAILED_TESTS=$((FAILED_TESTS + 1))
            fi
        done
    done
    
    echo ""
    cd ..
}

# Test Assignment 1: Insertion Sort
if [ -d "assignment-1" ]; then
    test_assignment "assignment-1" "insertion_sort.cpp" "Assignment 1: Insertion Sort"
else
    echo -e "${RED}✗ assignment-1 directory not found${NC}"
fi

echo ""
echo "=========================================="
echo ""

# Test Assignment 2: Merge Sort
if [ -d "assignment-2" ]; then
    test_assignment "assignment-2" "merge_sort.cpp" "Assignment 2: Merge Sort"
else
    echo -e "${RED}✗ assignment-2 directory not found${NC}"
fi

echo ""
echo "=========================================="
echo ""

# Test Assignment 3: Maximum Subarray
if [ -d "assignment-3" ]; then
    test_assignment "assignment-3" "max_subarray.cpp" "Assignment 3: Maximum Subarray"
else
    echo -e "${RED}✗ assignment-3 directory not found${NC}"
fi

echo ""
echo "=========================================="
echo "           TEST SUMMARY"
echo "=========================================="
echo "Total Tests: $TOTAL_TESTS"
echo -e "${GREEN}Passed: $PASSED_TESTS${NC}"
echo -e "${RED}Failed: $FAILED_TESTS${NC}"
echo ""

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}✓ All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}✗ Some tests failed${NC}"
    exit 1
fi

