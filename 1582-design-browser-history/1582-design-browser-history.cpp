class Node {
public:
    string data;
    Node *prev;
    Node *next;

    Node(string value){
        data = value;
        prev=nullptr;
        next=nullptr;
    }
};

class BrowserHistory {
public:
    //double linked list would be best
    Node *head = nullptr;
    Node *curr = nullptr;
    BrowserHistory(string homepage) {
        Node *newnode = new Node(homepage);
        head = newnode;
        curr=head;
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev=curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i++){
            if(curr==head) break;
            curr=curr->prev;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i++){
            if(curr->next==nullptr) break;
            curr=curr->next;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */