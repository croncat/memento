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

#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memento.h"

namespace Cli
{
    void AddCategory(int argc, char *argv[])
    {
        if (argc == 3 && strncmp(argv[1],"-a", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::AddCategory(argv[2]);
            exit(0);
        }
    }

    void ListCategories(int argc, char *argv[])
    {
        if (argc == 2 && strncmp(argv[1],"-l", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::ListCategories();
            exit(0);
        }
    }

    void DeleteCategory(int argc, char *argv[])
    {
        if (argc == 3 && strncmp(argv[1],"-d", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::DeleteCategory(argv[2]);
            exit(0);
        }
    }

    void NewMessage(int argc, char *argv[])
    {
        if (argc == 4 && strncmp(argv[1],"-n", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::NewMessage(argv[2], argv[3]);
            exit(0);
        }
    }

    void ShowMessages(int argc, char *argv[])
    {
        if (argc == 3 && strncmp(argv[1],"-s", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::ShowMessages(argv[2]);
            exit(0);
        }
    }

    void RemoveMessage(int argc, char *argv[])
    {
        if (argc == 4 && strncmp(argv[1],"-r", 2) == 0 && strlen(argv[1]) == 2) {

            Memento::RemoveMessage(argv[2], argv[3]);
            exit(0);
        }
    }

    void HelpFeature()
    {
        printf( "memento 0.1a [alpha] ( http://github.com/croncat/memento )\n"
            "Usage: memento [OPTION] {ARGUMENT/S}\n"
            "OPTIONS:\n"
            "  -l: list all categories\n"
            "  -a: add category\n"
            "  -d: delete category\n"
            "  -n: add new note/message to category\n"
            "  -s: show all notes/messages in category\n"
            "  -r: remove note/message from category\n"
            "EXAMPLES:\n"
            "  memento -l\n"
            "  memento -a netlog\n"
            "  memento -d commands\n"
            "  memento -n quotes \"my first quote, yeah!\"\n"
            "  memento -s films\n"
            "  memento -r quotes 151\n"
            "memento: fast and minimalist note-taking application\n");

        exit(0);
    }
}

#endif
