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
	string a;
	getline(cin,a);
	for(int i = a.size()-1;i >= 0 ;i--){
		if((a[i]<='z'&&a[i]>='a')||(a[i]<='Z'&&a[i]>='A')){
			if(a[i] == 'A' || a[i] == 'a' || a[i] == 'E' || a[i] == 'e' || a[i] == 'I' || a[i] == 'i'|| a[i] == 'O' || a[i] == 'o'||a[i]=='U'|| a[i]=='u' || a[i]=='Y' || a[i]=='y'){
				cout << "YES";
				break;
			}else{
				cout << "NO";
				break;
			}
		}
	}
}
