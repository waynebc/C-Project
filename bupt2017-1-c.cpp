#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
static const int USER_NUM=1000;
int main(){

	 int T;  //the number of test case;
 	 scanf("%d",&T);
	 while(T--){
         vector<int> relVec[USER_NUM];  //each user's friends
		 bool relArr[USER_NUM][USER_NUM]={0};  //relationship array
		 int numNewFri[USER_NUM]={0};  //the number of new friends of each user

		 int n;  //the number of users;
		 int m;  //the number of relationships
		 scanf("%d",&n);
		 scanf("%d",&m);
		 int u,v;  //user u and v are friends
		 while(m--){
			 scanf("%d",&u);
			 scanf("%d",&v);
			 relArr[u-1][v-1]=relArr[v-1][u-1]=1;
             
             relVec[u-1].push_back(v-1);
             relVec[v-1].push_back(u-1);
		 }
		 for(int i=0;i<n;i++){
			 for(int j=i+1;j<n;j++){
				 if(!relArr[i][j]){
					 for(int k=0;k<relVec[i].size();k++){
                         int g=relVec[i][k];
						 if(relArr[j][g]){
							 numNewFri[i]++;
							 numNewFri[j]++;
							 break;
						 }
					 }
				 }
			 }
		 }

		 for(int i=0;i<n;i++){
			 printf("%d\n",numNewFri[i]);
		 }
	 }
	 return 0;
}
