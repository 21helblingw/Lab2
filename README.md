# lab 2
## Program Overview
The program takes a screenshot of the system and determines if the system is in a safe state. It uses the safety algorithm of the banker's algorithm to determine if the system is in a safe state. If it is in a safe state, it also returns the order in which those processes should run.
## Installations Needed To Run The Programs
### Recommend using Linux Machine to run  
### Installing compiling packages
Need g++ to compile the c++ code
First need to make sure packages are up to date
```bash
sudo apt update
```
Now we can download the compiling packages with the meta package build-essential. This is to install gcc and g++ compilers for c/c++.
```bash
sudo apt install build-essential
```

## Usage
```bash
g++ -Wall banker.cpp -o banker
./banker <inputFile>
```
### Usage Example with input file named input.txt
```bash
g++ -Wall banker.cpp -o banker
./banker input.txt
```
## Documentation
### Input File
The input file uses flags to determine where the data should go and it uses "_" and ";" to separate the data values. A colon is used to separate the flag from the data values. Every line of code starts with the flag, followed by the data. For example, "1: 1_2_3_4_5;". The 1 is the flag and the data values are 1,2,3,4, and 5. The flags options are 1, 2, or 3. Flag 1 is for the allocation values of a process, flag 2 is for the maximum values of a process, and flag 3 is for the available resources. Another example in more details is:  "2: 1_2_5;". This adds a row in the maximum matrix with the values 1 for resource 1, 2 for resource 2, and 5 for resource 3. The order of this inputs does not matter because it looks for the flag before adding the value to any data structure.
### Data
All of the data extracted from the input files are stored in either vectors or 2D vectors. The input file contains the available resources and the allocation and maximum resources for each process. The available resources get inserted into a vector while the allocation and maximum values get inserted into a 2D vector. So the allocation matrix consists of n rows where n is the number of processes and each row is a vector where each value is the allocation value for each resource. The same thing applies to the maximum matrix, but each row is a vector where each value is the maximum value for each resource. The need matrix is calculated by subtracting the allocation matrix from the maximum matrix. This is accomplished with the calcuateNeed function which returns a 2D vector and takes two 2D matrices as parameters. This functions subtracts the allocation value from the maximum value for each element of the matrixes 
### Safely algorithm 
This algorithm is used to determine if the system is in a safe state and to print the safe sequence of processes in order to keep it in a safe state.
#### Algorithm Setup
The algorithm starts by setting a vector equal to available. The vector holds the current available resources and changes as processes release resources. There is another vector called order, which will hold the safe sequence of processes. A process is pushed into the vector once it can run safely. There is also an array of booleans called finish, where its size is equal to the number of processes. Every element is initialized to 0 and after a process can run safely, that process's element is set to true.
#### Algorithm Body
The algorithm goes through each process and checks if it is already finished and if its needed resources are less than the current available resources. If the process is not finished and its needed resources are less than the current available resources, it releases its allocated resources and adds them to the work vector. It also sets its element in the finish array to true and that process is pushed onto the order vector. It repeats the loop for the number of processes in the system to ensure that processes that cannot go in previous passes can try again with the new available resources. After the loop, it checks each value in the finish array. If any of the elements in the array is false, the a process could not run and the system is not in a safe state 
#### Algorithm Return Values
If the system is in a safe state, it prints that it is in a safe state and prints the safe sequence of processes. If the system is not in a safe state, it just prints that it is not in a safe state
### Print Functions
There are two print functions that work together to print the state of the system. These include printVector and printTable. printVector prints the entire contents of the given vector, separating each value by a space. printTable uses printVector to help print the entire table. It prints the allocation resources, max resources, and need resources for each process. After that, it prints the available resources.
### Issues
The main drawback to this implamentation is that the input files have to use a specific format in order for the program to read in the data. The format allows for a dynamic amount of processes and resources, but the amount of resrouces for each process must be the same. The order of resources for each process must also be the same. Another issue with the format is that the available resources should only be state once. If it is stated twice, the orginal values will be overwritten by the other values.

## Examples
### Example 1:
```code
example....
```
### Example 2:
```code
example......
```
### Explanation
temp
