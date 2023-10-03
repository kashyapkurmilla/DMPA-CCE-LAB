#include <iostream>
#include <string.h>
using namespace std;

class Transactions {
private:
    char tid[3];
    char itemset[100][3];
public:
    Transactions() {
        tid[0] = '\0';
        for (int i = 0; i < 100; i++) {
            itemset[i][0] = '\0';
        }
    }

    void getInput() {
        cout << "Enter transaction id (2 characters): ";
        cin >> tid;
        cout << "Enter itemsets (enter -1 to stop): ";
        int k = 0;
        while (k < 100) {
            cin >> itemset[k];
            if (strcmp(itemset[k], "-1") == 0)
                break;
            k++;
        }
    }

    void display() {
        cout << "Transaction id: " << tid << endl;
        cout << "Itemsets: ";
        for (int i = 0; i < 100; i++) {
            if (strcmp(itemset[i], "-1") == 0)
                break;
            cout << itemset[i] << " ";
        }
        cout << endl;
    }
    void removeMinusOne() {
        for (int i = 0; i < 100; i++) {
            if (strcmp(itemset[i], "-1") == 0) {
                itemset[i][0] = '\0';  // Set the itemset to an empty string
            }
        }
    }

};

int main() {
    int n;
    double sup, con;
    cout << "Enter number of transactions: ";
    cin >> n;
    cout << "Enter support: ";
    cin >> sup;
    for (int i = 0; i < n; i++) {
        Transactions rule;
        rule.getInput();
        rule.display();
        rule.removeMinusOne();
    }

    return 0;
}
