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
	int n,m;
	cin >> n >> m;
	vi v;
	while(m--){
		int a,b;
		cin >> a >> b;
		v.pb(a);
		v.pb(b);
	}
	int center = 1;
	while(count(v.begin(),v.end(),center)){
		center++;
	}
	cout << n-1 << "\n";
	for(int i = 1;i <= n;i++){
		if(i!=center){
			cout << center << " " << i << "\n";
		}
	}
}
