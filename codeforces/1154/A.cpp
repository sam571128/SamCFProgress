#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define intz(z) int z = 0;
using namespace std;

int main(){
	fastio
	vector<int> v;
	for(int i = 0;i < 4;++i){
		int a;
		cin >> a;
		v.push(a);
	}
	sort(v.begin(),v.end());
	cout << v[3]-v[1] << " " << v[3] - v[2] << " " << v[3] - v[0];
}