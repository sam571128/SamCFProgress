#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int n;
	cin >> n;
	int sum = 0;
	int height = 0;
	for(int i = 0;i < n;i++){
		if(i!=0)sum++;
		int a;
		cin >> a;
		if(height>a){
			sum+=(height-a);
			height = a; 
		}
		sum += (a-height+1);
		height = a;
	}
	cout << sum;
}
