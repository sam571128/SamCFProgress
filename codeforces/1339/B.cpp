#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	vector<int> v;
	v.push_back(arr[n/2]);
	int i = n/2-1;
	int j = n/2+1;
	int count = 0;
	while(v.size()!=n){
		if(i>=0) v.push_back(arr[i]);
		if(j < n) v.push_back(arr[j]);
		i--;
		j++;
	}
	for(auto x : v) cout << x << " ";
	cout << "\n";

}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}