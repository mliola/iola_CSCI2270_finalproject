#include "BooleanCircuit.hh"
#include <iostream>

int main(int argc, char *argv[]){
   if (argc >2){
    std::cout << "Too many arguments"<< std::endl;
    return -1;
   }
   else if (argc == 2){
       Boolean_Circuit circuit(argv[1]);
   }
   else{
       std::cout << "File name not provided" << std::endl;
       Boolean_Circuit circuit;
       circuit.addNode(0, NodeType::PI, {});
       circuit.addNode(1, NodeType::PI, {});
       circuit.addNode(2, NodeType::NOT, {0});
       circuit.addNode(3, NodeType::NOT, {1});
       circuit.addNode(4, NodeType::OR, {0,1});
       circuit.addNode(5, NodeType::OR, {0,3});
       circuit.addNode(6, NodeType::OR, {2,1});
       circuit.addNode(7, NodeType::OR, {2,3});
       circuit.addNode(8, NodeType::AND, {4,5,6,7});
       circuit.printCircuit();

   }
    return 0;
}
