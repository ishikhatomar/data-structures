#include<iostream>
class List{
    private:
    struct node{
    int data;
    struct  node* next;   
};
node* head=NULL;
public:
node * getNode(int x){
    node* temp = new node();
    if(temp==NULL){
      std::cout<<"No memory available";
     exit(1);
    }
    temp->data = x;
    temp->next=NULL;
    return temp;
}
void push(int x){
    node* temp = getNode(x);
   if(head==NULL)
   {
     head=temp;
     return;
   }
   else{
     temp->next=head;
     head=temp;  
     temp=NULL;
     return;  
   } 
 }
 int pop(){
    if(head==NULL){
        std::cout<<"\n nothing to delete";
        return -1;
    }
    node* p =head;
    head=head->next;
    int y = p->data;
    delete p;
    p=NULL;
    return y;
 }
 void display(){
while(head!=NULL){
   std::cout<<pop()<<" ";
 }
 }
};
 
int main(){
 List l;
 for(int i =0; i<5; i++){
    l.push(i+2);
 }
 l.display();
 
    
   
 
}