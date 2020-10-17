#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Classgrades
{
    private:
     string name;
     int* Grades;

    public:
      Classgrades(string newName){
          cout << "In Constructor" << endl;
          name = newName;
          Grades = new int[3];
          for (int i = 0; i < 3 ; i++) { Grades[i] = 0; };
      }
      ~Classgrades(){
          cout << "In Destructor" << endl;
          delete [] Grades;
      }

      Classgrades& operator= (const Classgrades& newgrades){
          cout << "In Copy assignment operator" << endl;
          if (this != &newgrades){
              name = newgrades.name;
              if(Grades != NULL) delete [] Grades;
              Grades = new int[3];
              for(int i = 0; i < 3; i++){
                  Grades[i] = newgrades.Grades[i];
              }
          }
      }
     /* //move constructor
      Classgrades(Classgrades&& newgrades){
          cout << " In the move constructor :" << newgrades.Grades << endl;
          name = newgrades.name ;
          Grades = newgrades.Grades;
          newgrades.Grades = NULL;
      }
      //move assignment operator
      Classgrades& operator = (const Classgrades&& newgrades){
          cout << "In Move assignment operator" << endl;
          cout << "Moving record" << newgrades.name << "into record" << name << endl;
          name = newgrades.name;
          if( (this != &newgrades) && (newgrades.Grades != NULL)){
              if (Grades != NULL) delete [] Grades;
              Grades = newgrades.Grades;
              newgrades.Grades = NULL ;
          }
          return *this;
      }*/

      Classgrades operator- (const Classgrades& newgrades){
       
          cout << "To substract the grades of :" << name << "from the average grade :" << newgrades.name << endl;
          string newname;
          newname = name + '-' + newgrades.name;
          cout << "New NAME IS : "<<newname << endl;
          Classgrades avrgnewgrades(newname);
          for(int i = 0; i < 3; i++){
              avrgnewgrades.Grades[i] = Grades[i] - newgrades.Grades[i];
          }
          return avrgnewgrades;
      }

      void SetGrade(int id, int grade){
          Grades[id] = grade;
      }

      int& operator [] (int index){
        if(index >= 0 && index < 3){
            return Grades[index];
        }
      }

      void PrintGrades(){
          cout <<"Student " << name << " has grades: " << endl;
          for (int i = 0; i < 3; i++){ cout << Grades[i] <<" " ; }
      }
};

int main()
{
    Classgrades Student("Ravindra");
	Student[2] = 87;
    Student.SetGrade(2,50);
    Student[1] = 99;
    Student.PrintGrades();

    Classgrades Student1("Dikshya");
    Student1[2] = 100;
    Student1.PrintGrades();
    Student1 = Student;

    Student1.PrintGrades();

    Classgrades Avrg("Average Scoring");
	Avrg[0] = 80 ;
	Avrg[1] = 88 ;
	Avrg[2] = 78 ;

    Avrg.PrintGrades();
    //Move Constructor 
    Classgrades StudentAvrg("Label will be overwritten.");
    StudentAvrg = Student - Avrg;
    StudentAvrg.PrintGrades();
}