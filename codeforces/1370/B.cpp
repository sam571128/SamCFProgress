#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> odd;
	vector<int> even;
	for(int i = 0, tmp;i < 2*n; ++i){
		cin >> tmp;
		if(tmp&1) odd.push_back(i+1);
		else even.push_back(i+1);
	}
	if(odd.size()&1) odd.pop_back(), even.pop_back();
	else if(even.size()==0) odd.pop_back(),odd.pop_back(); 
	else even.pop_back(), even.pop_back();

	for(int i = 0;i < odd.size();i+=2){
		cout << odd[i] << " " << odd[i+1] << "\n";
	}
	for(int i = 0;i < even.size();i+=2){
		cout << even[i] << " " << even[i+1] << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}