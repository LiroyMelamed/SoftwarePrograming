#pragma once
#include "Direction.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

namespace ariel
{
  class Notebook
  {

  public:
    // constuctor
    Notebook();

    /**
     * change the '_' to what ever we want.
     *
     * This function will write what we want instead of the '_' symbol
     *
     * @param page The requested page to use.
     * @param row The requested row to use.
     * @param column The requested column to use.
     * @param dir The requested direction to use.
     * @param str The requested string to use.
     */

    void write(int page, int row, int column, ariel::Direction dir, string const &str);

    /**
     * Shows the string from the specific page.
     *
     * This function responsible for showing specific string.
     *
     * @param len The chosen length of string we want.
     *
     */
    string read(int page, int row, int column, ariel::Direction dir, int length);

    /**
     * delete_sym string from the page.
     *
     * This function responsible for deleting from the page.
     *
     */
    void erase(int page, int row, int column, ariel::Direction dir, int len);

    /**
     * print page.
     *
     * Function responsible for conveniently displaying the page.
     *
     */
    void show(int page_num);
    map<uint, map<uint, string>> notebook;

  private:
    /**
     * checking if the input is valid.
     *
     * This function checks the validation of the input.
     *
     * @param mode Our choose to write or read
     */
    bool valid(int page, int row_number, int col, ariel::Direction dir, int mode, string const &str = "OK", int len = 1)
    {
      /*
      Checking the parameters before use
      The row number, column, and page number should be positive values
      */
      if (row_number < 0 || col < 0 || col >= 100 || page < 0 || len < 0)
        throw invalid_argument("Incorrect parameters, can not write in negative locations");

      uint page_number = (uint)page;
      uint row = (uint)row_number;
      uint column = (uint)col;
      uint length = (uint)len;
      // Output deviation from the received column (not more than 100 columns)
      if (column >= 100)
        throw invalid_argument("column is invalid");

      // validity read
      if (mode)
      {
        // Check reading input length, not more than 100 columns per line or negative output length
        if (((length > 100 || length + column > 100) && dir == Direction::Horizontal) || length < 0)
          throw invalid_argument("String length is invalid");
      }
      // validity write
      else if (mode == 1)
      {
        uint length_str = str.length();

        // String length integrity check
        if (length_str == 0)
          throw invalid_argument("An empty string");

        // Input deviation from the received column (no more than 100 columns)
        if ((length_str + column >= 100 || length_str >= 100) && dir == Direction::Horizontal)
          throw invalid_argument("String length is invalid");
      }
      // validity erase
      else
      {
        // Check the input length for deletion
        if ((length >= 100 || length + column >= 100) && dir == Direction::Horizontal)
          throw invalid_argument("String length is invalid");
      }
      // Once all the tests are correct we will want to check if the requested page exists and create if necessary
      if (Notebook::pageExist(page_number))
        Notebook::setPage(page_number);

      return 1;
    }
    /**
     * Checking the existence of a page.
     *
     * This function checks if the page exist.
     *
     */
    bool page_check(uint page_num)
    {
      return Notebook::notebook[page_num].empty();
    }

    /**
     * Checking the existence of a line.
     *
     * This function checks if the line exist.
     *
     */
    bool row_check(uint page_num, uint row_number)
    {
      return notebook[page_num][row_number].empty();
    }

    /**
     * Create a new page.
     *
     * This function creates the page.
     *
     */
    void set_page(uint page_num)
    {
      map<uint, string> new_page;
      Notebook::notebook[page_num] = new_page;
    }

    /**
     * Create a new line.
     *
     * This function creates a line.
     *
     */
    void set_row(uint page_num, uint row_number)
    {
      string init_row;
      for (uint i = 0; i < 5; i++)
      {
        init_row += "____________________";
      }
      notebook[page_num][row_number] = init_row;
    }

    /**
     * Creates new lines.
     *
     * This function creates a new lines.
     *
     * @param num_of_rows The number of rows we want to create.
     *
     */
    void create_lines(uint page_num, uint row_number, uint num_of_rows = 3)
    {
      if (row_number <= 0)
      {
        row_number = 1;
        num_of_rows--;
      }
      for (uint i = row_number - 1; i < row_number + num_of_rows; i++)
      {
        if (Notebook::row_check(page_num, i))
          Notebook::set_row(page_num, i);
      }
    }
    /**
     * Returns the requested page.
     *
     * This function returns the requested page.
     *
     */
    map<uint, string>
    getPage(uint page_num)
    {
      return Notebook::notebook[page_num];
    }
  };
}