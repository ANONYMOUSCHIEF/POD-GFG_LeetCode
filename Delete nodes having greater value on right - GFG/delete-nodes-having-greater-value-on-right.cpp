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
    
    Node* reverse(Node *head){
        Node * prev=NULL;
        Node * forw=head->next;
        while(head){
            forw=head->next;
            head->next=prev;
            prev=head;
            head=forw;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        if(!head || !head->next) return head;
        head=reverse(head);
        Node * ans=new Node(head->data);
        Node * ans2=ans;
        head=head->next;
        while(head){
            if(ans->data <= head->data){
               ans->next=new Node(head->data);
               ans=ans->next;
            }
            head=head->next;
        }
         ans2=reverse(ans2);
         return ans2;
        
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