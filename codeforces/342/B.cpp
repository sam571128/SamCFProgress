#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 100005;
int n, m, s, f, t[N], l[N], r[N];
 
int main() {
	fastio
	cin >> n >> m >> s >> f;
	for (int i = 0; i < m; ++i) {
		cin >> t[i] >> l[i] >> r[i];
	}
	t[m] = -1;
	int timer = 0, pos = 0;
	string ans;
	while (s != f) {
		char ch = (s>f ? 'L' : 'R');
		++timer;
		if (t[pos] == timer) {
			int p1 = s, p2 = ch == 'L' ? s - 1 : s + 1;
			if (p1 >= l[pos] && p1 <= r[pos] || 
				p2 >= l[pos] && p2 <= r[pos]) {
				ch = 'X';
			}
			++pos;
		}
		ans += ch;
		if (ch == 'L') --s;
		else if (ch == 'R') ++s;
	}
	cout << ans << "\n";
	return 0;
}