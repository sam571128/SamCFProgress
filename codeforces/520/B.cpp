#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	int count = 0;
	while(m!=n){
		count++;
		if(m%2==0&&m>n){
			m/=2;
		}else{
			m++;
		}
	}
	cout << count;
}