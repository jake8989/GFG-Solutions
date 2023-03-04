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
vector<int> inorder(Node *root)
{
   vector<int> ans;
   stack<Node *> st;
   while (1)
   {
      if (root != NULL)
      {
         st.push(root);
         root = root->left;
      }
      else
      {
         if (st.empty())
            break;

         Node *tpp = st.top();
         st.pop();
         ans.push_back(tpp->data);
         root = root->right;
      }
   }
   return ans;
}
int main()
{

   return 0;
}