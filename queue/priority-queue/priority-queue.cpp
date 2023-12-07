// Ascending priority Queue
#include <iostream>
#define MAX 7
class PriorityQueue
{
private:
    int front;
    int rear;
    int arr[MAX];

public:
    PriorityQueue() : front(-1), rear(-1) {}
    void enqueue(int x)
    {
        if (rear == MAX - 1)
        {
            std::cout << "\nOverflow";
            return;
        }
        if (rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }
    int dequeue()
    {
        int min = 0;
        for (int i = 1; i <= rear; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        int x = arr[min];
        arr[min] = arr[rear];
        rear--;
        return x;
    }
    void display(){
        std::cout<<"\n";
        std::cout<<dequeue()<<" ";
    }
};
int main()
{
    PriorityQueue q;
    q.enqueue(35);
    q.enqueue(18);
    q.enqueue(70);
    q.enqueue(8);
    q.enqueue(96);
    q.enqueue(13);
    q.enqueue(46);
    q.display();
}