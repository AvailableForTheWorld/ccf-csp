#include<iostream>
using namespace std;
int main(){	
    int n,i,j,h;	
    int res,x;	
    int a[1010];
    scanf("%d", &n);
    res=0;		
    for(i=1;i<=n;i++){		
        scanf("%d",&a[i]);		
        res=max(res,a[i]);	    
    }	    
    for(i=1;i<=n;i++){	    	
        h=a[i];		
        for(j=i+1;j<=n;j++)		{			
            h=min(h,a[j]);			
            x=(j-i+1)*h;			
            res=max(res,x);	    
        }	    
        while(i<n&&a[i+1]<a[i])		
            i++; 		
    }	    
    printf("%d\n",res);
    return 0;
}
