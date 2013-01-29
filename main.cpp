#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int partition(int* input, int p, int r)
{
    int pivot = input[r];

    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;

        while ( input[r] > pivot )
            r--;

        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }

    return r;
}

void quicksort(int* input, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input, p, r);
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int main()
{
    int c = 0, n=10000;
    int numbers[10000];
    string line;
    fstream myfile;
    myfile.open("data10k.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        stringstream(line)>>numbers[c];
        c++;
    }
//Laman ng Array
    /*for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }*/

    cout<<"\n\n\nSorting\n";
    quicksort(numbers, 0, n);

//Laman ng Sorted Array
    for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }
    myfile.close();

    return 0;
}
