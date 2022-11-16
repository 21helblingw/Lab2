#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
    int processes = 0;
    int resources = 0;
    std::vector<int> available;
    int max[1][1]; 
    std::ifstream file("input.txt");
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
    for(int i = 0; i < input.size(); ++i){
        int index = input[i].find_first_of(":");
        std::string flag = input[i].substr(0,index);
        if(flag == "1"){
            processes = std::stoi(input[i].substr(index + 1,input[i].length()));
        }
        if(flag == "2"){
            resources = std::stoi(input[i].substr(index + 1,input[i].length()));
        }
        if(flag == "3"){
            std::string temp =input[i].substr(index + 1,input[i].length());
            std::cout<< temp <<std::endl;
            for(int j = 0; j < temp.length(); ++j){
                if(temp[j] != '_' && temp[j] != ' '&& temp[j] != ';'){
                    available.push_back(int(temp[j]) - '0'); // coverts the char to an int
                }
            }


        }
        if(flag == "4"){

        }
        }
    std::cout<<input[0] << " " << input[1]<<std::endl;
    std::cout<<processes << " | " << resources <<std::endl;
    std::cout<<available[0] << " | " << available[1] << " | " << available[2] <<std::endl;
}
