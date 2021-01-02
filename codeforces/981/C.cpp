#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int deg[N];

signed main(){
	fastio
	int n;
	cin >> n;
	vector<int> v;
	int idx = 0;
	for(int i = 2;i <= n;i++){
		int u,v;
		cin >> u >> v;
		deg[u]++, deg[v]++;
	}
	for(int i = 1;i <= n;i++){
		if(deg[i] > 2){
			if(idx){
				cout << "No\n";
				return 0;
			}else{
				idx = i;
			}
		}
		if(deg[i]==1) v.push_back(i);
	}
	cout << "Yes\n";
	if(idx){
		cout << v.size() << "\n";
		for(auto x : v){
			cout << idx << " " << x << "\n";
		}
	}else{
		cout << 1 << "\n";
		cout << v[0] << " " << v[1] << "\n";
	}
}