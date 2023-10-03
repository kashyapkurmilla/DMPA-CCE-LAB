#include <iostream>
#include <fstream>
using namespace std;

void read_db(int k, int numlines, string C[], char elements[][50], int lengths[], string tid[])
{

    string temp = "";

    for (int i = 0; i <= numlines; i++)

    {
        cout << "Read transaction\tTID=" << tid[i] << "\tElements= ";
        for (int j = 0; j < lengths[i]; j++){
            cout << elements[i][j] << " ";
        }
        cout << endl;
    }
    C[k] = temp;
}
int main()
{

    string data1;
    string tid[50];
    char elements[50][50];
    int lengths[50];
    int i = -1;
    ifstream file1("file1.txt");
    while (getline(file1, data1))
    {
        ++i;
        string line = data1;
        tid[i] = line[0];
        int len = (line.size()) / 2;
        int count1 = 2;
        lengths[i] = len;
        for (int j = 0; j < len; j++)
        {
            elements[i][j] = line[count1];
            count1 = count1 + 2;
        }
        cout << line << "\n";
    }
    cout << "TID:\tTransaction\tNum\n";
    for (int j = 0; j <= i; j++){
        cout << tid[j] << "\t";
        for (int k = 0; k < lengths[j]; k++){
            cout << elements[j][k] << "\t";
        }
        cout << lengths[j] << "\n";
    }
    file1.close();
    int numlines = i;
    int k = 1, support = 2;
    string C[50], L[50];
    read_db(1, numlines, C, elements, lengths, tid);
    return 0;
}
