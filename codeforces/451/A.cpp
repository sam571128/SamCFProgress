#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	cout << (min(n,m)%2==0 ? "Malvika" : "Akshat"); 
}