//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    int maxi;
    void rec(Node *head){
        if(head->next){
            rec(head->next);
        }
        if(head->data<maxi){
            //remove this node
            head->data=-1;
        }
        else maxi=head->data;
    }
    Node *compute(Node *head)
    {
        maxi = INT_MIN;
        rec(head);
        Node *ptr = head;
        while(ptr->next!=NULL){
            if(ptr->next->data==-1){
                ptr->next=ptr->next->next;
            }
            else ptr=ptr->next;
        }
        
        if(head->data==-1) return head->next;
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends