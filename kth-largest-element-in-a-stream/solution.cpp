class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(int i=0;i<nums.size();i++)
        {
            if(s>0)
            {
                pq.push(nums[i]);
                s--;
            }
            else
            {
                if(nums[i]>pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(s>0)
        {
            pq.push(val);
            s--;
        }
        else if(val>pq.top())
        {
            pq.pop();
            pq.push(val);
            
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */