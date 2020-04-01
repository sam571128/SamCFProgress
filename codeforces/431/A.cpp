#include <bits/stdc++.h>
#include <cmath>

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

int main(){
	fastio
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	string e;
	cin >> e;
	intz(sum);
	for(auto i : e){
		if(i=='1'){
			sum+=a;
		}else if(i=='2'){
			sum+=b;
		}else if(i=='3'){
			sum+=c;
		}else if(i=='4'){
			sum+=d;
		}
	}
	cout << sum;
}
