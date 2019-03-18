#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

struct oper{
  int num;
  char op;
  int type; // 0 for num 1 for op
};

int main() {
  int result = 0;
  stack<oper> ms;
  
  char in[5];
  cin>>in;
  while(1){
    oper a;
    if(in[0]=='+'||in[0]=='-'){
        a.type = 1;
        a.op = in[0];
        ms.push(a);
    }
    else{
        a.type = 0;
        a.num = atoi(in);
        
        while(!(ms.empty())){
            if(ms.top().type==1)    break;
      		int temp = ms.top().num;
      		ms.pop();
      		if(ms.top().op=='+')
      		    a.num = temp + a.num;
      		else
      		    a.num = temp - a.num;
      		ms.pop();
    	}
    	ms.push(a);
    }
    cin>>in;
    if(in[0]=='0')	break;
  }
  cout<<ms.top().num;
}