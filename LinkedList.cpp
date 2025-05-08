#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node *next;
    Node(int value){
        this->value=value;
        next=NULL;

    }
};
class LinkedList{
    public:
    Node* head;
    int size;

    LinkedList(){
        head=NULL;
        size=0;

    }
    void insertPrepend(int value){
        Node *newNode=new Node(value);
        newNode->next=head;
        head=newNode;
        size++;
    }
    void UpdateRecords(int index,int element){
        Node*current=head;
        for(int i=0;i<index;i++){
            current=current->next;
        }
        current->value=element;
    }
    void  deleteRecord(int index){
        if (index<0||head==NULL) {
            cout << "Invalid index." << endl;
            
        }
        else if (index==0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully at index "<< endl;
            
        }
    
        Node* current=head;
        for (int i = 0;i<index-1;i++) {
            current=current->next;
        }
        if (current==NULL||current->next == NULL) {
            cout << "Invalid index." << endl;
            
        }
    
        Node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
        cout << "Node deleted successfull at index: " <<  endl;
    }
    void displaySearch() {
        Node* current=head;
        cout<<"Linked List:"; 
        while(current!=NULL) {
            cout << current->value << "  ";
            current = current->next;
        }
        cout << endl;
    }
};
int main(){
    int choice;
    LinkedList list;
    do{
        cout<<"Press 1 For the Insert."<<endl
            <<"Press 2 For the Update."<<endl
            <<"Press 3 For the Delete."<<endl
            <<"Press 4 For the Display."<<endl
            <<"Press 0 For the Exit."<<endl;
        cout<<"Enter the choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int n;
            cout<<"Enter the total elements:";
            cin>>n;
            int value;
            for(int i=0;i<n;i++){
                cout<<"Enter the insert data:";
                cin>>value;
                list.insertPrepend(value);
               
            }
        break;
        case 2:
            int index,element;
            cout<<"Enter the index:";
            cin>>index;
            cout<<"Enter the new Elements:";
            cin>>element;
            list.UpdateRecords(index,element);
            list.displaySearch();
        break;
        case 3:
            int delIndex;
            cout<<"Enter the Index:";
            cin>>delIndex;
            list.deleteRecord(index);
            list.displaySearch();
            break;
            case 4:
                list.displaySearch();
                break;
        case 0:
            cout<<"Exit! the Program."<<endl;
        break;
        default:
            cout<<"Invalid choice."<<endl;
            break;
        }
    }while(choice!=0);
    return 0;
}