#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, c = 0, j;
	cin>>n;
	__int128 i = 1, l = 1;
	l <<= n;
	i <<= n-1;

	while(i<l) {
		for(j=n-2;j>=0;j--) {
			if (((i>>j) & 3) == 3) {
				break;
			}
		}
		if (j==-1) {
			i++;
			c++;
		} else {
			i += (1ULL<<j);
		}
	}
	cout<<c<<"\n";
	return 0;
}
