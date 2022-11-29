class Solution {
public:
    bool isValid(string s) {
        stack&lt;char&gt;st;
        for(int i=0;i&lt;s.length();i++){
            if(st.empty())
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.top()!='(')return false;
                else st.pop();
            }
            else if(s[i]=='}'){
                if(st.top()!='{')return false;
                else st.pop();
            }
            else if(s[i]==']'){
                if(st.top()!='[')return false;
                else st.pop();
            }
            else
                st.push(s[i]);
        }
        if(st.empty())return true;
        return false;        
    }
};