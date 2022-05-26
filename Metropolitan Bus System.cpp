#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

static int p = 0;
class a{
      char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
      public:
         void install();
         void allotment();
         void empty();
         void show();
         void avail();
         void position(int i);
}
bus [10];
void vline(char ch){
      for(int i = 80; i > 0; i--){
            cout<<ch;
      }
}
void a::install(){
      cout<<"Enter Bus No\n.";
      cin>>bus[p].busn;
      cout<<"\nEnter Driver's Name";
      cin>>bus[p].driver;
      cout<<"\nEnter Arrival Time";
      cin>>bus[p].arrival;
      cout<<"\nDeparture time";
      cin>>bus[p].depart;
      cout<<"\nFrom?\t\t\t";
      cin>>bus[p].from;
      cout<<"\nTo.?\t\t\t";
      cin>>bus[p].to;
      
      bus[p].empty();
      p++;
}

void a::allotment(){
      int seat;
      char number[5];
      top:
        cout<<"Enter Bus No.\n";
        cin>>number;
     int n;
     for(n = 0; n <= p; n++){
           if(strcmp (bus[n].busn, number) == 0){
             break;
           }
       while(n <= p){
            cout<<"\nSeat No.\t";
            cin>>seat;
            if(seat > 32){
                  cout<<"\nThere Are Only 32 Seats In This Bus!";
            }
           else if(seat < 32){
             if(strcmp(bus[n].seat[seat / 4][(seat % 4) - 1],"empty") == 0){
                        cout<<"Enter Pasenger's Name:\n";
                        cin>>bus[n].seat[seat / 4][(seat % 4) - 1];
                        break;
                  }
             else{
                    cout<<"\nThe seat is already Reserved!";
             }
           }     
       if(n  <= p){
             cout<<"\nEnter Correct Bus No.";
              goto top;
       }
}
     }
}
void a:: empty(){
      for(int i = 0; i < 8; i++){
            for(int j = 0; j < 4; j ++){
                  strcpy(bus[p].seat[i][j], "empty");
            }
      }
}

void a:: show(){
      int n;
      char number[5];
      cout<<"\nEnter Bus No.";
      cin>>number;
      for(n = 0; n <= p; n++){
            if(strcmp(bus[n].busn, number) == 0){
                  break;
            }
       while(n <= p){
             vline('*');
             cout<<"Bus No:\t"<<bus[n].busn<<"\nDriver:\t"<<bus[n].driver<<
                   "\t\tArrival Time:"<<bus[n].arrival<<"\tDeparture Time:"
                    <<bus[n].depart<<"\nFrom:"<<bus[n].from<<"\t\tTo:"
                     <<bus[n].to <<"\n";
                     
                     vline('*');
             bus[0].position(n);
             int a = 1;
             for(int i = 0; i < 8; i++){
                  for(int j = 0; j < 4; j++){
                   if(strcmp(bus[n].seat[i][j], "empty") != 0){
                         cout<<"\nThe Seat No."<<(a - 1)<<" is Reserved For"
                         << bus[n].seat[i][j]<< ".";
                   }
                 }
             } 
             break;
        }
     }
     if ( n < p){
           cout<<"Enter Correct Bus No.";
     }
}

void a:: position(int l){
  int s = 0, p = 0; 
    for(int i = 0; i < 8; i++){
          cout<<"\n";
          for(int j = 0; j < 4; j++){
                s++;
                if(strcmp(bus[l].seat[i][j], "empty") == 0){
                      cout.width(5);
                      cout.fill(' ');
                      cout<< s <<".";
                      cout.width(10);
                      cout.fill(' ');
                      cout<<bus[l].seat[i][j];
                      p++;
                }
               else{
                   cout.width(5);
                   cout.fill(' ');
                   cout<< s <<".";
                   cout.width(10);
                   cout.fill(' ');
                   cout<<bus[l].seat[i][j];
               }
          }
          cout<<"\n\nThere Are "<< p << "seats Empty in Bus No."<< bus[l].busn;
    }
}

 void a:: avail(){
      for(int n = 0; n <=p; n++){
            vline('*');
          cout<<"Bus No.\t"<< bus[n].busn<< "\nDriver:\t"<< bus[n].driver << "\t\tArrival Time: \t"<< bus[n].arrival<<"\tDeparture Time: \t"<<bus[n].depart<<"\nFrom\t\t"<< bus[n].from<<"\t\tTo:\t\t\t"<<bus[n].to << "\n";
            vline('*');
            vline('_');
      } 
}

int main()
{
   // cout<<"Hello World";
    system("cls");
    int userChoice;
    while(1){
          //System("cls");
         cout<<"\n\n\n\n\n";
         cout<<"\t\t\t 1.INSTALL\n\t\t\t 2.RESERVATION\n\t\t\t 3.SHOW\n\t\t\t 4.BUSES AVAILABLE \n\t\t\t 5.EXIT\n\t\t\t";
         
         cout<<"\n\t\t Enter Your Choice:)";
         cin >>userChoice;
         
         switch(userChoice){
               case 1 :
                  bus[p].install();
                  break;
                  
               case 2:
                 bus[p].allotment();
                 break;
                 
              case 3:
                  bus[0].show();
                  break;
                  
              case 4:
                  bus[0].avail();
                  break;
                  
              case 5:
                exit(0);
                break;
                
              default:
                 cout <<"\tINCORRECT  CHOICE ENTERED!\t";
         }
         
    }
    return 0;
}
