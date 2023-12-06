#include<iostream>
#include<vector>
class Stack{
 private:
 int top;
 int arr[30];
 public:
 Stack():top(-1){}
 void push(int x){
    arr[++top]=x;
 }
 int pop(){
    int y=arr[top--];
    top;
    return y;
 }
 int empty(){ 
        return (top==-1);
 }
 bool isFull(){
    if(top==29){
        std::cout<<"Overflow ";
        return true;
    }
 }
 int topElement(){
    return arr[top];
 }
};

int main(){
 Stack s;
 for(int i =0; i<5; i++){
    s.push(i+2);
 }
 while(!s.empty()){
    std::cout<<s.topElement()<<" ";
    s.pop();
 }

 
}