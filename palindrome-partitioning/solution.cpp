class Solution {
public:
bool Ispalindrome(string value)
{
    string temp=value;
    int start=0;
    int end=value.size()-1;

    while(start<end)
    {
        swap(temp[start],temp[end]);
        start++;

        end--;
    }
    if(temp==value)return true;
    return false;
}

void pal_part(string s, vector<string>&current,vector<vector<string>>&result,int index){
    if(index>=s.size())
    {
        result.push_back(current);
        return;
    }

    for(int i=index;i<s.size();i++)
    {
        string value=s.substr(index,i-index+1);
        if(Ispalindrome(value)==0)continue;

        current.push_back(value);
        pal_part(s,current,result,i+1);
        current.pop_back();



    }
}



    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>current;

        pal_part(s,current,result,0);


        return result;
           }
           
};