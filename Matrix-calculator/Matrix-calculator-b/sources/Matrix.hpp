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
     * @param mat The Matrix
     * @param row The row
     * @param column The columns
     *
     */

    Matrix(const vector<double> &mat, int row, int col);

    /**
     * @brief operator +
     *
     * @return Matrix.
     */

    Matrix operator+(const Matrix &mat) const;

    /**
     * @brief operator -
     *
     * @return Matrix.
     */

    Matrix operator-(const Matrix &mat) const;

    /**
     * @brief operator *
     *
     *
     * @return Matrix.
     */

    Matrix operator*(const Matrix &mat) const;

    /**
     * @brief operator *
     *
     * @param num The number we want to double the Matrix
     * @return Matrix.
     */

    Matrix operator*(double num) const;

    /**
     * @brief operator -
     *
     * @return Matrix.
     */

    Matrix operator-();

    /**
     * @brief operator +
     *
     * @return Matrix.
     */

    Matrix operator+();

    /**
     * @brief operator ++ (increment)
     *
     * @return Matrix.
     */

    Matrix &operator++();

    /**
     * @brief operator ++
     *
     * @return Matrix.
     */

    Matrix operator++(int);

    /**
     * @brief operator -- (Decrement)
     *
     * @return Matrix.
     */

    Matrix &operator--();

    /**
     * @brief operator --
     *
     * @return Matrix.
     */

    Matrix operator--(int);

    /**
     * @brief operator +=
     *
     * @return Matrix.
     */

    Matrix &operator+=(const Matrix &mat);

    /**
     * @brief operator -=
     *
     * @return Matrix.
     */

    Matrix &operator-=(const Matrix &mat);

    /**
     * @brief operator *=
     *
     * @return Matrix.
     */

    Matrix &operator*=(const Matrix &mat);

    /**
     * @brief operator *=
     *
     * @return Matrix.
     */

    Matrix &operator*=(double num);

    /**
     * @brief operator ==
     *
     * @return Matrix.
     */

    bool operator==(const Matrix &mat) const;

    /**
     * @brief operator !=
     *
     * @return Matrix.
     */

    bool operator!=(const Matrix &mat) const;

    /**
     * @brief operator >=
     *
     * @return Matrix.
     */

    bool operator>=(const Matrix &mat) const;

    /**
     * @brief operator <=
     *
     * @return Matrix.
     */

    bool operator<=(const Matrix &mat) const;

    /**
     * @brief operator <
     *
     * @return Matrix.
     */

    bool operator<(const Matrix &mat) const;

    /**
     * @brief operator >
     *
     * @return Matrix.
     */

    bool operator>(const Matrix &mat) const;

    /**
     * @brief operator *
     *
     * @return Matrix.
     */

    friend Matrix operator*(int num, Matrix mat);

    /**
     * @brief operator *
     *
     * @return Matrix.
     */

    friend std::istream &operator>>(std::istream &in, Matrix &mat);

    /**
     * @brief operator *
     *
     * @return Matrix.
     */

    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);

    /**
     * @brief checks the integrity of the input
     *
     * @return True or error.
     */

    bool arg_check(int row, int col, vector<double> mat)
    {

      size = row * col;
      if (col < 1 || row < 1 || mat.size() != size)
      {
        throw invalid_argument("Matrix size < 0");
      }
      return true;
    }

    /**
     * @brief checking the integrity of the Matrix dimension
     *
     * @param func Number representing the operations Account 1 for (+,-,==,!=, <=...) 2 to (*)
     *
     * @return True or error.
     */

    bool check_matrix_size(Matrix mat, int func) const
    {
      switch (func)
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

    /**
     * @brief summing the matrix members
     *
     * @return sum of matrix .
     */
    double sum_of_mat() const
    {
      double count = 0;
      for (size_t i = 0; i < size; ++i)
      {
        count += mat[i];
      }
      return count;
    }
  };
}
