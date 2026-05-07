class Node{
  public:
  int data;
  Node* next;
};
class CustomLinkedList{
  Node* head;
  public:
  CustomLinkedList(){
    head=NULL;
  }

  int sizze(){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
      count++;
      temp=temp->next;
    }
    return count;
  }

  void Show(){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
  }
  bool empty(){
    if(head==NULL)
    return true;
    return false;
  }
  void clear(){
     Node* temp=head;
     while(temp!=NULL){
       Node* nextt=temp->next;
       delete temp;
       temp=nextt;
     }
     head=NULL;
     }

     void addfirst(int item){
       Node* newnode=new Node();
       newnode->data=item;
       newnode->next=head;
       head=newnode;
     }
     void addlast(int item){
        Node* newnode=new Node();
       newnode->data=item;
       if(head == NULL){
    head = newnode;
     newnode->next=NULL;
    return;
}
       Node* temp=head;
       while(temp->next!=NULL){
         temp=temp->next;
       }
       temp->next=newnode;
       newnode->next=NULL;
     }

  void addin(int item,int pos){
      if(pos==0){
    addfirst(item);
      return;
    }
       Node* newnode=new Node();
       newnode->data=item;
    Node* temp=head;
    int index=0;
    while(index<pos-1&&temp!=NULL){
      index++;
      temp=temp->next;
    }
      if(temp == NULL){
        cout << "Position out of range\n";
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  }
  void removeFirst(){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void removeLast(){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }
    if(head->next == NULL){ 
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
  void removeat(int pos){
    if(head==NULL){
      cout<<"List is empty\n";
      return;
    }
  if(pos == 0){
    removeFirst();
    return;
}
    Node* del;
    Node* prev;
    Node* temp=head;
    int index=0;
    while(index<pos&&temp!=NULL){
      prev=temp;
       index++;
      temp=temp->next;
    }
     if(temp == NULL){
        cout << "Position out of range\n";
        return;
    }
    del=temp;
   prev->next=del->next;
    delete del;

  }
  int Search(int key){
    Node* temp = head;
    int index = 0;
    while(temp != NULL){
        if(temp->data == key){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; 
}

};
int main() 
{
    CustomLinkedList list;

    list.addfirst(10);
    list.addfirst(5);

    list.addlast(20);
    list.addlast(30);
    list.addin(15, 2);
    cout << "List: ";
    list.Show();
    list.removeFirst();
    cout << "After removeFirst: ";
    list.Show();

    list.removeLast();
    cout << "After removeLast: ";
    list.Show();

    list.removeat(1);
    cout << "After removeAt(1): ";
    list.Show();
    cout << "Search 20: " << list.Search(20) << endl;
    cout << "Search 100: " << list.Search(100) << endl;

    cout << "Size: " << list.sizze() << endl;
    list.clear();
    cout << "After clear: ";
    list.Show();
    return 0;
}
