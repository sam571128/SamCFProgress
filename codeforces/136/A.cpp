#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	int count[a];
	int b = 1;
	for(int i = 0;i < a;i++){
		int temp;
		cin >> temp;
		count[temp-1] = b;
		b++; 
	}
	for(int i = 0;i < a;i++){
		cout << count[i] << " ";
	}
}