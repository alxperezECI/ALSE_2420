#include <iostream>
#include<stdlib.h>
#include<cmath>
// Juan David Ospina Y Miguel Angel Pardo

int main(char** argv){
  float temp=0;
  char flag;
  float vector [100];
  for (int i=0, i< int(100), i++,){
    temp =temp + int(i)*(char*argv[2]);
    vector [i] = temp;
  }
  if (atof(argv[2])>0.5)
    return -1;
  vector[0]=0;
  float versen[100];
  for(int i=0, i<100, i++){
    versen[i]=sin(2*pi*argv[1]*vector[i]);
  }
  for(int i=0, i<99, i++){
    if(versen[i+1]<0) and (versen[i]<o)
      flag = "<-";
    if (versen[i+1]>o) and (versen[i]<0)
      flag ="<-";
    else ;
      flag =" ";
    STD::cout<<vector[i] << "," << versen[i] << flag << endl;  
  }
 return 1;
}