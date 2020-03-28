#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,l;
	cin >> n >> l;
	vector<long double> v;
	while(n--){
		int tmp;
		cin >> tmp;
		v.push(tmp);
	}
	sort(v.begin(),v.end());
	long double result = v[0];
	for(int i = 1;i < v.size();i++){
		result = max(result,(v[i]-v[i-1])/2.0);
	}
	result = max(result,l-v[v.size()-1]);
	cout << fixed << setprecision(20) << result;
}