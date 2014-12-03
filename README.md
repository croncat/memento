MEMENTO
=======

## Getting the source

You can either download the source using the "ZIP" button at the top
of the github page, or you can make a clone using git:

```
git clone https://github.com/croncat/croncat.git
```


## Install

```
$ make
# make install
```


## Usage

For help, type 'memento' in your terminal.

```
memento 0.1a [alpha] ( http://github.com/croncat/memento )
Usage: memento [OPTION] {ARGUMENT/S}
OPTIONS:
  -l: list all categories
  -a: add category
  -d: delete category
  -n: add new note/message to category
  -s: show all notes/messages in category
  -r: remove note/message from category
EXAMPLES:
  memento -l
  memento -a netlog
  memento -d commands
  memento -n quotes "my first quote, yeah!"
  memento -s films
  memento -r quotes 151
memento: fast and minimalist note-taking application
```