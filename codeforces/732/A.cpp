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
	cini(k);
	cini(r);
	int count = 1;
	while(k*count%10!=0&&(k*count-r)%10!=0){
		count++;
	}
	cout << count;
}