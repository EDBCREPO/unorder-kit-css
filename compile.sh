#!/bin/bash

if [ ! -d "./build" ] ; then 
    mkdir "./build"
fi

if [ ! -d "./build/CmakeFiles" ] ; then
   ( cd build; cmake .. )
fi

( cd build; make ); 

if [ ! $? -eq 0 ]; then
    echo "exit error"; exit;
fi

./build/main ; ./build/main ?mode=test