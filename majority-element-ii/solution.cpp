class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int element1=-1;
        int element2=-2;
        int count1=0;
        int count2=0;

        //find the candidate
        for(int i=0;i<n;i++)
        {
            if(count1==0 && nums[i]!=element2)
            {
                element1=nums[i];
                count1=1;

            }
            else if(count2==0 && nums[i]!=element1)
            {
                element2=nums[i];
                count2=1;
            }
            else if(element1==nums[i])
            {
                count1++;
            }
            else if(element2==nums[i])
            {
                count2++;
            }
            else
            {

                count1--;
                count2--;
            }
        }

        count1=0;
        count2=0;
        for(int num:nums)
        {
            if(num==element1)count1++;
            if(num==element2)count2++;
        }
        vector<int>ls;
        if(count1>n/3)
        {
        ls.push_back(element1);
        }
        if(count2>n/3)
        {
        ls.push_back(element2);
        }
        return ls;
        
    }
};