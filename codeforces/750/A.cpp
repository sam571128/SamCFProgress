#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(k+5*i>240)break;
		k+=5*i;
		count = i;
	}
	cout << count;
}