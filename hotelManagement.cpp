#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
using namespace std;

void manageRoom();

class administrator
{
public:
    void adminMenu()
    {
        ofstream reg("username&password.txt", ios::app);
        // ofstream reg("username&password.txt");
        system("cls");
        cout << " ********Admin Menu******\n";
        cout << "1.Login";
        cout << "\n2.Forgot Credentials" << endl;
        cout << "3.Main Menu";
        cout << "\nEnter your choice:";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            forgot();
            break;
        case 3:
            return;
        default:
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            adminMenu();
        }
        }
    }

    void login()
    {
        int exist;
        string user, pass, u, p;
        system("cls");
        cout << "Enter the username :";
        cin >> user;
        cout << "Enter the password :";
        cin >> pass;
        ifstream input("username&password.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                exist = 1;
            }
        }
        input.close();
        if (exist == 1)
        {
            // cout << "Hello " << user << "\n We're glad that you're here \n";
            // getch();
            manageRoom();
            // main();
            // adminMenu();
        }
        else
        {
            cout << "Sorry,login error. ";
            getch();
            adminMenu();
        }
    }

    void forgot()
    {
        int ch;
        system("cls");
        cout << "1.search your account by username ";
        cout << "\n2.Search your account by password";
        cout << "\n3.Back";
        cout << "\nEnter your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int ex = 0;
            string searchuser, su, sp;
            ifstream searchu("username&password.txt");
            cout << "Enter your remembered username :";
            cin >> searchuser;

            while (searchu >> su >> sp)
            {
                if (su == searchuser)
                {
                    ex = 1;
                    break;
                }
            }
            searchu.close();
            if (ex == 1)
            {
                cout << "Hurray : account found !\n";
                cout << "Your password is " << sp << endl;
                getch();
                adminMenu();
            }
            else
            {
                cout << "Sorry, Your account is not found \n";
                getch();
                adminMenu();
            }
            break;
        }

        case 2:
        {
            int exi = 0;
            string searchpass, su2, sp2;
            ifstream searchp("username&password.txt");
            cout << "Enter the remembered password :";
            cin >> searchpass;

            while (searchp >> su2 >> sp2)
            {
                if (sp2 == searchpass)
                {
                    exi = 1;
                }
            }
            searchp.close();
            if (exi == 1)
            {
                cout << "Hurray ! the account found \n";
                cout << "Your Username is :" << su2 << endl;
                cout << "Your password is :" << sp2 << endl;
                getch();
                adminMenu();
            }
            else
            {
                cout << "Sorry, Your account is not found \n";
                getch();
                adminMenu();
            }
            break;
        }
        case 3:
        {
            adminMenu();
            break;
        }
        default:
        {
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            forgot();
        }
        }
    }
};

class roomManagement
{
public:
    string roomNo, bedNum, ac, rent, status;
    void addRoom()
    {
        // cout<<"Add Room"<<endl;
        // getch();
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            // cout<<"VIP"<<endl;
            // getch();
            ofstream vip("viproom.txt", ios::app);
            cout << "Please enter Room No" << endl;
            cin >> roomNo;
            cout << "Please enter Number of bed" << endl;
            cin >> bedNum;
            cout << "Please enter Ac or Non-Ac" << endl;
            cin >> ac;
            cout << "Please enter Rent" << endl;
            cin >> rent;
            // cout<<"Please enter status"<<endl;
            // cin>>status;
            status = "0";
            vip << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
            // while(cin>>roomNo>>bedNum>>ac>>rent>>status)
            // {
            //     vip<<roomNo<<" "<<bedNum<<" "<<ac<<" "<<rent<<" "<<status<<endl;
            // }
        }
        else if (choice == 2)
        {
            ofstream vip("normalroom.txt", ios::app);
            // string roomNo,bedNum,ac,rent,status;
            cout << "Please enter Room No" << endl;
            cin >> roomNo;
            cout << "Please enter Number of bed" << endl;
            cin >> bedNum;
            cout << "Please enter Ac or Non-Ac" << endl;
            cin >> ac;
            cout << "Please enter Rent" << endl;
            cin >> rent;
            // cout<<"Please enter status"<<endl;
            // cin>>status;
            status = "0";
            vip << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
        else if (choice == 3)
        {
            return;
        }
        else
        {
            cout << "Your have a wrong choice. Press a key to try again." << endl;
            getch();
            addRoom();
        }
    }
    void displayRoom()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            ifstream vip("viproom.txt", ios::app);
            cout << "show all room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------+";
            cout << "\n| Room No.| Number of bed | Ac or Non Ac |    Rent    |   Status  |";
            cout << "\n+---------+---------------+--------------+------------+-----------+\n";
            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     " << status << endl;
            }
        }
        else if (choice == 2)
        {
            ifstream normal("normalroom.txt", ios::app);
            cout << "show all room:\n";
            cout << "\n+---------+---------------+--------------+------------+-----------+";
            cout << "\n| Room No.| Number of bed | Ac or Non Ac |    Rent    |   Status  |";
            cout << "\n+---------+---------------+--------------+------------+-----------+\n";
            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                cout << "   " << roomNo << "\t         " << bedNum << "\t        " << ac << "\t      " << rent << "\t     " << status << endl;
            }
        }
        else
        {
            return;
        }
        getch();
    }

    void copyvip()
    {

        ifstream viptemp("viptemp.txt", ios::app);
        ofstream viproom("viproom.txt", ios::out);
        while (viptemp >> roomNo >> bedNum >> ac >> rent >> status)
        {
                viproom << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
    }

    void copynormal()
    {

        ifstream normaltemp("normaltemp.txt", ios::app);
        ofstream normalroom("normalroom.txt", ios::out);
        while (normaltemp >> roomNo >> bedNum >> ac >> rent >> status)
        {
                normalroom << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
        }
    }

    void modifyRoom()
    {
        system("cls");
        cout << "1.Vip Room" << endl;
        cout << "2.Normal Room" << endl;
        cout << "3.Back" << endl;
        int choice;
        cin >> choice;
        string rmNo;
        cout << "Enter room no:";
        cin >> rmNo;
        if (choice == 1)
        {
            // read mood
            fstream vip;
            vip.open("viproom.txt", ios::in);
            // write mood
            fstream viptemp;
            viptemp.open("viptemp.txt", ios::out);

            while (vip >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    
                    cout << "Please enter Number of bed" << endl;
                    cin >> bedNum;
                    cout << "Please enter Ac or Non-Ac" << endl;
                    cin >> ac;
                    cout << "Please enter Rent" << endl;
                    cin >> rent;
                    cout << "Please enter status" << endl;
                    cin >> status;
                    // status = "0";
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    viptemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copyvip();
            // vip.close();
            // viptemp.close();

        }



        else if (choice == 2)
        {
            // read mood
            fstream normal;
            normal.open("normalroom.txt", ios::in);
            // write mood
            fstream normaltemp;
            normaltemp.open("normaltemp.txt", ios::out);

            while (normal >> roomNo >> bedNum >> ac >> rent >> status)
            {
                if (rmNo == roomNo)
                {
                    
                    cout << "Please enter Number of bed" << endl;
                    cin >> bedNum;
                    cout << "Please enter Ac or Non-Ac" << endl;
                    cin >> ac;
                    cout << "Please enter Rent" << endl;
                    cin >> rent;
                    cout << "Please enter status" << endl;
                    cin >> status;
                    // status = "0";
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
                else
                {
                    normaltemp << roomNo << " " << bedNum << " " << ac << " " << rent << " " << status << endl;
                }
            }
            copynormal();
            // vip.close();
            // viptemp.close();
        }
        else
        {
            return;
        }
        
        getch();
    }
};

class customer
{
public:
    void check()
    {
        cout << "Customers" << endl;
        getch();
        return;
    }
};

void mainMenu()
{
    cout << "1.Administrator" << endl;
    cout << "2.Customer" << endl;
    cout << "3.End the program" << endl;
}

int main()
{
    // Homepage
    cout << "      \n\t\t\t--------------------------------";
    cout << "      \n\t\t\t| HOTEL MANAGEMENT PROJECT      |";
    cout << "      \n\t\t\t--------------------------------";
    cout << "      \n\n\t\t\t Developed By:   Nazibur Rahman(IT-21017)\n";
    cout << "      \t\t\t\t\t Mahmudul Hasan(IT-21019)\t\t\t\t\t   ";
    cout << "      \n\n\t\t\t submitted to :  S.M. Shamim";
    cout << "      \n\t\t\t\t\t Assistant Professor  ";
    cout << "      \n\t\t\t\t\t ICT,MBSTU  ";
    cout << "      \n\n\n\n\n\n\n\t\t\tPress any key to enter the main program!!\n";
    getch();

    // Object creation
    administrator admin;
    customer custom;

    // roomManagement ob;
    // ob.modifyRoom();

    // Main Menu
    int choice;
    do
    {
        system("cls");
        mainMenu();
        cout << "Please enter you choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin.adminMenu();
            break;
        case 2:
            custom.check();
            break;
        case 3:
            return 0;
        default:
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            // break;
        }
    } while (choice != 3);
}

void manageRoom()
{
    roomManagement rm;

    int option;
    do
    {
        system("cls");
        cout << "1.Add room\n2.Display all room\n3.Modify room\n4.Back to main manu\nEnter your option:";
        cin >> option;
        switch (option)
        {
        case 1:
            rm.addRoom();
            break;
        case 2:
            rm.displayRoom();
            break;
        case 3:
        {
            rm.modifyRoom();
            break;
        }
        case 4:
            break;
        default:
            cout << "\nPlease Enter correct option\n";
            break;
        }
    } while (option != 4);
}