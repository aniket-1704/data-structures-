 #include <stdio.h>
    #include <stdlib.h>
    struct node
    {
        int data;
        struct node* next;
        struct node* prev;
    };
    struct node* head;//global variable declaration
    struct node* getnewnode(int x)
    {
        struct node* t;
        t=(struct node*)(malloc(sizeof(struct node)));
        t->data=x;
        t->next=NULL;
        t->prev=NULL;
        return t;
    }
    void insertatbeg(int x)//insertion at beggining
    {
        struct node* t=getnewnode(x);
        if(head!=NULL)
        {
        t->next=head;
        head->prev=t;
        }
        head=t;
    }
    void insertatend(int x)
    {
        struct node* t=getnewnode(x);
        if(head==NULL)
        {
            head=t;
        }
        else
        {
            struct node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=t;
            t->prev=t;
        }

    }
    void insertatpos(int pos,int x)
    {
        struct node* t=getnewnode(x);
        if(pos==1)
        {
            insertatbeg(x);
        }
        else
        {
           int c=1;
           struct node* temp=head;
           while(c!=pos-1)
           {
               temp=temp->next;
               c++;
           }
           t->next=temp->next;
           temp->next->prev=t;
           temp->next=t;
           t->prev=temp;
        }   

    }
    void deleteatstart()
    {
        if(head==NULL)
        {
            printf("list empty\n");
        }
        else
        {
            
            struct node* temp=head;
            struct node * temp1=head;
            if(temp->next==NULL)
            {
                free(temp);
                head=NULL;
            }
            else
            {
            temp=temp->next;
            head=temp;
            head->prev=NULL;
            temp1->next=NULL;
            free(temp1);
            }
            
        }       
    }
    void deleteatlast()
    {
        if(head==NULL)
        {
            printf("list empty\n");
        }
        else
        {
             struct node* temp=head;
             if(temp->next==NULL)
             {
                 free(temp);
                 head=NULL;
             }
             else
             {
                 while(temp->next->next!=NULL)
                 {
                     temp=temp->next;
                 }
                 struct node* temp1=temp;
                 temp1=temp1->next;
                 temp->next=NULL;
                 free(temp1);
             }
             
        }   
    }
    void maxmin(struct node* head)
    {
        struct node* temp=head;
        int min=temp->data;
        int max=temp->data;
        while(temp!=NULL)
        {
            if(temp->data>max)
            {
                max=temp->data;
            }
            if(temp->data<min)
            {
                min=temp->data;
            }
            temp=temp->next;
        }
        printf("the smallest element in the list is %d \n",min);
        printf("the largest element in the list is %d \n",max);
    }
    void display()//method to display the list
    {
        struct node* temp;
        temp=head;
        if(temp==NULL)
        {
            printf("list is empty\n");
        }
        else
        {
            while(temp!=NULL)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
       
    }
    int main()
    {
    int ele;
    int n;
    int pos;
        printf("\t 1.insertatbeg \t 2.insertatend \t 3.inser at a pos \t 4. delete at start  \t 5.delete at end \t 6.display \t 7.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insertatbeg(ele);
            break;
        case 2:
             printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insertatend(ele);
            break;
        case 3:
             printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            printf("enter the position u want to insert\n");
            scanf("%d", &pos);
            insertatpos(pos,ele);
            break;
        case 4:
            deleteatstart();
            break;
        case 5:
            deleteatlast();
            break;
        case 6:
            display();
            break;
        }
    } while (n != 7);
    return 0;
    }
