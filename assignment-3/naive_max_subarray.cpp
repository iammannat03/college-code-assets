#include<iostream>
#include<vector>
#include<ctime>
#include<climits>
using namespace std;

int main()
{
    vector<int> elements;
    int n, ele;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    
    clock_t tStart = clock();
    
    // Naive Approach: Check all possible subarrays
    // Time Complexity: O(n²)
    int maxSum = INT_MIN;
    int startIdx = -1, endIdx = -1;
    
    for(int i=0; i<n; i++)
    {
        int currentSum = 0;
        for(int j=i; j<n; j++)
        {
            currentSum += elements[j];
            if(currentSum > maxSum)
            {
                maxSum = currentSum;
                startIdx = i;
                endIdx = j;
            }
        }
    }
    
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Start index: "<<startIdx<<endl;
    cout<<"End index: "<<endIdx<<endl;
    cout<<"Sum: "<<maxSum<<endl;
    cout<<"Time taken is "<<time1<<endl;
}

