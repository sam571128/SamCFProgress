#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push emplace_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 


int main(){
	fastio
	int a;
	cin >> a;
	while(a--){
		double temp;
		cin >> temp;
		double sides = -360.0/(temp-180.0);
		if(ceil(sides)==sides&&sides >= 1){
			cout << "YES" << "\n";
		}else{
			cout << "NO" << "\n";
		}
	}
}