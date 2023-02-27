//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/



class Solution
{
public:
   Node* reverse(Node* head)
   {
       Node* curr=head;
       Node* prev=NULL;
       Node* nxt;
       
       while(curr!=NULL)
       {
           nxt=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nxt;
       }
       
       return prev;
   }
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* temp=head;
        for(int i=0;i<k-1; i++)
        {
            temp=temp->next;
        }
        
        Node* secondHead=reverse(temp->next);
        temp->next=NULL;
        Node* firstHead=reverse(head);
        
        temp=firstHead;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=secondHead;
        
        return firstHead;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends