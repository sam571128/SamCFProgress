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
	while(m--){
		int temp;
		cin >> temp;
		v.push(temp);
	}
	ll int sum = v[0]-1;
	for(int i = 1;i < v.size();i++){
		if(v[i]>=v[i-1]){
			sum+= v[i]-v[i-1];
		}else{
			sum+= v[i]-v[i-1]+n;
		}
	}
	cout << sum;
}