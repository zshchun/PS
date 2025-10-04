#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define INPOSSIBLE 0
#define THANKS 1
#define NO_THANKS 2
int ans;

void dfs(int x, int price, int coins, int ku, int borrowed) {
	if (x == 10) {
		if (price == 0) {
			if (!borrowed)
				ans = max(ans, NO_THANKS);
			else if (coins == 0 && borrowed)
				ans = max(ans, THANKS);
		}
		return;
	}
	int coin = (1<<x);
	dfs(x+1, price-coin, coins & ~coin, ku, borrowed);
	dfs(x+1, price, coins, ku, borrowed);
	if (ku & coin)
		dfs(x+1, price-coin*2, coins & ~coin, ku & ~coin, true);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, price, ku;
	int coins = (1<<10) - 1;
	cin >> price >> ku;
	dfs(0, price, coins, ku, false);

	if (ans == INPOSSIBLE)
		cout << "Impossible\n";
	else if (ans == NO_THANKS)
		cout << "No thanks\n";
	else if (ans == THANKS)
		cout << "Thanks\n";
	return 0;
}
