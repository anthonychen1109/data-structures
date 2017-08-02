#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class listBinTreeNode{
    friend class HuffmanLinkedList;
    friend class HuffmanBinaryTree;
private:
public:
    string chStr;
    int prob;
    listBinTreeNode* next;
    listBinTreeNode* left;
    listBinTreeNode* right;
    
    listBinTreeNode(){
    }//listBinTreeNode constructor
    
    listBinTreeNode(string chStr, int prob){
        this->chStr = chStr;
        this->prob = prob;
        next = NULL;
        left = NULL;
        right = NULL;
    }//listBinTreeNode constructor
    /*
     listBinTreeNode(string chStr, int prob, listBinTreeNode* next, listBinTreeNode* left, listBinTreeNode* right){
     this->chStr = chStr;
     this->prob = prob;
     this->next = next;
     this->left = left;
     this->right = right;
     }//listBinTreeNode constructor
     */
    ~listBinTreeNode(){
        //         delete next;
        //         delete left;
        //         delete right;
    }//listBinTreeNode destructor
    
    // given a node, T, print T’s chStr, T’s prob, T’s next’s chStr, T’s left’s chStr, T ‘s right’s chStr
    void printNode(listBinTreeNode* T, ofstream& outFile2){
        if(T->next == NULL && (T->left == NULL || T->right == NULL)){
            outFile2 << T->chStr << " " << T->prob << " " << " " << "" << " " << "" << " " << endl;
            
        }else if(T->next == NULL){
            outFile2 << T->chStr << " " << T->prob << " " << " " << T->left->chStr << " " << T->right->chStr << " " << endl;
        }else if(T->left == NULL || T->right == NULL){
            outFile2 << T->chStr << " " << T->prob << " " << T->next->chStr << " " << " " << endl;
        }//else if
        else{
            outFile2 << T->chStr << " " << T->prob << " " << T->next->chStr << " " << T->left->chStr << " " << T->right->chStr << " " << endl;
        }//else
    }//printNode function
    
};//listBinTreeNode class

class HuffmanLinkedList{
    friend class HuffmanBinaryTree;
private:
public:
    listBinTreeNode* listHead;
    listBinTreeNode* oldListHead;
    string chStr;
    int prob;
    
    //create a dummylistNode and let listHead point to it
    HuffmanLinkedList(){
        listHead = new listBinTreeNode("dummy",0);
    }//HuffmanLinkedList constructor
    
    //inserting newNode into the list using inserting sort
    void listInsert(listBinTreeNode* newNode){
        if(newNode->prob < listHead->prob){
            newNode->next = listHead;
        }else{
            listBinTreeNode* spot = findSpot(newNode->prob);
            newNode->next = spot->next;
            spot->next = newNode;
        }//else
    }//listInsert function
    
    listBinTreeNode* findSpot(int pro){
        listBinTreeNode* spot = listHead;
        while(spot->next != NULL && spot->next->prob < pro){
            spot = spot->next;
        }//while
        return spot;
    }//findSpot function
    
    bool isEmpty(){
        if (listHead == NULL){
            return true;
        }//if
        else{
            return false;
        }//else
    }//isEmpty function
    
    //print the list from listHead to the end to the outFile3 (argv[4]) in the following format:
    //listHead -->(“dummy”, 0, nextString)-->(nextString, prob, next)
    //-->(nextString, prob, nextString)--> ...... --> (nextString, prob, NULL)--> NULL
    
    void printList(ofstream& outFile3){
        listBinTreeNode* spot = listHead;
        outFile3 << "ListHead -->(\"" << spot->chStr << "\"," << spot->prob << ",";
        
        while(spot->next != NULL){
            spot = spot->next;
            outFile3 << spot->chStr<<")-->("<<spot->chStr<<","<<spot->prob<<",";
        }//while
        outFile3 <<"NULL)-->NULL"<<endl;
    }//printList function
    
};//HuffmanLinkedList class

class HuffmanBinaryTree{
private:
public:
    string chStr;
    int prob;
    string code;
    listBinTreeNode* root;
    
    HuffmanBinaryTree(HuffmanLinkedList LL,ofstream& outFile3){
        listBinTreeNode* oldListHead = LL.listHead;
        oldListHead->next = LL.listHead->next;
        // cout<<LL.listHead->next->prob;
        listBinTreeNode* first = LL.listHead->next;
        while(first->next!= NULL){
            listBinTreeNode* newNode = new listBinTreeNode();
            newNode->prob = first->prob + first->next->prob; // first is the node after dummy
            newNode->chStr = first->chStr + first->next->chStr;
            cout << newNode->prob <<" "<<newNode->chStr<<endl;
            newNode->left = first;
            newNode->right = first->next;
            LL.listHead = first->next->next;
            first = LL.listHead;
            
            if(LL.listHead != NULL) LL.listInsert(newNode);
            
            if(LL.listHead == NULL ||newNode->prob < LL.listHead->prob){
                first = newNode;
                LL.listHead = first;
            }//if
            newNode->printNode(newNode,outFile3);
        }//while
        root = first;
        
    }//HuffmanBinaryTree constructor
    
    ~HuffmanBinaryTree(){
    }//destructor
    
    void preOrderTraversal(listBinTreeNode* T, ofstream& outFile2){
        
        if(T == NULL){
            return;
        }//if
        else{
            T->printNode(T,outFile2);
            preOrderTraversal(T->left,outFile2);
            preOrderTraversal(T->right,outFile2);
        }//else
    }//preOrderTraversal function
    
    void constructCharCode(listBinTreeNode* T, string code, ofstream& outFile1){
        if(T == NULL){
            return;
        }//if
        else if(T->left == NULL && T->right == NULL){
            outFile1 << T->chStr; // argv[2]
            outFile1 << code<<"\n"; //to outfile2
        }//else if
        else{
            constructCharCode (T->left, code + "0",outFile1);
            constructCharCode (T->right, code + "1",outFile1);
        }//else
    }//constructCharCode function
    
};//HuffmanBinaryTree class

int main(int argc, const char * argv[]) {
    
    ifstream inFile;
    ofstream outFile1;
    ofstream outFile2;
    ofstream outFile3;
    
    inFile.open(argv[1]);
    outFile1.open(argv[2]);
    outFile2.open(argv[3]);
    outFile3.open(argv[4]);
    string data;
    string chStr;
    int prob;
    int count = 0;
    int count2 = 0;
    HuffmanLinkedList LL;
    while(inFile>>data){
        count++;
    }//while
    inFile.close();
    inFile.open(argv[1]);
    while(count2 < count){
        inFile>>chStr;
        inFile>>prob;
        count2 += 2;
        listBinTreeNode* newNode = new listBinTreeNode(chStr,prob);
        LL.listInsert(newNode);
        LL.printList(outFile3);
    }//while
    HuffmanBinaryTree BT(LL,outFile3);
    BT.preOrderTraversal(BT.root, outFile2);
    BT.constructCharCode(BT.root, "", outFile1);
    inFile.close();
    
    outFile1.close();
    outFile2.close();
    outFile3.close();
    return 0;
}//main
