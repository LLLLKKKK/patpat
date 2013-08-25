#include <cstdio>

int main() {
    int k,left=0,right=-1,mleft=-1,mright=-1;
    int nums[10000];
    long sum = 0,msum=-1;
    scanf("%d", &k);
    for (int i=0;i<k;i++) {
        scanf("%d", nums+i);
    }
    for (int i=0;i<k;i++) {
        sum += nums[i];
        if (sum >= 0) {
            right++;
            if (sum > msum) {
                msum = sum;
                mleft = left;
                mright = right;
            }
        }
        else if (sum < 0) {
            left=i+1;
            right=i;
            sum=0;
        }
    }
    if (mleft != -1) {
        printf("%ld %d %d\n",msum,nums[mleft],nums[mright]);
    }
    else {
        printf("0 %d %d\n",nums[0],nums[k-1]);
    }
}
