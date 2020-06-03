#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		int deg[n+1] = {};
		for(int i = 0;i < n-1;i++){
			int u,v;
			cin >> u >> v;
			deg[u]++, deg[v]++;
		}
		if(deg[x] <= 1){
			cout << "Ayush" << "\n";
			continue;
		}
		if(n%2){
			cout << "Ashish" << "\n";
		}else{
			cout << "Ayush" << "\n";
		}
	}
}