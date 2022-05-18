#include "OrgChart.hpp"

using namespace ariel;

namespace ariel
{

 OrgChart::OrgChart() : root(nullptr), employe_num(0) {}

 OrgChart OrgChart::add_root(const string &_name)
 {
  if (root == nullptr)
  {
   root = new Node(_name, 0);
  }
  else
  {
   root->name = _name;
  }
  employe_num++;

  return *this;
 }

 OrgChart OrgChart::add_sub(const string &parent, const string &child)
 {
  if (root == nullptr)
  {
   throw invalid_argument("create Organzation first");
  }
  else
  {
   Node *new_Child = new Node(child, 0);
   add_child(root, parent, new_Child);
  }
  employe_num++;
  return *this;
 }
 OrgChart::Iterator OrgChart::begin_level_order()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::end_level_order()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::begin_reverse_order()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::reverse_order()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::end_preorder()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::begin_preorder()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::begin()
 {
  return Iterator{root};
 }
 OrgChart::Iterator OrgChart::end()
 {
  return Iterator{root};
 }

 std::ostream &operator<<(ostream &out, const OrgChart &p1)
 {
  p1.root->print_tree("", p1.root, false);
  return out;
 }

 void OrgChart::add_child(Node *temp_root, string parent, Node *new_child)
 {
  if (temp_root->name == parent)
  {
   new_child->level_order = temp_root->level_order + 1;
   for (Node *n : temp_root->children)
   {
    if (n->name == new_child->name)
    {
     throw invalid_argument("Employee exist");
    }
   }
   temp_root->children.push_back(new_child);
  }
  else
  {
   int l = temp_root->children.size();
   for (unsigned int i = 0; i < l; i++)
   {
    if (temp_root->children[i]->name == parent)
     add_child(temp_root->children[i], parent, new_child);
    else
     add_child(temp_root->children[i], parent, new_child);
   }
  }
  // else
  // {
  //  for (Node *n : root->children)
  //  {
  //   if (n->name == parent)
  //   {
  //    add_child(n, parent, new_child);
  //   }
  //   add_child(n, parent, new_child);
  //  }
  // }
 }
 OrgChart::Node &OrgChart::get_root()
 {
  return *root;
 }
}