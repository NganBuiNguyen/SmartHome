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

bool DbHistory::insertToDbHistory(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_History (Day,Mon,Year,Hour,Min,Sec,StatusDoor,CheckCard) values(?,?,?,?,?,?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setInt(1, info.dateTime.day);
        (this->prep_stmt)->setInt(2, info.dateTime.month);
        (this->prep_stmt)->setInt(3, info.dateTime.year);
        (this->prep_stmt)->setInt(4, info.dateTime.hour);
        (this->prep_stmt)->setInt(5, info.dateTime.min);
        (this->prep_stmt)->setInt(6, info.dateTime.sec);
        

        if(info.history.statusDoor == true){
            (this->prep_stmt)->setInt(7, 1);
        }
        else{
            (this->prep_stmt)->setInt(7, 0);
        }

        if(info.history.checkCard == true){
            (this->prep_stmt)->setInt(8, 1);
        }
        else{
            (this->prep_stmt)->setInt(8, 0);
        }

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

bool DbHistory::selectToDbHistory(std::vector<CardInfo*>& vectorCardInfos)
{       

    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT Day,Mon,Year,Hour,Min,Sec,StatusDoor,CheckCard FROM tbl_History");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            // strcpy(item->card.idCard,(char*)res->getString("ID").c_str());
            // strcpy(item->door.ip,(char*)res->getString("IP").c_str());
            // char* port = new char[PORT];
            // strcpy(port,(char*)res->getString("Port").c_str());
            // item->door.port = atol(port);
            item->dateTime.day = res->getInt("Day");
            item->dateTime.month = res->getInt("Mon");
            item->dateTime.year = res->getInt("Year");
            item->dateTime.hour = res->getInt("Hour");
            item->dateTime.min = res->getInt("Min");
            item->dateTime.sec = res->getInt("Sec");

            if(res->getInt("StatusDoor") == 1){
                item->history.statusDoor = true;
            }else{
                item->history.statusDoor = false;
            }

            if(res->getInt("CheckCard") == 1){
                item->history.checkCard = true;
            }else{
                item->history.checkCard = false;
            }
            
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


