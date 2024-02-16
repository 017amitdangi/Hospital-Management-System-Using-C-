#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

void menu();
void pascode();
void cpascode();

class one
{
public:
    virtual void get() = 0;
    virtual void show() = 0;
};

class information : public one
{
public:
    char name[50], time[50];
    int num, age;
    void get()
    {
        system("cls");
        cin.sync();
        cout << "\n Enter the patient name =";
        cin.getline(name, 50);
        cout << "\n Enter the Appointment Time =";
        cin.getline(time, 50);
        cout << "\n Enter the age =";
        cin >> age;
        cout << "\n Enter Appointment No =";
        cin >> num;
    }
    void show()
    {
        cout << "\n Name =" << name;
        cout << "\n Age =" << age;
        cout << "\n No =" << num;
        cout << "\n Time =" << time;
    }
};

class rana : public information
{
public:
    information a1;
    void get()
    {
        system("cls");
        ofstream out("Rana.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(information));
        out.close();
        cout << "Your Entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("Rana.txt");
        if (!in)
        {
            cout << "\n\n Data in the file";
            cout << "\n\n\t Press any key to continue";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};

class waqar : public information
{
public:
    information a1;
    void get()
    {
        system("cls");
        ofstream out("Waqar.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(information));
        out.close();
        cout << "Your Entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("Waqar.txt");
        if (!in)
        {
            cout << "\n\n Data in the file";
            cout << "\n\n\t Press any key to continue";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            cout << "\n\n\t Press any key to continue";
            getch();
            menu();
        }
    }
};

class ahmad : public information
{
public:
    information a1;
    void get()
    {
        system("cls");
        ofstream out("Ahmad.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(information));
        out.close();
        cout << "Your Entry has been saved";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("Ahmad.txt");
        if (!in)
        {
            cout << "\n\n Data in the file";
            cout << "\n\n\t Press any key to continue";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};

class staff : public one
{
public:
    char all[999];
    char name[50], age[20], sal[30], pos[20];

    void get()
    {
        ofstream out("staff.txt", ios::app);
        {
            system("cls");
            cin.sync();
            cout << "\n Enter Name = ";
            cin.getline(name, 50);
            cout << "\n Enter Age = ";
            cin.getline(age, 20);
            cout << "\n Enter Salary = ";
            cin.getline(sal, 30);
            cout << "\n Enter working position = ";
            cin.getline(pos, 20);
        }
        out << "\nName =" << name << "\nAge " << age << "\nSalary" << sal << "\nWorking Position\n"
            << pos;
        out.close();
        cout << "\n\n Your information has been saved: \n\t\t Press any key to continue ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("staff.txt");
        if (!in)
        {
            cout << "file open error";
        }
        while (!(in.eof()))
        {
            in.getline(all, 999);
            cout << all << endl;
        }
        in.close();
        cout << "\n\n\t\t\t Press any key to continue";
        getch();
        menu();
    }
};

class info
{
public:
    void drinfo()
    {
        system("cls");
        system("color F3");
        cout << "\n=========================================\n";
        cout << "\n\n\t\t(Three Doctor Available)\n\n\t\t[Information And Timing Are given below]\n";
        cout << "-----------------------------------------------------------------------";
        cout << "\t\t Dr.Available:\n";
        cout << "\t\tDr.Rana (skin specialist)\n\n";
        cout << "\t\t\t[[Timing]]\n\n";
        cout << "\t Monday To Friday\t\t9AM To 5pm\n";
        cout << "\tSaturday          \t\t 9Am To 1PM\n";
        cout << "\tSunday             \t\toff/n";
        cout << "\n--------------------------------------------------------------------------\n";
        cout << "\t\tDr.waqar (child specialist)\n\n";
        cout << "\t\t\t[[Timing]]\n\n";
        cout << "\t Monday To Friday\t\t9AM To 5pm\n";
        cout << "\tSaturday          \t\t 9Am To 1PM\n";
        cout << "\tSunday             \t\toff/n";
        cout << "\n--------------------------------------------------------------------------\n";
        cout << "\t\tDr.Ahmad (dvm specialist)\n\n";
        cout << "\t\t\t[[Timing]]\n\n";
        cout << "\t Monday To Friday\t\t9AM To 5pm\n";
        cout << "\tSaturday          \t\t 9Am To 1PM\n";
        cout << "\tSunday             \t\toff/n";
        cout << "\n--------------------------------------------------------------------------\n";
        cout << "\nPress Any key for continue: ";
        getch();
        menu();
    }
};

void call_dr()
{
    system("cls");
    int choice;
    cout << "\n\n\n\t\tPress 1 for Dr Rana \n\n\n\t\tPress 2 for Dr waqar  \n\n\n\t\tPress 3 for Dr ahmad";
    cin >> choice;

    one *ptr;
    rana s3;
    waqar s4;
    ahmad s5;
    if (choice == 1)
    {
        ptr = &s3;
        ptr->get();
    }
    if (choice == 2)
    {
        ptr = &s4;
        ptr->get();
    }
    if (choice == 3)
    {
        ptr = &s5;
        ptr->get();
    }
    else
    {
        cout << "sorry invalid choice:";
    }
}

void pinfo6show()
{
    system("cls");
    int choice;
    cout << "Please enter your choice";
    cin >> choice;

    one *ptr;
    rana s3;
    waqar s4;
    ahmad s5;
    if (choice == 1)
    {
        ptr = &s3;
        ptr->show();
    }
    if (choice == 2)
    {
        ptr = &s4;
        ptr->show();
    }
    if (choice == 3)
    {
        ptr = &s5;
        ptr->show();
    }
    else
    {
        cout << "sorry invalid choice:";
        getch();
        menu();
    }
}

void menu()
{
    system("cls");
    system("color FC");
    cout << "\n";
    cout << "\n";
    cout << "\t\t  |   ++++++++++ MAIN MENU  +++++++++++  |  \n";
    cout << "\t\t  |       Hospital Management system     |  \n";
    cout << "\t\t  |======================================|  \n";
    cout << "\n---------------------------------------------------------------------\n";
    cout << "\t\t          Please Select Any Option               \n";
    cout << "\n\n\t1-\t\tPress 1 for Available doctor Information \n\n";
    cout << "\t2-\t\tPress 2 for Doctor Appointment\n\n";
    cout << "\t3-\t\tPress 3 for Saving staff information\n\n";
    cout << "\t4-\t\tPress 4 for checking Patient appointment Menu:\n\n";
    cout << "\t5-\t\tPress 5 for checking staff information Menu: \n\n";
    cout << "\t6-\t\tPress 6 for change password or create password :\n\n";
    cout << "\t7-\t\t[   Press 7 for Logout    ]\n";

    cout << "\n============================================================================\n";
    cout << "\n\n\t\tPlease enter your choice: ";
    info a1;
    one *ptr;
    staff a2;
    int a;
    cin >> a;
    if (a == 1)
    {
        a1.drinfo();
    }
    else if (a == 2)
    {
        call_dr();
    }
    else if (a == 3)
    {
        ptr = &a2;
        ptr->get();
    }
    else if (a == 4)
    {
        pinfo6show();
    }
    else if (a == 5)
    {
        ptr = &a2;
        ptr->show();
    }
    else if (a == 6)
    {
        cpascode();
    }
    else if (a == 7)
    {
        pascode();
    }
    else
    {
        cout << "sorry invalid choice : ";
    }
}

void pascode()
{
    char p1[50], p2[50];
    system("cls");
    ifstream in("password.txt");
    
    if (!in)
    {
        cout << "\n\n\t\t\tPassword file not found. Please create a password first.\n";
        Sleep(2000);
        menu();
    }

    cin.sync();
    cout << "\n\n\n\n\n\n\n\t\t\tEnter the password:  ";
    cin.getline(p1, 50);
    in.getline(p2, 50);

    in.close();

    if (strcmp(p2, p1) == 0)
    {
        menu();
    }
    else
    {
        cout << "\n\n\t\t\tIncorrect Passcode. Please Try Again.\n";
        Sleep(2000);
        pascode();
    }
}


void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout << "\n\n\n\n\t\t\tEnter the new password: ";
        cin.getline(n, 50);
        out << n;
    }
    out.close();
    cout << "\n\nYour Password has been saved";
    getch();
    menu();
}

int main()
{
    pascode();
    system("cls");
    return 0;
}

