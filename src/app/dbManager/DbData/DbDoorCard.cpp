 #include "DbDoorCard.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);
    
DbDoorCard::DbDoorCard()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbDoorCard::closeConn()
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

bool DbDoorCard::insertToDbDoorCard(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Door_Card (IDCard,IDDoor) values(?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.door.idDoor);
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

bool DbDoorCard::selectToDbDoorCard(std::vector<CardInfo>& vectorCardInfos)
{
    vectorCardInfos.clear();
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT IDCard , IDDoor FROM tbl_Door_Card");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->card.idCard,(char*)res->getString("IDCard").c_str());
            strcpy(item->door.idDoor,(char*)res->getString("IDDoor").c_str());
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

bool DbDoorCard::updateToDbDoorCard(const CardInfo &info,int id)
{
    
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_Door_Card SET IDCard = ? IDDoor = ? WHERE ID = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.door.ip);
        (this->prep_stmt)->setInt(3, id);
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

bool DbDoorCard::deleteToDbDoorCard(const CardInfo &info,int id)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_Door_Card WHERE ID = ?");

    (this->prep_stmt)->setInt(1, id);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
