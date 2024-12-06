#include <iostream>
using namespace std;
class node
{
    friend class doublelinkedlist;
    public:
    int data;
    node* right;
    node* left;
    node (int d)
    {
        data=d;
        right=left=nullptr;
    }
};
class doublelinkedlist
{
    node* first;
    node* last;
    public:
    doublelinkedlist();
    ~doublelinkedlist();
    void add_in_order(node* newnode); // This function get digits of number and storage in ascending order.
    void print();
};
doublelinkedlist::doublelinkedlist()
{
    first=last=nullptr;
}
doublelinkedlist::~doublelinkedlist()
{
    node* temp;
    
    while (first!=nullptr)
    {
        temp=first;
        first=first->right;
        delete temp;
    } 
}
void doublelinkedlist::add_in_order(node* newnode)
{
    if(first==nullptr)   //case 1 : list is empty.
    {
        first=last=newnode;
        return;
    }
    if(newnode->data<=first->data)     // case 2 : newnode data less than data in first.
    {
        newnode->right=first;
        first->left=newnode;
        first=newnode;
    }
    else if(newnode->data>=last->data)       //case 3: newnode data grater than data in last.
    {
        newnode->left=last;
        last->right=newnode;
        last=newnode;
    }
    else  //case 4: newnode data between in first and last nodes. 
    {
        node* ptr=first->right;  //start check from second node.   
        
        while (ptr !=nullptr)
        {
            if(newnode->data <ptr->data)
            {
                newnode->left=ptr->left;
                newnode->right=ptr;
                ptr->left->right=newnode;
                ptr->left=newnode;
                return;
            }
            ptr=ptr->right;

        }
        
    }

}
void doublelinkedlist::print()
{
    if(last==nullptr)
    {
        cout<<"This list is empty."<<endl;
        return;
    }
    node* curptr=last; // start from the end.
    while (curptr!=nullptr)
    {
        cout<<curptr->data;
        curptr=curptr->left;
    }
    cout<<"\n";
}
int main()
{
    doublelinkedlist a;
    long long int n;
    int t;
    do {
    cout << "Enter a non-negative number: ";
    cin >> n;
    } while (n < 0);
    if (n == 0) {
    a.add_in_order(new node(0));
    }
    else{
        while(n!=0)
    {
        t=n%10;
        node*temp=new node(t);
        a.add_in_order(temp);
        n=n/10;
    }
    }
    cout << "The number in descending order: ";
    a.print();
    return 0;
}