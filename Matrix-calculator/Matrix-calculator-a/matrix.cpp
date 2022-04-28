#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <string>
using namespace std;

namespace ariel
{

 Matrix::Matrix(const vector<double> &_mat, int _row, int _col)
 {
  arg_check(_row, _col, _mat);
  col = _col;
  row = _row;
  mat = _mat;
  size = _row * _col;
 }

 Matrix Matrix::operator+(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);
  return *this;
 }

 Matrix Matrix::operator-(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return *this;
 }

 Matrix Matrix::operator*(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 2);

  return *this;
 }

 Matrix Matrix::operator*(double num) const
 {

  return *this;
 }

 Matrix Matrix::operator-()
 {
  return *this;
 }

 Matrix Matrix::operator+()
 {
  return *this;
 }

 Matrix &Matrix::operator++()
 {
  return *this;
 }

 Matrix Matrix::operator++(int)
 {
  return *this;
 }

 Matrix &Matrix::operator--()
 {
  return *this;
 }

 Matrix Matrix::operator--(int)
 {
  return *this;
 }

 Matrix &Matrix::operator+=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 1);

  return *this;
 }

 Matrix &Matrix::operator-=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 1);

  return *this;
 }

 Matrix &Matrix::operator*=(const Matrix &_mat)
 {
  check_Matrix_size(_mat, 2);

  return *this;
 }

 Matrix &Matrix::operator*=(double num)
 {

  return *this;
 }

 bool Matrix::operator==(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 bool Matrix::operator!=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 bool Matrix::operator>=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 bool Matrix::operator<=(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 bool Matrix::operator<(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 bool Matrix::operator>(const Matrix &_mat) const
 {
  check_Matrix_size(_mat, 1);

  return true;
 }

 Matrix operator*(int num, Matrix _mat)
 {

  return _mat;
 }

 std::istream &operator>>(std::istream &in, Matrix &_mat)
 {
  return in;
 }

 std::ostream &operator<<(std::ostream &out, const Matrix &_mat)
 {
  return out;
 }
}