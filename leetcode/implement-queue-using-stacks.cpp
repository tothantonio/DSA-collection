#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
    //Time: O(1) // amortized
    //Space: O(n) // where n is the number of elements in the queue
public:

    stack<int> input;
    stack<int> output;
    
    MyQueue(){
    }

    void push(int x){
        input.push(x);
    }

    int pop(){
        int val = peek();
        output.pop();
        return val;
    }

    int peek(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty(){
        return input.empty() && output.empty();
    }
};

int main(){

    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.peek() << endl;
    cout << q.empty() << endl;

    return 0;
}