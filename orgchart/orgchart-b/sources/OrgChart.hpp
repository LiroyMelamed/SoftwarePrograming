#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

namespace ariel
{
 class OrgChart
 {
 private:
  class Node
  {
  public:
   string name;
   vector<Node *> children;
   int level_order;

   Node(const string &_name, int level)
   {
    name = _name;
    level_order = level;
   }
   void print_tree(const std::string &prefix, const Node *node, bool has_son)
   {
    {
     if (node != nullptr)
     {
      std::cout << prefix;

      std::cout << (has_son ? "├──" : "└──");

      // print the value of the node
      std::cout << node->name << std::endl;

      // enter the next tree level - left and right branch
      for (Node *n : node->children)
      {
       print_tree(prefix + (has_son ? "│   " : "    "), n, true);
      }
     }
    }
   }
  };
  class Iterator
  {
  private:
   Node *employe;
   std::list<Node *> sorted;

  public:
   Iterator(int Case, Node *temp = nullptr)
   {
    if (temp != nullptr)
    {
     switch (Case)
     {
     case 1:
      level_order(temp);
      break;
     case 2:
      pre_order(temp);
      break;
     case 3:
      reverse_level_order(temp);
      break;
     }
     employe = sorted.front();
     sorted.pop_front();
    }
    else
    {
     employe = nullptr;
    }
   }

   void level_order(Node *ptr = nullptr)
   {
    queue<Node *> que;
    que.push(ptr);
    while (!que.empty())
    {
     employe = que.front();
     que.pop();
     sorted.push_back(employe);
     for (Node *p : employe->children)
     {
      que.push(p);
     }
    }
   }
   void pre_order(Node *ptr = nullptr)
   {
    stack<Node *> temp;
    temp.push(ptr);
    while (!temp.empty())
    {
     employe = temp.top();
     temp.pop();
     sorted.push_back(employe);
     for (unsigned int i = employe->children.size(); i > 0; i--)
     {
      temp.push(employe->children[i - 1]);
     }
    }
   }
   void reverse_level_order(Node *ptr = nullptr)
   {
    map<int, vector<Node *>> temp_employee;
    queue<Node *> que;
    que.push(ptr);
    while (!que.empty())
    {
     employe = que.front();
     que.pop();
     temp_employee[employe->level_order].push_back(employe);
     for (auto *p : employe->children)
     {
      que.push(p);
     }
    }

    for (size_t index = temp_employee.size(); index > 0; index--)
    {
     for (auto *node : temp_employee[index - 1])
     {
      sorted.push_back(node);
     }
    }
   }

   string &operator*() const
   {
    return employe->name;
   }
   /**
    * Overloading operator->
    * @return string name.
    */
   string *operator->() const
   {
    return &employe->name;
   }
   /**
    * Overloading operator++
    * @return iterator.
    */
   Iterator &operator++()
   {
    if (!sorted.empty())
    {
     employe = sorted.front();
     sorted.pop_front();
    }
    else
    {
     employe = nullptr;
    }
    return *this;
   }

   /**
    * Overloading ++operator
    * @return iterator.
    */
   Iterator operator++(int)
   {
    Iterator temp = *this;
    return temp;
   }
   /**
    * Overloading operator==
    * @return bool .
    */
   bool operator==(const Iterator &ite) const
   {
    return employe == ite.employe;
   }
   /**
    * Overloading operator!=
    * @return bool .
    */
   bool operator!=(const Iterator &ite) const
   {
    return employe != ite.employe;
   }
  };

  Node *root;
  int employe_num;

 public:
  OrgChart();

  /**
   * @brief adding the name to the root
   */
  OrgChart add_root(string const &);

  /**
   * @brief adding the name under his manger
   */
  OrgChart add_sub(const string &, const string &);

  /**
   * @brief sort the tree from the root to the last leaf
   *
   * @return the root
   */
  Iterator begin_level_order();

  /**
   * @brief
   */
  Iterator end_level_order();

  /**
   * @brief sort the tree from the leaf to the root
   *
   * @return the last leaf
   */
  Iterator begin_reverse_order();

  /**
   * @brief
   */
  Iterator reverse_order();

  /**
   * @brief sort the tree in pre_order
   *
   * @return sorted last leaf from left
   */
  Iterator begin_preorder();

  /**
   * @brief
   */
  Iterator end_preorder();

  Iterator begin();

  Iterator end();

  /**
   * @brief operator << to print the tree
   */
  friend std::ostream &operator<<(std::ostream &, const OrgChart &);

  void add_child(Node *, const string &, const string &);

  Node &get_root();
 };
}
