#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v;
	vector<int> ans;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	ans.push_back(v[0]);
	bool in = (v[0]>v[1]);
	for(int i = 1;i < n-1;i++){
		if(in){
			if(v[i]<v[i+1]){
				ans.push_back(v[i]);
				in = !in;
			}
			
		}else{
			if(v[i]>v[i+1]){
				ans.push_back(v[i]);
				in = !in;
			}
			
		}
	}
	ans.push_back(v[n-1]);
	cout << ans.size() << "\n";
	for(auto x : ans){
		cout << x << " ";
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}