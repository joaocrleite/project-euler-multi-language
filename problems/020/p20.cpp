#include <iostream>
#include <string>

using namespace std;

int resolve(){

    string n1 = "12";
    string n2 = "12";

    int n1s = n1.size();
    int n2s = n2.size();

    cout << "n1s " << n1s << endl;
    
    for(int i = n1s - 1; i >= 0; i--){
        cout << n1[i] << endl;
    }

    return 0;
}

int main()
{

    int result = resolve();

    cout << "Result = " << result << endl;

    return 0;
}
