#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,t;
	cin >> n >> t;
	vector<int> v;
	for(int i = 0;i < n-1;i++){
		int temp;
		cin >> temp;
		v.push(temp);
	}
	int a = 1;
	while(a<t){
		a+= v[a-1];
	}
	if(a==t){
		cout << "YES";
		return 0;
	}else{
		cout << "NO";
		return 0;
	}
}