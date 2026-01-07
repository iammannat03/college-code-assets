# Lab Exercise 3: Maximum Sum Subarray

This assignment contains implementations of various Maximum Sum Subarray problems.

## Programs

### 1. `naive_max_subarray.cpp`
- **Approach**: Naive/Brute Force
- **Time Complexity**: O(n²)
- **Description**: Checks all possible subarrays to find the one with maximum sum
- **Output**: Start index, End index, Sum, Time taken

### 2. `divide_conquer_max_subarray.cpp`
- **Approach**: Divide and Conquer
- **Time Complexity**: O(n log n)
- **Description**: Recursively divides the array and finds maximum subarray crossing the midpoint
- **Output**: Start index, End index, Sum, Time taken

### 3. `linear_max_subarray.cpp`
- **Approach**: Kadane's Algorithm (Linear Time)
- **Time Complexity**: O(n)
- **Description**: Single pass through the array using dynamic programming approach
- **Output**: Start index, End index, Sum, Time taken

### 4. `zero_sum_subarray.cpp`
- **Approach**: Prefix Sum with Hash Map
- **Time Complexity**: O(n)
- **Description**: Finds if there exists a subarray with sum zero
- **Output**: Start index, End index (or -1, -1 if not found), Time taken

### 5. `max_sum_max_length_subarray.cpp`
- **Approach**: Modified Kadane's Algorithm
- **Time Complexity**: O(n)
- **Description**: Finds maximum sum subarray, and if multiple exist with same sum, picks the longest one
- **Output**: Start index, End index, Sum, Time taken

## Input Generation

Use the Python scripts to generate input files:
- `ascending.py` - Generates ascending order numbers
- `descending.py` - Generates descending order numbers  
- `generate_random.py` - Generates random numbers (including negatives)

**Required sizes**: 100, 1000, 10000, 50000, 100000, 500000, 1000000

Change the `n` value in each Python script and run:
```bash
python3 generate_random.py
```

## Compilation and Execution

```bash
# Compile
g++ -o naive naive_max_subarray.cpp
g++ -o dc divide_conquer_max_subarray.cpp
g++ -o linear linear_max_subarray.cpp
g++ -o zero zero_sum_subarray.cpp
g++ -o maxlen max_sum_max_length_subarray.cpp

# Run
./naive < random_1000.txt
./dc < random_1000.txt
./linear < random_1000.txt
./zero < random_1000.txt
./maxlen < random_1000.txt
```

## Test Examples

- `test_example1.txt`: Array from problem 1 (16 elements)
- `test_example4.txt`: Array from problem 4 (7 elements)
- `test_example5.txt`: Array from problem 5 (13 elements)

## Performance Comparison

For problems 2 and 3, compare the performance of:
- Naive algorithm (O(n²))
- Divide and Conquer (O(n log n))
- Linear algorithm (O(n))

Test with input sizes: 100, 1000, 10000, 50000, 100000, 500000, 1000000

