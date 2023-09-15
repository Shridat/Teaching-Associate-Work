#include <iostream>
#include<array>
#include<vector>
//Item class has three fields name, price, quantity
class Item{
    std::string name;
    double price;
    int quantity;
    public:
        Item(){
            name = "";
            price = 0.0;
        }
        Item(std::string n, double p, int q){
            name = n;
            price = p;
            quantity = q;
        }
        std::string getname(){
            return name;
        }
        double getprice(){
            return price;
        }
        int getquantity(){
            return quantity;
        }
};
const int max_size=5;
class ShoppingCart{
    public:
        std::string name;
        std::vector<Item> cart;
        ShoppingCart(std::string n){
            name = n;
        }
        //function to add item in a cart
        void addToCart(std::string name, double price, int quant){
            if(cart.size()<max_size){
                cart.push_back(Item(name, price,quant));
            }
        else{
                std::cout<<"Cart is full!!"<<std::endl;
            }
            
        }
        // function to display cart
        void showCart(){
            std::cout<<"User "<<this->name<<std::endl;
            std::cout<<"<----Shopping Cart---->"<<std::endl;
            std::cout<<"Item name "<<"  "<<"Price "<<"  "<<"Quantity "<<std::endl;
            for(int i=0;i<cart.size();i++){
                std::cout<<cart[i].getname()<<"  "<<cart[i].getprice()<<"  "<<cart[i].getquantity()<<std::endl;
            }
            std::cout<<"--------------------------------"<<std::endl;
        }
        //function for checkout
        /*void checkoutCart(){

        }*/
};
int main(){
    //created first user
    ShoppingCart s1("Danny");
    s1.addToCart("Soap",4.5,2);
    s1.addToCart("Milk",3.49,2);
    s1.addToCart("Bread",1.99,1);
    s1.showCart();
    //created second user
    ShoppingCart s2("Chis");
    s2.addToCart("Milk",3.49,1);
    s2.addToCart("Cerels",5.29,2);
    s2.showCart();
}