 #include "DbDoor.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);
    
DbDoor::DbDoor()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbDoor::closeConn()
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

bool DbDoor::insertToDbDoor(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Door (IDDoor,NameDoor,IP,Port,IDRoom) values(?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.door.idDoor);
        (this->prep_stmt)->setString(2, info.door.nameDoor);
        (this->prep_stmt)->setString(3, info.door.ip);
        (this->prep_stmt)->setString(4, std::to_string(info.door.port));
        (this->prep_stmt)->setString(1, info.door.idRoom);
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

bool DbDoor::selectToDbDoor(std::vector<CardInfo*>& vectorCardInfos)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT * FROM tbl_Door");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->door.idDoor,(char*)res->getString("IDDoor").c_str());
            strcpy(item->door.nameDoor,(char*)res->getString("NameDoor").c_str());
            strcpy(item->door.ip,(char*)res->getString("IP").c_str());
            char* port = new char[PORT];
            strcpy(port,(char*)res->getString("Port").c_str());
            item->door.port = atol(port);
            strcpy(item->door.idRoom,(char*)res->getString("IDRoom").c_str());
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

bool DbDoor::updateToDbDoor(const CardInfo &info)
{
    
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_Door SET NameDoor = ? IP = ? Port = ? IDRoom = ? WHERE IDDoor = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        (this->prep_stmt)->setString(1, info.door.nameDoor);
        (this->prep_stmt)->setString(2, info.door.ip);
        (this->prep_stmt)->setString(3, std::to_string(info.door.port));
        (this->prep_stmt)->setString(4, info.door.idRoom);
        (this->prep_stmt)->setString(5, info.door.idDoor);

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

bool DbDoor::deleteToDbDoor(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_Door WHERE IDDoor = ?");

    (this->prep_stmt)->setString(1, info.door.idDoor);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
