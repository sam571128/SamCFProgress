#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs; 

int x[100000];
int main(){
	fastio
	int i,n,q,m;
	for(cin >> n, i = 0;i < n; cin >> x[i++]);
	for(sort(x,x+n),cin >> q,i = 0;i<q;i++){
		cin >> m, cout << upper_bound(x,x+n,m) - x << "\n";
	}
}