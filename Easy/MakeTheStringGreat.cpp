#include <iostream>

using namespace std;

class Solution {
public:
    string removeChar(string s, int index) {
        string r = "";
        for (int i = 0; i < s.length(); i++) {
            if (i != index) {
                r += s[i];
            }
        }
        return r;
    }
    string makeGood(string s) {
        int i = 0;
        while (i < s.length()-1 && s != "") {
            if ( toupper(s[i]) == toupper(s[i+1]) &&
                ( (isupper(s[i]) && islower(s[i+1])) || (islower(s[i]) && isupper(s[i+1])) )
            ) {
                s = removeChar(s, i);
                s = removeChar(s, i);
                i = 0;
                continue;
            }
            i++;
        }
        return s;
    }
};