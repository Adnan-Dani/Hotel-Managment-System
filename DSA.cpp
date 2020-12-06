#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
void main_Fun();
class Node{
	public:
	char stype, ac, type;
	int rent, status,  rmno, to_date, booking_id, from_date;
	double phone;
	float payment_advance;
	string name , address;
	Node *next;
};
class Hotel{
	
	char stype, ac, type;
	int rent, status, booking_id, opt , rmNo, to_date,  from_date;
	double phone;
	float payment_advance;
	string name , address;
 
	Node *hotel;
	public:
		Hotel(){
			hotel = NULL;
		}
		void manageRooms(){
			
			int check=0;
			do{
			system("cls");
			cout<<"\n### Manage Rooms ###";
			cout<<"\n1: Add Room";
			cout<<"\n2: Search Room";
			cout<<"\n3: Back to Main Menu";
			cout<<"\n\nEnter Option: ";
			cin>>opt;
			switch(opt){
				case 1: // adding room
					{
						repeat:
						cout<<"\nEnter Room Number: ";
						cin>>rmNo;
						if(hotel==NULL){
							cout<<"\nType AC/Non-AC (A/N): ";
							cin>>ac;
							cout<<"\nType Comfort (S/N): ";
							cin>>type;
							cout<<"\nType Size (B/S): ";
							cin>>stype;
							cout<<"\nDaily Rent: ";
							cin>>rent;
//							storing on linked list
							hotel = new Node;
							hotel->rmno = rmNo;
							hotel->type = type;
							hotel->ac = ac;
							hotel->stype = stype;
							hotel->status = 0;
							hotel->rent = rent;
							hotel->next= NULL;
							cout<<"\n Room Added Successfully!";
							getch();
							manageRooms();
						}
						else{
							int check = 0;
							Node *t = hotel;
							while(t->next!=NULL){
								if(t->rmno==rmNo){
									check = 1;
								}
								t = t->next;
							}
							if(check!=1){
								cout<<"\nType AC/Non-AC (A/N): ";
								cin>>ac;
								cout<<"\nType Comfort (S/N): ";
								cin>>type;
								cout<<"\nType Size (B/S): ";
								cin>>stype;
								cout<<"\nDaily Rent: ";
								cin>>rent;
								Node *temp= hotel;
								hotel = new Node;
								hotel->rmno = rmNo;
								hotel->type = type;
								hotel->ac = ac;
								hotel->stype = stype;
								hotel->status = 0;
								hotel->rent = rent;
								hotel->next= temp;
								cout<<"\n Room Added Successfully!";
								getch();
								manageRooms();
							}
							else{
								cout<<"\nRoom Number is Present.\nPlease enter unique Number";
								getch();
								goto repeat;	
							}
						}
						break;
					}

				case 2: // search room
					{
//						int rmNo;
						int check = 0;
						cout<<"\nEnter room number you want to search: ";
						cin>>rmNo;
						if(hotel==NULL){
							cout<<"\nRoom not found";
								getch();
								manageRooms();
						}
						else{
							Node *temp = hotel;	
							while(temp!=NULL){
								if(temp->rmno==rmNo){
									if(temp->status==1){
										cout<<"\nRoom is Reserved";
										//showing details of the room
										cout<<"\nRoom Number: \t"<<temp->rmno;
										cout<<"\nType AC/Non-AC (A/N): "<<temp->ac;
										cout<<"\nType Comfort (S/N): "<<temp->type;
										cout<<"\nType Size (B/S): "<<temp->stype;
										cout<<"\nRent: "<<temp->rent;
										getch();
										manageRooms();
										break;
									}
									else{
										cout<<"\nRoom is available";
										//showing details of the room
										cout<<"\nRoom Number: \t"<<temp->rmno;
										cout<<"\nType AC/Non-AC (A/N): "<<temp->ac;
										cout<<"\nType Comfort (S/N): "<<temp->type;
										cout<<"\nType Size (B/S): "<<temp->stype;
										cout<<"\nRent: "<<temp->rent;
										getch();
										manageRooms();
										break;
										
									}
								}
								temp = temp->next;
							} //while loop end
						}
						break;
							
					} //case 2 end
				case 3: // back to the main menu
					{
						main_Fun();
						break;
					}
				default: 
					cout<<"\nPlease Enter correct option";
					break;
					
			}
			}while(true);
		}
		void checkIn(){
			cout<<"\nEnter Room number : ";
			cin>>rmNo;
			int check = 0;
			Node *t = hotel;
			if(t!=NULL){
				while(t!=NULL){
					if(t->rmno==rmNo){
						if(t->status==1){
							cout<<"\nRoom is already Booked";
							getch();
							main_Fun();
						}
						else{
							cout<<"\nEnter booking id: ";
							cin>>t->booking_id;
							cout<<"\nEnter Customer Name (First Name): ";
							cin>>t->name;
							cout<<"\nEnter Address (only city): ";
							cin>>t->address;
							cout<<"\nEnter Phone: ";
							cin>>t->phone;
							cout<<"\nEnter From Date: ";
							cin>>t->from_date;
							cout<<"\nEnter to  Date: ";
							cin>>t->to_date;
							cout<<"\nEnter Advance Payment: ";
							cin>>t->payment_advance;
							t->status=1;
							cout<<"\n Customer Checked-in Successfully..";	
						}
					}
					else{
						check = 1;
					}
					t = t->next;
				}
				if(check==1){
					cout<<"\nRoom not found!";
				}
			}
			else{
				cout<<"Room is not available please add first! ";
				getch();
				main_Fun();
			}
		}
		void getAvailRoom(){
			if(hotel==NULL){
				cout<<"\nRooms add first.";
				getch();
				main_Fun();
			}
			else{
				int check = 0;
				Node *temp = hotel;
				while(temp!=NULL){
					if(temp->status==0){
						cout<<"\n===================================";
						cout<<"\nRoom Number: \t"<<temp->rmno;
						cout<<"\nType AC/Non-AC (A/N): "<<temp->ac;
						cout<<"\nType Comfort (S/N): "<<temp->type;
						cout<<"\nType Size (B/S): "<<temp->stype;
						cout<<"\nRent: "<<temp->rent;
						cout<<"\n===================================";
						cout<<"\n\nPress enter for next room";
						getch();
						main_Fun();
					}
					else{
						check = 1;
					}
					temp = temp->next;
				}
				if(check==1){
					cout<<"\nAll rooms are reserved";
					getch();
					main_Fun();
				}
			}
		}
	
		
		
};
void main_Fun(){
	Hotel obj;
	int opt;
	do{
		system("cls");
		cout<<"######## Hotel Management #########\n";
		cout<<"\n1. Manage Rooms";
		cout<<"\n2. Check-In Room";
		cout<<"\n3. Available Rooms";
		cout<<"\n4. Search Customer";
		cout<<"\n5. Check-Out Room";
		cout<<"\n6. Guest Summary Report";
		cout<<"\n7. Exit";
		cout<<"\n\nEnter Option: ";
		cin>>opt;
		switch(opt){
		case 1:
			obj.manageRooms();
			break;
		case 2:
			obj.checkIn();
			break;
		case 3:
			obj.getAvailRoom();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:	
			break;
		case 7:
			cout<<"\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout<<"\nPlease Enter correct option";
		break;
		}
	}while(opt!=7);
	
}

int main(){
	main_Fun(); // calling main fun
}
