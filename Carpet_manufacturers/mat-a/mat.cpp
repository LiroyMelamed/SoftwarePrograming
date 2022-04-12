#include "mat.hpp"
#include <iostream>
#include <map>g
#include <string.h>
#include <string>
using namespace std;

string ariel::mat(int width, int hight, char symbol1, char symbol2)
{
 // Checking if the column and row number is odd
 if (width % 2 == 0 || hight % 2 == 0)
 {
  throw invalid_argument("The row and column numbers need to be odd");
 }
 // Checking if the row and column isnt an negative number
 if (width <= 0 || hight <= 0)
 {
  throw invalid_argument("Input must be bigger the 0");
 }
 // Checking the symbol
 if (symbol1 < '!' || symbol1 > '~' || symbol2 < '!' || symbol2 > '~')
 {
  throw invalid_argument("Change your letters");
 }
 // New vector boot of a two-dimensional char type
 vector<vector<char> > vec;
 // Initialize vector rows in symbol2
 for (int i = 0; i < hight; i++)
 {
  vector<char> row;
  row.reserve(width);
  for (int j = 0; j < width; j++)
  {
   row.push_back(symbol2);
  }
  vec.push_back(row);
 }
 // A call to the function that builds the rug
 create_rug(0, hight - 1, 0, width, symbol1, vec);
 // A new variable of the string type that chains the result of the rug to it
 string mat;
 for (int i = 0; i < hight; i++)
 {
  string s(vec[i].begin(), vec[i].end());
  mat += s + '\n';
 }
 // Returns the desired result
 return mat;
}

void create_rug(int a, int b, int c, int d, char symbol1, vector<vector<char> > &matrix)
{
 int length_row = matrix.size();
 int length_col = matrix[a].size();
 // Stop conditions for recursion
 if (length_row / 2 < a || c > length_col / 2)
 {
  return;
 }

 for (int j = c; j < d; j++)
 {
  matrix[b][j] = symbol1;
  matrix[a][j] = symbol1;
 }

 for (int j = a; j < b; j++)
 {
  matrix[j][c] = symbol1;
  matrix[j][d - 1] = symbol1;
 }

 create_rug(a + 2, b - 2, c + 2, d - 2, symbol1, matrix);
}
