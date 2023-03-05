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
vector<vector<int>> levelOrder(Node *node)
{
   // Your code here
   vector<vector<int>> ans;
   queue<Node *> q;
   q.push(node);
   while (!q.empty())
   {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
         vector<int> level;
         Node *parent = q.front();
         q.pop();
         if (parent->left != NULL)
            q.push(parent->left);
         if (parent->right != NULL)
            q.push(parent->right);
         level.push_Back(parent->val);
      }
      ans.push_back(level);
   }

   return ans;
}
int main()
{

   return 0;
}