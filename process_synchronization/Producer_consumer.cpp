#include<iostream>
using namespace std;

 void producer();
 void consumer();
 void check_full();
 void check_empty();
 void wait();
 void signal();

int n,i;
int semaphore_s =1;
int semaphore_f=0;
int buffer[]={};

int main()
{
char checker;
char choice;
cout<<"Enter the Size of Buffer :";
cin>>n;
 buffer[n];
do {
 cout<<"Enter P To produce and C to consume :";
 cin>>checker;
 if (checker == 'p' || checker == 'P'){
    producer();
 }
 if (checker == 'c' || checker == 'C'){
    consumer();
 }
 cout << "Do you want to continue? (y/n): ";
 cin >> choice;

}while(choice == 'y' || choice == 'Y');

cout<<"Program Ended";
}

void producer()
    {       
    check_full();
    wait();
    buffer[i]=semaphore_f;
    cout<<"Produced :"<<buffer[i]<<endl;
    i++;
    semaphore_f++;
    signal();
    }

void consumer()
    {       
    check_empty();
    wait();
    i--;
    cout<<"Consumed ="<<buffer[i]<<endl;
    semaphore_f--;
    signal();
    }

void check_full()
    {
    if (semaphore_f>=n){
        cout<<"The buffer is full so cant produce more";
        exit(1);
        }
    }

void check_empty()
    {
    if (semaphore_f<=0){
        cout<<"The buffer is Empty so cant consume";
        exit(2);
        }
    }
void wait()        
    {
         --semaphore_s;
         cout<<"Semaphore ="<<semaphore_s <<"\tother processes are hold for this time"<<endl;
    }

void signal()
    {
         ++semaphore_s;
         cout<<"Semaphore ="<<semaphore_s<<"\tNow Other process can be executed"<<endl;
    }