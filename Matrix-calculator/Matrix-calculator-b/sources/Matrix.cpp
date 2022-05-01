#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <string>
using namespace std;


namespace zich
{

 Matrix::Matrix(const vector<double> &_mat, int _row, int _col)
 {
  arg_check(_row, _col, _mat);
  col = _col;
  row = _row;
  mat = (_mat);
  size = (_row * _col);
 }

 Matrix Matrix::operator+(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  vector<double> temp((size_t)(size));
  for (size_t i = 0; i < size; i++)
  {
   temp[i] = mat[i] + _mat.mat[i];
  }
  return Matrix(temp, row, col);
 }

 Matrix Matrix::operator-(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  vector<double> temp((size_t)(size));
  for (size_t i = 0; i < size; ++i)
  {
   temp[i] = mat[i] - _mat.mat[i];
  }
  return Matrix(temp, row, col);
 }

 Matrix Matrix::operator*(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 2);
  vector<double> temp((size_t)(row * _mat.col));

  for (size_t i = 0; i < row; ++i)
  {
   for (size_t j = 0; j < _mat.col; ++j)
   {
    uint index = i * (size_t)_mat.col + j;
    temp[index] = 0;
    for (size_t k = 0; k < _mat.row; ++k)
    {
     uint _row = i * (size_t)col + k;
     uint _col = k * (size_t)_mat.col + j;
     temp[index] += mat[_row] * _mat.mat[_col];
    }
   }
  }
  return Matrix(temp, row, _mat.col);
 }

 Matrix Matrix::operator*(double num) const
 {
  vector<double> temp((size_t)(size));
  for (size_t i = 0; i < size; ++i)
  {
   temp[i] = mat[i] * num;
  }
  return Matrix(temp, row, col);
 }

 Matrix Matrix::operator-()
 {
  vector<double> temp((size_t)(size));
  for (size_t i = 0; i < size; ++i)
  {
   if (mat[i] == 0)
   {
    continue;
   }
   temp[i] = mat[i] * -1;
  }
  return Matrix(temp, row, col);
 }

 Matrix Matrix::operator+()
 {
  return *this;
 }

 Matrix &Matrix::operator++()
 {
  for (size_t i = 0; i < size; ++i)
  {
   this->mat[i]++;
  }
  return *this;
 }

 Matrix Matrix::operator++(int)
 {
  Matrix temp = *this;
  for (size_t i = 0; i < size; ++i)
  {
   ++this->mat[i];
  }
  return temp;
 }

 Matrix &Matrix::operator--()
 {
  for (size_t i = 0; i < size; ++i)
  {
   this->mat[i]--;
  }
  return *this;
 }

 Matrix Matrix::operator--(int)
 {
  Matrix temp = *this;
  for (size_t i = 0; i < size; ++i)
  {
   --this->mat[i];
  }
  return temp;
 }

 Matrix &Matrix::operator+=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 1);
  for (size_t i = 0; i < size; ++i)
  {
   mat[i] += _mat.mat[i];
  }
  return *this;
 }

 Matrix &Matrix::operator-=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 1);
  for (size_t i = 0; i < size; ++i)
  {
   mat[i] -= _mat.mat[i];
  }
  return *this;
 }

 Matrix &Matrix::operator*=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 2);
  *this = *this * _mat;
  return *this;
 }

 Matrix &Matrix::operator*=(double num)
 {
  for (size_t i = 0; i < size; ++i)
  {
   if (mat[i] == 0)
   {
    continue;
   }
   mat[i] *= num;
  }
  return *this;
 }

 bool Matrix::operator==(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  for (size_t i = 0; i < size; ++i)
  {
   if (mat[i] != _mat.mat[i])
   {
    return false;
   }
  }
  return true;
 }

 bool Matrix::operator!=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  for (size_t i = 0; i < size; ++i)
  {
   if (mat[i] != _mat.mat[i])
   {
    return true;
   }
  }
  return false;
 }

 bool Matrix::operator>=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  return _mat.Matrix_sum() <= this->Matrix_sum();
 }

 bool Matrix::operator<=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  return _mat.Matrix_sum() >= this->Matrix_sum();
 }

 bool Matrix::operator<(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  return _mat.Matrix_sum() > this->Matrix_sum();
 }

 bool Matrix::operator>(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  return _mat.Matrix_sum() < this->Matrix_sum();
 }

 Matrix operator*(int num, Matrix _mat)
 {
  vector<double> temp((size_t)(_mat.size));
  for (size_t i = 0; i < _mat.size; ++i)
  {
   temp[i] = _mat.mat[i] * num;
  }
  return Matrix(temp, _mat.row, _mat.col);
 }

 int count_row(string str, char to_count)
 {
  int count = 0;

  for (size_t i = 0; i < str.size(); i++)
  {
   if (str[i] == to_count)
   {
    ++count;
   }
  }

  return count;
 }
 void valid_input(string str)
 {
  bool flag = false;
  for (size_t i = 0; i < str.length(); ++i)
  {
   if ((str[i] == ']' && !flag) || (str[i] == '[' && flag))
   {
    throw invalid_argument("invalid input ");
   }
   if (str[i] == ']' && flag)
   {
    flag = false;
   }
   if (str[i] == '[')
   {
    flag = true;
   }
   if ((str[i] == ',' && str[i - 1] != ']') ||
       (str[i] == ',' && str[i + 1] != ' '))
   {
    throw invalid_argument("invalid input ");
   }
  }
 }

 std::istream &operator>>(std::istream &in, Matrix &_mat)
 {
  string str;
  getline(in, str);
  valid_input(str);
  int row = count_row(str, ',') + 1;
  std::vector<double> mat_v;
  for (size_t i = 0, j = 0; i < str.length(); j = ++i)
  {
   while (isdigit(str[i]) != 0)
   {
    ++i;
   }
   if (i != j)
   {
    mat_v.push_back(std::stod(str.substr(j, i - j)));
   }
  }
  _mat = Matrix(mat_v, row, int(mat_v.size()) / row);
  return in;
 }

 std::ostream &operator<<(std::ostream &out, const Matrix &_mat)
 {
  int count = 0;
  for (size_t i = 0; i < _mat.size; ++i)
  {
   if (count == 0)
   {
    out << "[";
   }
   out << _mat.mat[i];
   out << ((count != _mat.col - 1) ? " " : (i != _mat.size - 1) ? "]\n"
                                                                : "]");
   count = count == _mat.col - 1 ? 0 : ++count;
  }
  return out;
 }
}
