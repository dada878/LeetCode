// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (result.back() == s[i]) {
                result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
