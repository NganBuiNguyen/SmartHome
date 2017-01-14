II.Setting python-3.5.2:
========================

Download python-3.5.2.tar.gz and moving to folder thirparties.

Step 4: tar -xvf Python-3.5.2.tar.gz

Step 5: cd Python-3.5.2

Step 6: export PATH=/development/gcc-5.4.0:$PATH

        export PATH=/development/gcc-5.4.0/bin:$PATH

Step 7: ./configure --prefix=/development/python3

Step 8: make

Step 9: make install

Step 10: cd /development/python3

Step 11: export PATH=/development/python3:$PATH

         export PATH=/development/python3/bin:$PATH

Step 12: which python3

**BUG** Bug in step 9: "Ignoring ensurepip failure: pip 8.1.1 requires SSL/TLS //make install"

**FIX BUG**
    (1). sudo apt-get install libssl-dev
    
    (2). Again Step 9: make intall