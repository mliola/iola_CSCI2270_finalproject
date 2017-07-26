#ifndef BOOLEAN_CIRCUIT_HH_
#define BOOLEAN_CIRCUIT_HH_
#include <string>
#include <vector>

enum class NodeType{PI, AND, OR, NOT};

class Node {
public:
    Node(unsigned id ,NodeType type);
    void addFanIn(Node * node);
    void addFanOut(Node * node);
    void printNode();

private:
    //bool flag;
    NodeType type;
    unsigned id;
    std::vector<Node*> fanIn;
    std::vector<Node*> fanOut;
};

class Boolean_Circuit{
public:
    Boolean_Circuit();
    Boolean_Circuit(std::string filename);
    ~Boolean_Circuit();
    void addNode( unsigned id, NodeType type, std::vector<unsigned> fanIn);
    //bool satisfy();
    bool simulate(std::vector<bool> inputs);
    int randomSuccessCount();
    int countLogicalNodes();
    void printCircuit();

protected:

private:
    bool evaluate(Node * node);
    std::vector<Node *> nodeList;
    std::string toString();//loop through nodelist
};
#endif // BOOLEAN_CIRCUIT_HH_
