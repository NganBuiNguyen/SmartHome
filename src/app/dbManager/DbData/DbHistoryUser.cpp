 #include "DbHistoryUser.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

/*!
 * @internal Default Constructor
 */
DbHistoryUser::DbHistoryUser()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbHistoryUser::closeConn()
{
    if(this->res != NULL)
    {
        delete this->res;
        this->res = NULL;
    }

    if (this->stmt != NULL)
    {
        delete this->stmt;
        this->stmt = NULL;
    }

    if (this->prep_stmt != NULL)
    {
        delete this->prep_stmt;
        this->prep_stmt = NULL;
    }
}

bool DbHistoryUser::insertToDbHistoryUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_HistoryUser (DateTime,StatusDoor,CheckCard,ID) values(?,?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.dateTime.dataDateTime);
        // (this->prep_stmt)->setInt(2, info.dateTime.month);
        // (this->prep_stmt)->setInt(3, info.dateTime.year);
        // (this->prep_stmt)->setInt(4, info.dateTime.hour);
        // (this->prep_stmt)->setInt(5, info.dateTime.min);
        // (this->prep_stmt)->setInt(6, info.dateTime.sec);
        
        if(info.history.statusDoor == true){
            (this->prep_stmt)->setInt(2, 1);
        }
        else{
            (this->prep_stmt)->setInt(2, 0);
        }

        if(info.history.checkCard == true){
            (this->prep_stmt)->setInt(3, 1);
        }
        else{
            (this->prep_stmt)->setInt(3, 0);
        }

        (this->prep_stmt)->setInt(4, info.history.id);
        // (this->prep_stmt)->setString(5, info.history.countTime);

        result = (this->prep_stmt)->executeUpdate();

        if(result < NO_ROW_EFFECTED)
        {
            return false;
        }
    }
    catch(sql::SQLException& e)
    {
        MYSQL_DB_CONNECTION->rollback();
        return false;
    }

    MYSQL_DB_CONNECTION->commit();
    this->closeConn();
    return true;
}



