#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs; 

int main(){
	fastio
	string a,b;
	cin >> a;
	getline(cin,b);
	getline(cin,b);
	for(int i = 0;i < b.size();i++){
		if(b[i]==a[0]||b[i]==a[1]){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}