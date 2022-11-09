// https://leetcode.com/problems/online-stock-span/description/

#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
public:
    vector<int> days;

    StockSpanner() {}
    
    int next(int price) {
        days.push_back(price);
        int i;
        for (i = days.size()-1; i >= 0; i--) {
            if (days[i] > price) break;
        }
        return days.size()-i-1;
    }
};