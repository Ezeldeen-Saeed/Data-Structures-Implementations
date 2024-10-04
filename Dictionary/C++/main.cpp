#include <iostream>
#include "./dictionary.cpp"
using namespace std;

int main() {
    Dictionary<string, string> dictionary;

    dictionary.set("ezeldeen", "saeed");
    dictionary.set("omar", "ahmed");
    dictionary.set("rana", "said");
    dictionary.set("abdo", "mohamed");
    dictionary.set("mahmoud", "nader");
    cout << "Size: " << dictionary.size() << endl;

    dictionary.print();



    dictionary.remove("omar");

    cout << "Size: " << dictionary.size() << endl;

    dictionary.print();
    
    cout << "Get rana: " << dictionary.get("rana") << endl;

}
