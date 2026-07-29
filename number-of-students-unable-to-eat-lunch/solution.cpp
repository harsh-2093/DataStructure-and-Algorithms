class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>pq;
        for(int i=students.size()-1;i>=0;i--)
        {
            pq.push(students[i]);
        }

        stack<int>st;
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            st.push(sandwiches[i]);
        }
        int cnt=0;

        while(!pq.empty())
        {
            if(cnt==st.size())
            {
                return pq.size();
            }
            if(pq.front()!=st.top())
            {
                int val =pq.front();
                pq.pop();
                pq.push(val);
                cnt++;
            }
            else{
                pq.pop();
                st.pop();
                cnt=0;
            }
        }
        return 0;
    }
};