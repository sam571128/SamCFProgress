#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5;
int deg[N];

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	sort(deg,deg+n+1);
	if(deg[1]==2&&deg[n]==2) cout << "ring topology" << "\n";
	else if(deg[1]==1&&deg[n-1]==1&&deg[n] == n-1) cout << "star topology" << "\n";
	else if(deg[1]==1&&deg[2]==1&&deg[n] == 2) cout << "bus topology" << "\n";
	else cout << "unknown topology" << "\n";

}