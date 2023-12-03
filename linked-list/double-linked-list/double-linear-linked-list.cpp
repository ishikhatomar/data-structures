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
        temp = NULL;
        return;
    }
    head->prev = temp;
    temp->next = head;
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
        temp = NULL;
        return;
    }
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    p = NULL;
    temp = NULL;
}
void insertAtPos(int data, int pos)
{
    if (head == NULL)
    {
        std::cout << "\nList is Empty";
        return;
    }
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
    
   
    while (p->next != NULL)
    {
        
        p = p->next;
        if (k == pos)
        {
            node *temp = getNode();
            temp->data = data;
            temp->prev = p->prev;
            temp->next = p;
            p->prev->next = temp;
            p->prev = temp;
            p = NULL;
           
            temp = NULL;
            return;
        }
        k++;
    }
    if (k == pos && p->next == NULL)
    {
        node *temp = getNode();
        temp->data = data;
        p->next = temp;
        temp->prev = p;
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
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    node* p = head;
    head = head->next;
    head->prev= NULL;
    delete p;
    p=NULL;
}
void deleteAtEnd(){
    if(head ==NULL){
        std::cout<<"\nList is Empty nothing to delete";
        return;
    }
    if(head->next ==NULL){
        delete head;
        head=NULL;
        return; 
    }
    node* after = head;
    
    while(after->next!=NULL){
       
        after=after->next;
    }
    after->prev->next=NULL;
    delete after;
    after=NULL;

}
void deleteAtPos(int pos){
    if(head==NULL){
        std::cout<<"\nList is empty nothig to delete";
        exit(1);
    }
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
    while(after->next!=NULL){
     
      after=after->next;
      if(k==pos){
        after->prev->next = after->next;
        if(after->prev->next!=NULL){
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
void reverseDLL(){
    if(head==NULL ||head->next==NULL){
      return;
    }
    node* p = head;
    node* q=NULL;
    while(p->next!=NULL){   
      p->prev =p->next;    
      p->next =q; 
      q=p;
      p=p->prev;
    } 
     p->next=q;
     p->prev=NULL;
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
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    p = NULL;
}

int main()
{
    // display();
    
    insertAtEnd(33);
    display();
   
    insertAtBegin(22);
    insertAtEnd(44);
    insertAtEnd(55);
    insertAtEnd(66);
    display();
    insertAtPos(77, 5);
    display();
    reverseDLL();
    display();
    deleteAtBegin();
    display();
    deleteAtEnd();
    display();
    deleteAtPos(5);
    display();
    
}