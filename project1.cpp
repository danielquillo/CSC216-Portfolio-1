//Write a C++ program for a matrix class that can add and multiply arbitrary two-dimensional arrays of integers. Do this by overloading the
//addition (“+”) and multiplication (“*”) operators.


#include <iostream>
#include <vector>

class Matrix 
{

    private: 
        std::vector<std::vector<int> > data;

    public:
    Matrix(const std::vector<std::vector<int> >& input) : data(input) {}

    Matrix operator+(const Matrix &other) const 
    {
        Matrix result(*this);

        if(data.size() != other.data.size () || data[0].size() != other.data[0].size()) 
        {
            std::cerr << "Error: Matrices must be of the same dimensions for addition";
            exit(1);
        }

        for(size_t i = 0; i < data.size(); ++i) 
        {
            for(size_t j = 0; j < data[0].size(); ++j) 
            {
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const 
    {
        if (data[0].size() != other.data.size() ) 
        {
            std::cerr << "Error: The dimensions of matrices are incompatible for multiplication";
            exit(1);
        }
        Matrix result(std::vector<std::vector<int> >(data.size(), std::vector<int>(other.data[0].size(), 0)));

        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) 
            {
                for (size_t k = 0; k < data[0].size(); ++k) 
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void display() const 
    {
        for (const auto& row : data) 
        {
            for (int value : row) 
            {
                std::cout << value << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {
    // Example usage
    Matrix matrix1( { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} } );
    Matrix matrix2( { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} } );

    // Addition
    Matrix sum = matrix1 + matrix2;
    std::cout << "Matrix Addition:\n";
    sum.display();
    std::cout << '\n';

    // Multiplication
    Matrix product = matrix1 * matrix2;
    std::cout << "Matrix Multiplication:\n";
    product.display();

    return 0;
}

