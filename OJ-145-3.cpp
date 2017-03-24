    #include<stdio.h>    
    #include<string.h>    
    #include<math.h>    
    #include<stdlib.h>    
    #include<iostream>  
    #include<algorithm>  
    #include<queue>  
    #include<vector>  
    using namespace std;  
    #define ll long long  
    #define inf 0x3f3f3f3f  
    #define N 1010  
      
    int ffx,ggx;  
    int n,ans;  
    int bit[20];  
      
    void dfs(int pos,int fx,int gx,int x,int f)  
    {  
        if(ggx!=-1 && gx+(pos+1)*9<=ggx) return ;//一个剪枝，不然就T死了。。  
        if(pos==-1)  
        {  
            if(x<n && fx<=ffx)  
            {  
                if(ggx==-1)  
                {  
                    ans=x,ggx=gx;  
                }  
                else if(gx>ggx){  
                    ans=x;  
                    ggx=gx;  
                }  
            }  
            return ;  
        }  
        int end=f?bit[pos]:9;  
        int i;  
        for(i=end;i>=0;i--)  
            dfs(pos-1,fx^i,gx+i,x*10+i,f&&(i==end));  
    }  
    void calc(int x)  
    {  
        int i,j,cnt=0;  
        while(x){  
            bit[cnt++]=x%10;  
            x/=10;  
        }  
        ffx=bit[0];  
        for(i=1;i<cnt;i++)  
            ffx^=bit[i];  
        for(i=bit[cnt-1];i>=0;i--){  
            dfs(cnt-2,i,i,i,i==bit[cnt-1]);  
        }  
    }  
    int main()  
    {  
        int t;  
        scanf("%d",&t);  
        while(t--)  
        {  
            int i,j,k;  
            scanf("%d",&n);  
            ans=0;  
            ggx=-1;  
            calc(n);  
            printf("%d\n",ans);  
        }  
    }  
