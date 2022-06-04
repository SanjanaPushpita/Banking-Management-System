#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread> //for delay
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>    //for date and time
#include <stdlib.h> //for system() function
#include <bits/stdc++.h>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main_exit;

int main();
void employee();
void client();
void menuEmployee();
void menuClient();
void close();

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Bank
{
public:
    string accountNumber; // storing account holders account number
    string name;          // storing the account holders name
    int dd, mm;           // storing the account holders date of birth
    string yyyy;
    string address;
    int phoneNumber;
    int deposit;            // storing the account holders deposit amount
    int accountType;        // Type of account - Savings or Current
    string password;        // storing the account holders account password
    string confirmPassword; // storing the account holders account password
    string DT;

public:
    void getData();
    void writeData();
    void modifyData();
    void searchData();
    void displayData();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Bank::getData()
{

    system("color 5"); // violet color
    cout << "\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Create a Bank Account \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n"
         << endl;
    int ch, dep;
    cout << "\nYour Account Number should not exceed 10 digits" << endl;
    cout << "Enter The Account Number: ";
    fflush(stdin);
    // cin >> accountNumber;
    getline(cin, accountNumber);
    while (accountNumber.length() > 10)
    {
        cout << "The length should be within 10 digits" << endl;
        cin.clear();   // clearing the error flags which are set when std::cin fails to interpret the input.
        fflush(stdin); // it is used after the cin, it flushes the input buffer also. It returns zero if successful, otherwise returns EOF and feof error indicator is set.
        cout << "\nEnter The Account Number again: ";
        getline(cin, accountNumber);
    }
    cout << "\nEnter The Account Holder's Name: ";
    fflush(stdin);
    getline(cin, name);
    // cin.clear();
    cout << "\nEnter the date of birth(dd/mm/yyyy):";
    fflush(stdin);

    cout << "\nDate: ";
    cin >> dd;
    fflush(stdin);
    cout << "\nMonth: ";
    cin >> mm;
    fflush(stdin);
    cout << "\nYear: ";
    getline(cin, yyyy);

    while (dd <= 31 && mm <= 12 && yyyy.length() > 4 && yyyy.length() < 4)
    {
        cout << "\nPlease give a correct date ";
        cout << "\nEnter the date of birth(dd/mm/yyyy):";
        fflush(stdin);

        cout << "\nDate: ";
        cin >> dd;
        fflush(stdin);
        cout << "\nMonth: ";
        cin >> mm;
        fflush(stdin);
        cout << "\nYear: ";
        getline(cin, yyyy);
    }

    cout << "\nEnter The Account Holder's Address: ";
    fflush(stdin);
    getline(cin, address);
    cout << "\nEnter The Account Holder's Phone number: ";
    cout << "+880";
    fflush(stdin);
    // getline(cin, phoneNumber);
    cin >> phoneNumber;
    while (sizeof(phoneNumber) > 11 && sizeof(phoneNumber) < 11)
    {
        cout << "\nInvalid Phone Number";
        cout << "\nEnter The Account Holder's Phone number: ";
        cout << "+880";
        fflush(stdin);
        cin >> phoneNumber;
    }

    cout << "\nEnter The type of account you want : ";
    cout << "\n1. Savings  ";
    cout << "\n2. Current  " << endl;
    cout << ": ";
    fflush(stdin);
    cin >> accountType;
    if (accountType == 1)
    {
        cout << "You have selected savings" << endl;
    }
    else if (accountType == 2)
    {
        cout << "You have selected Current" << endl;
    }
    else
    {
        while (accountType != 1 || accountType != 2) // it will continue until you choose option 1 or 2
        {

            cout << "Please give a correct choice " << endl;
            fflush(stdin);
            cout << "\nEnter The type of account you want : ";
            cout << "\n1. Savings  ";
            cout << "\n2. Current  " << endl;
            cout << ": ";
            cin >> accountType;
            if (accountType == 1)
            {
                cout << "You have selected savings" << endl;
            }
            else if (accountType == 2)
            {
                cout << "You have selected Current" << endl;
            }
        }
    }

    cout << "\nDo You want to deposit amount:\n\t1.Yes\n\t2.No\n:";

    fflush(stdin);
    cin >> ch;
    if (ch == 1)
    {
        cout << "\nEnter the amount to deposit: Rs ";
        fflush(stdin);
        cin >> dep;
        cout << "\nYour deposit amount is Rs. " << dep << endl;
    }
    else if (ch == 2)
    {
        fflush(stdin);
        dep = 0;

        cout << "\nYour deposit amount is Rs. " << dep << endl;
    }
    else
    {
        while (ch != 1 || ch != 2)
        {
            cout << "Please give a correct choice " << endl;
            fflush(stdin);
            cout << "\nDo You want to deposit amount:\n\t1.Yes\n\t2.No\n:";
            cin >> ch;
            if (ch == 1)
            {
                cout << "\nEnter the amount to deposit: Rs ";
                fflush(stdin);
                cin >> dep;
                cout << "\nYour deposit amount is Rs. " << dep << endl;
            }
            else if (ch == 2)
            {
                fflush(stdin);
                dep = 0;

                cout << "\nYour deposit amount is Rs. " << dep << endl;
            }
        }
    }

    deposit = dep;

    cout << "\nNow create a password for your account: ";
    // cin.clear();
    fflush(stdin);
    getline(cin, password);
    // cin >> password;
    // while (password < '48' || password > '57' && password < '65' || password > '90' && password < '97' || password > '122')
    // {
    //     cout << "\nYour password should contain atleast one capital letter,one small letter and one number ";
    //     cout << "\nNow create a password for your account: ";
    //     // cin.clear();
    //     fflush(stdin);
    //     // getline(cin, password);
    //     cin >> password;
    // }

    cout << "\nConfirm your password: ";
    // cin.clear();
    fflush(stdin);
    // cin >> confirmPassword;
    getline(cin, confirmPassword);
    while (password != confirmPassword)
    {
        cout << "\nPassword did not match. ";
        cout << "\nConfirm your password: ";
        fflush(stdin);
        getline(cin, confirmPassword);
    }

    cout << "\nCongratulations you have created your account ^_^ ";
    time_t now = time(0);
    // convert now to string form
    char *dt = ctime(&now);
    cout << "\n\nThe Account has been created on " << dt << endl;
    DT = dt;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Bank::writeData()
{
    ofstream file, file2;
    file.open("Bank Record.csv", ios::out | ios::app); // | = bitwise OR operator
    file << accountNumber << " , " << name << " , " << dd << "/" << mm << "/" << yyyy
         << " , " << address << " , " << phoneNumber << " , " << accountType << " , " << deposit << " , " << DT << " , " << endl;
    file.close();
    file2.open("Account Information.csv", ios::out | ios::app);
    file2 << accountNumber << " , " << password << " , " << endl;
    file2.close();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void close()
{
    cout << "\n";
    cout << "\n";
    cout << "\n\t  .......................The program is closed......................." << endl;
    cout << "\n\t  .......................      Thank you      ......................." << endl;
    cout << "\n\t  .......................          ^_^        ......................." << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menuEmployee()
{
    Bank h;
menu:
    int ch;
    system("cls");
    system("color 4");
    cout << "\n\n";
    cout << "\n            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n            ----------------------- Welcome to the Employee Menu ---------------------------";
    cout << "\n";
    cout << "\n                             1.Check the details of an existing account";
    cout << "\n                             2.Details of all Account Holders Name";
    cout << "\n                             3.Exit";
    cout << "\n";
    cout << "\n                               Enter Your Choice: ";
    cin >> ch;
    // cout << "\n";
    switch (ch)
    {
        // case 1:
        //     h.searchAcc();
        //     break;
        // case 2:
        //     h.displatData();
        //     break;
        // case 3:
        //     close();
        //     break;

    default:
        cout << "\n Invalid choice. Try again.....";
        break;
        system("cls");
        goto menu;
    }
login_try:
    cout << "\n\n\n";
    cout << " Enter 1 to go back to Main Menu" << endl;
    cout << " Enter 2 to go back to Previous Menu" << endl;
    cout << " Enter 0 to Exit " << endl;
    cout << " Enter your choice: ";
    cin >> main_exit;
    if (main_exit == 1)
    {
        system("cls");
        main();
    }

    else if (main_exit == 2)
    {
        system("cls");
        employee();
    }

    else if (main_exit == 0)
    {
        system("cls");
        close();
    }

    else
    {
        printf("\nInvalid Choice! Try again.....");
        // system("cls");
        goto login_try;
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void employee()
{
    string id, s;

menu:
    system("color 4");
    cout << "\n";
    cout << "\n------------------------ Employee Login Page ------------------------";
    cout << "\n";
    cout << "\n                      Enter the Employee ID:";
    getline(cin, id);
    if (id == "maliha" || id == "MALIHA" || id == "sanjana" || id == "SANJANA" || id == "mehjabin" || id == "MEHJABIN" || id == "runa" || id == "RUNA")
    {
        cout << "\n                      Welcome ^_^";
        fflush(stdin);
    }
    else
    {
        cout << "                   WRONG EMPLOYEE ID !!!!!!!!";
        system("cls");
        goto menu;
    }
    cout << "\n                      Enter the password:";

    getline(cin, s);
    if (s == "1234")
    {
        cout << "\n             Access Granted!";
        cout << "\n             Loading";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        system("cls");
        menuEmployee();
    }
    else
    {
        cout << "                   WRONG PASSWORD !!!!!!!!";
    // system("cls");
    // goto menu;
    login_try:
        cout << "\n\n\n";
        cout << " Enter 1 to go back to Main Menu" << endl;
        cout << " Enter 2 to go back to Previous Menu" << endl;
        cout << " Enter 0 to Exit " << endl;
        cout << " Enter your choice: ";
        cin >> main_exit;
        if (main_exit == 1)
        {
            system("cls");
            main();
        }

        else if (main_exit == 2)
        {
            system("cls");
            employee();
        }
        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid Choice! Try again.....");
            // system("cls");
            goto login_try;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menuClient()
{
    int ch;
    Bank c;
menu:
    // int ch;
    system("cls");
    system("color 6");
    cout << "\n\n";
    cout << "\n            \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n            ----------------------- Welcome to the Client Menu -----------------------------";
    cout << "\n";
    cout << "\n                             1.Create new account";
    cout << "\n                             2.Update information' of existing account";
    cout << "\n                             3.For transactions";
    cout << "\n                             4.Details of existing account";
    cout << "\n                             5.Exit";
    cout << "\n";
    cout << "\n                               Enter Your Choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:

        system("cls");
        c.getData();
        c.writeData();
        break;
    // case 2:
    //     c.modify_account();
    //     break;
    // case 3:
    //     c.deposit_withdraw();
    //     break;
    // case 4:
    //     c.search_rec();
    //     break;
    // case 5:
    //     close();

    //     break;
    default:
        cout << "\n Invalid choice. Try again.....";
        break;
        system("cls");
        goto menu;
    }
login_try:
    cout << "\n\n\n";
    cout << " Enter 1 to go back to Main Menu" << endl;
    cout << " Enter 2 to go back to Previous Menu" << endl;
    cout << " Enter 0 to Exit " << endl;
    cout << " Enter your choice: ";
    cin >> main_exit;
    if (main_exit == 1)
    {
        system("cls");
        main();
    }
    else if (main_exit == 2)
    {
        system("cls");
        client();
    }
    else if (main_exit == 0)
    {
        system("cls");
        close();
    }
    else
    {
        printf("\nInvalid Choice! Try again.....");
        // system("cls");
        goto login_try;
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void client()
{
    string id, s, pass, Caccount, account;
    char c;
    int ch, i = 0;
menu:
    system("cls");
    system("color 6");
    cout << "\n";
    cout << "\n------------------------ Client Login Page ------------------------";
    cout << "\n";
    cout << "\n                       1.New Client";
    cout << "\n                       2.Existing Client";
    cout << "\n";
    cout << "\n";
    cout << "\n                       Enter your choice : ";
    cin >> ch;

    if (ch == 1)
    {
        system("cls");
        menuClient();
    }
    else
    {

        cout << "\n             Enter the Client Id: ";
        fflush(stdin);
        getline(cin, Caccount);
        cout << "\n             Enter the Password: ";
        getline(cin, s);
        ifstream is("Account Information.csv");
        // cout << "\n             Welcome Client  ";
        // cout << "\n             Please enter your password: ";
        // fflush(stdin);
        // getline(cin, password);
        // fflush(stdin);
        do
        {
            getline(is, account, '\n');
            getline(is, pass, ',');

            if (account == Caccount)
            {
                i = 1;
                if (pass == s)
                {

                    cout << "\n             Access Granted!";
                    cout << "\n             Loading";
                    this_thread::sleep_for(chrono::milliseconds(700));
                    cout << ".";
                    this_thread::sleep_for(chrono::milliseconds(700));
                    cout << ".";
                    this_thread::sleep_for(chrono::milliseconds(700));
                    cout << ".";
                    this_thread::sleep_for(chrono::milliseconds(700));
                    cout << ".";
                    system("cls");
                    menuClient();
                }
            }
        } while (is.good());

        if (i == 0)
        {
            cout << "                   WRONG ID NUMBER !!!!!!!!";
        login_try:
            cout << "\n\n\n";
            cout << " Enter 1 to go back to Main Menu" << endl;
            cout << " Enter 2 to go back to Previous Menu" << endl;
            cout << " Enter 0 to Exit " << endl;
            cout << " Enter your choice: ";
            cin >> main_exit;
            if (main_exit == 1)
            {
                system("cls");
                main();
            }

            else if (main_exit == 2)
            {
                system("cls");
                client();
            }
            else if (main_exit == 0)
            {
                system("cls");
                close();
            }
            else
            {
                printf("\nInvalid Choice! Try again.....");
                // system("cls");
                goto login_try;
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    // Bank s;
    // s.getData();
    // s.writeData();
    // menuEmployee();
    // employee();
    int ch;

    system("color 9");

    cout << "\n\n\n\n                                      Welcome TO Our Bank";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << ".";
menu:
    system("cls");
    system("color 4");
    cout << "\n";
    cout << "\n       |################################################################################|";
    cout << "\n       |################################## FIRST HOPE ##################################|";
    cout << "\n       |################################################################################|";

    cout << "\n\n\n                                              MENU              ";
    cout << "\n";
    cout << "\n                                           1.Employee    ";
    cout << "\n                                           2.Client   ";
    cout << "\n                                           3.Exit                ";
    cout << "\n";
    cout << "\n                                    Enter Your Choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        employee();
        break;
    case 2:
        client();
        break;
    case 3:
        close();
        break;
    default:
        cout << "Invalid Input!\nTry Again";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
        system("cls");
        goto menu;
    }
}
