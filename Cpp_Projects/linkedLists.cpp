#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

void print(ListNode* head){
    while(head != NULL){
        cout << head->val << "  ";
        head = head->next;
    }
    cout << endl;
}

void insert(ListNode* &head, int x){
    ListNode* new_node = new ListNode;
    new_node->val = x;
    new_node->next = head;
    head = new_node;
}

void tail_insert(ListNode* &head, int x){
    ListNode* new_node = new ListNode;
    new_node->val = x;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        return;
    }
    ListNode* current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = new_node;
}

    //write a function to calulate the square root of 2
    


ListNode* mergeNodes(ListNode* head){
    int sum = 0;
    ListNode* current = head;
    ListNode* temp = head;
    ListNode* first = head;
    head = head->next;
    while(head != NULL){
        if(head->val == 0){
                head->val = sum;
                sum = 0;
                temp->next = head;
                temp = head;
        }
        else{
            sum += head->val;
            delete current;
        }
        head = head->next;
        current = head;
    }
    head = first;
    return head;
}

    //a doubly linked list definition
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
    };
    

ListNode* mergeLists(ListNode* list1, ListNode* list2){
    ListNode* merged = NULL;
    if(list1->val < list2->val){
        merged = list1;
        list1 = list1->next;
    }else{
        merged = list2;
        list2 = list2->next;
    }
    ListNode* temp = merged;
    while (list1 && list2){
        if(list1->val < list2->val){
            temp->next = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1)
        temp->next = list1;
    else
        temp->next = list2;
    return merged;
}


bool isSorted(ListNode* head){
    if(!head || !head->next)
        return true;
    if(head->val < head->next->val)
        return false;
    return isSorted(head->next);
}

bool search(ListNode* head, int x){
    if(!head)
        return false;
    if(head->val == x)
        return true;
    return search(head->next, x);
}

int max(ListNode* head) {
    // Base case: empty list
    if (!head) {
        std::cerr << "Empty list." << std::endl;
        // You might want to handle this case differently based on your requirements
        // For now, I'm returning a minimum possible integer value
        return INT_MIN;
    }

    // Base case: single-node list
    if (!head->next)
        return head->val;

    // Recursive case: find the maximum in the rest of the list
    int maxInRest = max(head->next);

    // Return the maximum of the current node's value and the maximum in the rest of the list
    return std::max(head->val, maxInRest);
}

int main(){
    ListNode* head = NULL;

    //insert(head, 4); insert(head, 5); insert(head, 9); insert(head, 12);
    print(head);
    cout << max(head);
}
     
    