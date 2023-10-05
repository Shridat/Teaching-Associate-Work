#include <iostream>
#include<memory>
template<typename T> class Node{
    public:
        T data;
        std::shared_ptr<Node<T>> next;
};
template<typename T> class LinkedStack{
        public: 
            std::shared_ptr<Node<T>> head;
            void PushFront(T d){
                auto new_node = std::make_shared<Node<T>>();
                if(head==nullptr){
                    new_node->data = d;
                    new_node->next = nullptr;
                    head = new_node;
                }
                else{
                    new_node->data=d;
                    new_node->next = head;
                    head = new_node;
                }
            }
            int size(){
                auto curr = head;
                int count = 0;
                while(curr){
                    curr = curr->next;
                    count++;
                }
                return count;
            }
            void PopFront(){
                std::shared_ptr<Node<T>> temp;
                if(head==nullptr){
                    throw "Stack Underflow";
                }
                else if(this->size()==1){
                    temp = head;
                    head = nullptr;
                    std::cout<<"The element Poped = "<<temp->data<<std::endl;
                }
                else{
                    temp = head;
                    head = head->next;
                    std::cout<<"The element Poped = "<<temp->data<<std::endl;
                }
            }
};
int main() {
    // Write C++ code here
    LinkedStack<int> l1;
    l1.PushFront(10);
    l1.PushFront(20);
    l1.PushFront(30);
    std::cout<<l1.size()<<std::endl;
    l1.PopFront();
    l1.PopFront();
    std::cout<<"size of linked stack = "<<l1.size()<<std::endl;
    l1.PopFront();
    std::cout<<"size of linked stack = "<<l1.size()<<std::endl;
    try{
        l1.PopFront();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    return 0;
}
