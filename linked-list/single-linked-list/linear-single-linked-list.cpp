#include <iostream>
struct node
{
    int data;
    struct node *next;
};
node *head = NULL;
node *getNode()
{
    node *temp = new node();
    if (temp == NULL)
    {
        std::cout << "space full";
        exit(1);
    }
    temp->next = NULL;
    return temp;
}
void insertAtEnd(int data)
{
    node *temp = getNode();
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        p = NULL;
    }
    temp = NULL;
}
void insertAtBegin(int data)
{
    node *temp = getNode();
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    temp = NULL;
}
void insertAtpos(int data, int pos)
{

    if (pos < 0)
    {
        std::cout << "\ninvalid position";
        return;
    }
    if (pos == 0)
    {
        insertAtBegin(data);
        return;
    }

    int k = 1;
    node *p = head;
    while (p != NULL)
    {
        if (k == pos) // pos=1
        {
            node *temp = getNode();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            p = NULL;
            temp = NULL;
            return;
        }
        k++;
        p = p->next;
    }

    std::cout << "\ninvalid position";
}
void display()
{
    node *p = head;
    std::cout << "\n";
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
}
void insertAtBeforeNode(int nodeData, int data)
{
    if (head == NULL)
    {
        std::cout << "List empty";
        return;
    }
    if (head->data == nodeData)
    {
        insertAtBegin(data);
        return;
    }
    node *after = head;
    node *prev = NULL;
    while (after->next != head)
    {
        prev = after;
        after = after->next;
        if (after->data == nodeData)
        {
            node *temp = getNode();
            temp->data = data;
            temp->next = after;
            prev->next = temp;
            prev = NULL;
            after = NULL;
            temp = NULL;
            return;
        }
    }
    std::cout << "\nElement not found";
}
void insertAtAfterNode(int nodeData, int data)
{
    if (head == NULL)
    {
        std::cout << "list empty";
        return;
    }

    node *p = head;
    if (head->next == NULL)
    {
        insertAtEnd(data);
        return;
    }

    while (p->next != NULL)
    {
        
        if (p->data == nodeData)
        {
            node *temp = new node();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            p = NULL;
            temp = NULL;
            return;
        }
        p = p->next;
    }
    std::cout<<"\nNode not found";
}
void deleteAtBegin()
{
    if (head == NULL)
    {
        std::cout << "List Empty";
        return;
    }
    node *p = head;
    head = head->next;
    delete (p);
    p = NULL;
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        std::cout << "List Empty";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    node *after = head;
    node *prev = NULL;
    while (after->next != NULL)
    {
        prev = after;
        after = after->next;
    }
    prev->next = NULL;
    delete after;
    after = NULL;
    prev = NULL;
}
void deleteAtPos(int pos)
{
    if (pos < 0)
    {
        std::cout << "\ninvalid position";
        return;
    }
    if (pos == 0)
    {
        deleteAtBegin();
        return;
    }
    int k = 1;
    node *after = head;
    node *prev = NULL;
    while (after->next != NULL)
    {

        prev = after;
        after = after->next;
        if (k == pos)
        {
            prev->next = after->next;
            delete after;
            after = NULL;
            prev = NULL;
            return;
        }
        k++;
    }
    std::cout << "\nInvalid position";
}
void reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *p = NULL, *q = NULL, *r = head;
    while (r != NULL)
    {
        q = r->next;
        r->next = p;
        p = r;
        r = q;
    }
    head = p;
    p = NULL;
}
int main()
{

    insertAtEnd(99);
    insertAtEnd(115);
    insertAtEnd(34);
    insertAtEnd(74);
    display();
    insertAtpos(13, 4);
    display();
    insertAtBeforeNode(99, 67);
    display();
    insertAtAfterNode(99, 22);
    display();
    // deleteAtBegin();
    // display();
    // deleteAtEnd();
    // display();
    // deleteAtPos(4);
    // display();
    // reverse();
    // display();
}