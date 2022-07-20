# The-source-code-for-searching-RKD-Trails-of-Simeck
**`Title`**：Related-key Differential Attacks on Full-Round SIMECK Block Cipher    
**`Author`**: Jinyu Lu, Zhenzhen Bao, Guoqiang Liu, Bing Sun, Chao Li and Li Liu   
**`Abstract`**：Simeck is a lightweight block cipher family that combines the good design components from both Simon and Speck to be even more compact and efficient. So far, Simeck benefits from Simon’s analysis due to its similarities with Simon. In this paper, we analyze the security of Simeck in the related-key model. We find that related-key differential (RKD) trails found under the Markov cipher assumption for Simeck are not necessarily valid. Therefore, we build an SMT model that can find good RKD trails and extract the right pairs to ensure validity. We then present full-round RKD trails for Simeck48/96 and Simeck64/128 and extended RKD trails for Simeck32/64. Although those trails are effective only for restricted sets of keys, their existence indicates undesirable properties of the designs, contradicting the designers’ claim about Simeck's good cryptographic properties in the related-key model. In addition, we give a comparison of RKD and rotational-XOR (RX) differentials since RX-differentials are the known most threatening properties for Simeck. It demonstrates that RX-differential attacks perform slightly inferior to related-key differential attacks in Simeck. Finally, we study the impact of the rotation parameters on the related-key differential attacks. Experimental results show that the resistance of Simeck against related-key differential attacks can not be significantly improved by simply replacing the rotation parameters. In contrast, we show that the resistance can be greatly improved while maintaining the lightweight structure without imposing computationally expensive operational burdens.
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
