// https://leetcode.com/problems/n-th-tribonacci-number
#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        for (int i = 0; i < n; i++) {
            long long tmp = c;
            c = a + b + c;
            a = b;
            b = tmp;
        }
        return (int)a;
    }
};