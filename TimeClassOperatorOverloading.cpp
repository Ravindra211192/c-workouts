#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Time
{
    private:
     int hrs;
     int mins;
     string StringForm;
     
    public:
     Time(){
         hrs = 0;
         mins = 0;
     }
     
     Time(int hour, int minute):hrs(hour),mins(minute){
     }
     
     operator const char*(){
         ostringstream out;
         out << hrs << "hour : " << mins << "minutes" <<endl;
         StringForm = out.str();
         return StringForm.c_str();
     }
     void print(){
         cout << hrs<<"hours and "<< mins <<"minutes"<< endl;
     }
     
     void Timecheck() {
         if (mins > 59) {
             hrs += mins/60;
             mins = mins%60;
         }
         
         if (mins < 0) {
             hrs -= (-mins/60)+1;
             mins = 60 - (-mins%60);
         }
         
         //if (hrs > 23) hrs = 0;
         if (hrs > 23) hrs = hrs % 23;
         //if (hrs < 0) hrs = 23;
         if (hrs < 0) hrs = 24 - (-mins % 60);
     }
     
     Time& operator++(){
         ++mins; Timecheck();
         return *this;
     }
     
     Time& operator--(){
         --mins; Timecheck();
         return *this;
     }
     
     Time operator++(int){
         Time tmpTime(hrs,mins);
         ++mins; Timecheck();
         return tmpTime;
     }
     
     Time operator--(int){
         Time tmpTime(hrs,mins);
         --mins; Timecheck();
         return tmpTime;
     }
     
     Time operator - (const Time& newTime){
         
         int newMins = mins - newTime.mins;
         int newHrs = hrs - newTime.hrs;
         Time newtime(newHrs , newMins);
         return newtime;
     }
     //-= binary operator, void coz same object is changing
     void operator -= (const Time& newTime){
         mins -= newTime.mins;
         hrs -=newTime.hrs;
         Timecheck();
     }
     
     bool operator==(const Time& newTime){
         return((mins == newTime.mins) && (hrs == newTime.hrs));
     }

     bool operator!=(const Time& newTime){
         //return !(this->operator == (newTime));
         return((mins != newTime.mins) || (hrs != newTime.hrs));
     }

     bool operator < (const Time& newTime){
         if(hrs < newTime.hrs) return(true);
         else if(hrs > newTime.hrs) return(false);
         else if(mins < newTime.mins) return(true);
         else return(false);
     }

     bool operator <=(const Time& newTime){
         if(this -> operator == (newTime)) return(true);
         else return(this -> operator < (newTime));
     }

     bool operator > (const Time& newTime){
         return !(this -> operator <= (newTime));
     }

     bool operator >= (const Time& newTime){
         return ((this -> operator > (newTime)) || (this -> operator == (newTime)));
     }
};

int main()
{
    Time T1(1,0);
    T1++;
    cout << "Time is " << T1 <<endl;
    Time T2 = T1--;
    T2.print();
    T1.print();
    Time T3(2,50);
    T3.print();
    Time T4(1,48);
    T4.print();
    T2 = T3 - T4;
    cout << "Time T2 is " << T2 <<endl;
    T2 -= T1;
    cout << "Time T1 is " << T1 <<endl;
    cout << "Time T2 after sub with T1 is " << T2 <<endl;
    T2 = T1;
    if(T1 == T2) {
        cout << "Time is equal" << endl;
    }
    else cout << "Time is not equal" << endl;
    T2 -= T1;
    cout << "T2 :" << T2 << endl;
    cout << "T1 :" << T1 << endl;
    if (T2 <= T1) {
        cout << "T2 <=T1 " << endl;
    }
    else cout << "Not worked !" << endl;
    if (T1 >= T2) {
        cout << "T1 >=T2 " << endl;
    }
    else cout << "Not worked !" << endl;
}