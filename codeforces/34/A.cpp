#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int n;
	cin >> n;
	vi v;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		v.pb(a);
	}
	int diff = INT_MAX;
	pair<int,int> p;
	for(int i = 0;i < v.size();i++){
		if(diff>abs(v[i]-v[(i+1)%n])){
			diff = abs(v[i]-v[(i+1)%n]);
			p = make_pair(i+1,(i+1)%n+1);
		}
	}
	cout << p.first << " " << p.second;
}
