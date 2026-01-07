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
    
    // Kadane's Algorithm (Linear Time)
    // Time Complexity: O(n)
    int maxSum = INT_MIN;
    int currentSum = 0;
    int startIdx = 0, endIdx = 0;
    int tempStart = 0;
    
    for(int i=0; i<n; i++)
    {
        currentSum += elements[i];
        
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
            startIdx = tempStart;
            endIdx = i;
        }
        
        if(currentSum < 0)
        {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Start index: "<<startIdx<<endl;
    cout<<"End index: "<<endIdx<<endl;
    cout<<"Sum: "<<maxSum<<endl;
    cout<<"Time taken is "<<time1<<endl;
}

