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
	intz(cc);
	intz(cm);
	cini(a);
	while(a--){
		cini(n);
		cini(m);
		if(n>m)cm++;
		else if(n<m) cc++;
	}
	if(cm>cc)cout<<"Mishka";
	else if(cc > cm)cout<<"Chris";
	else cout<< "Friendship is magic!^^";
}
