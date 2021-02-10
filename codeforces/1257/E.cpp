#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int bit[N];

void update(int pos, int val){
	while(pos < N){
		bit[pos] = max(val,bit[pos]);
		pos += pos&-pos;
	}
}

int query(int pos){
	int res = 0;
	while(pos){
		res = max(res,bit[pos]);
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	int arr1[a], arr2[b], arr3[c];
	for(auto &x : arr1) cin >> x;
	for(auto &x : arr2) cin >> x;
	for(auto &x : arr3) cin >> x;
	sort(arr1,arr1+a);
	sort(arr2,arr2+b);
	sort(arr3,arr3+c);
	int n = a+b+c;
	pair<int,int> arr[n];
	for(int i = 0;i < a;i++) arr[i] = {arr1[i],i+1};
	for(int i = a;i < a+b;i++) arr[i] = {arr2[i-a],i+1};
	for(int i = a+b;i < a+b+c;i++) arr[i] = {arr3[i-a-b],i+1};
	sort(arr,arr+n);
	int ans = 0;
	for(auto [aa,bb] : arr){
		int now = query(bb)+1;
		ans = max(now,ans);
		update(bb,now); 
	}
	cout << n-ans << "\n";
}