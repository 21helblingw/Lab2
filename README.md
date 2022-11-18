# lab 2
## Program Overview
The program takes in a screenshot of the system and determines if the system is in a safe state. It uses the safety algoithnm of the bankers algoothm to determine if the system is in a safe state. If it is in a safe sate, it also returns the order in which those pocesses should run.
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
The input file uses flags to determine where the data should go and it uses "_" and ";" to seperate the data values. A colon is used to seperate the flag from the data values. Every line of code starts with the flag, followed by the data. For example, "1: 1_2_3_4_5;". The 1 is the flag and the data values are 1,2,3,4, and 5. The flags options are 1, 2, or 3. Flag 1 is for the allocation values of a process, flag 2 is for the maximum values of a process, and flag 3 is for the available resources. An other example in more deitals is:  "2: 1_2_5;". This adds a row in the maximum matrix with the values 1 for resource 1, 2 for resource 2, and 5 for resource 3. The order of this inputs does not matter because it looks for the flag before adding the value to any data structure.
### Data
All of the data extracted from the input files are stored in either vectors or 2D vectors.
### Safely algorithm 
temp 
### Print Functions
There are two print functions that work together to print the state of the system. These inlcude printVector and printTable. printVector prints the entire contents of thegiven vector, seperating each value by a space. printTable uses printVector to help print the entire table. It prints the the allocation resources, max resources, and need resources for each process. After that, it prints the avialable resources.
### Issues
temp

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
