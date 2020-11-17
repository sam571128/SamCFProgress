#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int solve(vector<int> arr, int i){
	if(i < 0) return 0;
	vector<int> v1, v2;
	for(auto x : arr){
		if((x >> i) & 1) v1.push_back(x);
		else v2.push_back(x);
	}
	int a = 0, b = 0;
	if(v1.size()) a = solve(v1,i-1);
	if(v2.size()) b = solve(v2,i-1);
	return min(max((int)1,(int)v1.size())+b-1,max((int)1,(int)v2.size())+a-1);
}

signed main(){
	fastio
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << solve(v,30) << "\n";
}