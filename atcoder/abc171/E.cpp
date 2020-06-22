#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	ll sum = 0;
	for(int x : arr) sum ^= x;
	for(int x : arr) cout << (sum^x) << " ";
}	