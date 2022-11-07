// Link: https://leetcode.com/problems/maximum-69-number

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int numLen(int num)
    {
        int result = 0;
        while (num > 1)
        {
            num /= 10;
            result++;
        }
        return result;
    }
    int *numToArray(int num)
    {
        int len = numLen(num);
        int *result = new int[5];
        for (int i = len - 1; i >= 0; i--)
        {
            result[i] = num % 10;
            num /= 10;
        }
        return result;
    }
    int maximum69Number(int num)
    {
        int len = numLen(num);
        int *nums = numToArray(num);
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 6)
            {
                nums[i] = 9;
                break;
            }
        }
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            result += nums[i] * pow(10, len - i - 1);
        }
        return result;
    }
};