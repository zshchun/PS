#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N;
__uint128_t ans;

void hanoi(int from, int to, ll n) {
        if (n == 1) {
//                ans++;
                cout << from << ' ' << to << endl;
                return;
        }
        int other = 6 - from - to;

        hanoi(from, other, n - 1);
        hanoi(from, to, 1);
        hanoi(other, to, n - 1);
}
ostream& operator<<(ostream &out, __uint128_t v) {
        ostream::sentry s(out);
        char buf[64];
        char *p = end(buf);
        while (v) {
                p--;
                *p = "0123456789"[v % 10];
                v /= 10;
        };
        int len = end(buf) - p;
        out.rdbuf()->sputn(p, len);
        return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        cin >> N;
        ans = 1;
        for (int i=0;i<N;i++) {
                ans *= 2;
        }
        ans -= 1;
        cout << ans << endl;
        if (N <= 20)
                hanoi(1, 3, N);

	return 0;
}
