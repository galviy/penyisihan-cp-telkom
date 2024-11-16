#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

   
    if (n == 1 && a[0] == "?") {
        cout << "Fortune smiles upon us, for life must needs go on" << endl;
        return 0;
    }

   
    int first_known_index = -1, second_known_index = -1;
    int first_value = 0, second_value = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != "?") {
            if (first_known_index == -1) {
                first_known_index = i;
                first_value = stoi(a[i]);
            } else {
                second_known_index = i;
                second_value = stoi(a[i]);
                break;
            }
        }
    }

  
    if (first_known_index != -1 && second_known_index == -1) {
        cout << "Fortune smiles upon us, for life must needs go on" << endl;
        return 0;
    }

  
    int a_val = first_value;  
    int b_val = (second_value - first_value) / (second_known_index - first_known_index);

    for (int i = 0; i < n; ++i) {
        if (a[i] == "?") {
            a[i] = to_string(a_val + (i * b_val));
        }
    }

    for (const string& val : a) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
