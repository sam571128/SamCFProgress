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
	string n;
	cin >> n;
	int index = -1;
	int start = ((n[n.size()-1]=='0')? 1 : 0); 
	for(int i = start;i < n.size()-1;i++){
		if((n[i]-'0')%2==0){
			if((n[n.size()-1]-'0')>(n[i]-'0')){
				index = i;
				break;
			}else{
				index = i;
				continue;
			}
		}
	}
	if(index == -1){
		cout << index;
		return 0;
	}
	swap(n[index],n[n.size()-1]);
	cout << n;	
}
