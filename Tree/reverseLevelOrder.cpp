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
vector<int> reverseLevelOrder(Node *root)
{
   // code here
   vector<int> ans;
   map<int, vector<int>> mpp;
   queue<pair<Node *, int>> q;
   q.push({root, 0});
   while (!q.empty())
   {
      auto p = q.front();
      q.pop();
      Node *parent = p.first;
      int level = p.second;
      mpp[-level].push_back(parent->data);
      if (parent->left)
      {
         q.push({parent->left, level + 1});
      }
      if (parent->right)
      {
         q.push({parent->right, level + 1});
      }
   }
   for (auto it : mpp)
   {
      for (auto o : it.second)
      {
         ans.push_back(o);
      }
   }
   return ans;
}
int main()
{

   return 0;
}