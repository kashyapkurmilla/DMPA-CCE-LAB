#include <iostream>
using namespace std;

class Transactions {
private:
    char tid[2];
    char itemset[99];

public:
    Transactions() {
        tid = 0;
    }

    void getInput() {
        int temp;
        cout << "Enter transaction id: ";
        cin >> tid;
        cout << "Enter itemsets (enter -1 to stop): ";
        int k = 0;
        while (k < 99) { // Limit the number of items to 99 to avoid array overflow
            cin >> temp;
            if (temp == -1)
                break;
            else {
                itemset[k] = temp;
                k++;
            }
        }
    }

    void display() {
        cout << "Transaction id: " << tid << endl;
        cout << "Itemsets: ";
        for (int i = 0; i <10; i++) {
            if (itemset[i] == -1)
                break;
            cout << itemset[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Transactions rule;
    int n;
    double sup , con ;
    cout<<"Enter number of transactions : ";
    cin>>n;
    cout<<"Enter support : ";
    cin>>sup;
    cout<<"Enter Confidence :";
    cin>>con;
    rule.getInput();
    rule.display();
    return 0;
}

