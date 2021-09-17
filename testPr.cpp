#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "testPr.h"

void task(){
    std::ifstream in("in.txt");
    std::vector<std::pair<std::string, int>> v = {};
    
    if(in.is_open()){
        std::string number;
        
        
        bool numberIsInVector = false;
        while(getline(in, number)){
            for(auto& pair : v){
               if(pair.first == number){
                   ++pair.second;n.close();
            
    std::ofstream out;
    out.open("out.
                   numberIsInVector = true;
                   break;
                }
            }
            if(!numberIsInVector){
                v.push_back(std::make_pair(number, 1));
            }
            numberIsInVector = false;
        }
        
    }
    else { std::cout<< "File haven't opened" << "\n"; }
            in.close();
            
    std::ofstream out;
    out.open("out.txt");
    if(out.is_open()){
        for(auto iter = v.begin(); iter != v.end(); ++iter)
        {
            out << (*iter).first <<  "\t";
            std::cout << (*iter).first <<  "\t";
            for(auto i = 0; i < (*iter).second; ++i){
                out << "*";
                std::cout << "*";
            }
            out << '\n';
            std::cout << "\n";
        }
        
    }
    else {std::cout << "File haven't opened" << "\n";}
    out.close();
    
}
