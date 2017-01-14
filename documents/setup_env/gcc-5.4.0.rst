VI. Setting gcc-5.4.0
=======================

Download gcc-5.4.0.tar.gz and moving to folder thirparties.

**The step install are:**

Step 1: tar -xvf gcc-5.4.0.tar.gz

Step 2: cd gcc-5.4.0

Step 3: sudo apt-get install gcc-multilib

Step 4: ./configure --enable-languages=c,c++ --enable-multiarch --enable-shared --enable-threads=posix --with-gmp=/development/gmp-6.1.1 --with-mpc=/development/mpc-1.0.2 --with-mpfr=/development/mpfr-3.1.4 --prefix=/development/gcc-5.4.0

Step 5: make -j4

Step 6: make install

