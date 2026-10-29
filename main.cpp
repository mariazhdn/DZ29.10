#include "main.h"

Student::Student(string n, string sur, string un, int a)
{
    name = n;
    surname = sur;
    university = un;
    age = a;
}

void Student::Init()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter university: ";
    cin >> university;
    cout << "Enter age: ";
    cin >> age;   
}

void Student::Print()
{
    cout << "Name: " << name << ", Surname: " << surname 
    << ", University: " << university << ", Age: " << age << endl;
}

void Student::WriteFile(string filename)
{
    ofstream fout(filename, ios::app);

    if (fout.is_open()) 
    {
        fout << name << " " << surname << " " << university << " " << age << endl;
        fout.close();
    } 
    else 
    {
        cout << "Error opening file for writing!" << endl;
    }
}

void Student::ReadFile(string filename)
{
    ifstream fin(filename);
    if (fin.is_open()) 
    {
        string n, sur, un;
        int a;
        while (fin >> n >> sur >> un >> a) 
        {
            cout << "Student: " << n << " " << sur 
            << ", University: " << un << ", Age: " << a << endl;
        }
        fin.close();
    }
    else 
    {
        cout << "Error opening file for reading!" << endl;
    }
}

int main()
{
    // создать 5 объектов, записать в файл
    // реализовать чтение из файла

    const int N = 5;
    Student students[N];

    cout << "Enter info about " << N << " students: " << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << "\nStudent №" << i + 1 << ":" << endl;
        students[i].Init(); 
    }

    string filename = "students.txt";

    for (int i = 0; i < N; i++) 
    {
        students[i].WriteFile(filename);
    }
    cout << "\nInfo successfully written to " << filename << endl;

    cout << "\nReading info from file: " << endl;
    Student::ReadFile(filename);

    return 0;
}