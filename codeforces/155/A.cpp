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
	cini(a);
	cini(b);
	int ma = b;
	int mi = b;
	a--;
	intz(cnt);
	while(a--){
		cini(n);
		if(n>ma){
			ma = n;
			cnt++;
		}else if(n < mi){
			mi = n;
			cnt++;
		}
	}
	cout << cnt;
}