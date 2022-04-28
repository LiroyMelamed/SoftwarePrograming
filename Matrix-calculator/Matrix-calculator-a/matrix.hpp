#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace ariel
{
 class matrix
 {
 private:
  int row;
  int col;
  int size;
  vector<double> mat;

 public:
  /**
   *
   * @param mat The matrix
   * @param row The row
   * @param column The columns
   *
   */

  matrix(const vector<double> &mat, int row, int col);

  /**
   * operator +
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix operator+(const matrix &mat) const;

  /**
   * operator -
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix operator-(const matrix &mat) const;

  /**
   * operator *
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix operator*(const matrix &mat) const;

  /**
   * operator *
   *
   * @param num The number we want to double the matrix
   * @return matrix.
   */

  matrix operator*(double num) const;

  /**
   * operator -
   * - unary
   * @return matrix.
   */

  matrix operator-();

  /**
   * operator +
   * + unary
   * @return matrix.
   */

  matrix operator+();

  /**
   * operator ++ (increment)
   * @return matrix.
   */

  matrix &operator++();

  /**
   * operator ++
   * @return matrix.
   */

  matrix operator++(int);

  /**
   * operator -- (Decrement)
   * @return matrix.
   */

  matrix &operator--();

  /**
   * operator --
   * @return matrix.
   */

  matrix operator--(int);

  /**
   * operator +=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix &operator+=(const matrix &mat);

  /**
   * operator -=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix &operator-=(const matrix &mat);

  /**
   * operator *=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  matrix &operator*=(const matrix &mat);

  /**
   * operator *=
   *
   * @param num The number we want to double the matrix
   * @return matrix.
   */

  matrix &operator*=(double num);

  /**
   * operator ==
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator==(const matrix &mat) const;

  /**
   * operator !=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator!=(const matrix &mat) const;

  /**
   * operator >=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator>=(const matrix &mat) const;

  /**
   * operator <=
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator<=(const matrix &mat) const;

  /**
   * operator <
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator<(const matrix &mat) const;

  /**
   * operator >
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  bool operator>(const matrix &mat) const;

  /**
   * operator *
   *
   * @param mat The Vector expressing the matrix
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  friend matrix operator*(int num, matrix mat);

  /**
   * operator *
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  friend std::istream &operator>>(std::istream &in, matrix &mat);

  /**
   * operator *
   *
   * @param mat The Vector expressing the matrix
   * @return matrix.
   */

  friend std::ostream &operator<<(std::ostream &out, const matrix &mat);

  /**
   * A function that checks the integrity of the input
   *
   * @param mat The Vector expressing the matrix
   * @param row The rows
   * @param col The columns
   * @return True or error.
   */

  bool valid_argument(int row, int col, vector<double> mat)
  {

   size = row * col;
   if (col < 1 || row < 1 || mat.size() != size)
   {
    throw invalid_argument("matrix size < 0");
   }
   return true;
  }

  /**
   * A function is responsible for checking the integrity of the matrix dimension
   *
   * @param mat The Vector expressing the matrix
   * @param mode Number representing the operations Account 1 for (+,-,==,!=, <=...) 2 to (*)

   * @return True or error.
   */

  bool validsizematrix(matrix mat, int mode) const
  {
   switch (mode)
   {
   case 1:

    if (mat.col != col || mat.row != row)
    {
     throw invalid_argument("invalid matrix size for operator +");
    }
    break;
   case 2:
    if (col != mat.row)
    {
     throw invalid_argument("invalid matrix size for operator *");
    }
    break;
   }
   return true;
  }
 };

}