#!/bin/sh
rm -f ~/Development/versatile_ckernel/busybox-1.25.0/miscutils/ckernel_call.o
cd ~/Development/versatile_ckernel/busybox-1.25.0
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- install
cd ~/Development/versatile_ckernel/busybox-1.25.0/_install
find . | cpio -o --format=newc > ../rootfs.img
gzip -c ../rootfs.img > ../rootfs.img.gz
