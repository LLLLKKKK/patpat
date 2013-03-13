#include<stdio.h>
 #include<ctype.h>

 #define LLL_MAX 9223372036854775807LL
 long long convert(char *n, long long radix, long long in1)
 {
  int i = 0;
  long long r = 0;
  long long  tmp = 0;

  while(n[i] != '\0')
  {
   if (isdigit (n[i]) != 0)
    tmp = n[i] - '0';
   else 
    tmp = n[i] - 'a' + 10;
   
   if ( ( LLL_MAX - tmp)/radix < r)
    return in1 + 1;
   r = r * radix + tmp;
   i++;
  }

  return r;
 }
 long long test(char* n1, char *n2, long long radix)
 {
  long long in1 = convert (n1, radix, LLL_MAX);
  long long left, right, mid;
  long long in2;
  int i = 0;
  int tmp;

  left = 1;
  while (n2[i] != '\0')
  {
   if (isdigit (n2[i]))
    tmp = n2[i] - '0';
   else
    tmp = n2[i] - 'a' +10;
   if (left < tmp)
    left = tmp;
   i++;
  }
  left++;
  right = LLL_MAX;

  while(left < right)
  {

   mid = left + (right - left)/2;
   in2 = convert(n2, mid, in1);

   if (in1 > in2)
    left = mid + 1;
   else if (in2 < in1)
    right = mid - 1;
   else
    right = mid;
  }

  in2 = convert(n2, left, LLL_MAX);
  if (in1 != in2)
   left = -1;
   
  return left;
 }
 int main()
 {
  int flag;
  long long radix;
  char n1[11], n2[11];
  long long r;

  scanf("%s%s%d%lld",n1,n2,&flag,&radix);
  
  if (flag == 1)
   r = test(n1, n2, radix);
  else
   r = test(n2, n1, radix);
  
  if(r == -1)
   printf("Impossible\n");
  else
   printf("%lld\n", r);

  return 0;
 }
