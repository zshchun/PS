#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	string s;
	cin >> N;
	while (N--) {
		cin >> s;
		sort(s.begin(), s.end());
		do {
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end()));
	}
	return 0;
}
