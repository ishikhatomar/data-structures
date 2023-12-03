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
        temp->next = head;
        return;
    }

    node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = head;
    p = NULL;
    temp = NULL;
}
void insertAtBegin(int data)
{
    node *temp = getNode();
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        return;
    }

    node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    temp->next = head;
    p->next = temp;
    head = temp;
    p = NULL;
    temp = NULL;
}

void insertAtpos(int data, int pos)
{

    if (pos < 0)
    {
        std::cout << "\ninvalid position";
        return;
    }
    if (pos == 0 || head == NULL)
    {
        insertAtBegin(data);
        return;
    }

    int k = 1;
    node *p = head;
    do
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
    } while (p != head);

    std::cout << "\ninvalid position";
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
    do
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
    } while (p->next != head);

    std::cout << "\nElement not found";
}
void deleteAtBegin()
{
    if (head == NULL)
    {
        std::cout << "List Empty";
        return;
    }
    node *after = head;
    while (after->next != head)
    {
        after = after->next;
    }
    after->next = head->next;
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
    while (after->next != head)
    {
        prev = after;
        after = after->next;
    }
    prev->next = head;
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
    while (after->next != head)
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
void deleteElement(int nodedata)
{
    if (head == NULL)
    {
        std::cout << "List is mt";
        return;
    }
    if (nodedata == head->data)
    {
        deleteAtBegin();
        return;
    }
    node *after = head;
    node *prev = NULL;
    while (after->next != head)
    {
        prev = after;
        after = after->next;
        if (after->data == nodedata)
        {
            prev->next = after->next;
            delete after;
            after = NULL;
            prev = NULL;
            return;
        }
    }
    std::cout << "\nElement not found";
}
void reverseCircularList()
{
    if (head == NULL)
    {
        std::cout << "List is MPT";
        return;
    }
    node *p = NULL, *q = NULL, *r = head;
    do
    {
        q = r->next;
        r->next = p;
        p = r;
        r = q;
    } while (r != head);
   
    r->next = p;
    head = p;
    r=NULL;
    p=NULL;
    q=NULL;
}
void display()
{
    node *p = head;
    std::cout << "\n";
    if (head == NULL)
    {
        std::cout << "List is empty----";
        return;
    }
    do
    {
        std::cout << p->data << " ";
        p = p->next;
    } while (p != head);

    p = NULL;
}
int main()
{
    insertAtEnd(99);
    insertAtEnd(115);
    insertAtEnd(34);
    insertAtEnd(74);
    display();
    // insertAtpos(13, 4);
    // display();
    // insertAtBeforeNode(115, 67);
    // display();
    // insertAtAfterNode(67, 22);
    // display();
    // deleteAtBegin();
    // display();
    // deleteAtEnd();
    // display();
    // deleteAtPos(4);
    // display();

    // deleteElement(13);
    // display();
    reverseCircularList();
    display();
}