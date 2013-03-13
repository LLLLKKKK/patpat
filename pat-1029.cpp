#include <stdio.h>
 int num1[1000002];
 int num2[1000002];
 int num_fin[2000002];
 int main()
 {
     int len1,len2;
     scanf("%d",&len1);
     int i;
     for(i=0;i<len1;i++){
         scanf("%d",&num1[i]);
     }
     scanf("%d",&len2);
     for(i=0;i<len2;i++){
         scanf("%d",&num2[i]);
     }
     int j=0,k=0;
     i=0;
     while(i<len1&&j<len2){
         if(num1[i]<num2[j]){
             num_fin[k++]=num1[i++];
         }else if(num2[j]<num1[i]){
             num_fin[k++]=num2[j++];
         }else{
             num_fin[k++]=num1[i++];
             num_fin[k++]=num2[j++];
         }
     }
     if(i<len1&&j>=len2){
         for(;i<len1;i++){
             num_fin[k++]=num1[i];
         }
     }else if(i>=len1&&j<len2){
         for(;j<len2;j++){
             num_fin[k++]=num2[j];
         }
     }
 
     if((len1+len2)%2){
         printf("%d\n",num_fin[(len1+len2)>>1]);
     }else{
         printf("%d\n",num_fin[((len1+len2)>>1)-1]);
     }
 }
