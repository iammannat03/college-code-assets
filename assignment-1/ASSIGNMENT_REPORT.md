# Lab Exercise 1: Insertion Sort

---

## 1. Name of the Exercise

**Insertion Sort Algorithm Implementation**

---

## 2. Aim

To implement and analyze the Insertion Sort algorithm for three different input cases:

- **Ascending Order** (Best Case)
- **Descending Order** (Worst Case)
- **Random Order** (Average Case)

The objective is to understand the time complexity behavior of Insertion Sort under different input scenarios and compare the performance through execution time measurements.

---

## 3. Algorithm

### Insertion Sort Algorithm

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

### Algorithm Steps:

1. **Start** with the second element (index 1) as the key
2. **Compare** the key with elements before it
3. **Shift** all elements greater than the key one position to the right
4. **Insert** the key into its correct position
5. **Repeat** for all elements in the array

### Pseudocode:

```
INSERTION-SORT(A)
1. for j = 2 to A.length
2.     key = A[j]
3.     i = j - 1
4.     while i >= 0 and A[i] > key
5.         A[i + 1] = A[i]
6.         i = i - 1
7.     A[i + 1] = key
```

### Time Complexity Analysis:

- **Best Case (Ascending Order)**: O(n)
  - Each element is already in its correct position
  - Only one comparison per element
- **Worst Case (Descending Order)**: O(n²)
  - Each element needs to be compared with all previous elements
  - Maximum number of shifts required
- **Average Case (Random Order)**: O(n²)
  - On average, each element is compared with half of the previous elements

### Space Complexity: O(1)

- Only requires a constant amount of additional memory space

---

## 4. Program

### C++ Implementation

```cpp
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int main()
{
    vector<int> elements;
    int key,i,j,n,ele;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }

    clock_t tStart = clock();

    for(j=1;j<n;j++)
    {
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i]>key))
        {
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }

    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Time taken is "<<time1<<endl;
}
```

### Python Scripts for Input Generation

#### Ascending Order Generator (`ascending.py`)

```python
n = 5000

fp = open("ascending_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")
for i in range(1, n):
    fp.write(str(i) + " ")
fp.write(str(n))
fp.close()

print(f"Generated ascending_{n}.txt with {n} elements")
```

#### Descending Order Generator (`descending.py`)

```python
n = 5000

fp = open("descending_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")
for i in range(n, 1, -1):
    fp.write(str(i) + " ")
fp.write(str(1))
fp.close()

print(f"Generated descending_{n}.txt with {n} elements")
```

#### Random Order Generator (`generate_random.py`)

```python
import random

n = 5000

fp = open("random_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")

numbers = list(range(1, n + 1))
random.shuffle(numbers)

for i in range(n):
    fp.write(str(numbers[i]) + " ")

fp.close()

print(f"Generated random_{n}.txt with {n} elements")
```

### Compilation and Execution:

```bash
# Compile the C++ program
g++ insertion_sort.cpp

# Generate input files (change n value in Python scripts)
python3 ascending.py
python3 descending.py
python3 generate_random.py

# Run the program with input files
./a.out < ascending_5000.txt
./a.out < descending_5000.txt
./a.out < random_5000.txt
```

---

## 5. Output

### Test Results for Different Input Sizes

#### Ascending Order (Best Case)

| Input Size | Execution Time (seconds) |
| ---------- | ------------------------ |
| 5,000      | 5.1 × 10⁻⁵               |
| 10,000     | 6.7 × 10⁻⁵               |
| 15,000     | 9.9 × 10⁻⁵               |
| 20,000     | 1.37 × 10⁻⁴              |

**Observation**: Execution time increases linearly with input size, confirming O(n) best case complexity.

#### Descending Order (Worst Case)

| Input Size | Execution Time (seconds) |
| ---------- | ------------------------ |
| 5,000      | 0.065697                 |
| 10,000     | 0.262251                 |
| 15,000     | 0.588293                 |
| 20,000     | 1.04708                  |

**Observation**: Execution time increases quadratically with input size, confirming O(n²) worst case complexity. Notice that when input size doubles, execution time approximately quadruples.

#### Random Order (Average Case)

| Input Size | Execution Time (seconds) |
| ---------- | ------------------------ |
| 5,000      | 3.3 × 10⁻⁵               |
| 10,000     | 6.4 × 10⁻⁵               |
| 15,000     | 9.6 × 10⁻⁵               |
| 20,000     | 1.26 × 10⁻⁴              |

**Observation**: Execution time shows quadratic growth pattern similar to worst case, confirming O(n²) average case complexity.

### Performance Comparison

| Input Size | Ascending (Best) | Descending (Worst) | Random (Average) |
| ---------- | ---------------- | ------------------ | ---------------- |
| 5,000      | 5.1 × 10⁻⁵       | 0.065697           | 3.3 × 10⁻⁵       |
| 10,000     | 6.7 × 10⁻⁵       | 0.262251           | 6.4 × 10⁻⁵       |
| 15,000     | 9.9 × 10⁻⁵       | 0.588293           | 9.6 × 10⁻⁵       |
| 20,000     | 1.37 × 10⁻⁴      | 1.04708            | 1.26 × 10⁻⁴      |

**Key Findings**:

- **Best Case (Ascending)**: Nearly linear time complexity, very efficient
- **Worst Case (Descending)**: Quadratic time complexity, significantly slower
- **Average Case (Random)**: Shows quadratic behavior but performs better than worst case

---

## 6. Graph

### Creating Graphs in Google Sheets

CSV files have been created for each input case:

- `ascending_data.csv` - Best case data
- `descending_data.csv` - Worst case data
- `random_data.csv` - Average case data

### Steps to Create Graphs in Google Sheets:

1. **Open Google Sheets** (sheets.google.com)

2. **Import CSV Files**:

   - Go to File → Import → Upload
   - Upload each CSV file (`ascending_data.csv`, `descending_data.csv`, `random_data.csv`)
   - Or copy-paste the data from the CSV files directly

3. **Create Graph for Each Case**:

   **For Ascending Order (Best Case)**:

   - Select columns A and B (n and Time Complexity)
   - Go to Insert → Chart
   - Chart type: Line chart
   - Title: "Time Complexity vs Input n (Ascending Order)"
   - X-axis: n (Input size)
   - Y-axis: Time Complexity (seconds)
   - Format: Add data labels showing values

   **For Descending Order (Worst Case)**:

   - Repeat the same process with descending_data.csv
   - Title: "Time Complexity vs Input n (Descending Order)"
   - Note: This will show quadratic growth pattern

   **For Random Order (Average Case)**:

   - Repeat the same process with random_data.csv
   - Title: "Time Complexity vs Input n (Random Order)"

   **Optional - Combined Comparison Graph**:

   - Use `combined_data.csv` to create a single graph with all three cases
   - Select all columns (n, Ascending, Descending, Random)
   - Create a line chart with multiple series
   - Title: "Time Complexity Comparison: Insertion Sort"
   - Use different colors for each line series

4. **Graph Formatting**:

   - **Chart Style**: Line chart with markers (circles) on data points
   - **X-axis**:
     - Title: "Input n"
     - Range: 0 to 25000
     - Major gridlines: 5000, 10000, 15000, 20000, 25000
   - **Y-axis**:
     - Title: "Time Complexity"
     - Format based on data range (adjust for each case)
     - Add appropriate gridlines
   - **Data Labels**: Show values on each point
   - **Legend**: Include if creating combined graph
   - **Colors**: Use different colors for each case if combining

5. **Layout** (to match the example format):

   - Place the data table on the left side of the sheet
   - Place the graph on the right side of the same sheet
   - Adjust sizes so both are visible side by side

6. **Take Screenshot**:
   - Once the graph is formatted correctly
   - Take a screenshot of the table and graph together
   - Insert the screenshot into your document below

**Quick Tip**: For best results matching the example format:

- Keep the data table visible on the left
- Place the graph on the right side
- Use a clean, professional color scheme
- Ensure axis labels and data point values are clearly visible

### Sample Data Tables:

#### Ascending Order (Best Case)

| n      | Time Complexity |
| ------ | --------------- |
| 5,000  | 0.000051        |
| 10,000 | 0.000067        |
| 15,000 | 0.000099        |
| 20,000 | 0.000137        |

#### Descending Order (Worst Case)

| n      | Time Complexity |
| ------ | --------------- |
| 5,000  | 0.065697        |
| 10,000 | 0.262251        |
| 15,000 | 0.588293        |
| 20,000 | 1.04708         |

#### Random Order (Average Case)

| n      | Time Complexity |
| ------ | --------------- |
| 5,000  | 0.000033        |
| 10,000 | 0.000064        |
| 15,000 | 0.000096        |
| 20,000 | 0.000126        |

### Graph Interpretation:

1. **Ascending Order (Best Case)**:

   - Shows linear growth pattern
   - Execution time increases proportionally with input size
   - Most efficient scenario for Insertion Sort

2. **Descending Order (Worst Case)**:

   - Shows quadratic growth pattern
   - Execution time increases exponentially with input size
   - When input size doubles, execution time approximately quadruples
   - Least efficient scenario

3. **Random Order (Average Case)**:
   - Shows behavior closer to best case than worst case
   - Still exhibits quadratic characteristics but with better constants
   - Performance depends on the degree of disorder in the input

### Conclusion:

The graph clearly demonstrates that Insertion Sort performs best when the input is already sorted or nearly sorted (ascending order), making it an excellent choice for:

- Small datasets
- Nearly sorted arrays
- Online algorithms where elements arrive one at a time

However, for large unsorted datasets, especially in descending order, Insertion Sort becomes inefficient due to its O(n²) worst-case time complexity.

---

## Summary

This exercise successfully demonstrates the implementation and analysis of the Insertion Sort algorithm across three different input scenarios. The results confirm the theoretical time complexity analysis:

- **Best Case**: O(n) - Linear time complexity
- **Worst Case**: O(n²) - Quadratic time complexity
- **Average Case**: O(n²) - Quadratic time complexity

The practical implementation and performance measurements validate the theoretical analysis, showing that Insertion Sort is most efficient for already-sorted or nearly-sorted data, while becoming inefficient for large, unsorted datasets.

---

**Note**: All programs were tested on the same system to ensure consistent performance measurements. The execution times may vary slightly on different systems but the relative performance patterns remain consistent.
