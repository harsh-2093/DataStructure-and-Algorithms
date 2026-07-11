class Solution {
public:
    vector<vector<int>>result;
    void combine(int index,int k,int n,vector<int>&temp)
    {
        //bc
        if(k==0)
        {
            result.push_back(temp);
            return;
        }
        if(index>n)
        {
            return;
        }
        for(int i=index;i<=n;i++)
        {
            temp.push_back(i);
            combine(i+1,k-1,n,temp);
            temp.pop_back();


        }

        // temp.push_back(index);
        // combine(index+1,k-1,n,temp);
        // temp.pop_back();
        // combine(index+1,k,n,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        combine(1, k,n,temp);
        return result;
    }
};