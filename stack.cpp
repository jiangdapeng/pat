#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_KEY_VALUE = 100000;
class JdpStack
{
  public:
    JdpStack()
    {
      // init bucket
      for(int i=0;i<MAX_KEY_VALUE +1;++i)
      {
        bucket[i] = 0;
      }
    }
    int pop()
    {
      int tmp = stack.back();
      stack.erase(stack.begin()+stack.size()-1);
      bucket[tmp] --;
      return tmp;// may crash!
    }
    void push(int value)
    {
      stack.push_back(value);
      bucket[value]+=1; // using bucket sort
    }
    int peekMedia()
    {
      // bucket sort
      int media = 0;
      int target = (size()-1)/2 + 1;//the media
      int count = 0;
      for(int i=0;i<MAX_KEY_VALUE+1;++i)
      {
        count += bucket[i];
        if(count >= target)
        {
          media = i;
          break;
        }
      }
      return media;
    }
    int size()
    {
      return stack.size();
    }
    bool empty()
    {
      return stack.empty();
    }
  private:
    vector<int> stack;
    int bucket[MAX_KEY_VALUE+1];
};

int main()
{
  int n;
  string cmd;
  int op;
  cin >> n;
  JdpStack stack;
  for(int i=0;i<n;++i)
  {
    cin >> cmd;
    if(cmd == "Push")
    {
      cin >> op;
      stack.push(op);
    }
    else if(cmd == "Pop")
    {
      if(!stack.empty())
      {
        op = stack.pop();
        cout << op << endl;
      }
      else
      {
        cout << "Invalid" << endl;
      }
    }
    else if(cmd == "PeekMedian")
    {
      if(!stack.empty())
      {
        op = stack.peekMedia();
        cout << op << endl;
      }
      else
      {
        cout << "Invalid" << endl;
      }
    }
  }
  return 0;
}
