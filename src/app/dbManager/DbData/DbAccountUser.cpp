#include "DbAccountUser.h"



static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

/*!
 * @internal Default Constructor
 */
DbAccountUser::DbAccountUser()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbAccountUser::closeConn()
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

bool DbAccountUser::insertToDbAccountUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_User (IDUser, GrantUser, NameUser, Password) values(?,?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.person.idPerson);

        if(info.person.grantPerson == true){
            (this->prep_stmt)->setInt(2, 1);
        }
        else{
            (this->prep_stmt)->setInt(2, 0);
        }

        (this->prep_stmt)->setString(3, info.person.userName);
        (this->prep_stmt)->setString(4, info.person.password);
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

bool DbAccountUser::selectToDbAccountUser(std::vector<CardInfo*>& vectorCardInfos)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    try{
        stmt = MYSQL_DB_CONNECTION->createStatement();
        this->res = stmt->executeQuery("SELECT * FROM tbl_User");
        while (res->next())
        {
            CardInfo* item = new CardInfo;
            strcpy(item->person.idPerson,(char*)res->getString("IDUser").c_str());
            if(res->getInt("GrantUser") == 1){
                item->person.grantPerson = true;
            }else{
                item->person.grantPerson = false;
            }
            strcpy(item->person.userName,(char*)res->getString("UserName").c_str());
            strcpy(item->person.password,(char*)res->getString("Password").c_str());
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

bool DbAccountUser::updateToDbAccountUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);

    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_User SET GrantUser = ? UserName = ? Password = ? WHERE IDUser = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        if(info.person.grantPerson == true){
            (this->prep_stmt)->setInt(1, 1);
        }
        else{
            (this->prep_stmt)->setInt(1, 0);
        }
        (this->prep_stmt)->setString(2, info.person.userName);
        (this->prep_stmt)->setString(3, info.person.password);
        (this->prep_stmt)->setString(4, info.person.idPerson);
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

bool DbAccountUser::deleteToDbAccountUser(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_User WHERE IDCard = ?");

    (this->prep_stmt)->setString(1,info.person.idPerson);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
