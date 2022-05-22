#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <stack>
#include <queue>

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
   void print_tree(const std::string &prefix, const Node *node, bool is_left)
   {
    {
     if (node != nullptr)
     {
      std::cout << prefix;

      std::cout << (is_left ? "├──" : "└──");

      // print the value of the node
      std::cout << node->name << std::endl;

      // enter the next tree level - left and right branch
      for (Node *n : node->children)
      {
       print_tree(prefix + (is_left ? "│   " : "    "), n, true);
      }
     }
    }
   }
  };
  class Iterator
  {
  private:
   Node *employe;

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
    }
    else
    {
     employe = nullptr;
    }
   }

   void level_order(Node *ptr = nullptr)
   {
    queue<Node *> q;
    q.push(ptr);
    while (!q.empty())
    {
     employe = q.front();
     q.pop();
     for (Node *p : employe->children)
     {
      q.push(p);
     }
    }
   }
   void pre_order(Node *ptr = nullptr)
   {
    stack<Node *> Stack;
    Stack.push(ptr);
    while (!Stack.empty())
    {
     employe = Stack.top();
     Stack.pop();
     for (unsigned int i = employe->children.size(); i > 0; i--)
     {
      Stack.push(employe->children[i - 1]);
     }
    }
   }
   void reverse_level_order(Node *ptr = nullptr)
   {
    queue<Node *> q;
    q.push(ptr);
    while (!q.empty())
    {
     employe = q.front();
     q.pop();
     for (auto *p : employe->children)
     {
      q.push(p);
     }
    }
   }

   string &operator*() const { return employe->name; }
   /**
    * Overloading operator->
    * @return string name.
    */
   string *operator->() const
   {
    return &(employe->name);
   }
   /**
    * Overloading operator++
    * @return iterator.
    */
   Iterator &operator++()
   {
    return *this;
   }

   /**
    * Overloading ++operator
    * @return iterator.
    */
   Iterator operator++(int)
   {
    Iterator tmp = *this;
    return tmp;
   }
   /**
    * Overloading operator==
    * @return bool .
    */
   bool operator==(const Iterator &rhs) const
   {
    return employe == rhs.employe;
   }
   /**
    * Overloading operator!=
    * @return bool .
    */
   bool operator!=(const Iterator &rhs) const
   {
    return employe != rhs.employe;
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

  void add_child(Node *, string, Node *);

  Node &get_root();
 };
}
