#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	set<int> s;
	for(int i = 0;i < 4;i++){
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	cout << 4-s.size();
}