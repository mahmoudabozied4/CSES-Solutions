#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى
using namespace std;
#define ll long long
#define ull unsigned long long
#define lol long long int
#define endl '\n'
#define Zied() (ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr));
#define fixed(n) fixed << setprecision(n)
#define sz(s) int(s.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define pi  3.141592653589793
#define all(vec) vec.begin(), vec.end()
 
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
template <typename T = int> istream& operator >> (istream &in, vector <T> &v) {for(auto &x : v) in >> x; return in;}
template <typename T = int> ostream& operator << (ostream &out, const vector <T> &v) {for(const T &x : v) out << x << ' '; return out;}
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
 
vector < int > factors (int n){
    vector < int > ret ;
    for (int i = 1; i*i <= n ; ++i) {
        if (n%i==0){
            ret.push_back(i);
            if (!( i*i == n)) ret.push_back(n/i);
        }
 
    }
    return ret;
};
void Solve() {
    int n ;  cin >> n;
    auto x = factors(n);
    cout << sz(x)<< endl;
}
int main() {
    Zied()
    int test_cases = 1;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
//        cout << "Case #" << tc << ": ";
        Solve();
//        cout << endl;
    }
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