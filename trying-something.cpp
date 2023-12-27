#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // freopen("read-file.txt" , "rt" , stdin);
    // freopen("output-file.txt" , "wt" , stdout);
    // int x , y;

    // cin>>x>>y;
        ifstream fin("read-file.txt");
        ofstream fout("output-file.txt");
        int x = 0;
        int arr[10];

    while(x < 10)
    {
        if (fin.fail()){
            cout<<"cant open the input file\n";
            return 0;
        }

        fin>>arr[x];
        x++;
        // fin.close();

    }

    for (int i = 0; i < 10; i++)
    {
          if (fout.fail()){
            fout<<"cant open the output file\n";
            return 0;
        }
        fout<<arr[i]<<"\n";
    }
    
    return 0;
}