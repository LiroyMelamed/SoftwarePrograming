#include "OrgChart.hpp"

using namespace ariel;

namespace ariel
{

  OrgChart::OrgChart() : root(nullptr), employe_num(0) {}

  OrgChart OrgChart::add_root(const string &_name)
  {
    if (_name.empty())
    {
      throw invalid_argument("at least one char");
    }
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
    if (parent.empty() || child.empty())
    {
      throw invalid_argument("at least one char");
    }
    if (root == nullptr)
    {
      throw invalid_argument("create Organzation first");
    }
    int check = employe_num;
    add_child(root, parent, child);
    if (check == employe_num)
    {
      throw invalid_argument("cant find employee");
    }
    return *this;
  }
  OrgChart::Iterator OrgChart::begin_level_order()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{1, root};
  }
  OrgChart::Iterator OrgChart::end_level_order()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{1, nullptr};
  }
  OrgChart::Iterator OrgChart::begin_reverse_order()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{3, root};
  }
  OrgChart::Iterator OrgChart::reverse_order()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{3, nullptr};
  }
  OrgChart::Iterator OrgChart::end_preorder()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{2, nullptr};
  }
  OrgChart::Iterator OrgChart::begin_preorder()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{2, root};
  }
  OrgChart::Iterator OrgChart::begin()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{1, root};
  }
  OrgChart::Iterator OrgChart::end()
  {
    if (root == nullptr)
    {
      throw invalid_argument("chart is empty!");
    }
    return Iterator{1, nullptr};
  }

  std::ostream &operator<<(ostream &out, const OrgChart &p1)
  {
    p1.root->print_tree("", p1.root, false);
    return out;
  }

  void OrgChart::add_child(Node *temp_root, const string &parent, const string &child)
  {
    if (temp_root->name == parent)
    {
      Node *new_child = new Node(child, temp_root->level_order + 1);
      temp_root->children.push_back(new_child);
      employe_num++;
    }
    else
    {
      unsigned int l = temp_root->children.size();
      for (unsigned int i = 0; i < l; i++)
      {
        add_child(temp_root->children[i], parent, child);
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