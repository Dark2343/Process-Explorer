// Implement the KillTask function and make sure it works

#include "processExplorer.h"

int main(){
    
    char choice, save, order, kill;
    cout << "Welcome to Process Explorer\n\n";
    cout << "How would you like to print your processes according to:\n1- Alphabetical Order\n2- Process ID\n3- Memory Usage\n";
    cin >> choice;
    cout << "\nWould you like the data to be in:\n1- Ascending Order\n2- Descending Order\n";
    cin >> order;
    cout << "\nWould you like to save a copy of all the processes in a text file ? (Y/N)\n";
    cin >> save;

    TaskManager Manager;
    cout << "Printing list....\n\n";
    Manager.fillList(choice, save, order);

    while(true)
    {
        cout << "Would you like to terminate any programs? (Y/N)\n";
        cin >> kill;
        if (kill == 'Y' || kill == 'y')
        {
            cout << "Please enter process ID\n";
            string id;
            cin >> id;
            Manager.killTask(id);
        }   
        else{
            cout << "See you next time :D\n";
            break;
        }
    } 
}

