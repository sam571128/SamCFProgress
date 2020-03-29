#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin >> i;

using namespace std;

int main(){
	fastio
	cini(k);
	cini(n);
	vector<int> v;
	for(int i = 0;i < n;i++){
		int temp;
		cin >> temp;
		v.push(temp);
	}
	int ma = 0;
	for(int i = 1;i < v.size();i++){
		ma = max(ma,abs(v[i-1]-v[i]));
	}
	cout << k - max(ma,k-v.back()+v[0]);
}