//g++ -Wall -Wextra -std=c++11 file.cpp -o file
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "BooleanCircuit.hh"

Node::Node(unsigned idIn, NodeType typeIn){
    id = idIn;
    type = typeIn;
}

Boolean_Circuit::Boolean_Circuit(){}

Boolean_Circuit::Boolean_Circuit(std::string filename){
   std::ifstream in(filename);
   if(in.is_open()){
        std::string line;
        while(getline(in, line)){
            std::stringstream is(line);
            unsigned id;
            is>>id;
            std::string tag;
            is>>tag;
            NodeType type;
            if(tag == std::string("PI")) type = NodeType::PI;
            else if(tag == std::string("AND")) type = NodeType::AND;
            else if(tag == std::string("OR")) type = NodeType::OR;
            else if(tag == std::string("NOT")) type = NodeType::NOT;
            else{
                throw std::invalid_argument("Incorrect Inputs1");
            }
            std::vector<unsigned> fanIns;
            unsigned i;
            while(!is.eof()){
                is<<i;
                fanIns.push_back(i);
            }
            addNode(id, type, fanIns);

        }
   }
}

void Boolean_Circuit::addNode(unsigned id, NodeType type, std::vector<unsigned> fanIn){
    if (id != nodeList.size()){
        std::cout<< "ID = " << id << "NodeList Size = " << nodeList.size()<< std::endl;
        throw std::invalid_argument("Incorrect Inputs8");
    }

    if (type == NodeType::PI && fanIn.size()>0) throw std::invalid_argument("Incorrect Inputs2");
    else if (type == NodeType::AND && fanIn.size()<1) throw std::invalid_argument("Incorrect Inputs3");
    else if (type == NodeType::OR && fanIn.size()<1) throw std::invalid_argument("Incorrect Inputs4");
    else if (type == NodeType::NOT && fanIn.size()!=1) throw std::invalid_argument("Incorrect Inputs5");

    Node *newNode = new Node(id, type);
    for(size_t i = 0; i<fanIn.size(); i++){
        if(i>=id) throw std::invalid_argument("Incorrect Inputs6");
        newNode->addFanIn(nodeList[i]);
        nodeList[i]->addFanOut(newNode);
    }
    nodeList.push_back(newNode);

}

Boolean_Circuit::~Boolean_Circuit(){
    for(size_t i =0; i< nodeList.size();i++){
        delete(nodeList[i]);
     }
   nodeList.clear();
}


void Boolean_Circuit::printCircuit(){
    std::cout<< "Full circuit in order:"<<std::endl;
    for(size_t i = 0; i<nodeList.size(); i++){
        nodeList[i]->printNode();
    }
}

void Node::printNode(){
    std::string typeString;
    if(type == NodeType::PI) typeString = "PI";
    else if(type == NodeType::AND) typeString = "AND";
    else if(type == NodeType::OR) typeString = "OR";
    else if(type == NodeType::NOT) typeString = "NOT";
    else{
        throw std::invalid_argument("Incorrect Inputs7");
    }
    std::cout<< id << " " << typeString<< " In: ";
    for(size_t i=0; i<fanIn.size(); i++){
        std::cout<<fanIn[i]->id<<" ";
    }
    std::cout<<"Out: ";
    for(size_t i=0; i<fanOut.size(); i++){
        std::cout<<fanOut[i]->id<<" ";
    }
    std::cout<< "" << std::endl;
}

/*bool Boolean_Circuit::evaluate(Node node){ //if statuses rewrite so failed incoming set outgoing status to false
    if (!node) return 0;
    else if (node.type == NodeType::AND){
        for (int i=0; i<node.incoming.size(); i++){
            if(!node.incoming[i].status??) return 0; //relies on incoming returning bools
        }
        return 1;
    }

    else if(node.type == NodeType::OR){
       for (int i=0; i<node.incoming.size(); i++){
            if(node.incoming[i].status??) return 1; //relies on incoming returning bools
        }
        return 0;
    }

    else if (node.type == NodeType::NOT){
        //only ideas for this function rely on statuses
    }
}*/

bool Boolean_Circuit::simulate(std::vector<bool> inputs){
    std::unordered_map<unsigned, bool> mymap;
    //too many questions still, feel need to implement node flags non-satisfy
    //stack and queue flags. will need to work more closely on implementation
    return false;
}


void Node::addFanIn(Node * soloFan){
    fanIn.push_back(soloFan);
}

void Node::addFanOut(Node * soloFan){
    fanOut.push_back(soloFan);
}
