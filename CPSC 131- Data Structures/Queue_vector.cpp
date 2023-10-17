#include<iostream>
#include<vector>

template<typename T> class Queue{
    public:
        std::vector<T> queue;
        bool isEmpty(){
            if(queue.size()){
                return false;    
            }
            return true;

        }
        void Insert(T ele){
            queue.push_back(ele);
        }
        void Delete(){
            if (!queue.empty())
            {
                queue.erase(queue.begin());               
            }
            else{
                throw "Queue is empty!";
            }
        }
        void Front() {
            if(!queue.empty()){
                std::cout<<"Front element = "<<queue.front()<<std::endl;
            }
            else{
                throw "Queue is empty!";
            }

        }
        void display(){
            std::cout<<"The elements of queue = "<<std::endl;
            for(int i=0; i<queue.size();i++){
                std::cout<<queue[i]<<" ";
            }
            std::cout<<std::endl;
        }
};
int main(){
    Queue<int> q1;
    q1.Insert(1);
    q1.Insert(2);
    q1.Insert(3);
    q1.display();
    try{
        q1.Front();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        q1.Delete();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    q1.display();
    try{
        q1.Front();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        q1.Delete();
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    q1.display();
    return 0;
}