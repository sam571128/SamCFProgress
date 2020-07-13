#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast")
//#pragma optimize("O3")
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff first
#define ss second
#define forn(i, n) for(int i=0;i<n;i++)
#define fore(i, l, r) for(int i=l;i<r;i++)
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vpi vector<pi>
#define gcd(a,b) __gcd(a,b)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqr(x) ((x)*(x))
#define newstr cout << "\n"
#define call(a) for(auto xxx:a)cout<<xxx<<" ";cout<<"\n";
//#define FILE
const string alf = "abcdefghijklmnopqrstuvwxyz";
const int hashP = 239017;
const int N = 1e5+10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const ll INF2 = 1e18;
 
template<typename T>
bool umn(T &a, T b) { return (a > b ? (a = b, 1) : 0); }
template<typename T>
bool umx(T &a, T b) { return (a < b ? (a = b, 1) : 0); }
 
int main() {
 
    FASTIO;
 
#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
 
    int tt;
    cin >> tt;
    while(tt--) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll ans=0;
        ans+=min(b,c/2)*3;
        b-=c/2;
        if(b<0) b=0;
        ans+=min(a,b/2)*3;
        cout << ans << "\n";
    }
 
    return 0;
}