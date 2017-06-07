#include <iostream>
#include <fstream>

#include "Konto.h"
#include "sortedList.h"
#define N 3

using namespace std;

int main() {
    SortedList banks[N]; /// Arrays of sortedList of banks [0: iPKO, 1: mBank, 2: AliorBank]
    string bankCodes[3]={"1020", "1140", "2490"}; ///[0]-iPKO, [1]-mBank, [2]-AliorBank
    string outputFilesNames[3]={"1020.txt","1140.txt","2490.txt"}; ///Array of output file names

    fstream data;
    string data_file_name;

    /**
    * Take from user file name to open and check if it's opened properly
    * If not, take file name again until name will be good
    */
    do{
        cout<<"Podaj nazwe pliku z numerami kont bankowych: ";
        cin>>data_file_name; /// Take file name from standard output

        data.open(data_file_name.c_str(), ios::in); /// Open file in read only state

        if(data==NULL) /// if file will be not founded write information
            cout<<"Plik o nazwie "<<data_file_name<<" nie istnieje. Sprawdz poprawnosc wprowadzanych danych."<<endl;
        else
            cout<<"Plik zostal otwarty poprawnie."<<endl;
    } while(data==NULL);

    /**
    * read lines from file. Stop when reaches end of file
    * Every time make new Konto variable and pass read line
    * Check in every line bank code and assign it to proper SortedList
    */
    while(!data.eof()) {
        string line;
        getline(data, line);

        Konto k(line);

        for(int i=0; i<N; i++) {
            if((k.getBankCode().compare(bankCodes[i]))==0)
                banks[i].insert(k);
        }
    }

    data.close(); /// Close file after operations

    ofstream outputFiles[N];

    /**
    * Write to proper files sorted IBAN numbers from each SortedList
    */
    for(int i=0; i<N; i++) {
        outputFiles[i].open(outputFilesNames[i].c_str());

        if(outputFiles[i].bad()) {
            cout<<"Plik o nazwie "<<outputFilesNames[i]<<" nie zostal stworzony.\n";
            break;
        }

        while(!banks[i].isEmpty()) {
            outputFiles[i]<<banks[i].pop().getIBANNumber()<<endl;
        }

        outputFiles[i].close();
        cout<<"Dane zostaly poprawnie zapisane do pliku "<<outputFilesNames[i]<<endl;
    }

    return 0;
}
