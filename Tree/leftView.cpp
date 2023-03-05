/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if (root == NULL)
      return ans;

   map<int, int> mpp;
   queue<pair<Node *, int>> q;
   q.push({root, 0});
   while (!q.empty())
   {
      /* code */
      auto p = q.front();
      q.pop();
      Node *parent = p.first;
      int level = p.second;
      if (mpp[level] == 0)
         mpp[level] = parent->data;

      if (parent->left)
      {
         q.push({parent->left, level + 1});
         // level===vertex that is in the x dir'n;
      }
      if (parent->right)
      {
         q.push({parent->right, level + 1});
      }
   }
   for (auto it : mpp)
   {
      ans.push_back(it.second);
   }
   return ans;
}

int main()
{

   return 0;
}