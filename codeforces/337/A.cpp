#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<int> v;
	for(int i = 0;i < m;i++){
		int temp;
		cin >> temp;
		v.push(temp);
	}
	sort(v.begin(),v.end());
	int result = INT_MAX;
	for(int i = 0;i <= m-n;i++){
		result = min(result,v[i+n-1] - v[i]);
	}
	cout << result;
}