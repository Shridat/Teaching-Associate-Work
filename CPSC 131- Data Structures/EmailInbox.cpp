#include<iostream>
#include<string>
#include<vector>
class Email{
    std::string sender;
    std::string subject;
    std::string message;
    public:
        Email(std::string n,std::string sub,std::string msg){
            sender = n;
            subject = sub;
            message = msg;
        }
        std::string getSender(){
            return sender;
        }
        std::string getSubject(){
            return subject;
        }
        std::string getMessage(){
            return message;
        }
};
class EmailInbox{
    std::vector<Email> Inbox;
    public:
        void addToInbox(Email &obj){
            Inbox.push_back(obj);
        }
        void displayInbox(){
            std::cout <<"Inbox"<<"{"<<Inbox.size()<<"}"<<std::endl;
            std::cout<<"===================================="<<std::endl;
            for(int i = Inbox.size()-1; i>=0;i--){
                std::cout<<Inbox[i].getSender()<<std::endl;
                std::cout<<Inbox[i].getSubject()<<std::endl;
                std::cout<<Inbox[i].getMessage()<<std::endl;
            }
            std::cout<<"---------------------------------------------------------------------"<<std::endl;
        }

};
int main(){
    Email e1("Nolan","About Today's Class","Hi professor, Can you share the slides.Thank you");
    EmailInbox I1;
    I1.addToInbox(e1);
    Email e2("Raj","About Today's Class","Hi professor, Do we have class today?");
    I1.addToInbox(e2);
    I1.displayInbox();
    EmailInbox I2;
    Email e3("Gabby","About Quiz","Hi professor there is mistake in quiz. I have attached a screenshot. Thank you!");
    I2.addToInbox(e3);
    I2.displayInbox();
}