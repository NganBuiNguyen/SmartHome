II. Setting boost_1_62_0
========================

Download boost_1_62_0.tar.gz and moving to folder thirparties.

Step 4: tar -xvf boost_1_62_0.tar.gz

Step 5: moving  boost_1_62_0 to development :
                
            mv /development/thirparties/boost_1_62_0 /development

Step 6: cd /development/boost_1_62_0

Step 7: ./bootstrap.sh --with-libraries=all --with-python=/development/python-3.5.2/bin/
            --prefix=/development/boost_1_62_0

Step 8: ./b2 variant=release toolset=gcc link=shared threading=multi runtime-link=shared install

Step 9: ./b2 install