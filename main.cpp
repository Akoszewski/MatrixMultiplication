#include <iostream>
#include <vector>
#include <ctime>

const int maxVal = 9;

class Matrix
{
public:
    Matrix(int rows, int cols)
      : rows(rows), cols(cols)
    {
        data.reserve(rows);
        for (int i = 0; i < rows; i++)
        {
            data.push_back(std::vector<int>(cols, 0));
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = std::rand() % maxVal;
            }
        }
    }
    int getRows() const {
        return data.size();
    }
    int getCols() const {
        if (getRows() > 0) {
            return data[0].size();
        } else {
            return 0;
        }
    }
    void print() const
    {
        std::cout << std::endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    Matrix operator*(const Matrix& mat2)
    {
        return Matrix(2, 2);
    }
    std::vector<std::vector<int>> data;
private:
    int rows;
    int cols;
};

int main()
{
    std::srand(std::time(nullptr));
    Matrix matrix(2, 2);
    matrix.print();
    Matrix matrix2(2, 2);
    matrix2.print();
    Matrix res = matrix * matrix2;
    res.print();
    return 0;
}