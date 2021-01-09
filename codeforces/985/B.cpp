#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e3+5;
int cnt[N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<int> tmp[n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if(c=='1') tmp[i].push_back(j), cnt[j]++;
		}
	}
	for(int i = 0;i < n;i++){
		bool ok = true;
		for(auto x : tmp[i]) if(cnt[x] <= 1) ok = false;
		if(ok){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}