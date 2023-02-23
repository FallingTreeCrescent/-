#include <iostream>
#include <cstring>
using namespace std;
int f[410][410];
int input[1000];
int sum[210];
int n;
int main(){
    scanf("%d",&n);
    if(n==1){
        scanf("%d",&n);
        printf("0 0");
        return 0;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&input[i]);
    for(int j=n+1;j<=2*n-1;j++)
        input[j]=input[j-n];
    for(int i=1;i<=2*n-1;i++)
        sum[i]=sum[i-1]+input[i];
    for(int i=2*n-1;i>=1;i--)
    {
        f[i][i]=input[i];
        for(int j=i+1;j<=i+n-1&&j<=2*n-1;j++)
        {
            if(j==i+1)
            {
                f[i][j] =sum[j]-sum[i-1];
            }
            else
            {
                int Min=INT_MAX;
                for(int k = i; k < j; k++)
                {
                    int temp_Min=sum[j]-sum[i-1];
                    if(i!=k) temp_Min+=f[i][k];
                    if((k+1)!=j) temp_Min+=f[k+1][j];
                    Min = min(Min,temp_Min);
                }
                f[i][j] = Min;
            }
        }
    }
    int Min=INT_MAX;
    for(int i=1;i<=n;i++){
        Min=min(Min, f[i][i+n-1]);
    }
    printf("%d ",Min);

    for(int i=2*n-1;i>=0;i--)
    {
        f[i][i] = input[i];
        for (int j=i+1;j<=2*n-2;j++)
        {
            if(j==i+1)
            {
                f[i][j] =sum[j]-sum[i-1];
            }
            else
            {
                int Max=INT_MIN;
                for(int k = i; k < j; k++)
                {
                    int temp_Max=sum[j]-sum[i-1];
                    if(i!=k) temp_Max+=f[i][k];
                    if((k+1)!=j) temp_Max+=f[k+1][j];
                    Max = max(Max, temp_Max);
                }
                f[i][j] = Max;
            }
        }
    }
    int Max=INT_MIN;
    for(int i=1;i<=n;i++){
        Max=max(Max, f[i][i+n-1]);
    }
    printf("%d",Max);
    return 0;
}

