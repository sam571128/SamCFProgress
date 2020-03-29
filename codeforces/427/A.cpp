#include <bits/stdc++.h>

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
	cini(t);
	intz(sum);
	intz(count);
	while(t--){
		cini(tmp);
		if(sum+tmp<0){
			count++;
		}else{
			sum+=tmp;
		}
	} 
	cout << count;
}