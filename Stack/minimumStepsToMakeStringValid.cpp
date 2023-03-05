// wrong solution

// #include <bits/stdc++.h>
// using namespace std;
// int findMinimumCost(string str)
// {
//    // Write your code here
//    if (str.length() % 2)
//       return -1;
//    int op = 0, cl = 0;
//    for (int i = 0; i < str.length(); i++)
//    {
//       if (str[i] == '{')
//          op++;
//       else
//          cl++;
//    }
//    if (op != 0 && cl != 0)
//    {
//       if (op % 2 && cl % 2)
//       {
//          return (op + 1) / 2 + (cl + 1) / 2;
//       }
//       if (op % 2 == 0 && cl % 2 == 0)
//       {
//          return (op + 1) / 2 + (cl + 1) / 2;
//       }
//    }
//    else
//    {
//       if (op == 0)
//       {
//          return cl / 2;
//       }
//       if (cl == 0)
//       {
//          return op / 2;
//       }
//    }
//    return -1;
// }
// int main()
// {

//    return 0;
// }