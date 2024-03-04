#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> que){
    stack<int> stk;
    while(!que.empty()){
        stk.push(que.front());
        que.pop();
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void queueEven(queue<int> que){
    int queueSize = que.size();
    for(int i = 0; i < queueSize; i++){
        if(que.front() % 2 == 0)
            cout << que.front() << " ";
        que.pop();
    }
}

int queueSum(queue<int> que){
    int sum = 0;
    int queueSize = que.size();
    for(int i = 0; i < queueSize; i++){
        sum += que.front();
        que.pop();
    }
    return sum;
}
  0
void binary(int x){
    queue<int> F;
    stack<int> P;
    int rest = 0;
    while(x){
        P.push(x % 2);
        x /= 2;
    }
    while(!P.empty()){
        F.push(P.top());
        P.pop();
    }
}

int decimal(queue<int> F){
    int x = 0;
    int exp = F.size() - 1;
    while(!F.empty()){
        x += F.front() * pow(2, exp);
        exp--;
        F.pop();
    }
    return x;
}


int main(){
    queue<int> que;
    que.push(1); que.push(1); que.push(0); que.push(1); 
    
    

    printQueue(que);
    cout << decimal(que);
}