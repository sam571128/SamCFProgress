#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int w,l;
	cin >> w >> l;
	vector<int> a(w+1);
	a[0] = a[w] = 1e9+5;
	for(int i = 1;i < w;i++){
		cin >> a[i];
	}
	int answer = 1e9+5;
	int sum = 0;
	for(int i = 0;i < l;i++){
		sum += a[i];
	}
	answer = min(sum,answer);
	for(int i = l;i < w; ++i){
		sum += a[i] - a[i-l];
		answer = min(answer,sum);
	}
	cout << answer << "\n";
}
