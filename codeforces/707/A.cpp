#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push emplace_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin>>s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int a,b;
	cin >> a >> b;
	for(int i = 0;i < a*b;i++){
		cins(temp);
		if(temp=="C"||temp=="M"||temp=="Y"){
			cout << "#Color";
			return 0;
		}
	}
	cout << "#Black&White";
}