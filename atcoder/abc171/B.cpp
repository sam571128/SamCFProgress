#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	int sum = 0;
	for(int i = 0;i < k;i++) sum += arr[i];
	cout << sum << "\n";
}