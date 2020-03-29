#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;

int main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> v;
	v.push(a);
	v.push(b);
	v.push(c);
	sort(v.begin(),v.end());
	cout << v[2]-v[0];
}