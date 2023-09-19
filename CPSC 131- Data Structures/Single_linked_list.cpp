#include<iostream>
#include<memory>

template<typename T> class Node{
    public:
        T data;
        std::shared_ptr<Node<T>>next;
};
template<typename T> class LinkedList{
    public:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
        void PushFront(T d){
            auto new_node = std::make_shared<Node<T>>();
            if(head==nullptr){
                new_node->data = d;
                new_node->next = nullptr;
                head = new_node;
                tail = new_node;
            }
            else{
                new_node->data = d;
                new_node->next = head;
                head = new_node;
            }
        }                                   // Time Complexity = O(1)
        void PushBack(T d){
            std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(); // You can just declare it as normal pointers 
            //auto new_node = std::make_shared<Node<T>>(); you can use auto to store it in register or RAM for faster access and to reuse the declarations
            if(head==nullptr){
                new_node->data = d;
                new_node->next = nullptr;
                head = new_node;
                tail = new_node;
            }
            else{
                new_node->data =d;
                new_node->next = nullptr;
                tail->next = new_node;
                tail = new_node;
            }
        }                               // Time Complexity = O(1)

        void PopFront() {
            std::shared_ptr<Node<T>> temp;
            if(head==nullptr){
                throw "Linked List is empty";
            }
            else if(head==tail){
                temp = head;
                head = nullptr;
                tail = nullptr;
            }
            else{
                temp = head;
                head = head->next;
                std::cout<<"Deleted Element is = "<<temp->data<<std::endl;
            }
        }
        void PopBack(){
            std::shared_ptr<Node<T>> prev = head;
            std::shared_ptr<Node<T>> temp;
            if(head==nullptr){
                throw "Array is empty";
            }
            else if(head==tail){
                temp = head;
                head = nullptr;
                tail = nullptr;
            }
            else{
            while(prev->next!=tail)
            prev = prev->next;
            temp = prev->next;
            prev->next = nullptr;
            std::cout<<"Deleted element = "<<temp->data<<std::endl;
            }
        }                                               // Time Complexity = O(n)
        void display(){
            std::shared_ptr<Node<T>> curr = head;
            while(curr!=nullptr){
                std::cout<<curr->data<<"->";
                curr = curr->next;
            }
            std::cout<<"Null";
            std::cout<<std::endl;
            //std::cout<<nullptr<<std::endl;
        }                                               // Time Complexity = O(n)
};
int main(){
    LinkedList<int> l1;
    l1.PushFront(23);
    l1.display();
    l1.PushFront(24);
    l1.display();
    l1.PushFront(25);
    l1.display();
    l1.PushBack(12);
    l1.display();
    l1.PushBack(13);
    l1.display();
    l1.PopFront();
    l1.display();
    l1.PopBack();
    l1.display();
    LinkedList<int> l2;
    // Whenever you use Pop function and linked list is empty you have to use try and catch block
    try{
        l2.PopFront();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    l2.display();
    l2.PushFront(90);
    l2.PushFront(91);
    l2.PushBack(88);
    l2.PushBack(87);
    l2.display();
    l2.PopBack();
    l2.PopFront();
    l2.display();
    return 0;
}