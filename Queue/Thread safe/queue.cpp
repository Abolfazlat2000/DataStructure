#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>

//Define a structue for queue
struct Queue
{
    int *a; //array to store data
    int front; //index of front
    int rear;// index of rear
    int size;
    unsigned c;//capacity of the queue
    mutable std::mutex m;
    std::condition_variable cv;
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
    
    std::lock_guard<std::mutex> lock(Queue::m);
    if (Queue::isFull()){
        return;
    }
    //critical section
    //find rear index beacuse it is FIFO
    Queue::rear = (Queue::rear + 1) % Queue::c;
    Queue::a[Queue::rear] = item;
    Queue::size++;
    std::cout<<"item "<< item << " added to queue."<< std::endl;
    Queue::cv.notify_one();
    
}

int Queue::dequeue(){

    std::unique_lock<std::mutex> lock(Queue::m);
    
    while(Queue::isEmpty()){
        // release lock as long as the wait and reaquire it afterwards.
        Queue::cv.wait(lock);
    }
    //critical section 
    lock.lock();
    int item;
    item = Queue::a[Queue::front];
    Queue::front = (Queue::front + 1) % Queue::c;
    Queue::size--;
    lock.unlock();
    return item;
}

int main(int argc, char const *argv[])
{   

    /* code */
    return 0;
}
