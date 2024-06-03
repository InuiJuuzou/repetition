#include<iostream>
#include<vector>
#include<cassert>

class Solution {
private:
    //нахождение середин и отражение относительно нее
    void mirror_horizontally(std::vector<std::vector<int>>& matrix)
    {
        size_t half_size = matrix.size() / 2;
        for (int begin = 0, end = matrix.size()-1; begin < half_size; ++begin, --end)
        {
            std::swap(matrix[begin], matrix[end]);
        }
    }

    void mirror_diagonally(std::vector<std::vector<int>>& matrix)
    {
        int diagonall = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                if (j < diagonall)
                    std::swap(matrix[i][j], matrix[j][i]);
            }
            ++diagonall;
        }
    }
public:
    //алгоритм подсмотрен на ютубе
    //сначала отражаем матрицу относительно горизонтальной середины
    //потом относительно диагонали
    void rotate(std::vector<std::vector<int>>& matrix) {
        mirror_horizontally(matrix);
        mirror_diagonally(matrix);
    }
};


int main()
{
    std::vector<std::vector<int>> matrix = { {1,2,3,10},
                                             {4,5,6,11},
                                             {7,8,9,12},
                                             {13,14,15,16} };

    std::vector<std::vector<int>> matrix1 = { {1,2},{3,4} };

    Solution s;
    s.rotate(matrix1);
    for (auto i : matrix1)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }


}

