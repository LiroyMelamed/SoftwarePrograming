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

    void change(int page, int row, int column, ariel::Direction dir, string const &str);

    /**
     * Shows the string from the specific page.
     *
     * This function responsible for showing specific string.
     *
     * @param len The chosen length of string we want.
     *
     */
    string print(int page, int row, int column, ariel::Direction dir, int len);

    /**
     * delete_sym string from the page.
     *
     * This function responsible for deleting from the page.
     *
     */
    void delete_sym(int page, int row, int column, ariel::Direction dir, int len);

    /**
     * print page.
     *
     * Function responsible for conveniently displaying the page.
     *
     */
    void print(int page_num);
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
      if (row_number < 0 || col < 0 || col >= 100 || page < 0 || len < 0)
        throw invalid_argument("Only possitive parameters");

      uint page_num = (uint)page;
      uint row = (uint)row_number;
      uint column = (uint)col;
      uint length = (uint)len;

      // write
      if (mode == 1)
      {
        uint length_str = str.len();
        if ((length_str + column >= 100 || length_str >= 100) && dir == Direction::Horizontal)
          throw invalid_argument("String len is invalid");
        if (length_str == 0)
          throw invalid_argument("An empty string");
      }
      // read
      else if (mode)
      {
        if (((len > 100 || len + column > 100) && dir == Direction::Horizontal) || len < 0)
          throw invalid_argument("Change string length");
      }
      // erase
      else
      {
        if ((len >= 100 || len + column >= 100) && dir == Direction::Horizontal)
          throw invalid_argument("String len is incorrect");
      }

      if (column >= 100)
        throw invalid_argument("More than 100 columns");

      // Checking if the page exist
      if (Notebook::page_check(page_num))
        Notebook::set_page(page_num);

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
  };

  /**
   * Returns the requested page.
   *
   * This function returns the requested page.
   *
   */
  map<uint, string> getPage(uint page_num)
  {
    return Notebook::notebook[page_num];
  }

}