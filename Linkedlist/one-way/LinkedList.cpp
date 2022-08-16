#include<bits/stdc++.h>
struct Node {
    int data;
    struct Node *next;
}*start;

Node *creatNode(int value){
    struct Node *n;
    n = new(struct Node);
    if (n == NULL){
        std::cout<<"not allocated "<<std::endl;
        return 0;
    }else{

        n->data = value;
        n->next = NULL;
        return n;    
    }
}

void insertAt(int value,int position){
    struct Node *current,*prev,*temp;
    int numOfNode = 0;
    //Create new Node
    temp = creatNode(value);

    current = start;
    while (current != NULL){
        current = current->next;
        numOfNode++;
    }
    // do{
    //     current = current->next;
    //     numOfNode++;
    // } while (current != NULL);
    
    
    if (position == 1){
        /* Insert begin */
        if(start == NULL){
            start = temp;
            start->next = NULL;
        }else{
            prev = start;
            // start->next = temp;
            // temp->next = prev;
            start = temp;
            start->next = prev;
        }


    }else if (position > 1 && position <= numOfNode ){
        /*Insert middle*/

        current = start;
        for (int i = 1; i < position; i++){
            /* goto position */
            prev = current;
            current = current->next;
        }
        prev->next = temp;
        temp->next = current;

    }else if(position == numOfNode+1){
        /*Insert at the end*/

        current = start;
        while (current->next != NULL){
            current = current->next;
        }
        
        temp->next = NULL;
        // current = new(struct Node);
        current->next = temp;

    }else{
        std::cout<<"Index outof bound!!"<<std::endl;
    }    
}
void display()
{
    struct Node *t;
    if (start == NULL)
    {
        std::cout<<"Empty\n------------------\n"<<std::endl;
        return;
    }

    t = start;
    std::cout<<"Elements: "<<std::endl;
    
    while (t != NULL)
    {
        std::cout << t->data << "->";
        t = t->next;
    }
    std::cout<<"NULL\n------------------------\n"<<std::endl;
}

int main(int argc, char const *argv[])
{
    int x,pos,value;
    start=NULL;
    
    while(1)     
    {
        std::cout<<"1. insert      " << std::endl;
        std::cout<<"2. show list           " << std::endl;
        std::cout<<"3. exit                " << std::endl;
        std::cout<<"enter(1..3):           " << std::endl;
        
        std::cin >>x;
        
        switch(x)
        {
            case 1:
                    std::cout<<"Enter value:"<<std::endl; 
                    std::cin>>value;
                    std::cout<<"Enter position:"<<std::endl; 
                    std::cin>>pos; 
                    insertAt(value,pos);
                    break;
            case 2:
                    display();
                    break;
            case 3:
                    exit(1);
                    break;
        }
    }
    return 0;
}
