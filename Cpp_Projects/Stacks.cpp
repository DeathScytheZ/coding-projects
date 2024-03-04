#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};


void insert(ListNode* &head, int x){
    ListNode* new_node = new ListNode;
    new_node->val = x;
    new_node->next = head;
    head = new_node;
}

void printList(ListNode* head){
    if(!head)
        return;
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


void printStack(stack<int> stk){
    queue<int> que;
    while(!stk.empty()){
        que.push(stk.top());
        stk.pop();
    }
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}

void stackEven(stack<int> stk){
    int stackSize = stk.size();
    for(int i = 0; i < stackSize; i++){
        if(stk.top() % 2 == 0)
            cout << stk.top() << " ";
        stk.pop();
    }
}

int stackSum(stack<int> stk){
    int sum = 0;
    int stackSize = stk.size();
    for(int i = 0; i < stackSize; i++){
        sum += stk.top();
        stk.pop();
    }
    return sum;
}


ListNode* copy(ListNode* head){
    ListNode* L = NULL;
    stack<int> stk;
    while(head){
        stk.push(head->val);
        head = head->next;
    }
    while(!stk.empty()){
        ListNode* newNode = new ListNode;
        newNode->val = stk.top();
        stk.pop();
        newNode->next = L;
        L = newNode;
    }
    return L;

}

stack<int> permutation(stack<int> &p, int N){
    stack<int> s;
    stack<int> ss;
    for(int i = 0; i < N; i++){
        s.push(p.top());
        p.pop();
    }
    while(!p.empty()){
        ss.push(p.top());
        p.pop();
    }
    while(!s.empty()){
        p.push(s.top());
        s.pop();
    }
    while(!ss.empty()){
        p.push(ss.top());
        ss.pop();
    }
    return p;
}

stack<int> createStack(int N){
    stack<int> stk;
    int x;
    for(int i = 1; i <= N; i++){
        cout << "enter the element number " << i << " : ";
        cin >> x;
        stk.push(x);
    }
    return stk;
}


int main(){
    //stack<int> stk;
    ListNode* head = NULL;
    //stk.push(7); stk.push(25); stk.push(30); stk.push(20); stk.push(50);
    insert(head, 5); insert(head, 6); insert(head, 93); insert(head, 13); insert(head, 87);



    printList(head);
    printList(copy(head));
    


    
}