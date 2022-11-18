#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void getInput(std::vector<int> &available, std::vector<std::vector<int>> &allocation, std::vector<std::vector<int>> &max, char *commandInput[]);
void printTable(std::vector<int>, std::vector<std::vector<int>>, std::vector<std::vector<int>>, std::vector<std::vector<int>>);
void printVector(std::vector<int> vec);
std::vector<std::vector<int>> calculateNeed(std::vector<std::vector<int>>,std::vector<std::vector<int>>);
int main(int args, char *commandInput[]){
    std::vector<int> available;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> max;
    if(args != 2){
        std::cout<<"ERROR: Invalid Arguments" <<std::endl;
        exit(1);
    }
    getInput(available,allocation,max, commandInput);
    std::vector<std::vector<int>> need = calculateNeed(allocation, max);
    printTable(available, allocation, max, need);

    //saftly algo
    int processes = allocation.size();
    std::vector<int> work = available;
    std::vector<int> order;
    int finish[processes] = { };
        for (int pass = 0; pass < processes; ++pass){
            for (int i = 0; i < processes; ++i){
                std::cout<<"need:";
                printVector(need[i]);
                std::cout<< "| work: ";
                printVector(work);
                std::cout<<std::endl;
            if(finish[i] == false && need[i] <= work){
                std::cout<< i <<std::endl;
                for(size_t j =0; j < available.size(); ++j){
                    work[j] += allocation[i][j];
                    finish[i] = true;
                }
                std::cout<< "work ";
                printVector(work);
                std::cout<<std::endl;
                order.push_back(i);
            }
            }
        }
    bool safe = true;
    for(int i = 0; i < processes; ++i){
        if(finish[i] == false) safe = false;
    }
    (safe) ? std::cout<<"safe"<<std::endl : std::cout<<"not safe"<<std::endl; 
    printVector(order);


}
void getInput(std::vector<int> &available, std::vector<std::vector<int>> &allocation, std::vector<std::vector<int>> &max, char *commandInput[]){
    std::ifstream file(commandInput[1]);
    if(!file){
      std::cout << "ERROR: opening file" << std::endl;
      exit(1);  
    }
    std::string token;
    std::vector<std::string> input;
    while(!file.eof()){
        std::getline(file, token);
        input.push_back(token);
        // first two lines are the number of proecsses and resouces
       
    }
    for(size_t i = 0; i < input.size(); ++i){
        int index = input[i].find_first_of(":");
        std::string flag = input[i].substr(0,index);
        if(flag == "1"){
            std::vector<int> row;
            std::string temp =input[i].substr(index + 2,input[i].length());
            std::string num = "";
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ';')
                    num += temp[j];
                else{
                    row.push_back(stoi(num));
                    num = ""; // coverts the char to an int
                }
            }
            allocation.push_back(row);
        }
        if(flag == "2"){
            std::vector<int> row1;
            std::string temp =input[i].substr(index + 2,input[i].length());
            std::string num = "";
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ';')
                    num += temp[j];
                else{
                    row1.push_back(stoi(num));
                    num = ""; // coverts the char to an int
                }
            }
            max.push_back(row1);
        }
        if(flag == "3"){
            std::string temp =input[i].substr(index + 1,input[i].length());
            for(size_t j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ' '&& temp[j] != ';'){
                    available.push_back(int(temp[j]) - '0'); // coverts the char to an int
                }
            }


        }
        }
}

void printTable(std::vector<int> available, std::vector<std::vector<int>> allocation, std::vector<std::vector<int>> max, std::vector<std::vector<int>> need){
    std::cout<< "Table:" <<std::endl;
    int processes = allocation.size();
    for(int i = 0; i < processes; ++i){
        std::cout<<"P" << i << ": " << "allocation: " ;
        printVector(allocation[i]);
        std::cout << " | max: ";
        printVector(max[i]);
        std::cout << " | need: ";
        printVector(need[i]);
        std::cout << std::endl;
    }
    std::cout << "available : ";
    printVector(available);
    std::cout << std::endl;
}
void printVector(std::vector<int> vec){
    for(size_t i = 0; i < vec.size(); ++i){
        std::cout<<vec[i] << " ";
    }
}
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
