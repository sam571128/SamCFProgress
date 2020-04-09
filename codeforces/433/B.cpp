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
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
ll int sum1[100005];
ll int sum2[100005];
void sumo(vll v){
	ll int sum = 0;
	for(int i = 0;i < v.size();i++){
		sum+=v[i];
		sum1[i] = sum; 
	}
}
void sums(vll v){
	ll int sum = 0;
	for(int i = 0;i < v.size();i++){
		sum+=v[i];
		sum2[i] = sum; 
	}
}
int main(){
	fastio
	int n;
	cin >> n;
	vll v;
	v.push(0);
	while(n--){
		cini(temp);
		v.push(temp);
	} 
	vll sorted(v.begin(),v.end());
	sort(sorted.begin(),sorted.end());
	sumo(v);
	sums(sorted);
	cin >> n;
	while(n--){
		ll int a,b,c;
		cin >> a >> b >> c;
		if(a==1)
			cout << sum1[c]-sum1[b-1] << "\n";
		else
			cout << sum2[c]-sum2[b-1] << "\n";
	}
}
