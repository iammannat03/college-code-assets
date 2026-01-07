#include<iostream>
#include<vector>
#include<ctime>
#include<unordered_map>
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
    
    // Linear algorithm to find subarray with sum zero
    // Time Complexity: O(n)
    unordered_map<int, int> prefixSumMap;
    int prefixSum = 0;
    int startIdx = -1, endIdx = -1;
    
    // Initialize with sum 0 at index -1 (before array starts)
    prefixSumMap[0] = -1;
    
    for(int i=0; i<n; i++)
    {
        prefixSum += elements[i];
        
        // If this prefix sum was seen before, subarray between those indices has sum 0
        if(prefixSumMap.find(prefixSum) != prefixSumMap.end())
        {
            startIdx = prefixSumMap[prefixSum] + 1;
            endIdx = i;
            break; // First occurrence
        }
        
        prefixSumMap[prefixSum] = i;
    }
    
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    
    if(startIdx == -1)
    {
        cout<<"Start index: -1"<<endl;
        cout<<"End index: -1"<<endl;
    }
    else
    {
        cout<<"Start index: "<<startIdx<<endl;
        cout<<"End index: "<<endIdx<<endl;
    }
    cout<<"Time taken is "<<time1<<endl;
}

