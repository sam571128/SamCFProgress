#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	map<string,int> m;
	while(t--){
		string a;
		cin >> a;
		if(!m[a]){
			cout << "OK\n";
			m[a]++;
		}else{
			cout << a << m[a] << "\n";
			m[a]++;
		}
	}
}