#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<char> arr;
	for(int i = 0;i < s.size();i++){
		s[i]=tolower(s[i]);
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y'){
				arr.push_back(s[i]); 
		}
	}
	for(int i = 0;i < arr.size();i++){
		cout << "." << arr.at(i);
	}
	return 0;
} 