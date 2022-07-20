There are 3 files in this repository：
simeck32-valid-RKD-trail.cpp
simeck48-valid-RKD-trail.cpp
simeck64-valid-RKD-trail.cpp
Instructions for Execution
For Simeck32:
For example, to search for a valid RKD trails with a Hamming weight of 30 in 14 rounds, you can execute the program according to the following command to obtain：

C++ simeck32-valid-RKD-trail.cpp -o a
linux: ./a 14 30 >14-30.smt2  Windows: a.exe 14 30 >14-30.smt2
time bitwuzla –hex 14-30.smt2 >14-30.txt
