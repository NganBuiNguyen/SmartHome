 #include "DbTmpStatus.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

/*!
 * @internal Default Constructor
 */
DbTmpStatus::DbTmpStatus()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbTmpStatus::closeConn()
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

bool DbTmpStatus::insert_to_db_TmpStatus(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement(INSERT_DB_TMP_STATUS);

    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        // (this->prep_stmt)->setInt(1, 1);
        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.ip_port.ip);
        (this->prep_stmt)->setInt(3, info.ip_port.port);
        (this->prep_stmt)->setInt(4, info.dateTime.day);
        (this->prep_stmt)->setInt(5, info.dateTime.mon);
        (this->prep_stmt)->setInt(6, info.dateTime.year);
        (this->prep_stmt)->setInt(7, info.dateTime.hour);
        (this->prep_stmt)->setInt(8, info.dateTime.min);
        (this->prep_stmt)->setInt(9, info.dateTime.sec);
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

bool DbTmpStatus::select_to_db_TmpStatus(int ID_TmpStatus)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    stmt = MYSQL_DB_CONNECTION->createStatement();
    this->res = stmt->executeQuery(SELECT_ID_TMP_STATUS);
    // this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement(SELECT_ID_TMP_STATUS);
    // (this->prep_stmt)->setInt(1,ID_TmpStatus);
     while (res->next())
    {
        std::cout << res->getInt("Sec") << std::endl;
    }
    
    MYSQL_DB_CONNECTION->commit();
    
    this->closeConn();
    return true;
}

