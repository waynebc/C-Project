#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

static set<int> pnums;

bool isPrime(int n){
	if(pnums.count(n)){
		return true;
	}
	int i=2;
	if(n%i==0)
		return false;
	for(i=3;i<=n/2;i+=2){
		if(n%i==0){
			return false;
		}
	}
	if(i>n/2){
		pnums.insert(n);
		return true;
	}
}


int main(){
	pnums.insert(2);
	int n,p1,p2;
	int psnum;
	scanf("%d",&n);
	while(n){
		psnum=0;
		p1=2;
		p2=n-p1;
		if(isPrime(p2)){
			psnum++;
		}
		for(p1=3;p1<=n/2;p1+=2){
			if(isPrime(p1)){
				p2=n-p1;
				if(isPrime(p2)){
					psnum++;
				}
			}
		}
		printf("%d\n",psnum);
		scanf("%d",&n);
	}
	return 0;
}
