#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <queue>

using namespace std;

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

struct Book{
    int book_id;
    string title;
    string author;
    int year;
    int copies;
};

struct TreeNode{
    Book book;
    TreeNode* left;
    TreeNode* right;
};

struct date{
    int day;
    int month;
    int year;
};

struct borrow_record{
    int book_id;
    int student_id;
    string student_name;
    date borrow_date;
    date return_date;
};

struct ListNode{
    borrow_record record;
    ListNode* next;
};

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

TreeNode* create_TreeNode(Book b){
    TreeNode* new_node = new TreeNode;
    new_node->book = b;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int tree_size(TreeNode* root){
    if (!root)
        return 0;
    else  
        return 1 + tree_size(root->left) + tree_size(root->right);
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void saving(){
    Sleep(150);
    cout << "Saving";
    for (int i = 0; i < 7; i++){
        cout << ".";
        Sleep(200);
    }
    cout << endl;
}

void loading(){
    Sleep(150);
    cout << "Loading";
    for (int i = 0; i < 6; i++){
        cout << ".";
        Sleep(200);
    }
    cout << endl;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

ListNode* create_ListNode(borrow_record r){
    ListNode* new_node = new ListNode;
    new_node->record = r;
    new_node->next = NULL;
    return new_node;
}

void List_insert(ListNode* &head, borrow_record r){
    ListNode* new_node = new ListNode;
    new_node->record = r;
    new_node->next = head;
    head = new_node;
}

void List_remove(ListNode* head, ListNode* target){
    if(head == target){
        head->next = target->next;
        delete target;
        return;
    }
    while(head){
        if(head->next == target){
            head->next = target->next;
            delete target;
            return;
        }
        head = head->next;
    }
}

//-------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------

bool is_book_id_in_use(TreeNode* root, int x){
    if (!root)
        return false;
    if (root->book.book_id == x)
        return true;
    else if (x < root->book.book_id)
        return is_book_id_in_use(root->left, x); 
    else
        return is_book_id_in_use(root->right, x);
}

Book input_book(TreeNode* root){
    Book b;
    cout << "Enter the ID of the book: ";
    while (is_book_id_in_use(root, b.book_id))
        cout << "Error! The entered ID is already in use by another book, please try a different one. " << endl;
    cin >> b.book_id;
    cout << "Enter the title of the book: ";
    cin.ignore();
    getline(cin ,b.title);
    cout << "Enter the first and last name of the author: ";
    cin.ignore();
    getline(cin, b.author);
    cout << "Enter the year of edition of the book: ";
    cin >> b.year;
    cout << "Enter the number of copies of this book: ";
    cin >> b.copies;
    return b;
}

void add_book(TreeNode* &root){
    TreeNode* new_node = create_TreeNode(input_book(root));
    if (!root){
        root = new_node;
        return;
    }
    TreeNode* current = root;
    TreeNode* parent = NULL;
    while (current){
        parent = current;
        if(new_node->book.book_id < current->book.book_id)
            current = current->left;
        else
            current = current->right;
    }
    if (new_node->book.book_id < parent->book.book_id)
        parent->left = new_node;
    else
        parent->right = new_node;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void display_books(TreeNode* root){
    if (root){
        display_books(root->left);
        cout << root->book.title << " by " << root->book.author << endl;
        display_books(root->right);
    }
}

//-------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

TreeNode* find_book_by_ID(TreeNode* root, int num){
    if (!root)
        return NULL;
    while (root){
        if (num == root->book.book_id){
            return root;
        }
        else if (num < root->book.book_id)
            root = root->left;
        else 
            root = root->right;
    }
    return NULL;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void duplicate_list(TreeNode* root){
    if (root){
        duplicate_list(root->left);
        cout << root->book.title << endl;
        duplicate_list(root->right);
    }
}

TreeNode* duplicate_insert(TreeNode* duplicate, TreeNode* root){
    if (!duplicate){
        duplicate = new TreeNode;
        duplicate->left = duplicate->right = NULL;
        duplicate->book = root->book;
    }
    else if (root->book.title <= duplicate->book.title)
        duplicate->left = duplicate_insert(duplicate->left, root);
    else{
        duplicate->right = duplicate_insert(duplicate->right, root);
    }
    return duplicate;
}
      
void display_books_alphabetically(TreeNode* root){
    if (!root){
        cout << "There are no books in the library right now, please try again later.";
        return;
    }
    TreeNode* duplicate = NULL;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()){
        if (que.front()->left)
            que.push(que.front()->left);
        if (que.front()->right)
            que.push(que.front()->right);
        duplicate = duplicate_insert(duplicate, que.front());
        que.pop();
    }
    duplicate_list(duplicate);
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

bool book_exists(TreeNode* root, int num){
    if (!root)
        return false;
    while (root){
        if(num == root->book.book_id && root->book.copies != 0)
            return true;
        else if(num < root->book.book_id)
            root = root->left;
        else
            root = root->right;
        }
    return false;
}

//-------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void display_book_info(Book b){
    cout << "Book: " << b.title << endl;
    cout << "Details: " << endl;
    cout << setw(5) << " " << "ID: " << b.book_id << endl;
    cout << setw(5) << " " << "Author: " << b.author << endl;
    cout << setw(5) << " " << "Edition Year: " << b.year << endl;
    cout << setw(5) << " " << "Number of availabale copies: " << b.copies << endl;
}

bool find_book_by_title(TreeNode* root, string t){
    if (!root)
        return false;
    if (root->book.title == t){
        display_book_info(root->book);
        return true;
    }
    return find_book_by_title(root->left, t) || find_book_by_title(root->right, t);
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void borrow_book(TreeNode* &root, ListNode* &head){
    if (!root){
        cout << "The library is empty right now, please try agian later.";
        return;
    }
    borrow_record r;
    cout << "Enter the ID of the book: ";
    cin >> r.book_id;
    TreeNode* book_to_borrow = find_book_by_ID(root, r.book_id);
    while (!book_to_borrow){
        cout << "Wrong ID, please enter a correct one: ";
        cin >> r.book_id;
        book_to_borrow = find_book_by_ID(root, r.book_id);
    }
    if (!book_to_borrow->book.copies){
        cout << "insufficient number of copies." << endl;
        return;
    }
    cout << "Enter the ID of the student: ";
    cin >> r.student_id;
    ListNode* current = head;
    while(current){
        if(current->record.book_id == r.book_id && current->record.student_id == r.student_id){
            Sleep(1000);
            cout << "This student has already borrowed a copy of this book." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Enter the first and last name of the student: ";
    cin.ignore();
    getline(cin, r.student_name);
    cout << "Enter the date the book was borrowed: " << endl;
    cout << "Day: ";
    cin >> r.borrow_date.day;
    cout << "Month: ";
    cin >> r.borrow_date.month;
    cout << "Year: ";
    cin >> r.borrow_date.year;
    cout << "Enter the date the book is going to be returned: " << endl;
    cout << "Day: ";
    cin >> r.return_date.day;
    cout << "Month: ";
    cin >> r.return_date.month;
    cout << "Year: ";
    cin >> r.return_date.year;
    List_insert(head, r);
    book_to_borrow->book.copies--;
    saving();
    cout << "Done." << endl;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void display_borrowed_books(TreeNode* root, ListNode* head){
    if(!head){
        cout << "No books have been borrowed yet." << endl;
        return;
    }
    while(head){
        cout << find_book_by_ID(root, head->record.book_id)->book.title << " by " << find_book_by_ID(root, head->record.book_id)->book.author << endl;
        head = head->next;
    }
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void return_book(TreeNode* root, ListNode* &head){
    if(!head){
        cout << "This student hasn't borrowed any books.";
        return;
    }
    int bookID, studentID;
    cout << "Enter the ID of the book to be returned: ";
    cin >> bookID;
    cout << "Enter the ID of the student returning the book: ";
    cin >> studentID;
    ListNode* current = head;
    while(current){
        if(current->record.book_id == bookID && current->record.student_id == studentID){
            find_book_by_ID(root, bookID)->book.copies++;
            List_remove(head, current);
            saving();
            cout << "Done." << endl;
            return;
        }
        current = current->next;
    }
    cout << "This student hasn't borrowed this book.";
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void borrowed_by_student(TreeNode* root, ListNode* head){
    bool found = false;
    if (!head){
        cout << "There are no borrowed books." << endl;
        return;
    }
    int num;
    cout << "Enter the student ID: ";
    cin >> num;
    loading();
    while (head){
        if (head->record.student_id  == num){
            cout << find_book_by_ID(root, head->record.book_id)->book.title << endl;
            found = true;
        }
        head = head->next;
    } 
    if (!found)
        cout << "This student hasn't borrowed any books." << endl;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

bool past_due_date(ListNode* head, date dueDate){
    if (head->record.return_date.year == dueDate.year){
        if (head->record.return_date.month == dueDate.month){
            if (head->record.return_date.day > dueDate.day)
                return true;
            else
                return false;
        }else if (head->record.return_date.month > dueDate.month)
            return true;
        else
            return false;
    }else if (head->record.return_date.year > dueDate.year)
        return true;
    else 
        return false;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------

void display_books_not_returned(TreeNode* root, ListNode* head){
    if(!head){
        cout << "No books have been borrowed yet." << endl;
        return;
    }
    bool found = false;
    date dueDate;
    cout << "Enter the due date: " << endl;
    Sleep(700);
    cout << "day: ";
    cin >> dueDate.day;
    cout << "month: ";
    cin >> dueDate.month;
    cout << "year: ";
    cin >> dueDate.year;
    loading();
    while(head){
        if (past_due_date(head, dueDate)){
           cout <<  find_book_by_ID(root, head->record.book_id)->book.title << endl;
           found = true;
        }
        head = head->next;
    }
    if (!found)
        cout << "there are no books that haven't been returned in this day." << endl;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------



int main(){
    TreeNode* root = NULL;
    ListNode* head = NULL;
    Book b;
    b.book_id = 323;
    b.title = "bin";
    b.author = "dks efd";
    b.year = 2390;
    b.copies = 2;
    root = create_TreeNode(b);
    bool running = true;
    int choice;
    system("cls");
    while(running){
        cout << setw(88) << "Wellcome to the Library" << endl << setfill('=') << setw(155) << "=" << endl << setfill(' ');
        cout << "[1] Add a book to the library's data base. " << setw(34) << "||" << setw(4) << " ";
        cout << "[7] Lend a book to a student."  << endl;
        cout << "[2] Display all the books that are available in the library right now." << setw(7) << "||" << setw(4) << " ";
        cout << "[8] Display the list of borrowed books." << endl;
        cout << "[3] Search for a book by it's ID." << setw(44) << "||" << setw(4) << " ";
        cout << "[9] Return a book that was borrowed by a student." << endl;
        cout << "[4] Search for a book by it's title." << setw(41) << "||" << setw(4) << " ";
        cout << "[10] Display the list of books borrowed by a specific student." << endl;
        cout << "[5] Check if a book is available or not." << setw(37) << "||" << setw(4) << " ";
        cout << "[11] Display all the list that have not been returned in a specific date." << endl;
        cout << "[6] Display all the books in an Alphabatic order." << setw(28) << "||" << setw(4) << " ";
        cout << "[12] Quit." << endl << endl;
        Sleep(500);
        cout << "please choose the number corresponding for the funciton: ";
        cin >> choice;
        Sleep(750);
        switch(choice){
            case 1: { system("cls"); add_book(root); saving(); break;
            }case 2: { system("cls"); loading(); display_books(root); Sleep(1500); break;
            }case 3: {
                system("cls");
                int n; 
                cout << "Please enter the ID of the book you are looking for: ";
                cin >> n; 
                loading();
                if(!find_book_by_ID(root, n)){
                    cout << "This book doesn't exist in the library." << endl; 
                    Sleep(1500);
                }else{
                    display_book_info(find_book_by_ID(root, n)->book);
                    Sleep(1500);
                }
                break;
            }case 4: {
                system("cls");
                string t;
                cout << "Please enter the title of the book you are looking for: ";
                cin >> t;
                loading();
                if(!find_book_by_title(root, t))
                    cout << "This book doesn't exist in the library." << endl;
                Sleep(1500);
                break;
            }case 5: {
                system("cls");
                int m;
                cout << "Enter the ID of the book you are looking for: ";
                cin >> m;
                loading();
                if(book_exists(root, m))
                    cout << "This book is available" << endl;
                else
                    cout << "This book is not available" << endl;
                Sleep(1500);
                break;
            }case 6: { system("cls"); loading(); display_books_alphabetically(root); Sleep(1500); break;
            }case 7: { system("cls"); borrow_book(root, head); Sleep(1500); break;
            }case 8: { system("cls"); loading(); display_borrowed_books(root, head); Sleep(1500); break;
            }case 9: { system("cls"); return_book(root, head); Sleep(1500); break;
            }case 10: {system("cls"); borrowed_by_student(root, head); Sleep(1500); break;
            }case 11: {system("cls"); display_books_not_returned(root, head); Sleep(1500); break;
            }case 12: {cout << "See you later. "; Sleep(1500); running = false; system("cls"); break;
            }default: cout << "Please enter a valid number. "; Sleep(2000); system("cls");
        }
    }
}