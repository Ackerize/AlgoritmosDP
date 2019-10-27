//1213 - Sum of Different Primes
#include<cstdio>
#include<vector>
#include<string.h>
#define N 1120
#define K 14

using namespace std;

vector<int> P;
int DP[1121][15];

void make(){
	P.clear();
	P.push_back(2);
	P.push_back(3);
	int i, j, gap = 2;
	for (i = 5; i <= N; i += gap, gap = 6 - gap){
		for (j = 0; j < P.size(); j++)
			if (i % P[j] == 0)
				break;
		if (j >= P.size())
			P.push_back(i);
	}
}
void solve(){
	make();
	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;

	// prime can't add twice

	for (int k = 0; k < P.size(); k++){
		for (int i = N; i >= 1; i--){
			if (i - P[k] < 0)	
                break;
			for (int j = K; j >= 1; j--){
				DP[i][j] += DP[i - P[k]][j - 1];
			}
		}
	}
}
int main(){
	solve();
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		printf("%d\n", DP[n][m]);
	}
	return 0;
}