#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Class to store each process into
class Process
{
private:
    string taskName;
    string PID;
    string memoryUsage;

public:
    // Setter function to assign all info
    void setInfo(string task, string pid, string memory){
        taskName = task;
        PID = pid;
        memoryUsage = memory;
    }

    // Getter function to get each process's data
    string getTask(){
        return taskName;
    }
    string getPID(){
        return PID;
    }
    string getMemory(){
        return memoryUsage;
    }

};

// Class to control the listing of all processes
class TaskManager
{
private:
    void printDataAlpha(Process data[], int size, char order){    // Printing by alphabetical order

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // Determines if the first letter in the process's name is smaller or bigger than the next process's name
                // Then swaps their locations accordingly
                if (order == '1')
                {
                    if(data[i].getTask()[0] < data[j].getTask()[0]){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }

                }
                else if (order == '2')
                {
                    if(data[i].getTask()[0] > data[j].getTask()[0]){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                    
                }
                
            }
            
        }

        // Prints all the data
        for (int i = 0; i < size; i++)
        {
            cout << "Task: " << data[i].getTask() << setw(32 - data[i].getTask().length()) << "PID: " << data[i].getPID() << setw(30 - data[i].getPID().length());
            cout << "Memory usage: "<< data[i].getMemory() << "\n";
        }
    
    }

    void printDataPID(Process data[], int size, char order){    // Printing by PID

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // Changes the PID string into numbers then determines which one is smaller or bigger
                // Then swaps their locations accordingly
                if (order == '1'){

                    if(stoi(data[i].getPID()) < stoi(data[j].getPID())){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }

                }
                else if (order == '2'){

                    if(stoi(data[i].getPID()) > stoi(data[j].getPID())){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }

                }

            }
            
        }

        // Prints all the data
        for (int i = 0; i < size; i++)
        {
            cout << "Task: " << data[i].getTask() << setw(32 - data[i].getTask().length()) << "PID: " << data[i].getPID() << setw(30 - data[i].getPID().length());
            cout << "Memory usage: "<< data[i].getMemory() << "\n";
        }
        
    }

    void printDataMemory(Process data[], int size, char order){    // Printing by memory usage

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // Changes the memory string into numbers then determines which one is smaller or bigger
                // Then swaps their locations accordingly
                if (order == '1'){

                    if(stoi(data[i].getMemory()) < stoi(data[j].getMemory())){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
                else if (order == '2'){

                    if(stoi(data[i].getMemory()) > stoi(data[j].getMemory())){
                        auto temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }

            }
            
        }

        // Prints all the data
        for (int i = 0; i < size; i++)
        {
            cout << "Task: " << data[i].getTask() << setw(32 - data[i].getTask().length()) << "PID: " << data[i].getPID() << setw(30 - data[i].getPID().length());
            cout << "Memory usage: "<< data[i].getMemory() << "\n";
        }
        
    }

public:
    // Function to fill all task processes into a text file then assign them to a class Process array 
    void fillList(char choice, char save, char order){

        int size = 1, count = 1;
        fstream file;
        string line, taskName, PID, memoryUsage;

        // Using commands to store all tasks into a text file
        system("tasklist > data.txt");

        // Opening the text file then determining how many lines it has.
        file.open("data.txt", ios::in);
        while (getline(file, line)) {size++;}

        size -= 4;      // Removing the extra lines that are either blank or contain unnecessary info. 
        Process data[size];     // Using the size value to make an array of process objects so each process would be unique.
        file.close();
        
        // Opening the file to assign each variable its value
        file.open("data.txt", ios::in);
        while (getline(file, line))
        {
            string word;

            // Skipping the first 3 lines
            if(count >= 4){

                // Cutting the entire line into words then using if conditions to assign each part to its variable
                for (int i = 0; i < line.length(); i++)
                {
                    word += line[i];

                    if(line[i] == ' ' && line[i + 1] == 'K' && i > 63){
                        memoryUsage =  word + 'K';
                        memoryUsage.erase(remove(memoryUsage.begin(), memoryUsage.end(), ','), memoryUsage.end());
                    }

                    else if(i == 26){
                        taskName = word;
                        taskName.erase(remove(taskName.begin(), taskName.end(), ' '), taskName.end());
                        taskName[0] = toupper(taskName[0]);
                    }

                    else if(i < 36 && i > 29 && line[i] >= '0' && line[i] < '9' && line[i + 1] == ' '){
                        PID = word;
                        PID.erase(remove(PID.begin(), PID.end(), ' '), PID.end());
                    }

                    else if (line[i] == ' ' && i > 26)
                    {
                        word = "";
                    }
                }
                // Setting each array its info starting fro array[0] to array[size]
                data[count - 4].setInfo(taskName, PID, memoryUsage);
            }
            count++;
        }

        // Printing the list of processes according to user input
        if(choice == '1'){printDataAlpha(data, size, order);}
        if(choice == '2'){printDataPID(data, size, order);}
        if(choice == '3'){printDataMemory(data, size, order);}

        // Saving or deleting the file according to user input
        if(save == 'n' || save == 'N'){
            file.close();
            system("del data.txt");
        }

        else  {file.close();}
    }

    void killTask(Process data[], int size, string name){
        for (int i = 0; i < size; i++)
        {
            if (data[i].getTask() == name)
            {
                string command = "taskkill/im " + data->getTask() + " /F";
                system(command);
            }
            
        }
    }

};