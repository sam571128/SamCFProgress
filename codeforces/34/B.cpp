#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int n,k;
	cin >> n >> k;
	vi v;
	int sum = 0;
	while(n--){
		cini(temp);
		v.push(temp);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < k;i++){
		if(v[i]>0) break;
		sum-=v[i];
	}
	cout << sum;
}
