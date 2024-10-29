#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen :protected clsScreen
{

private:
    
    static bool _Login()
    {
        short FaildLoginCount = 0;
        bool LoginFaild = false;
        

        string Username, Password;
        do
        {
           
            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << 3 - FaildLoginCount << " Trial(s) to login.\n\n";

                if (FaildLoginCount==3 )
                {
                    cout << "\nYour are Loced after 3 falid trials\n\n";
                    return false;
                }

            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();

        return true;
    }

public:
   
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
