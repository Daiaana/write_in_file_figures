//создать бинарный файл, записать в него числа от a до b с шагом h. вывести компоненты файла через одну, начиная со второй

#include <iostream>
#include "fstream"
using namespace std;

int main()
{
    ofstream out("f.dat", ios::binary);
    double a, b, h, i;
    cout << 'a = ';
    cin >> a;
    cout << 'b = ';
    cin >> b;
    cout << 'h = ';
    cin >> h;
    for (i = a; i < b; i += h)
        out.write((char*)&i, sizeof(i));
    out.close();
    ifstream in("f.dat", ios::binary);
    in.seekg(sizeof(double));
    while (in.peek() != EOF) {
        in.read((char*)&i, sizeof(double));
        cout << i << ' ';
        in.seekg(sizeof(double), ios::cur);
    }
    in.close();
    return 0;
}
