#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

struct product{
    int ref;
    int quant;
    float price;
    string des;
    date fab;
    date exp;

};


struct node{
    product pro;
    node* left;
    node* right;
};


node* createNode(product pro){
    node* new_node = new node;
    new_node->pro = pro;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* bstInsert(node* &root, product pro){  
    if(!root)
        root = createNode(pro);
    else if(root->pro.ref >= pro.ref)
        root->left = bstInsert(root->left, pro);
    else
        root->right = bstInsert(root->right, pro);
    return root;
}

void insertProduct(node* &root){
    product pro;
    cout << "enter the reference for the product: ";
    cin >> pro.ref;
    cout << "enter the quantiy of the product: ";
    cin >> pro.quant;
    cout << "enter the price of the product: ";
    cin >> pro.price;
    cout << "enter the date of fabrication of the product: " << endl;
    cout << "day: ";
    cin >> pro.fab.day;
    cout << "month: ";
    cin >> pro.fab.month;
    cout << "year: ";
    cin >> pro.fab.year;
    cout << "enter the date of expiration of the product: " << endl;
    cout << "day: ";
    cin >> pro.exp.day;
    cout << "month: ";
    cin >> pro.exp.month;
    cout << "year: ";
    cin >> pro.exp.year;
    bstInsert(root, pro);
}

node* search(node* root, int ref){
    if(!root)
        return NULL;
    if(root->pro.ref == ref)
        return root;
    if(root->pro.ref >= ref)
        return search(root->left, ref);
    else
        return search(root->right, ref);
}

void print(node* root){
    if(!root)
        return;
    print(root->left);
    cout << "Reference: " << root->pro.ref << endl;
    cout << "Quantity: " << root->pro.quant << endl;
    cout << "Price: " << root->pro.price << endl;
    cout << "Designation: " << root->pro.des << endl;
    cout << "Date of Fabrication: " << root->pro.fab.day << "/" <<  root->pro.fab.month << "/" root->pro.fab.year << endl;
    cout << "Date of Experation: : " << root->pro.exp.day << "/" <<  root->pro.exp.month << "/" root->pro.exp.year << endl;
    print(root->right);
}

void create(node* &root, int n){
    for(int i = 0; i < n; i++)
        insertProduct(root);
}

void sell(node* &root, int ref, int quantity){
    node* p = search(root, ref);
    if(p->pro.quant < quantity)
        cout << "error" << endl;
    else{
        p->pro.quant -= quantity;
        cout << "Done" << endl;
    }
}


void supply(node* root, int ref, int quantity){
    node* p = search(root, ref);
    if(p)
        p->pro.quant += quantity;
    else{
        product pro;
        pro.ref = ref;
        pro.quant = quantity;
        cout << "this product doesn't exist!" << endl;
        cout << "enter the designation of the product: ";
        cin >> pro.des;
        cout << "enter the price of the product: ";
        cin >> pro.price;
        cout << "enter the date of fabrication of the product: " << endl;
        cout << "day: ";
        cin >> pro.fab.day;
        cout << "month: ";
        cin >> pro.fab.month;
        cout << "year: ";
        cin >> pro.fab.year;
        cout << "enter the date of expiration of the product: " << endl;
        cout << "day: ";
        cin >> pro.exp.day;
        cout << "month: ";
        cin >> pro.exp.month;
        cout << "year: ";
        cin >> pro.exp.year;
        bstInsert(root, pro);
        }
}

void experation(node* root, date d){
    queue<node*> que;
    que.push(root);
    node* topNode;
    while(!que.empty()){
        topNode = que.front();
        if(topNode->left)
            que.push(topNode->left);
        if(topNode->right)
            que.push(topNode->right);
        if(topNode->pro.exp.year < d.year)
            print(topNode);
        else if(topNode->pro.exp.year == d.year){
            if(topNode->pro.exp.month < d.month)
                print(topNode);
            else if(topNode->pro.exp.month == d.month){
                if(topNode->pro.exp.day < d.day)
                    print(topNode);
            }
        }
        que.pop();
    }
}

int main(){
    node* root = NULL;
    insertProduct(root);
}