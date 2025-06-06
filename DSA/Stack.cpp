#include <iostream>

using namespace std;
const int MAX_SIZE = 100; //maximum size

class Stack {
    // <--- ADD YOUR CODE HERE --->
    
    private:

        int top;
        int* arr;
        int size;
        
    public:
    
        Stack(int size){
            
            this->size = size;
            arr = new int[size];
            
            top = -1;
        }
        ~Stack(){
            delete[] arr;
        }
    
    void push(int x){
        
        if(isFull()){
            
            cout << "Stack Overflow" << endl;
        }else{
            
            top++;
            arr[top] = x;
            
        }
    }
    
    void pop(){
        
        if(isEmpty()){
        
            cout << "Stack underflow" << endl;
            
            //return -1;
            
        }else{
            
            //int popped_value = arr[top];
            top--;
            
            
            
        }
    }
    
    bool isEmpty(){
        
        return top == -1;
    }
    
    bool isFull(){
        
        return top == size -1;
        
    }


    int stackTop(){
        
        if (isEmpty()){
            
            //cout << "empty stasck" << endl;
            
            return -1;
        }
        
        return arr[top];
    }
    
    void display(){
        
        if (isEmpty()){
            
            cout << "empty" << endl;
        }else {
            
            for (int i = top; i >= 0; i--){
                
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(5);
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "isFull") {
            if (myStack.isFull()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "exit") {
            break;
        }else if(instruction == "stackTop"){
            
            cout << myStack.stackTop() << endl;
        }
        else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}