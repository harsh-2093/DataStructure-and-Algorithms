class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp=strs[0];
        string ans="";

        for(int i=0;i<temp.size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(i >= strs[j].size()||temp[i]!=strs[j][i])
                {
                    return ans;
                }
            }
            ans+=temp[i];
        }
            return ans;

    }
        
    
};