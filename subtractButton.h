#ifndef SUBTRACTBUTTON
#define SUBTRACTBUTTON

#include<FL/Fl_Button.H>
//#include"utils.h"
#include"stack.h"
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

class SubtractButton : public Fl_Button {
 public:
    float from_string( const std::string &s) {
    stringstream ss(s);
    float result;
    ss >> result;    // TODO handle errors
    return result;
  }

  string *myStr;
  Stack *stack;
  //float id;
  
  
 SubtractButton(int X, int Y, int W, int H, char* label, Stack *stack, string* str) : Fl_Button(X,Y,W,H,label){
    this->stack = stack;
    this->myStr = str;
  }
  
  
  static void sbCB(Fl_Widget * w, void*){
    float op1;
    float op2;
    SubtractButton *myButton = (SubtractButton *)w;
    
    float number =  myButton->from_string(*myButton->myStr);
    zmyButton->stack->push(number);    

    op2 = myButton->stack->pop();
    op1 = myButton->stack->pop();
    
    
    myButton->stack->push(op1-op2);    

    cout <<"The number you pushed on the stack was : " << op1-op2 << endl;
  }
};

#endif
