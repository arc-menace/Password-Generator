#include"global.h"
#include"WordList.h"
#include"Password.h"
#include"Component.h"

int main()
{  
    WordList* words = new WordList("words.txt");
    while (true)
    {
        srand(int(time(NULL)));

        cout << "Enter # of Password Sections (Max: 10, Min: 1, Recommended: 5): " << endl;
        int num_sections = 0;
        cin >> num_sections;
        while (cin.fail() || num_sections > 10 || num_sections <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please try again: ";
            cin >> num_sections;
        }

        //Actual program running here
        
        Password password(num_sections, words);
        int change = 1;
        do {
            cout << "To change a component, enter its corresponding index (1 - " << num_sections << "), 0 to start a new password, 11 to shuffle the password or 12 to exit: ";
            cin >> change;
            while (cin.fail() || change > 12)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please try again: ";
                cin >> change;
            }
            if (change == 11)
            {
                password.shuffle_password();
                password.print_password();
            }
            else if (change == 12)
            {
                exit(0);
            }
            else if (change != 0)
            {
                password.reroll(change);
            }
            
        } while (change != 0);
    }

    return 0;
}
