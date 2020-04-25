#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int x,a,b;
		cin >> x >> a >> b;
		while(x>20&&a--){
			x = x/2 + 10;
		}
		while(x>0&&b--){
			x-=10;
		}
		if(x<=0){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
