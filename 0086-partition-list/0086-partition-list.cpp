/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// void trimLeftTrailingSpaces(string &input) {
//     input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//         return !isspace(ch);
//     }));
// }

// void trimRightTrailingSpaces(string &input) {
//     input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//         return !isspace(ch);
//     }).base(), input.end());
// }

// vector<int> stringToIntegerVector(string input) {
//     vector<int> output;
//     trimLeftTrailingSpaces(input);
//     trimRightTrailingSpaces(input);
//     input = input.substr(1, input.length() - 2);
//     stringstream ss;
//     ss.str(input);
//     string item;
//     char delim = ',';
//     while (getline(ss, item, delim)) {
//         output.push_back(stoi(item));
//     }
//     return output;
// }

// ListNode* stringToListNode(string input) {
//     // Generate list from the input
//     vector<int> list = stringToIntegerVector(input);

//     // Now convert that list into linked list
//     ListNode* dummyRoot = new ListNode(0);
//     ListNode* ptr = dummyRoot;
//     for(int item : list) {
//         ptr->next = new ListNode(item);
//         ptr = ptr->next;
//     }
//     ptr = dummyRoot->next;
//     delete dummyRoot;
//     return ptr;
// }

// void prettyPrintLinkedList(ListNode* node) {
//   while (node && node->next) {
//       cout << node->val << "->";
//       node = node->next;
//   }

//   if (node) {
//     cout << node->val << endl;
//   } else {
//     cout << "Empty LinkedList" << endl;
//   }
// }

// ListNode* partition(ListNode* head, int x) {
//         if (head == NULL) return head;
        
//         ListNode* smallerHead=new ListNode(); //Head of the list with nodes <x
//         ListNode* smallerTail=smallerHead; //Tail of the list with nodes <x
        
//         ListNode* greaterHead=new ListNode();//Head of the list with nodes >=x
//         ListNode* greaterTail=greaterHead; //Tail of the list with nodes >=x
        
//         ListNode* curr = head;
//         while (curr) {//partition into greater & smaller lists
//             if (curr->val < x) {
//                 smallerTail->next = curr;
//                 smallerTail =smallerTail->next;
//                 cout<<curr->val<<"<"<<x<<":smaller\n";
                
//             } 
//             else {
//                 greaterTail->next = curr;
//                 greaterTail=greaterTail->next;
//                 cout<<curr->val<<">="<<x<<": greater\n";
                
//             }
//             cout<<"smaller:"; prettyPrintLinkedList(smallerHead);
//             cout<<"greater:"; prettyPrintLinkedList(greaterHead);
//             cout<<"-------\n";
//             curr = curr->next;
//         }
        
//         greaterTail->next = NULL; 
//         smallerTail->next = greaterHead->next;//Connect the smaller and the greater lists
        
//         head = smallerHead->next; //Update the head of the list
       
//         return head;
//     }
// int main() 
// {
//     ListNode* head=stringToListNode("[1,4,3,2,5,2]");
//     int x=3;
//     ListNode* ans=partition(head, x);
//     cout<<"ans:\n";
//     prettyPrintLinkedList(ans);
//     return 0;
// }
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller=new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        ListNode* temp=smaller;
        ListNode * temp2=greater;
        
        while(head){
            if(head->val < x){
                smaller->next=head;
                smaller=smaller->next;
          }
            else{
                greater->next=head;
                greater=greater->next;
             }
            head=head->next;
         }
        greater->next=NULL;
        smaller->next=temp2->next;
        return temp->next;
        
    }
};