#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define lol long long int
#define endl '\n'
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fr first
#define sc second
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define kill return 0
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define pi  3.14159
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
typedef pair<int , int> pii;
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
const int N = 1e5 + 1 , M = 998244353 , OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9;
vector < string > RET = {"No", "Yes"};
 
void Zied(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
template<typename T = int> istream& operator >>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}
template<typename T = int> ostream& operator <<(ostream& out, const vector<T>& v) {
    for (const T& x : v)
        out << x << ' ';
    return out;
}
 
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
char di[] = {'D', 'L', 'U', 'R'};
 
void preprocessing() {
 
}
int cost = 0 ;
void dfs(int node , vector < bool > &vis , vector <vector <int >> &grid) {
    vis[node] = 1 ;
    for (auto ch : grid[node]) {
        if (!vis[ch]){
            dfs(ch  , vis , grid);
        }
    }
}
void Solve() {
    int n , m ; cin >> n >> m  ;
    vector<vector<int>> grid( n , vector<int> ( ));
    for (int i = 0; i < m ; ++i) {
        int u , v ; cin >> u >> v ; u-- , v--;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    vector < bool > vis(n);
    queue < int > q;
    q.push(0);
    vector < int > parent(n);
    parent[0] = -1;
    vis[0] = 1;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto ch : grid[cur]) {
            if (!vis[ch]){
                q.push(ch);
                vis[ch] = 1 ;
                parent[ch] = cur;
            }
        }
    }
    if (!vis[n - 1]){
        cout << "IMPOSSIBLE" << endl;
    }else{
        vector < int > v;
        v.push_back(n);
        int ed = n - 1 ;
        while (parent[ed]!= -1){
            v.push_back(parent[ed] + 1);
            ed = parent[ed];
        }
        reverse(all(v));
        cout << sz(v) << endl << v ;
    }
}
 
 
int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
//    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
//                cout << endl;
    }
    kill;
    //    Time
}
/*
                ,     :     ,
           '.    ;    :    ;    ,`
     '-.  `.  `-.._ .:. _..-'  ,'
  ,     '-. .:  __     __  :.-' ,
  :  :    ,  ,-'"  `. .  `"-.  ,    ;  ;
  '  `._ ,-'" `"-.  .-".  .-"` "-._ ,'  ,'
        `:.   `.  `. -  `-'  ,'  , :    ,'
  ,    .      `.  `. -  `-'  ,'  , :  '    .
       ;  `,   `.  `-..__.,-' ,  ,` '    ;
   ` . :   `,.  `-..__,,..-' ,'  ,    :    ` .
       ` .   `-.__,,..-'   ,    ,   :    ` .
 
*/