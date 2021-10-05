# include <stdio.h>
# include <malloc.h>
# include <iostream>

typedef struct qnode
{
   int data;//Medical record number
   struct qnode * next; //The next node pointer
} QNode; //Chain node type 
typedef struct
{
	QNode *front,*rear;//First node and last node pointer
} QuType; //Declare the chain team type

void Destroyqueue(QuType * &qu) //Release the chain team
{
	QNode *pre,*p;
    pre=qu->front;
    if (pre!=NULL) //If the chain team is not empty
	{
        p=pre->next;
        while(p!=NULL)//Release all data nodes in the queue
		{
           free(pre);
		   pre=p;
		   p=p->next;
		}
        free(pre);
	}
    free(qu); //Release the chain node
}

bool exist(QuType *qu,int no) //Determine whether there is a patient with no medical record number in the queue 
{
	bool find =false;
	QNode *p=qu->front;
    while(p!= NULL&&!find)
    {
    	if(p->data==no) find=true;
    	else p=p->next;
    }
    return find;
}

void SeeDoctor()//Simulate the process of seeing a patient
{
	int sel,no;
    bool flag=true;//The initial value is set to true
    QuType *qu;//Chain node pointer variable
    QNode *p;//Chain node type variable
    qu=(QuType *)malloc(sizeof(QuType)); //Create empty team
    qu->front=qu->rear=NULL;
    while(flag) //Loop execution
    {
    	printf("1: Queuing 2: Seeing a doctor 3: Checking the queuing 4:Queue sequence 5: Off duty Please select:"); 
    	scanf("%d",&sel);//Read the number 
    	switch(sel)
    	{
	    	case 1://If it reads "1"Then line up
			        printf("Enter medical record number:");
					while(true)
					{
						scanf("%d",&no);//Read medical record number 
						if(exist(qu,no))//Judgment 
						     printf("The entered medical record number is repeated, re-enter:");
                        else break;// jump out 
					}
					p=(QNode *)malloc( sizeof(QNode));//Create node
					p->data=no;//Store medical record number 
					p->next=NULL;
				    if(qu->rear==NULL) //The first patient lined up
                        qu->front=qu->rear=p;
                    else
                    {
                    	qu->rear->next=p;
                        qu->rear=p; //P node into the team
                    }
                    break;
            case 2:
                   if(qu->front==NULL)//The team is empty
                       printf("There are no patients in line!\n");
                   else //The team is not empty
                   {
                   	   p=qu->front;
                   	   printf("Patient %d visits a doctor\n",p->data);
                   	   if (qu->rear==p) //Only one patient lined up
						   qu->front=qu->rear=NULL;
					   else
					       qu->front=p->next;
	                   free(p);
	                   break;
                   }
            case 3:
                   if (qu->front==NULL) //View the queue
                        printf("There are no patients in line!\n");// Team is empty
                   else //The team is not empty
                   {
                   	   p=qu->front;
			           printf("Queue patients:");
			           while(p!=NULL)
			           {
           				  printf("%d  ",p->data);
           				  p=p->next;
   			           }
   			           printf("\n");
                   }
                   break;
            case 4: //No more queues			 
                   if (qu->front==NULL) //The team is empty
                        printf("There are no patients in line!\n");
                   else //The team is not empty
                   {
                   	   p=qu->front;
                   	   printf("Patients are treated in the following order:");
                   	   while(p!=NULL)
                   	   {
   	                   	   printf("%d  ",p->data);
   	                   	   p=p->next;
   	                   }
   	                   printf("\n");
                   }
                   Destroyqueue(qu);//Release the chain team 
                   flag=false; //drop out  
                   break;
               case 5: //Off work  
                      if (qu->front!=NULL) //team
                           printf("Patients in line, please see a doctor tomorrow!\n");
                      flag=false; //Retire
                      Destroyqueue(qu); //release
                      break;   
			   default:printf("Please choose the correct serial number!\n");break;   
             }
     }
}
int main()
{
	SeeDoctor();
	return 1;
}
