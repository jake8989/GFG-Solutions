/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int data)
   {
      this->val = data;
      this->left = this->right = NULL;
   }
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
   vector<vector<int>> ans;
   if (root == NULL)
      return ans;

   queue<TreeNode *> q;
   q.push(root);
   bool LtoR = true;
   while (!q.empty())
   {
      int size = q.size();
      vector<int> level(size);
      for (int i = 0; i < size; i++)
      {
         int index = (LtoR) ? (i) : (size - i - 1);
         TreeNode *par = q.front();
         q.pop();
         level[index] = par->val;
         if (par->left != NULL)
         {
            q.push(par->left);
         }
         if (par->right != NULL)
         {
            q.push(par->right);
         }
      }
      ans.push_back(level);
      LtoR = !LtoR;
   }

   return ans;
}
int main()
{

   return 0;
}