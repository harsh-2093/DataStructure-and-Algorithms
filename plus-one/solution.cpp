class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]+1>9)
            {
                digits[i]=0;

            }
            else
            {
                digits[i]+=1;
                carry=1;
                break;
                
            }
        }
        if(carry==0)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;

        
    }
};