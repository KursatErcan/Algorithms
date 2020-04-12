#include <stdio.h>
#include <stdlib.h>

int main()
{
    int px[3]={80,175,270};
    int py[3]={150,50,150};
    int n=2;
    printf("%d",px[1]);
   // int px[0]=80,py[0]=150,px[1]=175,py[1]=50,px[2]=270,py[2]=150;
    double t=0,bin;
    double s1,s2=1,s3=1;
    int i,j,k,l,m,o;
    double Xsonuc=0,Ysonuc=0,us=1,us2=1;
    s1=1;
    for(j=1;j<=n;j++){
            s1=s1*j;
        }
        // printf("s1: %d\n",s1);
    while(t<1){
        for(i=0;i<n;i++){
            for(k=1;k<=n-i;k++){
                s2=s2*k;
            }
            //printf("s2: %d\n",s2);

            for(l=1;l<=i;l++){
                s3=s3*l;
            }
             //printf("s3: %d\n",s3);
            bin=s1/(s2*s3);
            //printf("bin: %d\n",bin);
            for(m=0;m<n-i;m++){
            	us=us*(1-t);
			}
			for(o=0;o<i;o++){
            	us2=us2*t;
			}
			Xsonuc+=bin*us*us2*px[i];
            Ysonuc+=bin*us*us2*py[i];
        }
        printf("t:%f icin Xsonuc: %f\n",t,Xsonuc);
        printf("t:%f icin Ysonuc: %f\n",t,Ysonuc);
        t=t+0.1;
        Xsonuc=0,Ysonuc=0;
        s2=1;
        s3=1;
        us=1;
        us2=1;
    }
    return 0;
}
