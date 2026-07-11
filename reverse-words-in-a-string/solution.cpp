class Solution {
public:
    void rev(string &temp,int start,int end)
    {
        while(start<end)
        {
            swap(temp[start],temp[end]);
            start++;
            end--;
        }

    }
    string reverseWords(string s) {
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
            }
            else if(!temp.empty() && temp.back()!=' ')
            {
                temp+= ' ' ;


            }

        }
        if(!temp.empty() && temp.back()==' ')
        {
            temp.pop_back();
        }
        rev(temp ,0,temp.size()-1);
        int start=0;
        for(int end=0;end<temp.size();end++)
        {
            if(temp[end]==' ')
            {
                rev(temp,start,end-1);
                start=end+1;
            }
        }
        rev(temp,start,temp.size()-1);
        for(int i=0;i<temp.size();i++)
        {
            cout<<temp[i];
        }
   





        return temp;
    }

};