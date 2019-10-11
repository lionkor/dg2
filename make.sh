#!/bin/bash

clear
cd bin
rm dg2
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j 9
cd ..

