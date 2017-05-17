 #include "DbRoom.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);
    
DbRoom::DbRoom()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbRoom::closeConn()
{
    if(this->res!=NULL)
    {
        delete this->res;
    }
    if(this->stmt !=NULL)
    {
        delete this->stmt;
    }
    if(this->prep_stmt !=NULL)
    {
        delete this->prep_stmt;
    }
}

bool DbRoom::insertToDbRoom(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Room (IDRoom,NameRoom) values(?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.room.idRoom);
        (this->prep_stmt)->setString(2, info.room.nameRoom);

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

bool DbRoom::selectToDbRoom(std::vector<CardInfo>& vectorCardInfos)
{
    vectorCardInfos.clear();
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT * FROM tbl_Room");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->room.idRoom,(char*)res->getString("IDRoom").c_str());
            strcpy(item->room.nameRoom,(char*)res->getString("NameRoom").c_str());
            vectorCardInfos.push_back(*item);
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

bool DbRoom::updateToDbRoom(const CardInfo &info)
{
    
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_Room SET NameRoom = ? WHERE IDRoom = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        (this->prep_stmt)->setString(1, info.room.nameRoom);
        (this->prep_stmt)->setString(2, info.room.idRoom);

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

bool DbRoom::deleteToDbRoom(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_Room WHERE IDRoom = ?");

    (this->prep_stmt)->setString(1, info.room.idRoom);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
