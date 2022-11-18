#include <iostream>
#include <sqlite3.h>
using namespace std;

int main(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int BB, N26, Rv;

    BB = sqlite3_open("Boursorama.db", &db);
    N26 = sqlite3_open("N26.db", &db);
    Rv = sqlite3_open("Revolut.db", &db);



    if(BB && N26 && Rv)
    {
        cout<<"Can't open database %s"<<sqlite3_errmsg(db)<<endl;
        return 0;
    }
    else
    {
        cout<<"Opened database successfully"<<endl;
    }
    sqlite3_close(db);
}