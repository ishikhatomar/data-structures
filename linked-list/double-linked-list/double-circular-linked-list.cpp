#include <iostream>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
node *head = NULL;
node *getNode()
{
    node *temp = new node();
    if (temp == NULL)
    {
        std::cout << "Memory full";
        exit(1);
    }
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
void insertAtBegin(int data)
{
    node *temp = getNode();
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        temp->prev = head; 
        temp->next =head;  
        temp = NULL;
        return;
    }
    temp->next = head;
    temp->prev= head->prev;
    head->prev = temp;
    temp->prev->next = temp;
    head = temp;
    temp = NULL;
}
void insertAtEnd(int data)
{
    node *temp = getNode();
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        temp->prev = head; 
        temp->next =head;  
        temp = NULL;
        return;
    }
    node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    temp->prev=p;
    temp->next= p->next;
    p->next->prev = temp;
    p->next = temp;
    p = NULL;
    temp = NULL;
}
void insertAtPos(int data, int pos)
{
    // if (head == NULL)
    // {
    //     std::cout << "\nList is Empty";
    //     return;
    // }
    if (pos < 0)
    {
        std::cout << "\nInvalid position";
        return;
    }
    if (pos == 0)
    {
        insertAtBegin(data);
        return;
    }
    int k = 1;
    node *p = head;
    
   
    while (p->next != head)
    {   
        p = p->next;
        if (k == pos)
        {
            node *temp = getNode();
            temp->data = data;
            temp->next = p;
            temp->prev = p->prev;
            p->prev->next = temp;
            p->prev = temp;
            p = NULL;
            temp = NULL;
            return;
        }
        k++;
    }
    if (k == pos && p->next == head)
    {
        node *temp = getNode();
        temp->data = data;
        temp->prev = p;
        temp->next=p->next;
        p->next->prev = temp;
        p->next = temp;
        p = NULL;
        temp = NULL;
        return;
    }

    std::cout << "\nInvalid Position";
}
void deleteAtBegin()
{
    if (head == NULL)
    {
        std::cout << "Nothing to delete";
        exit(1);
    }
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }
    node* p = head;
    p->prev->next=head->next;
    head->next->prev = p->prev;
    head = head->next;
    delete p;
    p=NULL;
}
void deleteAtEnd(){
    if(head ==NULL){
        std::cout<<"\nList is Empty nothing to delete";
        return;
    }
    if(head->next ==head){
        delete head;
        head=NULL;
        return; 
    }
    node* after = head; 
    while(after->next!=head){  
        after=after->next;
    }
    after->prev->next = after->next;
    after->next->prev = after->prev;
    delete after;
    after=NULL;
}
void deleteAtPos(int pos){
    if(pos<0){
        std::cout<<"\nInvalid position";
        return;
    }
    if(pos==0){
        deleteAtBegin();
        return;
    } 
    node* after = head; 
    int k=1;
    while(after->next!=head){
     
      after=after->next;
      if(k==pos){
        after->prev->next = after->next;
        if(after->prev->next!=head){
             after->next->prev = after->prev;
        }
        delete after;
        after=NULL;
        
        return;
      }
      k++;
    }
    std::cout<<"\nInvalid position";
}
void reverseCircularDLL(){
    if(head==NULL ||head->next==head){
      return;
    }
    node* p = head;
    node* q=NULL;
    while(p->next!=head){   
      p->prev =p->next;    
      p->next =q; 
      q=p;
      p=p->prev;
    } 
    
    p->prev =p->next;  
    p->next->next=p;
    p->next = q;   
    head=p;
    p=NULL;
    q=NULL;
}
void display()
{
    if (head == NULL)
    {
        std::cout << "\nList is MT";
        return;
    }
    node *p = head;
    std::cout << "\n";
    do{
        std::cout << p->data << " ";
        p = p->next;
    }
    while (p!= head);
    
    p = NULL;
}

int main()
{
   insertAtBegin(10);
   insertAtBegin(12);
   insertAtPos(40,0);
   insertAtEnd(12);
   display();
   reverseCircularDLL();
   display();
   deleteAtPos(3);
   display();
   deleteAtBegin();
   display();
   deleteAtEnd();
   display();
    
}