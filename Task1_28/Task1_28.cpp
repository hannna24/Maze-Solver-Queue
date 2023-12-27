#include <iostream>
#include <vector>
using namespace std;

void calculateTruthTable(bool& satisfiable, bool& valid)
{
    cout << "a | b | c | d |Premises1|Premises2|Premises3|Conclusion\n";
    cout << "---------------------------------------------------------\n";

    for (bool a : {false, true})
    {
        for (bool b : {false, true})
        {
            for (bool c : {false, true})
            {
                for (bool d : {false, true})
                {
                    // Evaluate premises and conclusion
                    bool premises1 = a || b;
                    bool premises2 = b || c;
                    bool premises3 = (!d || b) && (!b || d);
                    bool conclusion = a || d;
                    if ((premises1 && premises2 && premises3 && conclusion))
                    {
                        satisfiable = true;
                    }
                    if (premises1 && premises2 && premises3)
                    {
                        if (!conclusion)
                        {
                            valid = false;
                        }
                    }
                    // Print truth table row
                    cout << (a ? "T" : "F") << " | " << (b ? "T" : "F") << " | " << (c ? "T" : "F") << " | " << (d ? "T" : "F") << " | " << (premises1 ? "T" : "F") << "       | "
                        << (premises2 ? "T" : "F") << "       | " << (premises3 ? "T" : "F") << "       | " << (conclusion ? "T" : "F") << "\n";
                }
            }
        }
    }
}


int main()
{
    // Calculate and display truth table
    bool satisfiable = false;
    bool valid = true;
    calculateTruthTable(satisfiable, valid);

    cout << "\nThe argument is " << (satisfiable ? "Satisfiable" : "Not Satisfiable") << "\n";

    cout << "The argument is " << (valid ? "Valid" : "Falsifiable") << "\n";
    return 0;
}