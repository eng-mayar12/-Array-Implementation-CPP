

#include <iostream>
using namespace std;
class MyArray{
    
    public:
    int *arr;
    int length=0;
    int size;
    MyArray(int EnteredSize){
        size=EnteredSize;
        arr=new int[size];
    };
    bool IsEmpty(){
      return length==0;
    }
    int count(){
        return length;
    }
    void clear(){
        delete[] arr;
         arr=new int[size];
        length=0;
    }
    void show(){
      
        if(length==0)
        return;
          for(int i=0;i<length;i++){
          cout<<arr[i]<<" ";
        }
    }
    void AddFirst(int element){
        if(length==0){
            AddLast(element);
            return;
        }
        if(length==size){
            cout<<"Array is Full"<<endl;
            return;
        }  
        for(int i = length; i >= 1; i-- ){
            arr[i]=arr[i-1];
        }
        arr[0]=element;
        length++;
    }
    
    void AddLast(int element){
          if(length==size){
            cout<<"Array is Full"<<endl;
            return;
        }  
        arr[length++]=element;
    }
    void AddIndex(int element,int index){
          if(length==size){
            cout<<"Array is Full"<<endl;
            return;
        } 
          for(int i = length; i >= index; i-- ){
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        length++;
    }
    void RemoveFirst(){
        if(length==0){
            cout<<"Array is Empty"<<endl;
            return;
        }
        for(int i=0;i<length-1;i++){
            arr[i]=arr[i+1];
        }
        length--;
    }
      void RemoveLast(){
        if(length==0){
            cout<<"Array is Empty"<<endl;
            return;
        }
          arr[length - 1] = 0;
          length--;
      }
    
    void RemoveAt(int index){
        if(length==0){
            cout<<"Array is Empty"<<endl;
            return;
        }
        for(int i=index;i<length;i++){
            arr[i]=arr[i+1];
        }
        length--;
    }
    void SelectionSort(){
        
        int min,index;
        for(int i=0;i<length;i++){
             min=arr[i];
             index=i;
             for(int j=i+1;j<length;j++){
                 if(arr[j]<min){
                     min=arr[j];
                     index=j;
                     }
                     arr[index]=arr[i];
                     arr[i]=min;
                 }
             
            }
        }
    
        
        void InsertionSort(){
            int j,temp;
            for(int i=1;i<length;i++){
                temp=arr[i];
                j=i;
                while(j>0&&arr[j-1]>temp){
                    arr[j]=arr[j-1];
                    j--;
                    }
                arr[j]=temp;
                
                }
            }
            
            
};
int main() {
    MyArray arr(10);


    arr.AddLast(5);
    arr.AddLast(3);
    arr.AddLast(8);
    arr.AddLast(1);
    arr.AddLast(7);

    cout << "After AddLast: ";
    arr.show(); cout << endl;


    arr.AddFirst(10);
    cout << "After AddFirst(10): ";
    arr.show(); cout << endl;


    arr.AddIndex(99, 2);
    cout << "After AddIndex(99, 2): ";
    arr.show(); cout << endl;


    arr.RemoveFirst();
    cout << "After RemoveFirst: ";
    arr.show(); cout << endl;


    arr.RemoveLast();
    cout << "After RemoveLast: ";
    arr.show(); cout << endl;


    arr.RemoveAt(1);
    cout << "After RemoveAt(1): ";
    arr.show(); cout << endl;

    arr.SelectionSort();
    cout << "After SelectionSort: ";
    arr.show(); cout << endl;


    arr.AddLast(2);
    arr.AddLast(9);
    arr.InsertionSort();
    cout << "After InsertionSort: ";
    arr.show(); cout << endl;

    cout << "Count: " << arr.count() << endl;

 if(arr.IsEmpty())
    cout << "IsEmpty: " <<endl;
 else 
  cout << "NotEmpty: " <<endl;
    
    arr.clear();
    cout << "After Clear - IsEmpty: " << arr.IsEmpty() << endl;
     if(arr.IsEmpty())
    cout << "IsEmpty: " <<endl;
 else 
  cout << "NotEmpty: " <<endl;

    return 0;
}
