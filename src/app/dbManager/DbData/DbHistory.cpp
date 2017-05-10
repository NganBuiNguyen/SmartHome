 #include "DbHistory.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

/*!
 * @internal Default Constructor
 */
DbHistory::DbHistory()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbHistory::closeConn()
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

bool DbHistory::selectToDbHistory(std::vector<CardInfo*>& vectorCardInfos)
{       

    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT * FROM tbl_History");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->card.idCard,(char*)res->getString("IDCard").c_str());
            strcpy(item->ip_port.ip,(char*)res->getString("IP").c_str());
            char* port = new char[PORT];
            strcpy(port,(char*)res->getString("Port").c_str());
            item->ip_port.port = atol(port);
            item->dateTime.day = res->getInt("Day");
            item->dateTime.month = res->getInt("Mon");
            item->dateTime.year = res->getInt("Year");
            item->dateTime.hour = res->getInt("Hour");
            item->dateTime.min = res->getInt("Min");
            item->dateTime.sec = res->getInt("Sec");
            vectorCardInfos.push_back(item);
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


