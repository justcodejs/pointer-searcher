#!/bin/sh

DIRECTORY="bin"
NAMEPROJECT="project"
SOURCEFILES="src/main.cpp"

if [ ! -d $DIRECTORY ]; then
    mkdir $DIRECTORY
    g++ $SOURCEFILES -o $DIRECTORY/$NAMEPROJECT -std=c++11
else
    g++ $SOURCEFILES -o $DIRECTORY/$NAMEPROJECT -std=c++11
fi

./$DIRECTORY/$NAMEPROJECT