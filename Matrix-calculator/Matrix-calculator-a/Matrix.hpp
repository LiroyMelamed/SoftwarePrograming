#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace ariel
{
 class Matrix
 {
 private:
  int row;
  int col;
  int size;
  vector<double> mat;

 public:
  /**
   *
   * @param mat The Matrix
   * @param row The row
   * @param column The columns
   *
   */

  Matrix(const vector<double> &mat, int row, int col);

  /**
   * operator +
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator+(const Matrix &mat) const;

  /**
   * operator -
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator-(const Matrix &mat) const;

  /**
   * operator *
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator*(const Matrix &mat) const;

  /**
   * operator *
   *
   * @param num The number we want to double the Matrix
   * @return Matrix.
   */

  Matrix operator*(double num) const;

  /**
   * operator -
   * - unary
   * @return Matrix.
   */

  Matrix operator-();

  /**
   * operator +
   * + unary
   * @return Matrix.
   */

  Matrix operator+();

  /**
   * operator ++ (increment)
   * @return Matrix.
   */

  Matrix &operator++();

  /**
   * operator ++
   * @return Matrix.
   */

  Matrix operator++(int);

  /**
   * operator -- (Decrement)
   * @return Matrix.
   */

  Matrix &operator--();

  /**
   * operator --
   * @return Matrix.
   */

  Matrix operator--(int);

  /**
   * operator +=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator+=(const Matrix &mat);

  /**
   * operator -=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator-=(const Matrix &mat);

  /**
   * operator *=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator*=(const Matrix &mat);

  /**
   * operator *=
   *
   * @param num The number we want to double the Matrix
   * @return Matrix.
   */

  Matrix &operator*=(double num);

  /**
   * operator ==
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator==(const Matrix &mat) const;

  /**
   * operator !=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator!=(const Matrix &mat) const;

  /**
   * operator >=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator>=(const Matrix &mat) const;

  /**
   * operator <=
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator<=(const Matrix &mat) const;

  /**
   * operator <
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator<(const Matrix &mat) const;

  /**
   * operator >
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator>(const Matrix &mat) const;

  /**
   * operator *
   *
   * @param mat The Vector expressing the Matrix
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend Matrix operator*(int num, Matrix mat);

  /**
   * operator *
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend std::istream &operator>>(std::istream &in, Matrix &mat);

  /**
   * operator *
   *
   * @param mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);

  /**
   * A function that checks the integrity of the input
   *
   * @param mat The Vector expressing the Matrix
   * @param row The rows
   * @param col The columns
   * @return True or error.
   */

  bool valid_argument(int row, int col, vector<double> mat)
  {

   size = row * col;
   if (col < 1 || row < 1 || mat.size() != size)
   {
    throw invalid_argument("Matrix size < 0");
   }
   return true;
  }

  /**
   * A function is responsible for checking the integrity of the Matrix dimension
   *
   * @param mat The Vector expressing the Matrix
   * @param mode Number representing the operations Account 1 for (+,-,==,!=, <=...) 2 to (*)

   * @return True or error.
   */

  bool validsizeMatrix(Matrix mat, int mode) const
  {
   switch (mode)
   {
   case 1:

    if (mat.col != col || mat.row != row)
    {
     throw invalid_argument("invalid Matrix size for operator +");
    }
    break;
   case 2:
    if (col != mat.row)
    {
     throw invalid_argument("invalid Matrix size for operator *");
    }
    break;
   }
   return true;
  }
 };

}
