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
	int n,m;
	cin >> n >> m;
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(i%m==0){
			n++;
		}
		count++;
	}
	cout << count;
}