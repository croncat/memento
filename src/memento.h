/* Copyright (c) 2014, Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * * Neither the name of memento nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MEMENTO_H
#define MEMENTO_H

#include <stdlib.h>
#include <sqlite3.h>

namespace Memento
{
    sqlite3 *db;

    static int callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        int i;
        for(i=0; i<argc; i++) {
            printf("* %s\n", argv[i] ? argv[i] : "NULL");
        }
        //printf("\n");
        return 0;
    }

    void OpenMementoDatabase()
    {
        const char* home;
        char path[256];
        int rc;
        
        home = getenv("HOME");
        sprintf(path, "%s/.memento.db", home);
        
        rc = sqlite3_open(path, &db);
        if(rc) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
        }
    }

    void ExecMementoDatabase(char *query)
    {
        int rc;
        char *zErrMsg = 0;

        rc = sqlite3_exec(db, query, callback, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    } 

    void ListCategories()
    {
        char query[256];

        sprintf(query, "SELECT name FROM sqlite_master WHERE type = \"table\" AND name != \"sqlite_sequence\"");

        OpenMementoDatabase();
        ExecMementoDatabase(query);
        sqlite3_close(db);
    }

    void AddCategory(const char *category)
    {
        char query[256];

        sprintf(query, "CREATE TABLE %s(ID INTEGER PRIMARY KEY AUTOINCREMENT, MESSAGE TEXT NOT NULL)", category);

        OpenMementoDatabase();
        ExecMementoDatabase(query);
        sqlite3_close(db);
    }

    void DeleteCategory(const char *category)
    {
        char query[256];

        sprintf(query, "DROP TABLE %s", category);

        OpenMementoDatabase();
        ExecMementoDatabase(query);
        sqlite3_close(db);
    }

    void NewMessage(const char *category, const char *message)
    {
        char query[2048];

        sprintf(query, "INSERT INTO %s (MESSAGE) VALUES ('%s')", category, message);

        OpenMementoDatabase();
        ExecMementoDatabase(query);
        sqlite3_close(db);
    }

    void ShowMessages(const char *category)
    {
        char query[256];

        sprintf(query, "SELECT MESSAGE FROM %s", category);

        OpenMementoDatabase();
        ExecMementoDatabase(query);
        sqlite3_close(db);
    }
}

#endif
