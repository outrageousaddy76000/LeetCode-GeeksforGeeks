//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set <int> s;
        struct Node *ptr1=head1;
        struct Node *ptr2=head2;
        while(ptr1!=NULL){
            s.insert(ptr1->data);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            s.insert(ptr2->data);
            ptr2=ptr2->next;
        }
        struct Node *ptr=head1;
        int x = s.size();
        for(auto &val:s){
            x--;
            ptr->data=val;
            if(ptr->next==NULL && x!=0){
                struct Node * newnode =new Node(0);
                ptr->next=newnode;
            }
            if(x==0) ptr->next=NULL;
            else ptr=ptr->next;
        }
        return head1;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends