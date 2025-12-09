#!/bin/bash

clear

FLAG="-lcrypto -lssl -lz" # -largon2
NAME="service"
FILE=$(mktemp)

if [ ! -d "./build" ] ; then 
    mkdir "./build"
fi

echo -e "Killing Service\n" ; $( killall $NAME )

echo -e "Compiling Service\n"
if !( g++ -o ./build/$NAME ./service/$NAME.cpp -I ./include $FLAG ) 2> "$FILE"; then
      echo -e "\n" ; cat "$FILE" >&2 ; exit
else
      echo -e "Done"
fi

echo -e "\nRunning Service" ; ./build/$NAME; ./build/$NAME ?mode=test
