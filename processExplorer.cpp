// Implement the KillTask function and make sure it works

#include "processExplorer.h"

int main(){
    
    char choice, save, order, kill;
    cout << "Hello to Task Manager\n";
    cout << "How would you like to print your processes according to:\n1-Alphabetical Order\n2-Process ID\n3-Memory Usage\n";
    cin >> choice;
    cout << "Would you like the data to be in:\n1-Ascending Order\n2-Descending Order\n";
    cin >> order;
    cout << "Would you like to save a copy of all the processes in a text file ? (Y/N)\n";
    cin >> save;

    TaskManager Manager;
    cout << "Printing list....\n\n";
    Manager.fillList(choice, save, order);

    cout << "Would you like to kill any programs? (Y/N)\n";
    cin >> kill;
    if (kill == 'Y' || kill == 'y')
    {
        
    }
    
}

