/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std; //
// given one-based indexing
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
   int sx = KnightPos[0];
   int sy = KnightPos[1];
   int dx = TargetPos[0];
   int dy = TargetPos[1];
   vector<vector<int>> dist(N + 1, vector<int>(N + 1, 0));
   vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
   dist[sx][sy] = 0;
   vis[sx][sy] = 1;
   queue<pair<int, int>> q;
   q.push({sx, sy});
   int movx[] = {1, 2, 2, 1, -1, -2, -2, -1};
   int movy[] = {2, 1, -1, -2, -2, -1, 1, 2};

   while (!q.empty())
   {
      /* code */
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int i = 0; i < 8; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 1 && dr <= N && dc >= 1 && dc <= N && (!vis[sx][sy]))
         {
            q.push({dr, dc});
            dist[dr][dc] = dist[row][col] + 1;
            vis[dr][dc] = 1;
         }
      }
   }
   if (!vis[dx][dy])
      return false; // means not visited
   return dist[dx][dy];
}
int main()
{

   return 0;
}