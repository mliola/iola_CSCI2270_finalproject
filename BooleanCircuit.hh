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
    NodeType getType();
    unsigned getId();
    Node* getFanIn(size_t i);
    Node* getFanOut(size_t i);
    std::vector<Node *> getFanInVector();
    std::vector<Node *> getFanOutVector();
    void printNode();
    bool evaluate();
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
    bool simulate(std::vector<bool> inputs);
    int countLogicalNodes();
    void printCircuit();

protected:

private:
    std::vector<Node *> nodeList;
    std::unordered_map<unsigned, bool> mymap;
};
#endif // BOOLEAN_CIRCUIT_HH_
