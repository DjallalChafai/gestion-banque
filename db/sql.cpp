#include <iostream>
#include <sqlite3.h>
#include <string.h>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(){
    sqlite3 *BB, *N26, *RV;
    char *zErrMsg = 0;
    int bb, n26, rv;

    bb = sqlite3_open("Boursorama.db", &BB);
    n26 = sqlite3_open("N26.db", &N26);
    rv = sqlite3_open("Revolut.db", &RV);

    char *sql, *query;

    if(!BB || !N26 || !RV)
    {
        cout<<"Can't open database %s"<<sqlite3_errmsg(BB)<<sqlite3_errmsg(N26)<<sqlite3_errmsg(RV)<<endl;
        
        return 1;
    }
    else
    {
        cout<<"Opened database successfully"<<endl;
    }
    
    /* Create SQL statement */
   sql = "CREATE TABLE INFO("  \
    "ID INTEGER PRIMARY KEY     NOT NULL," \
    "FIRST_NAME           TEXT    NOT NULL," \
    "LAST_NAME           TEXT    NOT NULL)"; //\
    // "ADDRESS        CHAR(50)    NOT NULL," \
    // "EMAIL        CHAR(50)     NOT NULL," \
    // "PHONE         REAL     NOT NULL,"\
    // "ACCOUNT_NUMBER            INT     NOT NULL," \
    // "PASSWORD        CHAR(50)     NOT NULL);";

    query = "SELECT * FROM INFO";
  
    sqlite3_exec(BB, query, callback, 0, &zErrMsg);

    sqlite3_exec(BB, sql, callback, 0, &zErrMsg);

    sql = "INSERT INTO INFO VALUES (NULL, 'Mehdi', 'Chafai');";//, 'Algérie', 'bougnoule@oran.dz', '+213000000000', '12345678910', 'Bougnoule@');";

    sqlite3_exec(BB, sql, callback, 0, &zErrMsg);


    if(rv && n26 && bb != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
   else 
   {
        fprintf(stdout, "Successfully\n");
   }

    sqlite3_close(BB);
    sqlite3_close(N26);
    sqlite3_close(RV);

    return 0;
}