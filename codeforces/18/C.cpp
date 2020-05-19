#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	ll sum = 0;
	ll arr[n] = {};
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
		if(i>0) arr[i]+=arr[i-1];
	}
	int ans = 0;
	for(int i = 0;i < n-1;i++){
		if(arr[i]==sum/2.0) ans++;
	}
	cout << ans << "\n";
}