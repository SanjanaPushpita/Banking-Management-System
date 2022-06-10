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
    // int dd, mm;           // storing the account holders date of birth
    string dob;
    string address;
    string phoneNumber;
    string deposit;         // storing the account holders deposit amount
    string accountType;     // Type of account - Savings or Current
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

    getline(cin, dob);

    cout << "\nEnter The Account Holder's Address: ";
    fflush(stdin);
    getline(cin, address);
    cout << "\nEnter The Account Holder's Phone number: ";
    // cout << "+88";
    fflush(stdin);
    // getline(cin, phoneNumber);
    cin >> phoneNumber;
    // while (sizeof(phoneNumber) != 11)
    // {
    //     cout << "\nInvalid Phone Number";
    //     cout << "\nEnter The Account Holder's Phone number: ";
    //     // cout << "+88";
    //     fflush(stdin);
    //     cin >> phoneNumber;
    // }

    fflush(stdin);
    cout << "\nEnter The type of account you want : ";
    cout << "\n1. Savings  ";
    cout << "\n2. Current  " << endl;
    cout << ": ";
    // fflush(stdin);
    // cin >> accountType;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        accountType = "Savings";
        cout << "You have selected savings" << endl;
    }
    else if (choice == 2)
    {
        accountType = "Current";
        cout << "You have selected Current" << endl;
    }
    else
    {
        while (choice != 1 || choice != 2) // it will continue until you choose option 1 or 2
        {

            cout << "Please give a correct choice " << endl;
            fflush(stdin);
            cout << "\nEnter The type of account you want : ";
            cout << "\n1. Savings  ";
            cout << "\n2. Current  " << endl;
            cout << ": ";
            fflush(stdin);
            cin >> choice;
            if (choice == 1)
            {
                accountType = "Savings";
                cout << "You have selected savings" << endl;
            }
            else if (choice == 2)
            {
                accountType = "Current";
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
        cin >> deposit;
        cout << "\nYour deposit amount is Rs. " << deposit << endl;
    }
    else if (ch == 2)
    {
        fflush(stdin);
        deposit = to_string(0);

        cout << "\nYour deposit amount is Rs. " << deposit << endl;
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
                cin >> deposit;
                cout << "\nYour deposit amount is Rs. " << deposit << endl;
            }
            else if (ch == 2)
            {
                fflush(stdin);
                deposit = to_string(0);

                cout << "\nYour deposit amount is Rs. " << deposit << endl;
            }
        }
    }

    // deposit = dep;

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
    file << accountNumber << " , " << name << " , " << dob
         << " , " << address << " , " << phoneNumber << " , " << accountType << " , " << deposit << " , " << DT << " , " << endl;
    file.close();
    file2.open("Account Information.csv", ios::out | ios::app);
    file2 << accountNumber << " , " << password << " , " << endl;
    file2.close();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Bank::searchData()
{
    int flag = 0, choice, amount;
    string accNo, nameS;
    ifstream is("Bank Record.csv");
    cout << "\nDo you want to search data by \n";
    cout << "\n1.Account Number";
    cout << "\n2.Account Name\n";
    fflush(stdin);
    cin >> choice;
    if (choice == 1)
    {
        cout << "\nEnter the account number:";
        fflush(stdin);
        cin >> accNo;
        do
        {
            getline(is, accountNumber, ',');
            getline(is, name, ',');
            getline(is, dob, ',');
            getline(is, address, ',');
            getline(is, phoneNumber, ',');
            getline(is, accountType, ',');
            getline(is, deposit, ',');
            getline(is, DT, ',');
            amount = atoi(deposit.c_str());
            if (accNo == accountNumber)
            {
                flag = 1;
                system("cls");
                system("color 4");
                cout << "\nAccount NO.:" << accountNumber << endl;
                cout << "\nName:" << name << endl;
                cout << "\nDOB:" << dob << endl;
                cout << "\nAddress: " << address << endl;
                cout << "\nPhone number:" << phoneNumber << endl;
                cout << "\nType Of Account:" << accountType << endl;
                cout << "\nAmount deposited:" << deposit << endl;
                cout << "\nDate of Account created:" << DT << endl;
            }

        } while (is.good());
    }
    else if (choice == 2)
    {
        cout << "Enter the Name of Account Holder:";
        fflush(stdin);
        cin >> nameS;
        do
        {
            getline(is, accountNumber, ',');
            getline(is, name, ',');
            getline(is, dob, ',');
            getline(is, address, ',');
            getline(is, phoneNumber, ',');
            getline(is, accountType, ',');
            getline(is, deposit, ',');
            getline(is, DT, ',');
            amount = atoi(deposit.c_str());
            if (nameS == name)
            {
                flag = 1;
                system("cls");
                system("color 4");
                cout << "\nAccount NO.:" << accountNumber << endl;
                cout << "\nName:" << name << endl;
                cout << "\nDOB:" << dob << endl;
                cout << "\nAddress: " << address << endl;
                cout << "\nPhone number:" << phoneNumber << endl;
                cout << "\nType Of Account:" << accountType << endl;
                cout << "\nAmount deposited:" << deposit << endl;
                cout << "\nDate of Account created:" << DT << endl;
            }

        } while (is.good());
    }
    if (choice == 0)
    {
        cout << "\n\n\t\tAccount doesn't Exist!";
    }
    is.close();
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
        menuEmployee();
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

void Bank::displayData()
{
    int amount;
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================="
         << "========================================================="
         << "=================================================================\n";
    cout << "  Account No. \t\t Name \t\t Type \t\t Balance \t\t Address \t\t Phone No. \t\t Creation Date \t\t\n";
    cout << "====================================================="
         << "========================================================="
         << "=================================================================\n";
    ifstream is("Bank Record.csv");
    int i = 1, sz = 0, sz1 = 0;
    char c;
    // is.seekg(0, ios::end);
    sz = is.tellg();
    // cout << sz << endl;
    is.seekg(0, ios::beg); // used to move the get pointer to a desired location which is beginning of the file
    while (!is.eof())
    {
        cout << i << ". ";
        i++;
        getline(is, accountNumber, ',');
        getline(is, name, ',');
        getline(is, dob, ',');
        getline(is, address, ',');
        getline(is, phoneNumber, ',');
        getline(is, accountType, ',');
        getline(is, deposit, ',');
        getline(is, DT, ',');

        amount = atoi(deposit.c_str()); // atoi is used to convert string value to integer
        sz1 = is.tellg();               /// is used to know where the get pointer is in a file.
        cout << accountNumber << "\t\t" << name << "\t\t" << accountType << "\t" << amount << "\t\t\t" << address << "\t\t\t" << phoneNumber << "\t\t" << DT << "\t\t" << endl;
        if (sz == (sz1))
            break;
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
        menuEmployee();
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
    cout << "\n                             1.Details of all Account Holders Name";
    cout << "\n                             2.Exit";
    cout << "\n";
    cout << "\n                               Enter Your Choice: ";
    cin >> ch;
    // cout << "\n";
    switch (ch)
    {

    case 1:
        h.displayData();
        break;
    case 2:
        close();
        break;
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
    cout << "\n                             2.Exit";
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
    case 2:
        close();
        break;
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
        system("cls");
        employee();
        break;
    case 2:
        system("cls");
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
