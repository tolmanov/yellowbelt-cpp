#include "matrix.h"

void Matrix::Reset(int num_rows, int num_cols){
    if ((num_rows < 0) || (num_cols < 0)) throw std::out_of_range("Number cannot be negative");
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this->data = std::vector<std::vector<int>>(num_rows, std::vector<int>(num_cols));
    return;
}

Matrix::Matrix(int num_rows, int num_cols){
    if ((num_rows < 0) || (num_cols < 0)) throw std::out_of_range("Number cannot be negative");
    this->num_rows = num_rows;
    this->num_cols=num_cols;
    this->data = std::vector<std::vector<int>>(num_rows, std::vector<int>(num_cols));
    return;
}


const int& Matrix::At(int row, int col) const{
    if ((row >= this->num_rows) || (col >= this->num_cols) || (row < 0) || (col < 0)) 
        throw std::out_of_range("Exceeds the columns/rows range");
    return data[row][col];
}

int& Matrix::At(int row, int col){
    return const_cast<int &>(static_cast<const Matrix &>(*this).At(row, col));
}


int Matrix::GetNumRows() const{
    return this->num_rows;
}

int Matrix::GetNumColumns() const{
    return this->num_cols;
}

bool Matrix::operator ==(const Matrix& rhs) const{
    if ((this->num_cols * this->num_rows == 0) && (rhs.num_cols * rhs.num_rows == 0)) return true;
    else if ((this->num_cols != rhs.num_cols) || (this->num_rows != rhs.num_rows)) return false;
    else{
        for (int i=0; i<this->num_rows; i++){
            for (int j=0; j<this->num_cols; j++){
                if (this->At(i, j) != rhs.At(i, j)) return false;
            }
        }
        return true;
    }
}

Matrix Matrix::operator +(const Matrix& rhs) const{
    if ((this->num_cols * this->num_rows == 0) && (rhs.num_cols * rhs.num_rows == 0)) return Matrix();
    else if ((this->num_cols != rhs.num_cols) || (this->num_rows != rhs.num_rows)) throw std::invalid_argument("Size does not match");
    else {
        Matrix m = Matrix(this->num_rows, this->num_cols);
        for (int i=0; i<this->num_rows; i++){
            for (int j=0; j<this->num_cols; j++){
                m.At(i, j) = this->At(i, j) + rhs.At(i, j); 
            }
        }
        return m;
    }
}
