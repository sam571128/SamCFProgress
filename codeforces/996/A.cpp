#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define intz(z) int z = 0;
using namespace std;

int main(){
	fastio
	int deno[] = {1,5,10,20,100};
	cini(n);
	intz(count);
	for(int i = 4;i >= 0;i--){
		count+=(n/deno[i]);
		n%=deno[i];
	}
	cout <<count;
}