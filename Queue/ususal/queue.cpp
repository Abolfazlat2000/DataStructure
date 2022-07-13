#include <bits/stdc++.h>


//Define a structue for queue
struct Queue
{
    int *a; //array to store data
    int front; //index of front
    int rear;// index of rear
    int size;
    unsigned c;//capacity of the queue

    Queue(unsigned cap){
        c = cap;
        a = (int*)malloc(sizeof(int) * c);
        front = 0;
        rear = c - 1;
        size = 0;

    }
    bool isEmpty();
    bool isFull();
    void enqueue(int item);
    int dequeue();

};
//implement structs functions
bool Queue::isEmpty(){
    //check if queue is empty

    return (Queue::size == 0);
}

bool Queue::isFull(){
    //check if queue is full

    return (Queue::size == c);
}

void Queue::enqueue(int item){
    
    if (Queue::isFull()){
        return;
    }
    //find rear index beacuse it is FIFO
    Queue::rear = (Queue::rear + 1) % Queue::c;
    Queue::a[Queue::rear] = item;
    Queue::size++;
    std::cout<<"item "<< item << " added to queue."<< std::endl;
    
}

int Queue::dequeue(){

    if(Queue::isEmpty()){
        return INT8_MIN;
    }

    int item;
    item = Queue::a[Queue::front];
    Queue::front = (Queue::front + 1) % Queue::c;
    Queue::size--;
    return item;
}

int main(int argc, char const *argv[])
{   
    struct Queue q(5);

    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(75);

    std::cout<<"front= "<<q.front<<std::endl;
    std::cout<<"rear= "<<q.rear<<std::endl;
    std::cout<<"size= "<<q.size<<std::endl;
      
    std::cout<<"delete= "<<q.dequeue()<<std::endl;
    
    std::cout<<"front= "<<q.front<<std::endl;
    std::cout<<"rear= "<<q.rear<<std::endl;
    std::cout<<"size= "<<q.size<<std::endl;

    /* code */
    return 0;
}
