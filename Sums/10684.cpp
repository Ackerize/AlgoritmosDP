//10684 The jackpot
#include<stdio.h>

int main(){
	int n;
	while(cin >> n){
		if(n==0)
			break;		
		int i,max;
		int m[10000];
		int DP[10000]={0};
		for(i=0;i<n;i++)
			cin >> m[i];
		max=0;
		if(m[0]>0){
			DP[0]=m[0];
			max=DP[0];
		}
		else
			DP[0]=0;
		for(i=1;i<n;i++){
			DP[i]=DP[i-1]+m[i];
			if(DP[i]<0)
				DP[i]=0;
			if(max<DP[i])
				max=DP[i];
		}
		if(max>0)
			cout << "The maximum winning streak is " << max << "." << endl;
		else
			cout << "Losing streak." << endl;
	}
	return 0;
}