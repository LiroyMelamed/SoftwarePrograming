#include <iostream>
#include "matrix.hpp"
#include <vector>
#include <string>
using namespace std;

namespace ariel
{

 matrix::matrix(const vector<double> &mat, int row, int col)
 {
  valid_argument(row, col, mat);
  _col = col;
  _row = row;
  _mat = mat;
  _size = row * col;
 }

 matrix matrix::operator+(const matrix &mat) const
 {
  check_matrix_size(mat, 1);
  return *this;
 }

 matrix matrix::operator-(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return *this;
 }

 matrix matrix::operator*(const matrix &mat) const
 {
  check_matrix_size(mat, 2);

  return *this;
 }

 matrix matrix::operator*(double num) const
 {

  return *this;
 }

 matrix matrix::operator-()
 {
  return *this;
 }

 matrix matrix::operator+()
 {
  return *this;
 }

 matrix &matrix::operator++()
 {
  return *this;
 }

 matrix matrix::operator++(int)
 {
  return *this;
 }

 matrix &matrix::operator--()
 {
  return *this;
 }

 matrix matrix::operator--(int)
 {
  return *this;
 }

 matrix &matrix::operator+=(const matrix &mat)
 {
  check_matrix_size(mat, 1);

  return *this;
 }

 matrix &matrix::operator-=(const matrix &mat)
 {
  check_matrix_size(mat, 1);

  return *this;
 }

 matrix &matrix::operator*=(const matrix &mat)
 {
  check_matrix_size(mat, 2);

  return *this;
 }

 matrix &matrix::operator*=(double num)
 {

  return *this;
 }

 bool matrix::operator==(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 bool matrix::operator!=(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 bool matrix::operator>=(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 bool matrix::operator<=(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 bool matrix::operator<(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 bool matrix::operator>(const matrix &mat) const
 {
  check_matrix_size(mat, 1);

  return true;
 }

 matrix operator*(int num, matrix mat)
 {

  return mat;
 }

 std::istream &operator>>(std::istream &in, matrix &mat)
 {
  return in;
 }

 std::ostream &operator<<(std::ostream &out, const matrix &mat)
 {
  return out;
 }
}