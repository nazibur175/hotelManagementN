#include<bits/stdc++.h>
#include<conio.h>
using namespace std;





class administrator
{
public:
    void adminMenu()
    {
        ofstream reg("database.txt", ios::app);
        system("cls");
        cout << " ********Admin Menu******\n";
        cout << "1.Login";
        cout << "\n2.Forgot Credentials"<<endl;
        cout<<"3.Main Menu";
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
            return ;
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
        ifstream input("database.txt");
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
            cout << "Hello " << user << "\n We're glad that you're here \n";
            getch();
            // main();
            adminMenu();
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
            ifstream searchu("database.txt");
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
            ifstream searchp("database.txt");
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





class customer
{
public:
    void check()
    {
        cout<<"Customers"<<endl;
        getch();
        return;
    }
};




void mainMenu()
{
    cout<<"1.Administrator"<<endl;
    cout<<"2.Customer"<<endl;
    cout<<"3.End the program"<<endl;
}




int main()
{
    //Homepage
    cout<<"      \n\t\t\t--------------------------------";
    cout<<"      \n\t\t\t| HOTEL MANAGEMENT PROJECT      |";
    cout<<"      \n\t\t\t--------------------------------";
    cout<<"      \n\n\t\t\t Developed By:   Nazibur Rahman(IT-21017)\n";
    cout<<"      \t\t\t\t\t Mahmudul Hasan(IT-21019)\t\t\t\t\t   ";
    cout<<"      \n\n\t\t\t submitted to :  S.M. Shamim";
    cout<<"      \n\t\t\t\t\t Assistant Professor  ";
    cout<<"      \n\t\t\t\t\t ICT,MBSTU  ";
    cout<<"      \n\n\n\n\n\n\n\t\t\tPress any key to enter the main program!!\n";
    getch();

    //Object creation
    administrator admin;
    customer custom;

    //Main Menu
    int choice;
    do
    {
        system("cls");
        mainMenu();
        cout<<"Please enter you choice :"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            admin.adminMenu();
            break;
        case 2:
            custom.check();
            break;
        case 3:
            return 0;
        default :
            cout << "Your have a wrong choice. Press a key to try again.";
            getch();
            //break;

        }
    }
    while(choice !=3);

}
