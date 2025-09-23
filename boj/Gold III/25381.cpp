#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int cnt[3];
int ab, b, bc;
enum { A, B, C };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	string s;
	cin >> s;
	n = s.size();
	for (i=0;i<n;i++) {
		if (s[i] == 'A') {
			cnt[A]++;
		} else if (s[i] == 'B') {
			if (cnt[A]) {
				ab++;
				cnt[A]--;
			}
			cnt[B]++;
			b++;
		} else if (s[i] == 'C') {
			if (cnt[B]) {
				bc++;
				cnt[B]--;
			}
		}
	}

	cout << min(b, ab+bc) << endl;
	return 0;
}
