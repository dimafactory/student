//
//  main.cpp
//  student
//
//  Created by Дима on 07.09.23.
//

#include <iostream>
using namespace std; 
class Student{
    char* name;
    int age;
    char* email;
    
public:
    Student(){
        cout << "constructor by default \n";
        name = nullptr;
        age = 0;
        email = nullptr;
    }
    
    Student(const char* n, int a){// Oleg 20
        name = new char[strlen(n) + 1]; //выделяем память при создании обьекта
       strcpy(name, n);
        age = a;
        cout << "constructor by two parameters \n";
    }
    
    Student(const char* n, int a, const char* e){// Oleg 20
        name = new char[strlen(n) + 1]; //выделяем память при создании обьекта
       strcpy(name, n);
        age = a;
        email = new char[strlen(e) + 1];
        strcpy(email, e);
        cout << "constructor by three parameters \n";
        
    }
    
    
    ~Student(){
    delete[] name; //явно освобождаем память при уничтожении
    delete[] email;
    cout << "destructor \n";
    }
    
    void input(){
        char buff[20];
        char buff1[50];
        cout << "enter a name: ";
        cin >> buff;
        if(name != nullptr){
            cout << "delete -> " << name << "... \n";
            delete[] name;
        }
        name = new char[strlen(buff) + 1];
        strcpy(name, buff);
        cout << "enter age: ";
        cin >> age;
        
        cout << "enter an e-mail: ";
        cin >> buff1;
    
        if(email != nullptr){
            cout << "delete -> " << email << "... \n";
            delete[] email;
        }
        email = new char[strlen(buff1) + 1];
        strcpy(email, buff1);
     
    }
    
    void Print(){
        cout << "Name: " << name << "\t Age: " << age << "\t e-mail: " << email << endl;
    }
    const char* getName() const {
           return name;
       }

       int getAge() const {
           return age;
       }

       const char* getEmail() const {
           return email;
       }
    
   //добавить после e-mail (char*)
   //добавить конструктор с тремя параметрами
   //добавить методы аксессоры
   //удаление динамической памяти в деструкторе
    
};
int main() {
    Student a;
   // Student b("Oleg", 20);
    Student b("Oleg", 20, "kizaru@gmail.com");

    b.Print();
    b.input();
    b.Print();
}
 
