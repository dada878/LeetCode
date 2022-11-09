// https://leetcode.com/problems/fibonacci-number
#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int tmp = b;
            b = a+b;
            a = tmp;
        }
        return a;
    }
};