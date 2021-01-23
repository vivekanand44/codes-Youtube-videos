#include<bits/stdc++.h>
using namespace std;
class Node
    {
        public:
            int data;
            int count;
            Node *left;
            Node *right;
    };

void printBinaryTree(Node* p)
{
    
    if(p)
    {
        printBinaryTree(p->left);
        cout << "\t" << p->data << " count = " << p->count;
        printBinaryTree(p->right);
    }

}

int majorityElement(int a[], int size)
{    
    Node* p =NULL; 
    Node* q =NULL;
    Node *head;    
    
    q = new Node();
    q->left=NULL;
    q->right=NULL;
    q->data=a[0];
    q->count=1;

    head = q;
    int flag = 0;
    for(int i=1;i<size;i++)
    {
        p = head;
        // cout<< "head = " << head->data; 
        // cout << "\n" << a[i];        
        int value = a[i];
        while(true)
        {
            if(p->data == value)
            {
                int cnt = p->count;
                cnt = cnt + 1;
                if (cnt > (size/2))
                    {
                        cout << a[i];
                        flag = 1;
                        break;
                    }
                p->count = cnt;
                break;
            }
            else if(value < p->data)
            {
                if(p->left)
                    p = p->left;
                else
                {
                    /* code */
                    Node *new_node = new Node();
                    new_node->left = NULL;
                    new_node->right = NULL;
                    new_node->data = value;
                    new_node->count= 1; 
                    p->left=new_node;
                    break;
                }
                                        
            }
            else if(value > p->data)
            {
                if(p->right)
                    p = p->right;
                else
                {
                    /* code */
                    
                    Node *new_node = new Node();
                    new_node->left = NULL;
                    new_node->right = NULL;
                    new_node->data = value;
                    new_node->count= 1;
                    p->right=new_node;
                    break;
                }
                
                     
            }
        }

        if (flag == 1)
            break;
    }

    // printBinaryTree(head);
    
    // your code here
    return 0;
}

int main()
{
int arr[]={3,1,3,3,2};

majorityElement(arr , 5);

}