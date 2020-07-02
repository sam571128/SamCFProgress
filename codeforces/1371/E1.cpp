#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,p;
	cin >> n >> p;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	int mi = -1, ma = INT_MAX;
	for(int i = 0;i < n;i++)
		mi = max(mi,arr[i]-i);
	for(int i = p-1;i < n;i++)
		ma = min(ma,arr[i]-(i-(p-1)+1));

	vector<int> ans;
	while(mi++<=ma){
		ans.push_back(mi-1);
	}
	cout << ans.size() << "\n";
	for(int i = 0;i < ans.size();i++)
		cout << ans[i] << " \n"[ans.size()-1==i];
}