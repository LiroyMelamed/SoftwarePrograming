#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/OrgChart.hpp"
using namespace ariel;

int main()
{
 OrgChart organi;
 organi.add_root("liroy");
 organi.add_sub("liroy", "liav");
 organi.add_sub("liroy", "lishai");
 organi.add_sub("liroy", "liren");
 organi.add_sub("liav", "moshe");
 organi.add_sub("liav", "yael");

 cout << organi << endl;
}