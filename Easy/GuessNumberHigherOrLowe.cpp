// https://leetcode.com/problems/guess-number-higher-or-lowe
class Solution {
public:
    int guess(int num); //not this
    int guessNumber(int n) {
        int min = 1;
        int max = n;
        int response;
        int guessNum = max;
        while (true) {
            response = guess(guessNum);
            if (response == 0) {
                break;
            } else if (response == 1) {
                min = guessNum;
            } else {
                max = guessNum;
            }
            guessNum = ((long long)min + (long long)max) / 2;
        }
        return guessNum;
    }
};