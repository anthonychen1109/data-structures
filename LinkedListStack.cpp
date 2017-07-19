//
//  main.cpp
//  stackproject1
//
//  Created by anthony chen on 2/4/16.
//  Copyright © 2016 anthony chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node{
private:
    Node* next;
    int data;
public:
    Node(int d){ //constructor
        data=d;
        next=NULL;
    }//Node constructor
    Node(int d, Node* n){ //constructor
        data=d;
        next=n;
    } //Node constructor
    ~Node(){ //destructor, calls when instance of class is destroyed
        delete (next);
    } //~Node
    friend class LinkedListStack; //allows inheritance
};

class LinkedListStack{
private:
    Node* Top;
    int count=0;
    
public:
    LinkedListStack(){
        Top = NULL;
    }
    
    void push(int d){
        Node* newTop;
        if(isEmpty()){
            newTop= new Node(d,NULL);
            Top = newTop;
            count++;
        }//if
        else{
            newTop= new Node(d,Top);
            Top = newTop;
            count++;
        }//else
    }//push function
    
    int pop(){
        if(isEmpty()){
            cout<<"The Stack is empty"<<endl;
            return 0;
        }//if
        
        Node* temp=Top;
        Top=Top->next;
        count--;
        cout << "pop " << temp->data << endl;
        free(temp);
        return temp->data;
    }//pop function
    
    bool isEmpty(){
        if(count==0){
            return true;
        } //if
        return false;
    }//isEmpty function
    
    void printStack(){
        cout<<"STACK:"<<endl;
        for(Node* p=Top; p!=NULL;p=p->next)
            cout<<p->data<<endl;
    }//printStack
};

int main(int argc, const char * argv[]) {

    LinkedListStack LLS;
    ifstream inFile(argv[1]);
    inFile.open("text.txt");
    
    int d;
    while(inFile >> d){
        LLS.push(d);
        cout <<"push "<< d << endl;
    } //while
    LLS.printStack();
    while (!LLS.isEmpty()){
        LLS.pop();
        LLS.printStack();
    }//while
    
    inFile.close();
    return 0;
}
