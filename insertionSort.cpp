
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class listNode{
private:
    //  int data;
    //  listNode* next;
public:
    int data;
    listNode* next;
    
    listNode(int data){
        this->data = data;
        next = NULL;
    }//constructor
    
    listNode(int data, listNode* next){
        this->data = data;
        this->next = next;
    }//constructor
    
    ~listNode(){
    }//destructor
    
    friend class linkedList;
    
};//class

class linkedList{
private:
    //listNode* listHead;
public:
    listNode* listHead;
    linkedList(){
        listNode* junk = new listNode(-9999,NULL);
        listHead = junk;
    }
    
    bool isEmpty(){
        if (listHead->next == NULL){
            return true;
        }//if
        else{
            return false;
        }//else
    }//isEmpty function
    
    void listInsert(int data){
        listNode* spot = findSpot(data);
        if(spot->next != NULL && spot->next->data == data){
            cout << data << " already exists" << endl;
        }//if
        else{
            listNode* newNode = new listNode(data);
            newNode->next = spot->next;
            spot->next = newNode;
        }//else
    }//listInsert function
    
    listNode* findSpot(int data){
        listNode* spot = listHead;
        while(spot->next != NULL && spot->next->data < data){
            spot = spot->next;
        }//while
        return spot;
    }//findSpot function
    
    void printList(){
        listNode* spot = listHead;
        while(spot != NULL){
            if(spot == listHead){
                if(spot->next != NULL)
                    cout << "ListHead -->" << "(" << spot->data << "," << spot->next->data << ")--> ";
                else
                    cout << "ListHead -->" << "(" << spot->data << "," << "-1" << ")--> "<<endl;
            }//if
            else{
                if(spot->next != NULL){
                    cout<<" (" << spot->data << "," << spot->next->data << ")-->";
                }
                else{
                    cout << " (" << spot->data << "," << "-1" << ")" << endl;
                }
            }
            spot = spot->next;
        }
    }//printList function
    
    void printList(ofstream& out){
        listNode* spot = listHead;
        while(spot != NULL){
            if(spot == listHead){
                if(spot->next != NULL)
                    out << "ListHead -->" << "(" << spot->data << "," << spot->next->data << ")--> ";
                else
                    out << "ListHead -->" << "(" << spot->data << "," << "-1" << ")--> "<<endl;
            }//if
            else{
                if(spot->next != NULL){
                    out<<" (" << spot->data << "," << spot->next->data << ")-->";
                }
                else{
                    out << " (" << spot->data << "," << "-1" << ")" << endl;
                }
            }
            spot = spot->next;
        }
    }//printList function
    
    
};//class

int main(int argc, const char * argv[]) {
    int data;
    linkedList LL;
    ifstream inFile(argv[1]);
    inFile.open(argv[1]);
    while(inFile >> data){
        cout << "read data " << data << endl;
    }//while
    inFile.close();
    inFile.open(argv[1]);
    ofstream outFile;
    outFile.open(argv[2]);
    while(inFile >> data){
        LL.findSpot(data);
        LL.listInsert(data);
        LL.printList();
        LL.printList(outFile);
    }//while
    inFile.close();
    outFile.close();
    return 0;
}//main
