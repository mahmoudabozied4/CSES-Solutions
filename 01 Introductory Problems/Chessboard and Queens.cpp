#include <bits/stdc++.h>
using namespace std;
#define Zied ios_base::sync_with_stdio(false);cin.tie(nullptr);
 
char grid[8][8];
int ans = 0;
vector<pair<int, int>> queens;
void solve(int col)
{
    if(col == 8)
    {
        ans++;
        return;
    }
 
    for(int row = 0; row < 8; row++) if(grid[row][col] != '*')
    {
        int flag = 1;
        // check
        for(auto [x, y] : queens)
            if(row == x || ((x+y) == (row+col)) || ((x-y) == (row-col))) 
                flag = 0;
        
        if(flag)
        {
            queens.push_back({row, col});
            solve(col+1);
            queens.pop_back();
        }
    }
}
 
int main()
{
    Zied
 
    for(int i = 0; i < 8; i++)
        for(int j =  0; j < 8; j++)
            cin >> grid[i][j];
    solve(0);    
 
    cout << ans;
    return 0;
}