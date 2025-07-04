#!/bin/bash

clear

FLAG="-lcrypto -lssl -lz" # -largon2
NAME="service"
FILE=$(mktemp)

if [ ! -d "./Build" ] ; then 
  mkdir "./Build"
fi

echo -e "\nKilling Service" ; $( killall $NAME )

echo -e "\nCompiling Service"
if !( g++ -o ./Build/$NAME ./Services/$NAME.cpp -I ./Modules $FLAG ) 2> "$FILE"; then
      echo -e "\n" ; cat "$FILE" >&2 ; exit
else
      echo -e "Done"
fi

echo -e "\nRunning Service" ; ./Build/$NAME;
