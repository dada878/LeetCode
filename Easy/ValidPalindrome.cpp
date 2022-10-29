#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = end(s) - begin(s);
        int left = 0, right = len - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            else if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (toupper(s[left]) != toupper(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};