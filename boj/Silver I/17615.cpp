#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, R = 0, B = 0;
	int i, lr, rr, lb, rb;
	cin >> N;
	string s;
	cin >> s;
	for (i=0;i<N;i++) {
		if (s[i] == 'R') R++;
		else if (s[i] == 'B') B++;
	}

	for (i=0;i<N-1;i++) if (s[i] != 'R') break;
	lr = R - i;
	for (i=0;i<N-1;i++) if (s[i] != 'B') break;
	lb = B - i;
	for (i=N-1;i>=0;i--) if (s[i] != 'R') break;
	rr = R - (N - 1 - i);
	for (i=N-1;i>=0;i--) if (s[i] != 'B') break;
	rb = B - (N - 1 - i);

	cout << min({lr, lb, rr, rb}) << endl;

	return 0;
}
