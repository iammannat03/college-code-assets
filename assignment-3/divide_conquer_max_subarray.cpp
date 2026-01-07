#include<iostream>
#include<vector>
#include<ctime>
#include<climits>
using namespace std;

struct Result {
    int sum;
    int startIdx;
    int endIdx;
};

// Find maximum subarray crossing the midpoint
Result maxCrossingSubarray(vector<int>& arr, int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;
    
    for(int i=mid; i>=low; i--)
    {
        sum += arr[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid+1;
    
    for(int j=mid+1; j<=high; j++)
    {
        sum += arr[j];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxRight = j;
        }
    }
    
    Result res;
    res.sum = leftSum + rightSum;
    res.startIdx = maxLeft;
    res.endIdx = maxRight;
    return res;
}

// Divide and Conquer approach
Result maxSubarrayDivideConquer(vector<int>& arr, int low, int high)
{
    if(low == high)
    {
        Result res;
        res.sum = arr[low];
        res.startIdx = low;
        res.endIdx = high;
        return res;
    }
    
    int mid = low + (high - low) / 2;
    
    Result left = maxSubarrayDivideConquer(arr, low, mid);
    Result right = maxSubarrayDivideConquer(arr, mid+1, high);
    Result cross = maxCrossingSubarray(arr, low, mid, high);
    
    if(left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if(right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

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
    
    // Divide and Conquer Approach
    // Time Complexity: O(n log n)
    Result result = maxSubarrayDivideConquer(elements, 0, n-1);
    
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Start index: "<<result.startIdx<<endl;
    cout<<"End index: "<<result.endIdx<<endl;
    cout<<"Sum: "<<result.sum<<endl;
    cout<<"Time taken is "<<time1<<endl;
}

