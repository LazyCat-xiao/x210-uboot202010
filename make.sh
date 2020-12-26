#!/bin/bash
export CROSS_COMPILE=arm-linux-gnueabihf-
make -j24 
rm -f 210.bin
./mkmini210 u-boot.bin 210.bin