#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
    string name;
    string surname;
    string university;
    int age;
public:
    Student(){};
    Student(string n, string sur, string un, int a);
    void Init(); 
    void Print();

    void WriteFile(string filename); 
    static void ReadFile(string filename);
};