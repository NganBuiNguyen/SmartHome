import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

DATA_TYPE_DEF_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 'app', 'dataConverter'))

DBCARD_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'dbManager', 'cWrapperData'))
DBCARD_FOR_C_LIBS = ["DbDataForC"]

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

dbCard_cffi = cffi.FFI()
dbCard_cffi.cdef("""
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

    bool insert_to_db_Card_ForC(CardInfo* info); 
    bool update_to_db_Card_ForC(CardInfo* info);
    bool selectToDbCardForC(const CardInfo** info, int *numberOfElement);
    bool delete_to_db_Card_ForC(CardInfo* info);
    bool insertToDbHistoryForC (const CardInfo* info);
""")

dbCard_c = dbCard_cffi.verify("""
                #include "DbCardForC.h"
                #include "DataDef.h"
                """,
                include_dirs = [DBCARD_FOR_C_INCLUDES, POCO_INCLUDES, 
                               MYSQL_CONN_INCLUDES, DATA_TYPE_DEF_INCLUDES],
                libraries = DBCARD_FOR_C_LIBS + MYSQL_CONN_LIBS + POCO_LIBS,
                library_dirs = [LIDT_LIBS, MYSQL_CONN_LIB_DIR, POCO_LIB_DIR],
                modulename = "__cffi_dbCard")
