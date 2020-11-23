#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	string s1, s2;
	cin >> s1 >> s2;
	int cnt[27] = {}, cnt2[27] = {};
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	for(auto x : s1){
		cnt[x-'a']++;
	}
	for(auto x : s2){
		cnt2[x-'a']++;
	}
	for(int i = 0;i < 26;i++){
		if(cnt[i] < cnt2[i]){
			cout << "NO\n";
			return;
		}else{
			cnt[i] -= cnt2[i];
			if(cnt[i]%k){
				cout << "NO\n";
				return;
			}
			cnt[i+1] += cnt[i];
		}
	}
	if(cnt[26]==0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}