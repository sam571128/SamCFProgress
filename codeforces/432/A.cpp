#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	vi v;
	while(n--){
		cini(temp);
		if(temp+k<=5)v.push(temp);
	}
	cout << v.size()/3;
}