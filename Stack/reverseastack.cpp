// void insertAtBottom(stack<int> &st, int ele)
// {
//    if (st.size() == 0)
//    {
//       st.push(ele);
//       return;
//    }
//    int tp = st.top();
//    st.pop();
//    insertAtBottom(st, ele);
//    st.push(tp);
// }
// void Reverse(stack<int> &st)
// {
//    if (st.size() == 0)
//    {
//       return;
//    }
//    int ele = st.top();
//    st.pop();
//    Reverse(st);
//    insertAtBottom(st, ele);
// }