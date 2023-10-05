#include<iostream>
#include<vector>

template<typename T> class VectorStack{
    std::vector<T> stack;
    public:
        void push(T v) { 
            stack.push_back(v); 
        }
        void pop(){
            stack.pop_back();
        }
        void display(){
            for(int i= stack.size()-1; i>0;i--){
                std::cout<<stack[i]<<std::endl;
            }
        }
        void top(){
            std::cout<<stack[stack.size()-1]<<std::endl;
        }
};

int main(){
    VectorStack<int> v1;
    v1.push(23);
    v1.push(32);
    v1.push(45);
    v1.push(56);
    v1.display();

    return 0;
}