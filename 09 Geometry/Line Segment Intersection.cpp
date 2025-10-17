#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define ld long long
#define int long long
#define ull unsigned long long
#define endl '\n'
typedef pair<int, int> pii;
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
const int N = 2e4, M = 1e9 + 7, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = acos(-1);
#define kill return 0
vector<string> RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
 
void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
template<typename T = int>
istream &operator >>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}
 
template<typename T = int>
ostream &operator <<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
enum dir { d, r, u, l, ul, dr, ur, dl };
 
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
 
 
struct point{
    ld x , y;
};
 
point operator+ (point a , point b){
    return {a.x + b.x , a.y + b.y};
}
 
point operator- (point a , point b){
    return {a.x - b.x , a.y - b.y};
}
 
point operator- (point a){
    return {-a.x , -a.y};
}
 
point operator* (point a , point b){
    return {a.x * b.x , a.y * b.y};
}
 
point operator/ (point a , point b){
    return {a.x / b.x , a.y / b.y};
}
 
point operator* (point a , ld d){
    return {a.x * d , a.y * d};
}
 
point operator/ (point a , ld d){
    return {a.x / d , a.y / d};
}
 
bool operator== (point a , point b){
    return a.x == b.x && a.y == b.y;
}
 
bool operator!= (point a , point b){
    return a.x != b.x || a.y != b.y;
}
 
auto sq(point a){
    return a.x * a.x + a.y * a.y;
}
 
auto abs(point a){
    return sqrt(sq(a));
}
 
auto dot(point a , point b){
    return a.x * b.x + a.y * b.y;
}
 
auto cross(point a , point b){
    return a.x * b.y - a.y * b.x;
}
 
ld angle(point a , point b){
    if(!cross(a , b))
        return a.x > 0 == b.x > 0 && a.y > 0 == b.y > 0 ? 0 : 180;
    return acos(dot(a , b) / abs(a) / abs(b)) * 180 / pi;
}
 
auto dist(ld x1 , ld y1 , ld x2 , ld y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
auto dist(point a , point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
auto area_of_tri(point a , point b , point c){
    return abs(cross(b - a , c - a) / 2.0);
}
 
ld area_of_polygon(vector<point> &v){
    ld ret = 0;
    int n = v.size();
    for(int i = 0; i < n; i ++){
        ret += cross(v[i] , v[(i + 1) % n]);
    }
    return abs(ret);
}
 
int orientation(point a, point b, point c) { // ab, c
    auto val = cross(b - a , c - a);
    if (val == 0)
        return 0;  // Collinear
    return (val > 0) ? 1 : 2;  // Counterclockwise or Clockwise
}
 
bool onSegment(point a, point b, point c) { // a -> b -> c
    return !cross(c - a, b - a) && b.x >= min(a.x, c.x) && b.x <= max(a.x, c.x) &&
            b.y >= min(a.y, c.y) && b.y <= max(a.y, c.y);
}
 
bool doLinesIntersect(point a, point b, point c, point d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);
 
    // General case
    if (o1 != o2 && o3 != o4) return true;
 
    if (onSegment(a, c, b)) return true;
    if (onSegment(a, d, b)) return true;
    if (onSegment(c, a, d)) return true;
    if (onSegment(c, b, d)) return true;
 
    return false;
}
 
void preprocessing() {
}
 
void Solve() {
    vector<point> v(4);
    for (auto &it : v)
        cin >> it.x >> it.y;
    cout << RET[doLinesIntersect(v[0], v[1], v[2], v[3])]  << endl;
}
 
int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
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