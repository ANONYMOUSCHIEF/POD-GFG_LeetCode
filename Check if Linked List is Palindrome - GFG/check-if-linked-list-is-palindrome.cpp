//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(!head->next)
        return true;
        Node * temp=head;
        int count=0;
        while(temp){
            count+=1;
            temp=temp->next;
        }
        temp=head;
        Node * prev=NULL;
        Node * forw=temp->next;
        Node * curr=temp;
        int mid=count/2;
        while(mid--){
            curr->next=prev;
            prev=curr;
            curr=forw;
            forw=forw->next;
        }
        // cout<<prev->data<<" "<<curr->data<<" "<<forw->data<<endl;
        
        if(count%2==0){
            while(curr && prev){
                if(curr->data!=prev->data)
                return false;
                curr=curr->next;
                prev=prev->next;
            }
        }
        else{
            while(prev && forw){
                if(prev->data!=forw->data)
                return false;
                prev=prev->next;
                forw=forw->next;
            }
        }
        return true;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends