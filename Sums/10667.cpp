#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 105;
int arr[MAXN][MAXN];
int t, n, b;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                arr[i][j] = 1;
        cin >> b;
        while (b--) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            for (int i = r1; i <= r2; i++) 
                for (int j = c1; j <= c2; j++) 
                    arr[i][j] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) 
                    arr[i][j] += arr[i-1][j];
                if (j > 0) 
                    arr[i][j] += arr[i][j-1];
                if (i > 0 && j > 0) 
                    arr[i][j] -= arr[i-1][j-1];   
            }   
        }  
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        int sum = arr[k][l];
                        if (i > 0) 
                            sum -= arr[i-1][l];
                        if (j > 0) 
                            sum -= arr[k][j-1];
                        if (i > 0 and j > 0) 
                            sum += arr[i-1][j-1]; 
                        if ((k - i + 1) * (l - j + 1) == sum) {
                            maxi = max(maxi, sum);   
                        }
                    }    
                }   
            }   
        } 
        cout << maxi << endl;
    }
	return 0;
}