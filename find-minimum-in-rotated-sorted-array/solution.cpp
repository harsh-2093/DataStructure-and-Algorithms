class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(arr[low]<=arr[mid] &&arr[mid]<=arr[high])
            {
                return arr[low];
            }
            else if(arr[mid]>arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return arr[low];
    }
};