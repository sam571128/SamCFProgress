#include <bits/stdc++.h>
#include <cmath>

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
	int a;
	cin >> a;
	int i = 1;
	while (i*5<a){
		a-=i*5;
		i*=2;
	}
	string names[] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
	cout << names[(a-1)/i];
}