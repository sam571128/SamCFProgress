#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 2e5+5;
ll tree[maxn];
ll n,q;

void update(ll idx, ll val){
	while(idx <= n){
		tree[idx] += val;
		idx += idx & (-idx);
	}
}

ll query(int idx){
	ll sum = 0;
	while(idx){
		sum += tree[idx];
		idx -= idx & (-idx);
	}
	return sum;
}

int main(){
	fastio
	cin >> n >> q;
	ll arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	while(q--){
		ll l,r;
		cin >> l >> r;
		update(l,1);
		update(r+1,-1);
	}
	vector<int> freq;
	for(int i = 1;i <= n;i++){
		freq.push_back(query(i));
	}
	sort(freq.begin(),freq.end());
	ll sum = 0;
	for(int i = 0;i < n ;i++){
		sum += freq[i]*arr[i];
	}
	cout << sum << "\n";
}