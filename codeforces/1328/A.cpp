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
	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		if(a%b!=0){
			cout << b*(a/b+1)-a << "\n";
		}else{
			cout << 0 << "\n";
		}
	}
}