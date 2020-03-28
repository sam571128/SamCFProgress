#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	string b;
	cin >> a >> b;
	int count1 = 0;
	int count2 = 0;
	for(int i = 0;i < b.size();i++){
		if(b[i]=='D')
			count1++;
		else
			count2++;
	}
	if(count1>count2)
		cout << "Danik";
	else if(count1 < count2)
		cout << "Anton";
	else
		cout << "Friendship";
}