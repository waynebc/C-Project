/*
USER_ID: test#jianyun
PROBLEM: 1461
SUBMISSION_TIME: 2017-04-14 20:12:27
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<climits>
using namespace std;
 
static const int MOD=1000000009;
 
void getPrimes(int n,map<int,int>& pmap){
    int i=2;
    int n2=n;
    int j=sqrt(n);
    while(i<=j+1){
        while(n2%i==0){
            pmap[i]++;
            n2/=i;
            if(n2==1)break;
        }
        if(n2==1)break;
        i++;
    }
    if(n2>1)pmap[n2]=1;
}
 
/*
 * get the big number of power by modulo
 */
int getPow(long long X,long long Y,int Z){
    long long multi=X;
    long long numy=Y;
    long long numx=1;
    long long tres=1;
    multi%=Z;
    if(multi>1){
        while(numy>1){
            if(multi==1){
                break;
            }
            long long ty=numy;
            X=1;
            numx=0;
            while(X<Z && ty>0){
                X*=multi;
                numx++;
                ty--;
            }
            long long tmp=numy%numx;
            while(tmp){
                tres=(tres%Z)*multi;
                tmp--;
            }
 
            multi=X%Z;
            numy=numy/numx;
            tres=tres%Z;
        }
    }
    int res=(multi*tres)%Z;
    return res;
}
 
int main(){
    long long k;  //number of integers in the sets
    int d;  //GCD
    int m;  //LCM
    map<int,int> dmap;
    map<int,int> mmap;
    map<int,long long> mdmap;
    long long r;  //result
    while(scanf("%lld",&k)!=EOF){
        scanf("%d",&d);
        scanf("%d",&m);
        getPrimes(d,dmap);
        getPrimes(m,mmap);
        r=1;
        map<int,int>::iterator ditr;
        for(ditr=dmap.begin();ditr!=dmap.end();ditr++){
            if(mmap.find(ditr->first)==mmap.end()){
                break;
            }else if(dmap[ditr->first]>mmap[ditr->first]){
                break;
            }
        }
        if(ditr!=dmap.end()){
            printf("0\n");
            dmap.clear();
            mmap.clear();
            mdmap.clear();
            continue;
        }
 
 
        map<int,int>::iterator mitr;
        for(mitr=mmap.begin();mitr!=mmap.end();mitr++){
 
            int p=mitr->first;  //the prime number
            int dp=(dmap.find(p)==dmap.end())?0:dmap[p];
            int mp=mmap[p];
            int mdp=mp-dp;
            if(!mdp)continue;
            mdmap[mdp]++;
        }
        map<int,long long>::iterator mditr;
        for(mditr=mdmap.begin();mditr!=mdmap.end();mditr++){
            int mdp=mditr->first;
            long long mdk=mditr->second;
            long long tmp[3];
            for(int i=0;i<3;i++){
                tmp[i]=getPow(mdp-1+i,k,MOD);
            }
            int rtmp=(tmp[2]+(MOD-(2*tmp[1])%MOD)+tmp[0])%MOD;
            rtmp=getPow(rtmp,mdk,MOD);
 
            r=(r%MOD)*rtmp;
        }
        printf("%lld\n",r%MOD);
        dmap.clear();
        mmap.clear();
        mdmap.clear();
    }
    return 0;
}
