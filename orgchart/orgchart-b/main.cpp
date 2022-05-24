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

     cout << "our tree \n"
          << endl;
     // print the tree:
     //   └──liroy
     //      ├──liav
     //      │   ├──moshe
     //      │   ├──yael
     //      ├──lishai
     //      ├──liren

     cout << organi << endl;

     cout << "begin level order - "
          << endl;

     for (auto it = organi.begin_level_order(); it != organi.end_level_order(); ++it)
     {
          cout << (*it) << " ";

     } // prints: liroy liav lishai liren moshe yael

     cout << " \n"
          << endl;
     cout << "begin reverse order - "
          << endl;
     for (auto it = organi.begin_reverse_order(); it != organi.reverse_order(); ++it)
     {
          cout << (*it) << " ";
     } // prints: moshe yael liav lishai liren liroy

     cout << " \n"
          << endl;
     cout << "begin preorder - "
          << endl;
     for (auto it = organi.begin_preorder(); it != organi.end_preorder(); ++it)
     {
          cout << (*it) << " ";
     } // prints: liroy liav moshe yael lishai liren

     cout << " \n"
          << endl;
     cout << "level order - "
          << endl;
     for (auto element : organi)
     {
          cout << element << " ";
     } // prints: liroy liav lishai liren moshe yael
     cout << " \n"
          << endl;

     cout << "arrow operator (size of name) - "
          << endl;
     for (auto it = organi.begin_level_order(); it != organi.end_level_order(); ++it)
     {
          cout << it->size() << " ";
     } // prints: 5 4 6 5 5 4
     cout << " \n"
          << endl;

     cout << "changing the root \n"
          << endl;
     organi.add_root("lera");
     cout << organi << endl;

     cout << "adding sub with the same name \n"
          << endl;
     organi.add_sub("liren", "liren");
     cout << organi << endl;

     cout << "adding four level sub \n"
          << endl;
     organi.add_sub("moshe", "liroy");
     cout << organi << endl;
}