#include <iostream>
#include "Notebook.hpp"
#include <map>
#include <string>
using ariel::Notebook;
using namespace std;
typedef unsigned int uint;

void Notebook::change(int page, int row_number, int column, ariel::Direction direction, string const &str)
{
 uint row = (uint)row_number;
 uint col = (uint)column;
 uint page_number = (uint)page;
 uint len = (uint)str.length();
 string line;

 // checks if the input is valid
 if (!Notebook::valid(page, row_number, column, direction, 0, str))
 {
  throw invalid_argument("Input isnt valid");
 }

 if (direction == Direction::Horizontal)
 {
  Notebook::create_lines(page_number, row);
  line = notebook[page_number][row];
  for (uint i = col, cnt = 0; i < len + col; i++, cnt++)
  {
   if (line[i] != '_' || str[cnt] == '\n' || str[cnt] < ' ' || str[cnt] >= '~')
   {
    throw invalid_argument("Cant write horizanl");
   }
   line[i] = str[cnt];
  }
  notebook[page_number][row] = line;
 }

 else
 { // write vertical
  Notebook::create_lines(page_number, row, len + 1);
  bool flag = true;
  for (uint i = row, cnt = 0; i < row + len; i++, cnt++)
  {
   line = Notebook::notebook[page_number][i];
   if (line[col] != '_' || str[cnt] == '\n' || str[cnt] < ' ' || str[cnt] >= '~')
   {
    throw invalid_argument("Cant write vertical");
    flag = false;
    return;
   }
  }
  for (uint i = row, cnt = 0; flag && i < row + len; i++, cnt++)
  {
   Notebook::notebook[page_number][i][col] = str[cnt];
  }
 }
}

string Notebook::read(int page, int row_number, int column, ariel::Direction direction, int len)
{
 if (!Notebook::valid(page, row_number, column, direction, 1, "f", len))
 {
  throw invalid_argument("Input isnt valid");
 }

 uint row = (uint)row_number;
 uint col = (uint)column;
 uint page_number = (uint)page;
 uint length = (uint)len;
 string line;
 string word;
 // Number of rows to create if not available
 uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;
 Notebook::create_lines(page_number, row, count_row);
 // A loop responsible for reading vertically
 for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
 {
  line = Notebook::notebook[page_number][i];
  word += line[col];
 }
 // Gets the line
 line = Notebook::notebook[page_number][row];
 // A loop responsible for reading horizontally
 for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
 {
  word += line[i];
 }
 return word;
}

void Notebook::delete_sym(int page, int row_number, int column, ariel::Direction direction, int len)
{

 uint row = (uint)row_number;
 uint col = (uint)column;
 uint page_number = (uint)page;
 uint length = (uint)len;
 string line;
 string word;

 if (!Notebook::valid(page, row_number, column, direction, 2, "ok", len))
 {
  return;
 }
 uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;
 Notebook::create_lines(page_number, row, count_row);
 for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
 {
  Notebook::notebook[page_number][i][col] = '~';
 }
 for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
 {
  Notebook::notebook[page_number][row][i] = '~';
 }
}

void Notebook::print_page(int page_n)
{
 if (page_n < 0)
 {
  throw invalid_argument("Only positive parameters");
 }

 uint page_number = (uint)page_n;
 if (Notebook::page_check(page_number))
  Notebook::set_page(page_number);

 map<uint, string> page = Notebook::getPage(page_number);
 // Print the page conveniently
 cout << "-Page number(" << to_string(page_number) << ")-" << endl;
 for (auto const &kv : page)
 {
  cout << kv.second << endl;
 }
}

Notebook::Notebook(){};