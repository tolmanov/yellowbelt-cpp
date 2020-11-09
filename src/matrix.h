#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

class Matrix{
    public:
        Matrix() :
            num_rows{0},
            num_cols{0},
            data{std::vector<std::vector<int>>(0, std::vector<int>(0))} {}
        Matrix(int num_rows, int num_cols);
        const int& At(int row, int col) const;
        int& At(int row, int col);
        int GetNumRows() const;
        int GetNumColumns() const;
        void Reset(int num_rows, int num_cols);
        int num_rows;
        int num_cols;
        bool operator == (const Matrix& rhs) const;
        Matrix operator + (const Matrix& rhs) const;
        friend std::ostream &operator<<(std::ostream &output, const Matrix &m){
            output << m.num_rows << " " << m.num_cols << std::endl;
            for (auto row: m.data){
                for (auto i: row){
                    output << i << " ";
                }
                output << std::endl;
            }
            return output;
        }
        friend std::istream &operator>>(std::istream &input, Matrix &m){
            int num_rows, num_cols=0;
            input >> num_rows >> num_cols;
            m = Matrix(num_rows, num_cols);
            for(int i=0; i<m.num_rows; i++){
                for(int j=0; j<m.num_cols; j++){
                    input >> m.At(i, j);
                }
            }
            return input;
        }
    private:
        std::vector<std::vector<int>> data;

};
