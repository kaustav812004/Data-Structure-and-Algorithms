#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream dotFile("dependency_graph.dot");

    // Write the DOT script to the file
    dotFile << "digraph DependencyGraph {\n";
    dotFile << "\tnode [shape=box, style=filled, color=\"#FFFFCC\"];\n";
    dotFile << "\tedge [color=\"#000000\"];\n";

    // Define nodes and edges
    dotFile << "\tA -> B;\n";
    dotFile << "\tB -> C;\n";
    dotFile << "\tC -> D;\n";
    dotFile << "\tA -> D;\n";

    dotFile << "}\n";
    dotFile.close();

    // Execute the dot command to generate the image
    system("dot -Tpng dependency_graph.dot -o dependency_graph.png");

    cout << "Dependency graph generated as dependency_graph.png\n";

    return 0;
}