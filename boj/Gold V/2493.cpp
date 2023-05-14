#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, v, i, ans;
	cin >> N;
	stack<pa> s;
	for (i=1;i<=N;i++) {
		cin >> v;
		while (!s.empty() && s.top().first < v) {
			s.pop();
		}
		if (s.empty()) {
			cout << 0 << ' ';
		} else {
			cout << s.top().second << ' ';
		}
		s.push(pa(v, i));
	}
	cout << endl;

	return 0;
}
