class Solution {
public:
    bool check(string s){
        int n=s.size();
        //if the size of string is 1 that is always possible so return true
        if(n==1){
            return true;
        }
        //if we have length &gt;3 or string starts with 0 return false
        if(n&gt;3||s[0]=='0'){
            return false;
        }
        //we are converting string to integer to check if it is less than equalto 255
        int val=stoi(s);
        if(val&gt;255){
            return false;
        }
        //return true at last
        return true;
    }
    vector&lt;string&gt; restoreIpAddresses(string s) {
        int n=s.size();
        //we will store our ans in ans vector of strings
        vector&lt;string&gt;ans;
        //the max length of the ip address could be 12 as 255.255.255.255 so 
        //all the string s with size greater than 12 can have ans
        if(n&gt;12){
            return ans;
        }
        //now we have our string of length 12 or less than 12 so now 
            //1. we have to spit the s in parts such that it satisfy the ip address conditions
            //2. if all 4 strings satisfy the condition we will push into ans vector
        for(int i=1;i&lt;=3;i++){//for the length before first '.'
            for(int j=1;j&lt;=3;j++){//for the length between first and second '.'
                for(int k=1;k&lt;=3;k++){//for the length between second and third '.'
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k&lt;n&amp;&amp;i+j+k+3&gt;=n){
                        //dividing the s int substrings 
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
                        //if all the substring satisfy the check function condition 
                        //then we will push into ans vector 
                        if(check(a)&amp;&amp;check(b)&amp;&amp;check(c)&amp;&amp;check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        //return the ans vector
        return ans;
    }
};