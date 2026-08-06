class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;

        string ans="";

        int i=0;
        while(i<path.size())
        {
            if(path[i]=='/')
            {
                if(ans!="")
                {
                    //stack code
                    if(ans==".")
                    {
                        //don onthing
                    }
                    else if(ans=="..")
                    {
                        if(!st.empty())
                        {
                            st.pop_back();
                        }
                    }
                    else
                    {
                        st.push_back(ans);
                    }
                }
                ans="";
                i++;
                continue;
            }
            ans+=path[i++];
        }
        if(ans!="")
        {
            //stck code here to
            if(ans==".")
            {
                //don onthing
            }
            else if(ans=="..")
            {
                if(!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(ans);
            }
            ans="";
        }
        for(string c:st)
        {
            ans+="/";
            ans+=c;
        }
        if (ans=="")return"/";
        return ans;
    }
};