#include<iostream>
#include<cstdio>
using namespace std;


//各位异或
char f(char xc[],int len){
	char r=0;
	for(int i=0;i<len;i++){
		r^=xc[i];
	}
	return r;
}
//各位相加
char g(char xc[],int len){
	char r=0;
	for(int i=0;i<len;i++){
		r+=xc[i];
	}
	return r;
}
//将整数按位存储，并记录位数长度xcp
char* getXC(int xtmp,int& xcp){
	char* xc=new char[20];
	while(xtmp){
		//位数存储由低位到高位
		xc[xcp++]=xtmp%10;
		xtmp/=10;
	}
	//最高位前加0，使数实际为xcp+1位，便于之后递归求nass number
	xc[xcp]=0;
	return xc;
}
//将位数组s的值赋给r
void cpy(char* r,char* s,int len){
	for(int i=0;i<len;i++){
		r[i]=s[i];
	}
}
/*
 * 获得xc的nass number，
 * 位数len+1，第一次递归的首位为人为加0
 */
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

		//递归调用，求低len位数的nass number：res2，第len位不变的情况
		char* res2=getNass(xc,len-1,fxc,fpre^xc[len-1]);

		//如果第len位为0，则直接返回res2
		if(xc[len-1]==0){
			cpy(R,res2,len);
			delete[] res2;
			return R;
		}

		/*
		 * 求低len位的nass number：res1，第len位比原来小的情况
		 */
		char* res1=new char[20];
		//nass number特点猜测：中间位数为9**9，测试通过
		for(int i=len-2;i>0;i--){
			//第len-2到1位为9
			res1[i]=9;
		}

		//中间变量最大和
		char sum=0;

		/*
		 * 低len位的第len位 i 从减一依次变小，结合第0位 f 从9减到0，
		 * 此两位和其他所有位异或f^i^fpre^(9?)<=fxc条件满足时，
		 * 求和 sum=i+f 最大的 i 和 f 是多少，
		 * 从而求出res1[len-1]=i;res1[0]=f;
		 */
		for(char i=xc[len-1]-1;i>=0;i--){
			//减枝，如果保证和最大，跳出循环
			if((i+9)<sum){
				break;
			}
			//第0位 f 从9减到0
			char f=9;
			for(;f>=0;f--){
				char ftmp=f^i^fpre;
				//数的奇偶性决定是否再异或一个 9
				ftmp=len%2?(ftmp^('9'-'0')):ftmp;
				//此两位和其他所有位异或f^i^fpre^(9?)<=fxc条件满足时，跳出最低位循环
				if(ftmp<=fxc){
					break;
				}
			}
			//保证和最大
			if(i+f>sum){
				sum=i+f;
				res1[len-1]=i;
				res1[0]=f;
			}
		}
		
		//比较res2和res1的各位和来得到nass number的低len位
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

//将按位存储的nass number转为整数
int charToNass(char* res,int len){
	int nass=0;
	for(int i=len-1;i>=0;i--){
		nass=nass*10+res[i];
	}
	return nass;
}

int main(){
	int T=0;  //the number of test cases
	int x=0;  //the input integer
  	char* xc;  //the input integer's char array of bit
	int xclen=0;  //the length of xc
	char* res;  //the nass number's char array of bit
	int nass=0;  //the nass number integer
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
