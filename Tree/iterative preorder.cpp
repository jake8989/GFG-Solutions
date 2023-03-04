/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;

vector<int> preorder(Node *root)
{
   vector<int> ans;
   stack<Node *> st;
   st.push(root);
   while (!st.empty())
   {
      Node *parent = st.top();
      st.pop();
      ans.push_back(parent->val);
      if (parent->right)
      {
         st.push(parent->right);
      }
      if (parent->left)
      {
         st.push(parent->left);
      }
   }

   return ans;
}
int main()
{

   return 0;
}