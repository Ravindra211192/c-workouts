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
              //name = newgrades.name;
              if(Grades != NULL) delete [] Grades;
              Grades = new int[3];
              for(int i = 0; i < 3; i++){
                  Grades[i] = newgrades.Grades[i];
              }
          }
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
    Student.SetGrade(2,50);
    Student[1] = 99;
    Student.PrintGrades();

    Classgrades Student1("Dikshya");
    Student1[2] = 100;
    Student1.PrintGrades();
    Student1 = Student;

    Student1.PrintGrades();
}