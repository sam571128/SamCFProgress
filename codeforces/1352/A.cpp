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

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int count = 0;
		vi v;
		while(n!=0){
			int tmp = n%10*pow(10,count);
			if (tmp)v.pb(tmp);
			count++;
			n/=10;
		}
		cout << v.size() << "\n";
		for(int x : v){
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
