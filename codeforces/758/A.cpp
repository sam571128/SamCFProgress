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
	cini(n);
	vi v;
	while(n--){
		cini(temp);
		v.push(temp);
	}
	sort(v.begin(),v.end());
	intz(sum);
	for(int i = 0;i < v.size();i++){
		sum+=v[v.size()-1]-v[i];
	}
	cout << sum;
}