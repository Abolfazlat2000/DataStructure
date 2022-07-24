#include<bits/stdc++.h>

struct stack
{
    int top;
    int*a;
    int size;
    unsigned cap;
    stack(unsigned c){
        size = 0;
        a = (int*)malloc(sizeof(int)*c);
        top = -1;
        cap = c;
    }
    bool isFull();
    bool isEmpty();
    void push(int num);
    int pop();
    /* data */
};

bool stack::isFull(){
    return(stack::top == stack::cap - 1);
}

bool stack::isEmpty(){
    return(stack::top == -1);
}

void stack::push(int num){
    if(stack::isFull()){
        return;
    }
    stack::top++;
    stack::size++;
    stack::a[stack::top] = num;
}

int stack::pop(){
    if (stack::isEmpty()){
        return INT8_MIN;
    }
    int item;
    item = stack::a[stack::top];
    stack::top--;
    stack::size--;
    return item;
}



int main(int argc, char const *argv[])
{
    struct stack s(5);

    s.push(1);
    s.push(3);
    s.push(4);
    s.push(5);

    std::cout<<"top= "<<s.top<<std::endl;
    std::cout<<"item in top= "<<s.a[s.top]<<std::endl;
    std::cout<<"size= "<<s.cap<<std::endl;
      
    std::cout<<"delete= "<<s.pop()<<std::endl;
    
    std::cout<<"top= "<<s.top<<std::endl;
    std::cout<<"item in top= "<<s.a[s.top]<<std::endl;
    std::cout<<"size= "<<s.cap<<std::endl;
    
    return 0;
}
