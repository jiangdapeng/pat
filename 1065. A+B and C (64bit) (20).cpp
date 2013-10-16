#include <cstdio>

int main()
{
  long long a,b,c;
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;++i)
  {
      scanf("%lld %lld %lld",&a, &b, &c);
      bool gt = true;
      long long sum = a+b;
      if(a > 0 && b > 0 && sum <=0)
      {
            gt = true;
      }
      else if(a < 0 && b <0 && sum >= 0)
      {
            gt = false;
      }
      else
      {
            gt = sum > c;
      }
      if(gt)
        printf("Case #%d: true\n",i);
      else
        printf("Case #%d: false\n",i);
    }
  return 0;
}
