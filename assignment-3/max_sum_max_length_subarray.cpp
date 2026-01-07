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
    
    // Linear algorithm to find maximum sum subarray with maximum length
    // Time Complexity: O(n)
    int maxSum = INT_MIN;
    int currentSum = 0;
    int startIdx = 0, endIdx = 0;
    int tempStart = 0;
    int maxLength = 0;
    
    for(int i=0; i<n; i++)
    {
        currentSum += elements[i];
        
        int currentLength = i - tempStart + 1;
        
        // Update if we get a better sum, or same sum with longer length
        if(currentSum > maxSum || (currentSum == maxSum && currentLength > maxLength))
        {
            maxSum = currentSum;
            startIdx = tempStart;
            endIdx = i;
            maxLength = currentLength;
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

