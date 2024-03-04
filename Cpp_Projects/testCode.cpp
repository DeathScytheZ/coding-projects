#include <iostream>
#include <string>

struct node{
    int data;
    node* next;
};

void tail_insert(node* &head, int x){
    node* new_node = new node;
    new_node->data = x;
    new_node->next = head;
    head = new_node;
}

void print(node* head){
    while(head != NULL){
        std::cout << head->data << "   ";
        head = head->next;
    }
    std::cout << std::endl;
}

bool search(node* head, int x){
    while(head != NULL){
        if(head-> data == x)
            return true;
        head = head->next;
    }
    return false;
}


bool re_search(node* head, int x){
    if(head != NULL){
        if(head->data == x)
            return true;
        head = head->next;
        return re_search(head, x);
    }
    return false;
}

int len(node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

int re_len(node* head){
    if(head != NULL){
        head = head->next;
        return 1 + re_len(head);
    }
    return 0;
}

void delete_key(node* &head, int key){
    node* current = head;
    node* previous = head;
    if(head->data == key){
        head = head->next;
        delete current;
        return;
    }
    while(current != NULL){
        if(current->data == key){
            previous->next = current->next;
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void delete_pos(node* &head, int pos){
    node* current = head;
    node* previous = head;
    if(pos == 1){
        head = head->next;
        delete current;
        return;
    }
    while(pos != 1){
        previous = current;
        current = current->next;
        pos--;
    }
    previous->next = current->next;
    delete current;
}

void delete_list(node* &head){
    node* current = head; 
    while(head != NULL){
        head = head->next;
        delete current;
        current = head;
    }
}

int Nth_node(node* head, int N){
    if(N == 1)
        return head->data;
    while(N != 1){
        head = head->next;
        N--;
    }
    return head->data;
}

void reverse(node* &head){
    node* previous = NULL;
    node* current = head;
    node* next = head;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int count(node* head, int x){
    int result = 0;
    while(head != NULL){
        if(head->data == x)
            result++;
        head = head->next;
    }
    return result;
}

void head_insert(node* &head, int x){
    node* new_node = new node;
    new_node->data = x;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        return;
    }
    node* current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = new_node;
}

std::string stringify(node* head){
    std::string result = "";
    while(head != NULL){
        result += std::to_string(head->data) + " -> ";
        head = head->next;
    }
    result += "NULL";
    return result;
}

node* mergeNodes(node* &head){
    int sum = 0;
    node* first = head;
    node* current = head;
    node* temp = head;
    head = head->next;
    while(head != NULL){
        if(head->data != 0){
            sum += head->data;
            head = head->next;
            delete current;
        }
        else{
            head->data = sum;
            sum = 0;
            temp->next = head;
            temp = head;
            head = head->next;
        }
        current = head;
    }
    head = first;
    head = head->next;
    delete first;
    return head;
}


node* mergeLists(node* list1, node* list2){
    node* mergedList = NULL;
    node* current1 = list1;
    node* current2 = list2; 
    while(list1 && list2 != NULL){
        if(list1->data > list2->data){
            tail_insert(mergedList, current1->data);
            list1 = list1->next;
            delete current1;
            current1 = list1;
        }
        else{
            tail_insert(mergedList, current2->data);
            list2 = list2->next;
            delete current2;
            current2 - list2;
        }
    }
    if(list1 == NULL)
        mergedList->next = list2;
    else
        mergedList->next = list1;
    return mergedList;
}

int main(){
    node* list1 = NULL;
    node* list2 = NULL;
    tail_insert(list1, 3); tail_insert(list1, 4); tail_insert(list1, 7); tail_insert(list1, 0); tail_insert(list1, 1); tail_insert(list1, 4); tail_insert(list1, 9);
    tail_insert(list2, 8); tail_insert(list2, 1); tail_insert(list2, 0); tail_insert(list2, 2); tail_insert(list2, 3); tail_insert(list2, 7); tail_insert(list2, 5);
    print(list1);
    print(list2);
    print(mergeLists(list1, list2));
}




