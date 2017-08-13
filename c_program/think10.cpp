#include <iostream>
using namespace std;
struct run_union
{
  double x;
  double y;
  double z;

};

int main()
{
  run_union me;
  double avg;
  cout<<"please input your first cj:";
  cin>>me.x;
  cout<<"please input your second cj:";
  cin>>me.y; 
  cout<<"please input your third cj:";
  cin>>me.z;
  
  avg=(me.x+me.y+me.z)/3;
cout<<"avg_cj is:"<<avg<<endl;
 
return 0;

}
