#include <string>
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Good input")
{
 Notebook notebook;

 // print test from somewhere that is unwritten
 for (int i = 110; i < 116; i++)
  CHECK(notebook.print(i, 0, 0, Direction::Horizontal, 10) == "__________");

 // writing test
 for (int i = 0; i < 10; i++)
  notebook.change(i, 0, 0, Direction::Horizontal, to_string(i) + " row!");

 // printing test of the changes above
 for (int i = 0; i < 10; i++)
  CHECK(notebook.print(i, 0, 0, Direction::Horizontal, 6) == to_string(i) + " row!");
 for (int i = 10; i < 20; i++)
  CHECK(notebook.print(i, 0, 0, Direction::Vertical, 10) == to_string(i) + " column!");

 // delete test
 for (int i = 0; i < 10; i++)
  notebook.delete(i, 0, 0, Direction::Horizontal, 2);
 for (int i = 10; i < 20; i++)
  notebook.delete(i, 0, 0, Direction::Vertical, 1);

 for (int i = 10; i < 20; i++)
  notebook.change(i, 0, 0, Direction::Vertical, to_string(i) + " column!");

 // delete function test if removed
 for (int i = 0; i < 10; i++)
  CHECK(notebook.print(i, 0, 0, Direction::Horizontal, 2) == "~~");
 for (int i = 10; i < 20; i++)
  CHECK(notebook.print(i, 0, 0, Direction::Vertical, 1) == "~");
}

TEST_CASE("Bad input ")
{
 Notebook notebook;

 // invalid parameters test
 for (int i = -10; i < 0; i++)
 {
  CHECK_THROWS(notebook.print(i, 0, 0, Direction::Horizontal, i * -1));
  CHECK_THROWS(notebook.print(i, 0, 0, Direction::Horizontal, i));
  CHECK_THROWS(notebook.print(i, i, 0, Direction::Horizontal, i));
  CHECK_THROWS(notebook.print(i, i, i, Direction::Horizontal, i));
  CHECK_THROWS(notebook.print(i, 0, i, Direction::Horizontal, i));
  CHECK_THROWS(notebook.print(i, i, 0, Direction::Horizontal, i));
  CHECK_THROWS(notebook.print(i, 0, 0, Direction::Vertical, i * -1));
  CHECK_THROWS(notebook.print(i, 0, 0, Direction::Vertical, i));
  CHECK_THROWS(notebook.print(i, i, 0, Direction::Vertical, i));
  CHECK_THROWS(notebook.print(i, i, i, Direction::Vertical, i));
  CHECK_THROWS(notebook.print(i, 0, i, Direction::Vertical, i));
  CHECK_THROWS(notebook.print(i, i, 0, Direction::Vertical, i));
 }

 // change more then 100 char to a row from 0 and 99 column
 CHECK_THROWS(notebook.change(1, 0, 0, Direction::Horizontal, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
 CHECK_THROWS(notebook.change(1, 0, 99, Direction::Horizontal, "#$$%^^^^%^%^$%$^%&%"));

 // check if possible to change more then 100 chars to column
 CHECK_NOTHROW(notebook.change(2, 0, 0, Direction::Vertical, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2"));

 notebook.change(0, 0, 0, Direction::Horizontal, "Check the delete function");
 notebook.delete(0, 0, 0, Direction::Horizontal, 20);
 CHECK_THROWS(notebook.change(0, 0, 0, Direction::Horizontal, "Check the delete function"));

 // check for invalid input for column over 100 and length of row over 100
 CHECK_THROWS(notebook.print(0, 0, 120, Direction::Horizontal, 10));
 CHECK_THROWS(notebook.delete(0, 0, 120, Direction::Horizontal, 10));
 CHECK_THROWS(notebook.delete(0, 0, 0, Direction::Horizontal, 150));
 CHECK_THROWS(notebook.print(0, 0, 0, Direction::Horizontal, 150));
}
