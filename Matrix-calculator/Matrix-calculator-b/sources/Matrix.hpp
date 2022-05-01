#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace zich
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
   * @param _mat The Matrix
   * @param _row The row
   * @param _column The columns
   *
   */

  Matrix(const vector<double> &_mat, int _row, int _col);

  /**
   * operator +
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator+(const Matrix &_mat) const;

  /**
   * operator -
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator-(const Matrix &_mat) const;

  /**
   * operator *
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix operator*(const Matrix &_mat) const;

  /**
   * operator *
   *
   * @param num The number we want to double the Matrix
   * @return Matrix.
   */

  Matrix operator*(double num) const;

  /**
   * operator -
   * @return Matrix.
   */

  Matrix operator-();

  /**
   * operator +
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
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator+=(const Matrix &_mat);

  /**
   * operator -=
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator-=(const Matrix &_mat);

  /**
   * operator *=
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  Matrix &operator*=(const Matrix &_mat);

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
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator==(const Matrix &_mat) const;

  /**
   * operator !=
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator!=(const Matrix &_mat) const;

  /**
   * operator >=
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator>=(const Matrix &_mat) const;

  /**
   * operator <=
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator<=(const Matrix &_mat) const;

  /**
   * operator <
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator<(const Matrix &_mat) const;

  /**
   * operator >
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  bool operator>(const Matrix &_mat) const;

  /**
   * operator *
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend Matrix operator*(int num, Matrix _mat);

  /**
   * operator *
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend std::istream &operator>>(std::istream &in, Matrix &_mat);

  /**
   * operator *
   *
   * @param _mat The Vector expressing the Matrix
   * @return Matrix.
   */

  friend std::ostream &operator<<(std::ostream &out, const Matrix &_mat);

  /**
   * A function is responsible for summing the matrix members
   * @return Double sum of matrix .
   */
  double Matrix_sum() const
  {
   double count = 0;
   for (size_t i = 0; i < size; ++i)
   {
    count += mat[i];
   }
   return count;
  }

  /**
   * A function that checks the integrity of the input
   *
   * @return True or error.
   */

  bool arg_check(int _row, int _col, vector<double> _mat)
  {
    if (_col < 1 || _row < 1 || _mat.size() != _row * _col)
            {
                throw invalid_argument("Matrix size > 0");
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

  bool check_Matrix_size(Matrix _mat, int mode) const
  {
   switch (mode)
   {
   case 1:

    if (_mat.col != col || _mat.row != row)
    {
     throw invalid_argument("invalid Matrix size for operator +");
    }
    break;
   case 2:
    if (col != _mat.row)
    {
     throw invalid_argument("invalid Matrix size for operator *");
    }
    break;
   }
   return true;
  }
 };

}
