#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
static const int MODULE=1000000009;
static const int coins[17]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
static int sumArr[2001][17]={0};
int getSum(int n,int pos){
	if(sumArr[n][pos]){
		return sumArr[n][pos];
	}
	if(pos==0 || n==0){
		sumArr[n][pos]=1;
		return 1;
	}	
	if(pos==1){
		int chu=n/4;
		sumArr[n][pos]=chu+1;
		return chu+1;
	}

	int sum=0;
	for(int i=pos;i>0;i--){
		int chu=n/coins[i];
		int cha=n;
		while(chu--){
			cha-=coins[i];
			sumArr[cha][i-1]=getSum(cha,i-1);
			sum+=sumArr[cha][i-1];
			if(sum>MODULE){
				sum%=MODULE;
			}
		}
	}
	return sum+1;
}

int main(){
	int T;
	int n;
	int pos;
	int sum;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(pos=16;pos>=0;pos--){
			if(coins[pos]<=n){
				break;
			}
		}
		sum=0;
		sumArr[n][pos]=getSum(n,pos);
		sum+=sumArr[n][pos];
		printf("%d\n",sum);
	}
	return 0;
}

