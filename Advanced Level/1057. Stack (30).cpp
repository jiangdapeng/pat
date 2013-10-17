/*
 * 这道题重点就是解决超时问题
 * 其中peekMedia操作比较费时
 * 因为存储的时候并没有排序，而数值的大小有上限（100000)
 * 因此考虑用桶排序的方式
 * 但是桶的个数还是偏多，每次peekMedia都进行一次遍历，复杂度太高
 * 细想，发现可以使用两级桶，先找出中值在哪个大桶，然后再计算在大桶中的具体小桶
 */
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_VALUE = 100000;
const int MAX_N = 100000;
const int JMP_SIZE = 100;
const int JMP_BUCKET = MAX_VALUE/JMP_SIZE;

class JdpStack
{
public:
  JdpStack()
  {
    top = -1;
    for(int i=0;i<MAX_VALUE; ++i)
      bucket[i] = 0;
    for(int i=0;i<JMP_BUCKET; ++i)
      jb[i] = 0;
  }
  ~JdpStack(){}
  void pop()
  {
    if(empty())
      printf("Invalid\n");
    else
    {
      int v = e[top--];
      bucket[v]--;
      jb[v/JMP_SIZE]--;
      printf("%d\n",v);
    }
  }

  void push(int v)
  {
    if(full())
    {
      printf("Invalid\n");
    }
    else
    {
      e[++top] = v;
      bucket[v]++;
      jb[v/JMP_SIZE]++;
    }
  }

  bool empty()
  {
    return top == -1;
  }

  bool full()
  {
    return top == MAX_N;
  }

  void peekMedia()
  {
    if(empty())
      printf("Invalid\n");
    else
    {
      int n = top+1;
      int media = n%2==0?n/2:(n+1)/2;
      int count = 0;
      int i=0;
      // 找出中值在哪个大桶
      while(count < media)
      {
        count += jb[i++];
      }
      --i;
      // 找具体小桶
      count -= jb[i];
      int k = JMP_SIZE * i;
      while(count < media)
      {
        count += bucket[k++];
      }
      printf("%d\n", k - 1);
    }
  }
private:
  int top;
  int e[100000];
  int bucket[100000];
  int jb[JMP_BUCKET];
};

int main()
{
  int n;
  scanf("%d",&n);
  JdpStack s;
  char cmd[20];
  int v;
  for(int i=0;i<n;++i)
  {
    scanf("%s", cmd);
    if(strcmp(cmd,"Pop") == 0)
    {
      s.pop();
    }
    else if(strcmp(cmd,"Push") == 0)
    {
      scanf("%d", &v);
      s.push(v);
    }
    else
    {
      s.peekMedia();
    }
  }
  return 0;
}
