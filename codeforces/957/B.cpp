#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<int> r[n], c[m];
	int ccnt[m] = {}, rcnt[n]= {};
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char tmp;
			cin >> tmp;
			if(tmp=='#') r[i].push_back(j), c[j].push_back(i), rcnt[i]+=(1LL<<j), ccnt[j]+=(1LL<<i);
		}
	}
	bool ok = true;
	for(int i = 0;i < n;i++){
		int tmp = -1;
		for(auto x : r[i]){
			if(tmp==-1) tmp = ccnt[x];
			else if(ccnt[x]!=tmp) ok = false;
		}
	}
	for(int i = 0;i < m;i++){
		int tmp = -1;
		for(auto x : c[i]){
			if(tmp==-1) tmp = rcnt[x];
			else if(rcnt[x]!=tmp){
				ok = false;
			}
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}