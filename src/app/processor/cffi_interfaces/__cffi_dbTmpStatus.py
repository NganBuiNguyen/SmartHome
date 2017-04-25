import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

DATA_TYPE_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'dataConverter'))

DBTMPSTATUS_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'dbManager', 'cWrapperData'))
DBTMPSTATUS_FOR_C_LIBS = ["DbDataForC"]

#define common libraries
POCO_ROOT = os.getenv('POCO_ROOT')
POCO_INCLUDES = os.path.sep.join((POCO_ROOT, 'include'))
POCO_LIB_DIR = os.path.sep.join((POCO_ROOT, 'lib'))
POCO_LIBS = ["PocoFoundation", 'PocoFoundationd', "PocoData", 'PocoDatad', 'stdc++']


#define mysql libraries
MYSQL_ROOT = os.getenv('MYSQL_ROOT')
MYSQL_CONN_INCLUDES = os.path.sep.join((MYSQL_ROOT, 'include'))
MYSQL_CONN_LIB_DIR = os.path.sep.join((MYSQL_ROOT, 'lib'))
MYSQL_CONN_LIBS = ["mysqlcppconn", 'stdc++']

dbTmpStatus_cffi = cffi.FFI()
dbTmpStatus_cffi.cdef("""
    #define NAME_CARD_PERSON_LENGTH 20
    #define NAME_DOOR_ROOM 10

    typedef struct
    {
        int year ;
        int month ;
        int day ;
        int sec ;   
        int min ;   
        int hour ;
    }Date_Time;

    typedef struct
    {
        int idPerson;
        char namePerson[NAME_CARD_PERSON_LENGTH];
        int age;
        bool grantPerson;
        int idRoom;
    }Person;

    typedef struct
    {
        char idCard[NAME_CARD_PERSON_LENGTH];
        char typeCard[NAME_CARD_PERSON_LENGTH];
        int idPerson;
    }Card;

    typedef struct
    {
        int idDoor;
        char nameDoor[NAME_DOOR_ROOM]; 
    }Door;

    typedef struct
    {
        int idIP;
        char ip[20];
        long port;
        int idDoor;
    }IP;

    typedef struct
    {
        int idRoom;
        char nameRoom[NAME_DOOR_ROOM];
        int idDoor;
    }Room;

    typedef struct
    {
        Date_Time dateTime;
        Card card;
        Person person;
        Door door;
        Room room;
        IP ip_port;
    }CardInfo;
      
    
    
""")

dbTmpStatus_c = dbTmpStatus_cffi.verify("""
                #include "DbTmpStatusForC.h"
                #include "DataDef.h"
                #include "DbCardForC.h"
                """,
                include_dirs = [DBTMPSTATUS_FOR_C_INCLUDES, POCO_INCLUDES, 
                               MYSQL_CONN_INCLUDES, DATA_TYPE_DEF_INCLUDES],
                libraries = DBTMPSTATUS_FOR_C_LIBS + MYSQL_CONN_LIBS + POCO_LIBS,
                library_dirs = [LIDT_LIBS, MYSQL_CONN_LIB_DIR, POCO_LIB_DIR],
                modulename = "__cffi_dbTmpStatus")
