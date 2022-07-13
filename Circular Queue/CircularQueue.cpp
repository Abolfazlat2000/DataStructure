#include<bits/stdc++.h>
// this is made for only int type
struct CircularQueue
{
    int *a;//array to store data
    int front;//front index
    int rear;//rear index
    int size;
    CircularQueue(int s){
        size = s;
        a = new int[s];//dynamic memory allocating using 'new' instead of malloc
        front = -1;
        rear = -1;
    }

    bool isFull();
    bool isEmpty();

    void enqueue(int item);
    int dequeue();
    void PrintElements();
};

bool CircularQueue::isEmpty(){
    if(CircularQueue::front == -1){
        return true;
    }
    return false;
}
bool CircularQueue::isFull(){
    if((CircularQueue::front == 0 && CircularQueue::rear == CircularQueue::size-1) || (CircularQueue::rear == CircularQueue::front - 1) ){
         
         return true;
    }

    return false;
}

void CircularQueue::enqueue(int item){
    if(isFull()){
        return;
    }else if (CircularQueue::front == -1){
        // adding first item

        CircularQueue::front = 0;
        CircularQueue::rear = 0;
        CircularQueue::a[rear] = item;

    }else if(CircularQueue::rear == CircularQueue::size - 1 && CircularQueue::front != 0){
        //check if front of queue is empty and there is a free space to locate

        CircularQueue::rear = 0; //reset rear
        CircularQueue::a[CircularQueue::rear] = item;

    }else{
        //usual adding item
        CircularQueue::rear++;
        CircularQueue::a[CircularQueue::rear] = item;
    }
    std::cout<<"item "<< item<<" added to queue"<<std::endl;
}

int CircularQueue::dequeue(){
    if(CircularQueue::isEmpty()){
        return INT8_MIN;
    }
    // remove item from the front
    int item;
    item = CircularQueue::a[CircularQueue::front];
    CircularQueue::a[CircularQueue::front] = INT8_MAX;

    if(CircularQueue::front == CircularQueue::rear){
        //last item in queue
        CircularQueue::front = -1;
        CircularQueue::rear = -1;

    }else if(CircularQueue::front == size - 1){
        //reset front
        CircularQueue::front = 0;

    }else{
        //usual remove
        CircularQueue::front++;
    }

    return item;
}
void CircularQueue::PrintElements(){
    if (CircularQueue::front == -1) { std::cout<<"\nEmpty"; return; }
    
	std::cout<<"\nElements : ";
    if (CircularQueue::front <= CircularQueue::rear)
    {
        for (int i = CircularQueue::front; i <= CircularQueue::rear; i++)
            std::cout<<CircularQueue::a[i]<<", ";
    }
    else
    {
        for (int i = CircularQueue::front; i <= CircularQueue::size - 1; i++)
            std::cout<< CircularQueue::a[i]<<", ";
 
        for (int i = 0; i <= CircularQueue::rear; i++)
            std::cout<< CircularQueue::a[i]<<", ";
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    CircularQueue q(4);
   
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(3);
    
    q.PrintElements();
    
    int item = q.dequeue();
    std::cout<< item << " removed from queue"<< std::endl;

    q.PrintElements();
    
    q.enqueue(6);
    q.enqueue(4);
    
    q.PrintElements();

    q.enqueue(9);
    return 0;
}
