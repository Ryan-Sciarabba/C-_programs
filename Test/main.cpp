#include <iostream>
#include <stack>

using namespace std;

void printStack(stack <int> fStack){

    cout<<"Stack: ";

    while(!fStack.empty()){
        cout<<fStack.top()<<" ";
        fStack.pop();
    }
    cout<<endl;
}

void printStack(stack <char> fStack){

    cout<<"Stack: ";

    while(!fStack.empty()){
        cout<<fStack.top();
        fStack.pop();
    }
    cout<<endl;
}

void printStack(stack <double> fStack){

    cout<<"Stack: ";
    while(!fStack.empty()){
        cout<<fStack.top()<<" ";
        fStack.pop();
    }
    cout<<endl;
}

int main(){

    stack <int> iStack;
    stack <char> cStack;
    stack <double> dStack;

    int b,
        i = 0;

    char c,
         a[] = "ba";

    double d;

    cout<<"Input a number to add to the top of the stack: ";
    cin>>b;

    cout<<"Input a character to complete the word '_ab': ";
    cin>>c;

    cout<<"Input a double to add to a different stack: ";
    cin>>d;

    iStack.push(b);
    iStack.push(b + 5);
    iStack.push(1);
    iStack.push(3);
    iStack.push(40);

    while(a[i]){
        cStack.push(a[i]);
        i++;
    }

    cStack.push(c);

    dStack.push(d);
    dStack.push(d + 3.1);
    dStack.push(40.64);
    dStack.push(30.2);

    printStack(iStack);
    printStack(cStack);
    printStack(dStack);

    return 0;
}
