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
	int r,x1,y1,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	cout << ceil(dist/(2.0*r));
}
