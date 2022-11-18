#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
    std::cout<<"need:";
    printVector(need[i]);
    std::cout<< "| work: ";
    printVector(work);
    std::cout<<std::endl;
*/

void getInput(std::vector<int> &available, std::vector<std::vector<int>> &allocation, std::vector<std::vector<int>> &max, char *commandInput[]);
void printTable(std::vector<int>, std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::vector<std::vector<int>>);
void printVector(std::vector<int> vec);
std::vector<std::vector<int>> calculateNeed(std::vector<std::vector<int>>,std::vector<std::vector<int>>);

int main(int args, char *commandInput[]){
    std::vector<int> available;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> max;
    // checks amount of aguments given
    if(args != 2){
        std::cout<<"ERROR: Invalid Arguments" <<std::endl;
        exit(1);
    }
    // gets input from the file and inserts them into the available, allocation, and max vectors
    getInput(available,allocation,max, commandInput);
    std::vector<std::vector<int>> need = calculateNeed(allocation, max);
    printTable(available, allocation, max, need);

    //saftly algo
    int processes = allocation.size(); // gets the number of processes
    std::vector<int> work = available; // sets a vector equal to the available resources
    std::vector<int> order; // vector that holds the safe order of processes
    int *finish = new int[processes]{}; // process turns true if it can run safely
        // this checks each process x times, where x is the number of processes
        for (int x = 0; x < processes; ++x){
            for (int i = 0; i < processes; ++i){
                // if the process is not finsihed and what is needs is less than what is available
                // allow that process to run and return its allocated resources and add it to the order vector
                if(finish[i] == false && need[i] <= work){
                    for(size_t j =0; j < available.size(); ++j){
                        work[j] += allocation[i][j];
                        finish[i] = true;
                    }
                    order.push_back(i);
                }
            }
        }
    // if there is still a process which could not have run, then it is not in a safe state
    bool safe = true;
    for(int i = 0; i < processes; ++i){
        if(finish[i] == false) safe = false;
    }
    // print if the system is safe and if it is, the order of the process to run to have the safe state
    if(safe){
        std::cout<<"The system is safe"<<std::endl;
        std::cout<<"THe order of processes for: ";
        printVector(order);
        std::cout<<"\n";
    }
    else{
        std::cout<<"THe system is not safe"<<std::endl; 
    }


}
// reads the input file and stores the information in the vectors
void getInput(std::vector<int> &available, std::vector<std::vector<int>> &allocation, std::vector<std::vector<int>> &max, char *commandInput[]){
    std::ifstream file(commandInput[1]); //opens the file
    // checks if the file opened
    if(!file){
      std::cout << "ERROR: opening file" << std::endl;
      exit(1);  
    }
    std::string token;
    std::vector<std::string> input;
    // reads the file line by line until the end of the file and stores each line in the input vector
    while(!file.eof()){
        std::getline(file, token); // line of the file
        input.push_back(token); // adding line to the vector
    }
    // each line starts with flag tag
    // 1: is the available resources
    // 2: is the allocation resources
    // 3: is the max resources
    // depending on the flag on the string, add the data to the available, allocation, or max vectors
    for(size_t i = 0; i < input.size(); ++i){
        // seperates the flag from the rest of the string
        int index = input[i].find_first_of(":");
        std::string flag = input[i].substr(0,index);
        // allocation resources
        if(flag == "1"){
            std::vector<int> row;
            // seperates the data from the flag
            std::string temp =input[i].substr(index + 2,input[i].length());
            std::string num = "";
            // checks each character in the string, adds the charachters to the num string until it hits a "_" or a ";"
            // once it hits a "_" or ";", it adds the num to the row and sets num to empty
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ';')
                    num += temp[j];
                else{
                    row.push_back(stoi(num)); // coverts the char to an int
                    num = ""; 
                }
            }
            // adds the row to the matrix of allocation
            allocation.push_back(row);
        }
        // max resources
        if(flag == "2"){
            std::vector<int> row1;
            // seperates the data from the flag
            std::string temp =input[i].substr(index + 2,input[i].length());
            std::string num = "";
            // checks each character in the string, adds the charachters to the num string until it hits a "_" or a ";"
            // once it hits a "_" or ";", it adds the num to the row and sets num to empty
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ';')
                    num += temp[j];
                else{
                    row1.push_back(stoi(num));// coverts the char to an int
                    num = "";
                }
            }
            // adds the row to the matrix of max
            max.push_back(row1);
        }
        // available resources
        if(flag == "3"){
            // seperates the data from the flag
            std::string temp =input[i].substr(index + 1,input[i].length());
            std::string num = "";
            // checks each character in the string, adds the charachters to the num string until it hits a "_" or a ";"
            // once it hits a "_" or ";", it adds the num to the row and sets num to empty
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ';')
                    num += temp[j];
                else{
                    available.push_back(stoi(num));// coverts the string to an int and adds it to available vector
                    num = "";
                }
            }
        }
        }
}
// prints the values of available, allocation, max, and need
void printTable(std::vector<int> available, std::vector<std::vector<int>> allocation, std::vector<std::vector<int>> max, std::vector<std::vector<int>> need){
    std::cout<< "Table:" <<std::endl;
    int processes = allocation.size();
    // for each process print its allocation, max, and need values
    for(int i = 0; i < processes; ++i){
        std::cout<<"P" << i << ": " << "allocation: " ;
        printVector(allocation[i]);
        std::cout << " | max: ";
        printVector(max[i]);
        std::cout << " | need: ";
        printVector(need[i]);
        std::cout << std::endl;
    }
    // prints the available vector
    std::cout << "available : ";
    printVector(available);
    std::cout << std::endl;
}
// prints the contents of the given vector seperated by a space
void printVector(std::vector<int> vec){
    for(size_t i = 0; i < vec.size(); ++i){
        std::cout<<vec[i] << " ";
    }
}
// calucates the need matrix, which is max - allocation
// it does max - allocation for each [i][j] of the matrix
std::vector<std::vector<int>> calculateNeed(std::vector<std::vector<int>> allocation,std::vector<std::vector<int>> max){
    std::vector<std::vector<int>> result;
    for(size_t i = 0; i < allocation.size(); ++i){
        std::vector<int> temp;
        for(size_t j = 0; j < allocation[i].size(); ++j){
            temp.push_back(max[i][j] - allocation[i][j]);
        }
        result.push_back(temp);
    }
    return result;
}
