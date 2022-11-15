// https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkDiff(string s, int start, int size) {
        string save;
        for (int i = start; i < start + size; i++) {
            if ((int)save.find(s[i]) >= 0) {
                return true;
            }
            save.push_back(s[i]);
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int winSize = 1;
        int winPoint = 0;
        while (winPoint + winSize <= s.length()) {
            if (checkDiff(s, winPoint, winSize)) {
                winPoint++;
            } else {
                winSize++;
            }
        }
        return winSize - 1;
    }
};