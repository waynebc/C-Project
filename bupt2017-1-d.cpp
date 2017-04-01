#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
 
int main(){
    int T;  //the number of test cases.
    int N;  //the number of dishes
    int A;  //the flavor of each sushi
    map<int,int> flaLstPos;  //the last position of flavor Ai
    int* flaArr;  //the flavor arr of all the dishes
     
    int maxNum=0;  //the max number of sushi she can have
    int subBeg=0;  //the subNum's range mark
    int curPos=0;  //the curPos of flaArr, to get maxNum
 
    scanf("%d", &T);
    while(T--){
        scanf("%d",&N);
        flaArr=new int[2*N];
        for(int i=0;i<N;i++){
            scanf("%d",&A);
            flaArr[i]=flaArr[i+N]=A;
        }
        maxNum=subBeg=0;
        for(curPos=0;curPos<=subBeg+N;curPos++){
            if(flaLstPos.find(flaArr[curPos])!=flaLstPos.end()){
                int lstPos=flaLstPos[flaArr[curPos]];
                if(lstPos>=subBeg){
                    int curMaxNum=curPos-subBeg;
                    if(maxNum<curMaxNum){
                        maxNum=curMaxNum;
                    }
                    subBeg=lstPos+1;
                }
            }
            if(subBeg>=N)break;
            flaLstPos[flaArr[curPos]]=curPos;
        }
        printf("%d\n",maxNum);
        delete [] flaArr;
        flaLstPos.clear();
    }
    return 0;
}
