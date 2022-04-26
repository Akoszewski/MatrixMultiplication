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
        std::srand(std::time(nullptr));
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
    std::vector<std::vector<int>> data;
private:
    int rows;
    int cols;
};

int main()
{
    Matrix matrix(2, 2);
    // std::cout << matrix.getRows() << std::endl;
    matrix.print();
    return 0;
}