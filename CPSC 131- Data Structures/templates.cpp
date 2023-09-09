#include<iostream>
//functional templates
template<typename T> T max(T a, T b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
//class templates
template<typename T> class vector{
    int size;
    public:
        T *vect;
        vector(int m){
            size = m;
            vect = new T[size];
        }
        T dotproduct(vector &obj){
            T d = 0;
            for(int i = 0; i < size;i++){
                d+= this->vect[i]*obj.vect[i];
            }
            return d;
        }
        void display(){
            for(int i=0; i<size; i++){
                std::cout<<vect[i]<<std::endl;
            }
        }
};
int main(){
    /*
    std::cout<<"The maximum between two numbers = "<<max(4,6)<<std::endl;
    std::cout<<"The maximum between two numbers = "<<max(4.2,3.6)<<std::endl;
    std::cout<<"The maximum between two numbers = "<<max(4.2324242,6.34924924);*/
    vector<int> v1(4);
    v1.vect[0] = 2;
    v1.vect[1] = 3;
    v1.vect[2] = 4;
    v1.vect[3] = 5;
    vector<int> v2(4);
    v1.display();
    v2.vect[0] = 3;
    v2.vect[1] = 4;
    v2.vect[2] = 5;
    v2.vect[3] = 6;
    v2.display();
    std::cout<<"The dot product = "<<v1.dotproduct(v2)<<std::endl;
    return 0;
}