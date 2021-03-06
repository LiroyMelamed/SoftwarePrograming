#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 */
string nospaces(string input)
{
  std::erase(input, ' ');
  std::erase(input, '\t');
  std::erase(input, '\n');
  std::erase(input, '\r');
  return input;
}

TEST_CASE("Good input")
{

  CHECK(nospaces(mat(1, 5, '&', '-')) == nospaces("&\n"
                                                  "&\n"
                                                  "&\n"
                                                  "&\n"
                                                  "&"));

  CHECK(nospaces(mat(1, 1, 'm', '-')) == nospaces("m"));

  CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                  "@-------@\n"
                                                  "@-@@@@@-@\n"
                                                  "@-@---@-@\n"
                                                  "@-@@@@@-@\n"
                                                  "@-------@\n"
                                                  "@@@@@@@@@"));

  CHECK(nospaces(mat(7, 5, '@', '-')) == nospaces("@@@@@@@\n"
                                                  "@-----@\n"
                                                  "@-@@@-@\n"
                                                  "@-----@\n"
                                                  "@@@@@@@"));

  CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces("@@@@@@@\n"
                                                  "@-----@\n"
                                                  "@-@@@-@\n"
                                                  "@-@-@-@\n"
                                                  "@-@@@-@\n"
                                                  "@-----@\n"
                                                  "@@@@@@@"));

  CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n"
                                                  "@-@\n"
                                                  "@-@\n"
                                                  "@-@\n"
                                                  "@@@"));

  CHECK(nospaces(mat(5, 7, '@', '-')) == nospaces("@@@@@\n"
                                                  "@---@\n"
                                                  "@-@-@\n"
                                                  "@-@-@\n"
                                                  "@-@-@\n"
                                                  "@---@\n"
                                                  "@@@@@"));

  CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                   "@-----------@\n"
                                                   "@-@@@@@@@@@-@\n"
                                                   "@-----------@\n"
                                                   "@@@@@@@@@@@@@"));

  CHECK(nospaces(mat(11, 15, '@', '-')) == nospaces("@@@@@@@@@@@\n"
                                                    "@---------@\n"
                                                    "@-@@@@@@@-@\n"
                                                    "@-@-----@-@\n"
                                                    "@-@-@@@-@-@\n"
                                                    "@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@\n"
                                                    "@-@-@-@-@-@\n"
                                                    "@-@-@@@-@-@\n"
                                                    "@-@-----@-@\n"
                                                    "@-@@@@@@@-@\n"
                                                    "@---------@\n"
                                                    "@@@@@@@@@@@\n"));
}

TEST_CASE("Bad input")
{

  for (int i = 0; i < 20; i += 2)
  {
    CHECK_THROWS(mat(i, i - 1, '$', '%'));
    CHECK_THROWS(mat(9, i, '$', '%'));
    CHECK_THROWS(mat(i, i + 8, '$', '%'));
    CHECK_THROWS(mat(i + 1, i, '$', '%'));
    CHECK_THROWS(mat(10, i, '$', '%'));
  }

  for (int i = 0; i > -20; i--)
    for (int j = 0; j < 20; j++)
      CHECK_THROWS(mat(i, j, '$', '%'));

  for (int i = 0; i > -20; i--)
    for (int j = 0; j < 20; j++)
      CHECK_THROWS(mat(j, i, '$', '%'));
}

TEST_CASE("Bad letters")
{

  char a = '\0', b = '\0';
  for (int i = -256; i < 256; i++)
  {
    if (i < 33 || 126 < i)
    {
      a = i;
      CHECK_THROWS(mat(9, 7, a, b));
    }
  }
  for (int i = -256; i < 256; i++)
  {
    if (i < 33 || 126 < i)
    {
      b = i;
      CHECK_THROWS(mat(9, 7, a, b));
    }
  }
  for (int i = -256; i < 256; i++)

  {
    if (i < 33 || 126 < i)
    {
      a = i;
    }
    for (int j = -256; j < 256; j++)
    {
      if (j < 33 || 126 < j)
      {
        b = j;
        CHECK_THROWS(mat(8, 7, a, b));
        CHECK_THROWS(mat(9, 8, a, b));
        CHECK_THROWS(mat(2, 8, a, b));
        CHECK_THROWS(mat(10, 2, a, b));
      }
    }
  }
}