#include<iostream>
#include<cstdio>
using namespace std;



char f(char xc[],int len){
	char r=0;
	for(int i=0;i<len;i++){
		r^=xc[i];
	}
	return r;
}
char g(char xc[],int len){
	char r=0;
	for(int i=0;i<len;i++){
		r+=xc[i];
	}
	return r;
}
char* getXC(int xtmp,int& xcp){
	char* xc=new char[20];
	while(xtmp){
		xc[xcp++]=xtmp%10;
		xtmp/=10;
	}
	xc[xcp]=0;
	return xc;
}
void cpy(char* r,char* s,int len){
	for(int i=0;i<len;i++){
		r[i]=s[i];
	}
}

char* getNass(char* xc,int len,char fxc,char fpre){
	char* R=new char[20];
	R[len]=xc[len];
	if(len==0){
		return R;
	}
	if(len==1){
		for(char i=xc[0]-1;i>=0;i--){
			if(fxc >= (i^fpre)){
				R[0]=i;
				return R;
			}
		}
		R[1]=R[0]=0;
		return R;
	}else{
		char* res2=getNass(xc,len-1,fxc,fpre^xc[len-1]);
		if(xc[len-1]==0){
			cpy(R,res2,len);
			delete[] res2;
			return R;
		}

		char* res1=new char[20];
		for(int i=len-2;i>0;i--){
			res1[i]=9;
		}
		char sum=0;
		for(char i=xc[len-1]-1;i>=0;i--){
			if((i+9)<sum){
				break;
			}
			char f=9;
			for(;f>=0;f--){
				char ftmp=f^i^fpre;
				ftmp=len%2?(ftmp^('9'-'0')):ftmp;
				if(ftmp<=fxc){
					break;
				}
			}
			if(i+f>sum){
				sum=i+f;
				res1[len-1]=i;
				res1[0]=f;
			}
		}
		
		if(g(res2,len)>=g(res1,len)){
			cpy(R,res2,len);
		}else{
			cpy(R,res1,len);
		}
		delete[] res1;
		delete[] res2;
		return R;
	}
}

int charToNass(char* res,int len){
	int nass=0;
	for(int i=len-1;i>=0;i--){
		nass=nass*10+res[i];
	}
	return nass;
}

int main(){
	int T=0;
	int x=0;
  	char* xc;
	int xclen=0;
	char* res;
	int nass=0;
	scanf("%d",&T);
	for(int m=0;m<T;m++){
		xclen=0;	
		scanf("%d",&x);	
		
		xc=getXC(x,xclen);
		res=getNass(xc,xclen,f(xc,xclen),0);

		nass=charToNass(res,xclen);
		printf("%d\n",nass);	
		delete[] xc;
		delete[] res;
	}
	return 0;
}
