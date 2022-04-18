#include<iostream>
using namespace std;

string check(int);
int display1();
int search(int);

struct node{
    node *prev;
    int data;
    int x,y,sum;     //x == quantity
    string name,nam;   //y == price
    node *next;
};

struct node *start=NULL;
node* create_node(){
    node *n = new node;
    cout<<"ENTER PRODUCT ID: "<<endl;
    cin>>n->data;
    cout<<"ENTER PRODUCT NAME: "<<endl;
    cin>>n->name;
    cout<<"ENTER QUANTITY: "<<endl;
    cin>>n->x;
    cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
    cin>>n->y;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insert_node_End(){
    node *temp;
    temp = create_node();
    if(start == NULL){
    start = temp;
    }
    else{
    node *traverse;
    traverse = start;
    while(traverse->next != NULL){
        traverse = traverse->next;
    }
    traverse->next=temp;
    temp->prev=traverse;
}
}

void add_begin(){
node *temp;
if(start==NULL){
	temp = create_node();
	temp->next=NULL;
		temp->prev=NULL;
		start=temp;
}
else{
	temp = create_node();
    temp->next = start;
    start->prev = temp;
    start=temp;
}
    
}


    void display(){
    node *traverse;
    traverse  = start;
    system("cls");
    cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************"<<endl;
    cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
    while(traverse!=NULL){
    cout<<traverse->data<<"\t\t";
    cout<<traverse->name<<"\t\t";
    cout<<traverse->x<<"\t\t";
    cout<<traverse->y<<"\n";
    traverse = traverse->next;

}
}

void delete_beg(){
    node *temp;
    temp = start;
    start = start->next;
    start->prev=NULL;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);
    
 
}

void delete_end(){
    node *traverse;
    traverse = start;
    while(traverse->next != NULL){
    traverse = traverse->next;
    }
    traverse->prev->next = NULL;
    cout<<traverse->data<<" has been deleted"<<endl;
    delete(traverse);
    
}

void delete_after(){
  int value;
  cout<<"Enter the product id which you want to be deleted"<<endl;
  cin>>value;
  node *traverse;
  traverse = start;
   while(traverse->data != value || traverse->next!=NULL){
      traverse = traverse->next;
}
if(traverse==start){
	start = start->next;
    start->prev=NULL;
    cout<<traverse->data<<" hasF been deleted"<<endl;
    delete(traverse);
}
//Delete rear Node
else if(traverse->next==NULL){
	 traverse->prev->next = NULL;
    cout<<traverse->data<<" hasl been deleted"<<endl;
    delete(traverse);
}

else{
	traverse->prev->next = traverse->next;
   traverse->next->prev = traverse->prev;
   cout<<traverse->data<<" has been deleted"<<endl;
   delete(traverse);
}
   
}

void update_Product(){
	int pid,xs,ys;
	string a;
	if(start==NULL){
		cout<<"Empty";
	}
	else{
		cout<<"Enter id of the product: ";
	cin>>pid;
	node *temp=start;
	while(temp!=NULL){
	if(temp->data==pid){
	cout<<"ENTER PRODUCT NAME: "<<endl;
    cin>>a;
	temp->name=a;
	
    cout<<"ENTER QUANTITY: "<<endl;
    cin>>xs;
	temp->x=xs;
    cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
    cin>>ys;
	temp->y=ys;
	break;
		}
		temp=temp->next;
	}

	}
	
}
void buy(){
    system("cls");
    string products[20];
    int pay=0,no,c=0,price,id,i=1;
    if(start==NULL) {
	cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	else{
        cout<<"How many items you wanna to buy!\n";
		cin>>no;
			int count= display1();
			//cout<<"KKKKK"<<count;
	while (no>=i){
			struct node *cur=start;
    int quant,cho;
	cout<<"Enter id of item that you want to buy: \n";
    int id,pos=0;
	cin>>id;
	pos=search(id);
	//cout<<"Posiii"<<pos;
	if(pos<=count){
		while(cur->data!=id){
			cur=cur->next;
		}
	cout<<"How many quantities you want: \n";
	cin>>quant;
	
	if(quant>cur->x){
		cout<<"it to much quantity:";
		return;
	}
	else{

	products[c]=cur->name; c++;
	pay=pay+(cur->y*quant);
	cur->x=cur->x - quant;//available quantity - customer choose quantity
	i++;
		}
	}
	else{
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	    }
}
	//system("cls");
cout<<"\n\n\n\t\t\tYou have bought : ";
for(int i=0;i<no;i++){
	cout<<products[i]<<",";
}
price=pay*(0.95);
	cout<<"\n\nOriginal price : "<<pay;
    cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n";
}
}

//check/count item positon
	int search(int id)
 {
 	int count=1;
 	struct node *p=start;
 	while(p!=NULL)
 	{
 		if(p->data==id)
 		{

 			break;    }
 		else
 			count++;
 			p=p->next;
	}

 	return count;
 }
//Check/count existing items
int display1(){
	//	system("cls");
    int c=0;
    struct node *p=start;
    cout<<"Existing products are:\n";
    cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    while(p!=NULL)
		{
			cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<p->x<<"\t\t"<<"\n";
			p=p->next;
			c=c+1;
		}
    cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
    return c;
}


//Search available items
void srch(){
    system("cls");
    cout<<"\n\n\t\t\t**********************Super MArket Management system*****************************\n\n\n"<<endl;
    string nam;
    cout<<"Enter Product Name "<<endl;
    cin>>nam;
    int f=0;
 	struct node *p=start;
 	while(p!=NULL)
 	{
 		if(nam==p->name)
 		{
 		    f=1;
 			break;
 			    }

 			p=p->next;
	}

	if(f==1)
    {
        	cout<<"Product is available"<<endl;
    }
    else{
            cout<<"Out of Stock"<<endl;

    }
}
void intro();
void intro()
{
	
	cout << "\n\n\t\t\t\tPROJECT" << endl;
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tSuperMarket MANAGEMENT SYSTEM";
	cout << "\n\t\t\t\t======================\n";
	cout << "\n\n\t\t\t\tMADE BY ->";
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\t RollNo: 19014156-071\n";
	cout << "\t\t\t\t RollNo:  19014156-062";
	cout << "\t\t\t\t RollNo: 19014156-037\n";
	cout << "\t\t\t\t RollNo:  19014156-060";
	
	cout << "\n\t\t\t\t======================\n";
	cout << "\tPress Enter to Continue";
	cin.get();
}


int main(){
	FirstMenu:
    intro();
    system("cls");
    int option;
do{
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tSuperMarketMANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";
		cout << "\n\n\t\t\t\t****************" << endl;
	    cout<<"\n\t\t\t\t1. Cashier"<<endl;
	    cout<<"\n\t\t\t\t2. Customer"<<endl;
	    cout<<"\n\t\t\t\t3. Exit"<<endl;
	    cout<<"\n\n\t\t\t\t****************"<<endl;
        cin>>option;
        switch(option){
    	//Cashier Side
    	 case 1:
    	 	do{  
			  // system("CLS");  	 		
               cout<<"\n\t\t\t\t---------------------------------"<<endl;
               cout<<"\n\t\t\t\t1 ADD PRODUCT"<<endl;
               cout<<"\n\t\t\t\t2 ADD PRODUCT AT FIRST POSITION"<<endl;
               cout<<"\n\t\t\t\t4 DELETE PRODUCT AT LAST POSITION"<<endl;
               cout<<"\n\t\t\t\t5 DELETE PRODUCT AT FIRST POSITION"<<endl;
               cout<<"\n\t\t\t\t6 DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
               cout<<"\n\t\t\t\t7 DISPLAY"<<endl;
               cout<<"\n\t\t\t\t9 SEARCH"<<endl;
               cout<<"\n\t\t\t\t10 Update"<<endl;
               cout<<"\n\t\t\t\t3 Back to Menu"<<endl;
               cout<<"\n\t\t\t\t____________________"<<endl;
               cin>>option;
               switch(option){
   case 1:insert_node_End();
          break;
   case 2: add_begin();
           break;
   case 3: 
            system("CLS");
			goto FirstMenu;
           break;
   case 4: delete_end();
           break;
   case 5: delete_beg();
           break;
   case 6: delete_after();
           break;
   case 7: display();
           break;
   case 9: srch();
            break;
    case 10: update_Product();
            break;
   }

}while(option != 0);
          break;
          
         case 2: 
         //Customer Side
         do{
         	//system("CLS");  	 		
               cout<<"\n\t\t\t\t---------------------------------"<<endl;
               cout<<"\n\t\t\t\t1 DISPLAY Products"<<endl;
               
               cout<<"\n\t\t\t\t2 SEARCH"<<endl;
               cout<<"\n\t\t\t\t3 Buy"<<endl;
               cout<<"\n\t\t\t\t4 Back to Menu"<<endl;
               cout<<"\n\t\t\t\t____________________"<<endl;
               cin>>option;
         	   switch(option){
         	   	
         	   	case 1:
         	   		display();
         	   		break;
         	   	case 2:
         	   		srch();
         	   		break;
         	   	case 3:
         	   		buy();
         	   		break;
         	   	case 4:
         	   		system("CLS");
		        	goto FirstMenu;
         	   		break;
				}
		 }while(option != 0);
           break;
         case 3: 
           exit(0);
           break;
       
	}
}while(option != 0);


return 0;}
