#include "mat.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

void create_mat(int a, int b, int c, int d, char char1, vector<vector<char>> &mat)
{
 
 int length_row = mat.size();

 int length_col = mat[a].size();
 // Stop conditions for recursion
 if (length_row / 2 < a || c > length_col / 2)
 {
  return;
 }

 for (int j = c; j < d; j++)
 {
  mat[b][j] = char1;
  mat[a][j] = char1;
 }

 for (int j = a; j < b; j++)
 {
  mat[j][c] = char1;
  mat[j][d - 1] = char1;
 }

 create_mat(a + 2, b - 2, c + 2, d - 2, char1, mat);
}

string ariel::mat(int width, int hight, char char1, char char2)
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
 if (char1 < '!' || char1 > '~' || char2 < '!' || char2 > '~')
 {
  throw invalid_argument("Change your letters");
 }
 // New vector boot of a two-dimensional char type
 vector<vector<char>> vec;
 // Initialize vector rows in char2
 for (int i = 0; i < hight; i++)
 {
  vector<char> row;
  row.reserve(width);
  for (int j = 0; j < width; j++)
  {
   row.push_back(char2);
  }
  vec.push_back(row);
 }
 // A call to the function that builds the rug
 create_mat(0, hight - 1, 0, width, char1, vec);
 // A new variable of the string type that chains the result of the rug to it
 string matrix;
 for (int i = 0; i < hight; i++)
 {
  string s(vec[i].begin(), vec[i].end());
  matrix += s + '\n';
 }
 // Returns the desired result
 return matrix;
}
