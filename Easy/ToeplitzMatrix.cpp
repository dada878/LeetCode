#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int lenX = matrix.end() - matrix.begin();
        int lenY = matrix[0].end() - matrix[0].begin();

        int baseY = 0;

        while (baseY < lenY)
        {
            int baseX = lenX - 1;
            while (baseX >= 0)
            {
                int i = 0, j = 0, temp = -1;
                while (baseX + i < lenX & baseY + j < lenY)
                {
                    if (temp == -1)
                    {
                        temp = matrix[baseX + i][baseY + j];
                    }
                    else if (temp != matrix[baseX + i][baseY + j])
                    {
                        return false;
                    }
                    i++;
                    j++;
                }
                baseX--;
            }
            baseY++;
        }

        return true;
    }
};