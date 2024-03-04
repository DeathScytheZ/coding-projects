#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// defining the data structures

struct page{
    int pageNumber;
};

struct document{
    string name;
    queue<page> pageQue;
};

struct ListNode{
    document doc;
    ListNode* next;
};


// function for adding pages to the document
void addPages(document &doc){
    int N;
    page p;
    int numP;
    cout << "how many pages in the document? ";
    cin >> N;
    for(int i = 1; i <= N; i++){
        cout << "enter the number of page " << i << ": ";
        cin >> numP;
        p.pageNumber = numP;
        doc.pageQue.push(p);
    }
}



// function for inserting a new node into the linked list
void insert(ListNode* &head, string name){
    ListNode* new_node = new ListNode;
    new_node->doc.name = name;
    addPages(new_node->doc);
    new_node->next = head;
    head = new_node;
}



//function for printing the elements of the linked list
void printList(ListNode* head){
    if(!head)
        return;
    while(head){
    queue<page> temp = head->doc.pageQue;
        cout << "Document Name: " << head->doc.name << " / ";
        cout << "pages Numbers: ";
        while(!temp.empty()){
            cout << temp.front().pageNumber << " ";
            temp.pop();
        }
        cout << endl;
        head = head->next;
    }
    cout << endl;
}


//function for calculating the time it takes to print all the pages in the printer(the queue);
int printTime(ListNode* head){
    int time = 0;
    while(head){
        time += 5 * (head->doc.pageQue.size());
        head = head->next;
    }
    return time;
}


int main(){
    ListNode* head = NULL;
    insert(head, "tp1"); insert(head, "tp2"); 


    cout << printTime(head);

    
}