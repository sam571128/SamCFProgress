#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	map<int,int> idx;
	int arr[n][m];
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
		cin >> arr[i][j];
		if(j==0) idx[arr[i][j]] = i+1;
	}
	vector<int> a(n);
	for(int i = 0;i < m;i++){
		vector<int> order(n);
		bool ok = 1;
		for(int j = 0, tmp;j < n;j++){
			cin >> tmp; 
			order[j] = idx[tmp];
			if(idx[tmp]==0) ok = 0;
		}
		if(ok) a = order;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cout << arr[a[i]-1][j] << " ";
		cout << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}