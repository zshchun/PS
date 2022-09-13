#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, D, i;
	cin >> N >> D;
	while (N != 0 || D != 0) {
		string s, t;
		stack<char> st;
		cin >> s;
		for (i=0;i<N;i++) {
			char c = s[i];
			ll r = N - D;
			while (!st.empty() && st.top() < c && i < D+st.size())  {
				st.pop();
			}
			if (st.size() < N-D)
				st.push(c);
		}
		
		while (!st.empty()) {
			t = st.top() + t;
			st.pop();
		}
		cout << t << endl;
		cin >> N >> D;
	}
	return 0;
}
