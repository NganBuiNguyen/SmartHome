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
    #define PORT 10

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
        char idPerson[PORT];
        char namePerson[NAME_CARD_PERSON_LENGTH];
        int age;
        bool grantPerson;
        char userName[NAME_CARD_PERSON_LENGTH];
        char password[PORT];
    }Person;

    typedef struct
    {
        char idCard[NAME_CARD_PERSON_LENGTH];
        char idPerson[PORT];
    }Card;

    typedef struct
    {
        char idDoor[PORT];
        char nameDoor[NAME_DOOR_ROOM];
        char ip[20];
        long port;
        char idRoom[PORT];
    }Door;

    typedef struct
    {
        char idRoom[PORT];
        char nameRoom[NAME_DOOR_ROOM];
    }Room;

    typedef struct  
    {
        bool statusDoor;
        bool checkCard; 
    }History;

    typedef struct
    {
        Date_Time dateTime;
        Card card;
        Person person;
        Door door;
        Room room;
        History history;
    }CardInfo;

    typedef struct  
    {
        void* result; 
        int numberOfElement; 
    }DBAResult;

    bool insertToDbCardForC(const CardInfo* info);
    bool selectToDbCardForC(CardInfo** info, int *numberOfElement);
    bool updateToDbCardForC(const CardInfo* info);
    bool deleteToDbCardForC(const CardInfo* info);


    bool insertToDbDoorForC(const CardInfo* info);
    bool selectToDbDoorForC(const CardInfo** info, int *numberOfElement);
    bool updateToDbDoorForC(const CardInfo* info);
    bool deleteToDbDoorForC(const CardInfo* info);


    bool insertToDbRoomForC(const CardInfo* info);
    bool selectToDbRoomForC(const CardInfo** info, int *numberOfElement);
    bool updateToDbRoomForC(const CardInfo* info);
    bool deleteToDbRoomForC(const CardInfo* info);

    bool insertToDbPersonForC(const CardInfo* info);
    bool selectToDbPersonForC(const CardInfo** info, int *numberOfElement);
    bool updateToDbPersonForC(const CardInfo* info);
    bool deleteToDbPersonForC(const CardInfo* info);

    bool insertToDbDoorCardForC(const CardInfo* info);
    bool selectToDbDoorCardForC(const CardInfo** info, int *numberOfElement);
    bool updateToDbDoorCardForC(const CardInfo* info,int id);
    bool deleteToDbDoorCardForC(const CardInfo* info,int id);

    bool insertToDbAccountUserForC(const CardInfo* info);
    bool selectToDbAccountUserForC(const CardInfo** info, int *numberOfElement);
    bool updateToDbAccountUserForC(const CardInfo* info);
    bool deleteToDbAccountUserForC(const CardInfo* info);

    bool insertToDbHistoryForC(const CardInfo* info);
    bool selectToDbHistoryForC(const CardInfo** info, int *numberOfElement);
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
