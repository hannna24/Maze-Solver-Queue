#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function to evaluate the Boolean expression using logical gates
bool evaluateBooleanExpression(bool A, bool B, bool C) {
    return ((B || C) && (A || C)) && ((B || !C) && (A || !B));
}
bool SimplefiedBooleanExpression(bool A, bool B, bool C) {
    return ((A)&&(B));
}

// Function to print the truth table for a Boolean expression
void printTruthTable(bool& satisfiable, bool& Equivelent,vector<bool>& v1) {
    std::cout << std::setw(4) << "A" << std::setw(4) << "B" << std::setw(4) << "C" << std::setw(10) << "Result" << std::setw(10) << "result2"<<std::endl;
    std::cout << "--------------------------------------" << std::endl;
    
        for (bool A : {false, true})
        {
            for (bool B : {false, true})
            {
                for (bool C : {false, true})
                {
                bool result = evaluateBooleanExpression(A, B, C);
                bool result2 = SimplefiedBooleanExpression(A, B, C);
                std::cout << std::setw(4) << A << std::setw(4) << B << std::setw(4) << C << std::setw(8) << result << std::setw(8) << result2 << std::endl;
                if (result != result2)
                {
                    Equivelent = false;
                }
                if (result)
                {
                    satisfiable = true;
                    v1.push_back(A);
                    v1.push_back(B);
                    v1.push_back(C);
                }
                
                }
            }
        }
}

int main() {
    // Print the truth table for the given Boolean expression
    vector<bool> v1;
    bool satisfiable = false;
    bool Equivelent = true;
    printTruthTable(satisfiable, Equivelent,v1);
    cout << "\nThe argument is " << (satisfiable ? "satisfiable" : "Not satisfiable") << "\n";
    cout << "\nThe argument is " << (Equivelent ? "Equivelent" : "Not Equivelent") << "\n";
    if (satisfiable)
    {

        for (int i = 0; i < v1.size(); i+=3)
        {
            cout << "A: " << v1[i] << "   B: " << v1[i + 1] << "   C: " << v1[i + 2]<<endl;
        }
    }


    return 0;
}
