#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
typedef pair < int , int > pii;
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
const int N = 2e4 , M = 1e9 + 7 , OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9 , pi = 3.141592653589793;
#define kill return 0
vector < string > RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
 
void Zied(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
template <typename T = int>
istream& operator >>(istream& in, vector < T >& v){
    for ( auto& x : v ) in >> x;
    return in;
}
 
template <typename T = int>
ostream& operator <<(ostream& out, const vector < T >& v){
    for ( const T& x : v ) out << x << ' ';
    return out;
}
 
int dx[4] = {-1, 0, 1, 0};  // Up, Right, Down, Left
int dy[4] = {0, 1, 0, -1};  // Up, Right, Down, Left
char di[] = {'U', 'R', 'D', 'L'};  // Up, Right, Down, Left
 
 
void preprocessing(){
}
 
void Solve(){
    int n , m ;cin >> n >> m ;
    vector < vector < char > > grid(n, vector < char >(m));
    for ( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < m ; ++j ){
            cin >> grid[i][j];
        }
    }
    vector < vector < int > > p(n, vector<int>(m, -1));
    auto bfs = [&]( char c){
        vector < vector<int> > d(n, vector<int>(m, OO));
        queue < pii > q;
        for ( int i = 0 ; i < n ; ++i ){
            for ( int j = 0 ; j < m ; ++j ){
                if ( grid[i][j] == c ) q.push({i, j}), d[i][j] = 0;
            }
        }
        while ( !q.empty() ){
            auto [x , y] = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; ++i ){
                int nx = x + dx[i] , ny = y + dy[i];
                if ( nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == OO && grid[nx][ny] != '#' ){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                    p[nx][ny] = i;
                }
            }
        }
        return d;
    };
 
    auto d1 = bfs('M');
    auto d2 = bfs('A');
 
    int x1 , y1 , x2 = -1 , y2 = -1;
    for ( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < m ; ++j ){
            if ( grid[i][j] == 'A' ) x1 = i, y1 = j;
            if ( (!i or !j or i == n- 1 or j == m-1) && d1[i][j] > d2[i][j] ) x2 = i, y2 = j;
        }
    }
    if ( x2 == -1 ) endd("NO") ;
 
    pii B = {x2, y2} , A = {x1, y1};
    vector < char > path;
    while ( A != B ){
        int k = p[B.X][B.Y];
        path.push_back(di[k]);
        B.X -= dx[k];
        B.Y -= dy[k];
    }
    reverse(all(path));
    cout << "YES\n" << sz(path) << endl;
    for (auto it : path) cout << it;
 
}
 
 
int32_t main(){
    Zied();
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for ( int tc = 1 ; tc <= test_cases ; tc++ ){
        //        cout << "Case #" << tc << ": ";
        Solve();
        //                cout << endl;
    }
    kill;
    //    Time
}
 
/*
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___   MZ   `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)
*/