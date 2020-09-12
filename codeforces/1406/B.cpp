#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> pos, neg;
	int ans = -1e18;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		if(tmp > 0) pos.push_back(tmp);
		else if(tmp < 0) neg.push_back(tmp);
		else ans = 0;
	}
	if(pos.size()==0){
		if(neg.size()<5){
			cout << 0 << "\n";
			return;
		}
		if(ans==0){
			cout << 0 << "\n";
			return;
		}
		sort(neg.begin(),neg.end(),greater<int>());
		int prod = 1;
		for(int i = 0;i < 5;i++){
			prod *= neg[i];
		}
		cout << prod << "\n";
		return;
	}
	if(neg.size()==0){
		if(pos.size()<5){
			cout << 0 << "\n";
			return;
		}
		sort(pos.begin(),pos.end(),greater<int>());
		int prod = 1;
		for(int i = 0;i < 5;i++){
			prod *= pos[i];
		}
		cout << prod << "\n";
		return;
	}
	for(int i = 1;i <= 5;i+=2){
		sort(pos.begin(),pos.end(),greater<int>());
		sort(neg.begin(),neg.end());
		if(pos.size()<i||neg.size()<5-i) continue;
		int prod = 1;
		for(int j = 0;j < i;j++){
			prod *= pos[j];
		}
		for(int j = 0;j < 5-i;j++){
			prod *= neg[j];
		}
		ans = max(ans,prod);
	}
	for(int i = 2;i < 5;i+=2){
		sort(pos.begin(),pos.end(),less<int>());
		sort(neg.begin(),neg.end());
		if(pos.size()<i||neg.size()<5-i) continue;
		int prod = 1;
		for(int j = 0;j < i;j++){
			prod *= pos[j];
		}
		for(int j = 0;j < 5-i;j++){
			prod *= neg[j];
		}
		ans = max(ans,prod);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}