#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long


ull dp[10100];
ull coins[30];

int main(){
	for(ull i = 1 ; i < 22 ; i++){
		coins[i] = (i*i*i);
	}
	dp[0] = 1;
	for(ull i = 1; i < 22; i++){
		for(ull j = coins[i] ; j < 10100; j++){
            if(dp[j - coins[i]]){
                dp[j] += dp[j - coins[i]];
            }
		}
	}

	ull n;

	while(cin >> n){
        cout<< dp[n] << endl;
	}
	return 0;
}