#include <string>
#include <vector>
#include <iostream>
#include "preprocess.h"

using namespace std;

void clearScreen();

int main()
{
    Preprocess pre;
    vector<string> folder_name;
    string path = pre.create_pixels_txt(folder_name); //return folde path
    cout << "Path : " << path;
    pre.show(folder_name);
    return 0;
}
