#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 205;
string arr[N];
int ans[N];

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	int m;
	cin >> m;
	auto get = [&](int a){
		for(int i = 1;i <= 10;i++){
			for(int j = 0;j < (1<<i);j++){
				string s(i,'0');
				for(int k = 0;k < i;k++){
					if(j&(1<<k)) s[k] = '1';
				}
				if(arr[a].find(s)==-1) return i-1;
			}
		}
	};
	for(int i = 1;i <= m;i++){
		int l, r;
		cin >> l >> r;
		arr[i+n] = arr[l] + arr[r];
		ans[i+n] = max({ans[l],ans[r],get(i+n)});
		if(arr[i+n].size() > 2000) arr[i+n] = arr[i+n].substr(0,1000)+arr[i+n].substr(arr[i+n].size()-1000);
		cout << ans[i+n] << "\n";
	}
}