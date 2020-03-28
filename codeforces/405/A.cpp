#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	vector<int> v;
	while(a--){
		int tmp;
		cin >> tmp;
		v.push(tmp);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size();i++){
		cout << v[i] << " ";
	}
}