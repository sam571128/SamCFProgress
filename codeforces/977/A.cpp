#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	while(k--){
		if(n%10==0){
			n/=10;
		}else{
			n--;
		}
	}
	cout << n;
}