#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // freopen("read-file.txt" , "rt" , stdin);
    // freopen("output-file.txt" , "wt" , stdout);
    // int x , y;

    // cin>>x>>y;

    ifstream fin('just-created-file.txt');

    if (fin.fail())
    {
        cout<<"cant open the file\n";
        return 0;
    }
    int x , y;
    fin>>x>>y;

    cout<<x + y;

    fin.close();

    return 0;
}