#include <iostream>
using namespace std;

class Person{
	private:
		string name;
		int age;
		string address;
	public:
		Person(string n, int age, string addr) : name(n), age(0), address(addr){}
		virtual void displayDetails(){
			cout<<"Name : "<<name<<endl;
			cout<<"Age : "<<age<<endl;
			cout<<"Address : "<<address<<endl;		
		}
};
class Student : public Person{
	private:
		int studentID;
		int grades[3];
	public:
		Student(string name, int age, string address, int id, int grades) : Person(name, age, address), Student(id, {0}){}
		void setgrade(int i, int grade){
			grades[i] = grade;
		}
		void calculateGPA(){
			int result=0;
			for(int i=0;i<3;i++){
				result  += grades[i];
			}
			result = ((result/3)/100)*4;
			cout<<"GPA : "<<result<<endl;
		}
		void displayDetails(){
			cout<<"Student ID : "<<studentID<<endl;
			cout<<"Name : "<<name<<endl;
			cout<<"Age : "<<age<<endl;
			cout<<"Address : "<<address<<endl;
			cout<<"Grades : "<<grades[0]<<", "<<grades[1]<<", "<<grades[2]<<endl;		
		}
		
};
class Teacher : public Person{
	private:
		int teacherID;
		string subject;
	public:
		void assignGrade(Student& s){
			int grade;
			for(int i = 0; i < 3 ; i++){
				cout<<"Enter Grade "<<i+1<<" :";
				cin<<&grade<<endl;
				s.setgrade(i, grade);
			}
		}
		void displayDetails(){
			cout<<"Teacher ID : "<<teacherID<<endl;
			cout<<"Name : "<<name<<endl;
			cout<<"Age : "<<age<<endl;
			cout<<"Subject : "<<subject<<endl;
			cout<<"Address : "<<address<<endl;
		}
};
int main(){
	Student s1("Aly", 20, "Clifton park", 11, {0});
	Student s2("Abrar", 19, "DHA park", 12, {0});
	Teacher t("Teach", 34, "FAST", 10, "CS");
	
	t.assignGrade(s1);
	s1.calculateGPA();
	s2.calculateGPA();
	s1.displayDetails();
	s2.displayDetails();
	t.displayDetails();
	return 0;
}