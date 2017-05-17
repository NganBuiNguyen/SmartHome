#include "DbPerson.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);


DbPerson::DbPerson()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbPerson::closeConn()
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

bool DbPerson::insertToDbInfoUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_InfoUser (IDUser, NameUser, Age) values(?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.person.idPerson);
        (this->prep_stmt)->setString(2, info.person.namePerson);
        (this->prep_stmt)->setInt(3, info.person.age);
        // (this->prep_stmt)->setBoolean(4, info.person.grantPerson);
        // (this->prep_stmt)->setInt(5, info.person.idRoom);
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

bool DbPerson::selectToDbInfoUser(std::vector<CardInfo>& vectorCardInfos)
{
    vectorCardInfos.clear();
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT * FROM tbl_InfoUser");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->person.idPerson,(char*)res->getString("IDUser").c_str());
            strcpy(item->person.namePerson,(char*)res->getString("NameUser").c_str());
            item->person.age = res->getInt("Age");
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

bool DbPerson::updateToDbInfoUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);

    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_InfoUser SET NameUser = ? Age = ? WHERE IDUser = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        (this->prep_stmt)->setString(3, info.person.idPerson);
        (this->prep_stmt)->setString(1, info.person.namePerson);
        (this->prep_stmt)->setInt(2, info.person.age);
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
    //(this->prep_stmt)->executeUpdate();
    MYSQL_DB_CONNECTION->commit();
    this->closeConn();
    return true;
}

bool DbPerson::deleteToDbInfoUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_InfoUser WHERE IDUser = ?");

    (this->prep_stmt)->setString(1,info.card.idCard);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}


