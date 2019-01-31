#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class nodeTrie{
    public:
        unordered_map<char,nodeTrie*> children;
        int weight;
        nodeTrie(){
            this->weight = 0;
        }
};

class Trie{
    public:
        nodeTrie* head;
        Trie();
        ~Trie();
        void insert(const char* c);
        int search(const char* c);
        void print();       
};

Trie::Trie(){
    this->head = nullptr;
}

Trie::~Trie(){
    // implement destructor after
}

void Trie::insert(const char* str){
    if (this->head == nullptr)
        this->head = new nodeTrie();
    // start from the root node
    nodeTrie* current = this->head;
    while(*str){
        //create a new node if path doesn`t exists
        if(current->children.find(*str) == current->children.end())
            current->children[*str] = new nodeTrie();          
        //Update the current with the next child
        current = current->children[*str];
        current->weight++;
        //move to the next character
        str++;
    }
    //current->isLeaf = true;
}

int Trie::search(const char* str){
    // return false if Trie is empty
    if(this->head == nullptr)
        return 0;
    nodeTrie* current = this->head;
    while(*str){
        current = current->children[*str];
        // return false if Trie is empty
        if(current == nullptr)
            return 0;
        str++;
    }
    //if we reach the end of the string and could found all the letters, return the weight of the last node.
    return current->weight;
}

class nodeList{
    public:
        nodeList* next;
        char data;
    nodeList(){
        this->next = nullptr;
    }
};

class List{
    public:
        nodeList* head;
        unordered_map<char,bool> info;
    List(){
        this->head = 0;
    };
    ~List(){
        //implement destructor
    };
    void update(char c);
    int search (char c);
    void insert(char c);
    void print();

};

void List::insert(char c){
    nodeList* node = new nodeList();
    node->data = c;
    node->next = this->head;
    this->head = node;
    this->info[c] = true;
}

int List::search(char c){
    nodeList* node = new nodeList();
    node = this->head;
    int index = 0;
    if (this->info.find(c) == this->info.end())
        return -1;
    else{
        while(node){
            if(node->data == c)
                return index;
            else{
                node = node->next;
                index++;
            }
        }
        
    }
    return index;
}

void List::update(char c){
    nodeList* node = new nodeList();
    nodeList* aux = new nodeList();
    int i = 0;
    bool done = false;
    node = this->head;
    if (this->info.find(c) == this->info.end())
        return;
    else if (node->data == c){
        return;
    }else{
        while(node && !done){
            aux = node;
            node = aux->next;
            if (node->data == c){
                aux->next = node->next;
                node->next = this->head;
                this->head = node;
                done = true;
            }
        }
    }
}

void List::print(){
    nodeList* node = this->head;
    int i = 1;
    while(node){
        cout << i << ": " << node->data << "\n";
        node = node->next;
        i++;        
    }
    
}

void processText (char* &result, Trie* &head, const char* str , int cap){
    
} 

void testList(List* & list, const char* str){
    while(*str){
        cout << list->search(*str) << ", ";
        list->update(*str);
        str++;
        /* code */
    }    
    cout << endl;
}
int main(int argc, char *argv[] ){
    
    List* list = new List();
    for(int i = 127; i >= 0 ; i--){
        list->insert(char(i));
    }
    //list->print();
    testList(list,"aababcaba");
    //list->print();
    /*Trie* trie = new Trie();
    trie->insert("Saulo");
    trie->insert("Saulo");
    trie->insert("muskan");
    cout << trie->search("Saulo") <<"\n";
    cout << trie->search("saul") << "\n";
    cout << trie->search("musk") << "\n";
    cout << trie->search("muskan") << "\n";
    cout << trie->search("muske") << "\n";
    */
    
    return 0;
}
