#include<iostream>
#include<memory>
#include<vector>
#include<string>

template<typename T> class Tab{
    public:
        std::string url;
        std::string name;
        T memory;
        std::shared_ptr<Tab<T>> next;
        std::shared_ptr<Tab<T>> prev;
};

template<typename T> class Browser{
    public:
        int  max_memory = 800;   
        std::shared_ptr<Tab<T>> head;
        std::shared_ptr<Tab<T>> tail;
        std::shared_ptr<Tab<T>> current_tab;
        std::vector<std::pair<std::string,std::string>> bookmarks;
        void addNewTab(std::string u, std::string n, T m){
            auto new_tab = std::make_shared<Tab<T>>();
            new_tab->url = u;
            new_tab->name = n;
            new_tab->memory = m;
            if(head==nullptr){
                new_tab->next = nullptr;
                new_tab->prev = nullptr;
                head = new_tab;
                tail = new_tab;
            }
            else{
                new_tab->next = nullptr;
                new_tab->prev = tail;
                tail->next = new_tab;
                tail = new_tab;
            }
            current_tab = new_tab;
        }
        void switchToPrevTab(){
            if(current_tab && current_tab->prev){
                current_tab = current_tab->prev;
                std::cout<<current_tab->url<<std::endl;
                std::cout<<current_tab->name<<std::endl;
                std::cout<<current_tab->memory<<std::endl;
            }
            else{
                std::cout<<"No previuous tab"<<std::endl;
            }
            std::cout<<std::endl;
        }
        void switchToNextTab(){
            if(current_tab && current_tab->next){
                current_tab = current_tab->next;
                std::cout<<current_tab->url<<std::endl;
                std::cout<<current_tab->name<<std::endl;
                std::cout<<current_tab->memory<<std::endl;
            }
            else{
                std::cout<<"No next tab"<<std::endl;
            }
            std::cout<<std::endl;
        }
        void closeCurrentTab(){
            if(current_tab){
                auto prev_tab = current_tab->prev;
                auto next_tab = current_tab->next;
                if(prev_tab){
                    prev_tab->next = next_tab;
                }
                if(next_tab){
                    next_tab->prev = prev_tab;
                }
                if(!prev_tab){
                    head = head->next;
                    head->prev = nullptr;
                }
                if(!next_tab){
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                current_tab = prev_tab ? prev_tab : next_tab;
                std::cout<<"Now current tab is= "<<current_tab->name<<std::endl;
            }

        }
        void bookmarkCurrent(){
            if(current_tab){
                bool flag = false;
                for(int i=0;i<bookmarks.size();i++){
                    if(bookmarks[i].first==current_tab->name){
                        flag = true;
                    }
                }
                if(!flag){
                    bookmarks.push_back(std::make_pair(current_tab->name,current_tab->url));
                }
            }
        }
        void showBookmarkTab(){
            std::cout<<"Bookmarks : "<<std::endl;
            for(int i=0;i<bookmarks.size();i++){
                std::cout<<bookmarks[i].first<<"("<<bookmarks[i].second<<")"<<std::endl;
            }
        }
        void moveCurrentToFirst(){
            if(current_tab && current_tab!=head){
                current_tab->prev->next = current_tab->next;
                if(current_tab->next){
                    current_tab->next->prev = current_tab->prev;
                }
                if(current_tab==tail){
                    tail = current_tab->prev;
                }
                current_tab->next = head;
                current_tab->prev = nullptr;
                current_tab->next->prev = current_tab;
                head = current_tab;
                //std::cout<<"The current tab moved to front"<<std::endl;
            }
        }
        void deleteTab(){
            std::shared_ptr<Tab<T>> max_prev = nullptr;
            std::shared_ptr<Tab<T>> max_node = head;
            T max_val = head->memory;
            auto curr = head->next;
            auto prev = head; 
            while(curr){
                if(curr->memory>max_val){
                    max_val = curr->memory;
                    max_prev = prev;
                    max_node = curr;   

                }
                prev = curr;
                curr = curr->next;
            }
            if(max_prev){
                max_prev->next = max_node->next;
            }
            else{
                head = head->next;
                if(head){
                    head->prev =nullptr;
                }
            }
            if(max_node->next){
                max_node->next->prev = max_prev;
            }
            else{
                tail = tail->prev;
                if(tail){
                    tail->next = nullptr;
                }
            }
            std::cout<<"Deleted element = "<<max_node->name<<"with memory size = "<<max_node->memory<<std::endl;

        }
        T total_memory(){
            T consumption = 0;
            auto itr = head;
            while(itr){
                consumption += itr->memory;
                itr = itr->next;
            }
            return consumption;
        }
        void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
        
};
int main(){
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    b1.total_memory();
    b1.deleteTab();
    b1.display();
    return 0;
}