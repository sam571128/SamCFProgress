#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n,p;
	cin >> n >> p;
	set<int> v;
	while(p--){
		int temp;
		cin >> temp;
		v.insert(temp);
	}
	int y;
	cin >> y;
	while(y--){
		int temp;
		cin >>temp;
		v.insert(temp);
	}
	if(v.size()<n){
		cout << "Oh, my keyboard!";
	}else{
		cout << "I become the guy.";
	}
}