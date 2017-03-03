#include "DbCard.h"



static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                    MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

/*!
 * @internal Default Constructor
 */
DbCard::DbCard()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}

void DbCard::closeConn()
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

bool DbCard::insert_to_db_Card(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Card (IDCard,kindCard,IDPerson) values(?,?,?)");
    if (this->prep_stmt == NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.card.nameKindCard);
        (this->prep_stmt)->setInt(3, info.card.idPerson);
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

char* DbCard::select_to_db_Card()
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);

    std::vector<std::string> v;

    stmt = MYSQL_DB_CONNECTION->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_Card");
    while (res->next())
    {
        v.push_back(res->getString("IDCard"));
        
    }
    char *arr[10];
    for(std::vector<std::string>::iterator it = v.begin(); it != v.end() ; ++it )
        {
            //std::cout << *it <<std::endl;
            
                strcpy(arr, (*it).c_str());
                std::cout<<"ArrCard : "<<arr<<std::endl;
        }
    
    MYSQL_DB_CONNECTION->commit();
    
    this->closeConn();
    return arr;
}

bool DbCard::update_to_db_Card(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    //this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_Card SET kindCard = ? WHERE IDCard = ?");
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("UPDATE tbl_Card SET IDPerson = ? WHERE IDCard = ?");
    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;
    try
    {
        (this->prep_stmt)->setString(2, info.card.idCard);
        //(this->prep_stmt)->setString(2, info.card.nameKindCard);
        (this->prep_stmt)->setInt(1, info.card.idPerson);
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

bool DbCard::delete_to_db_Card(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("DELETE FROM tbl_Card WHERE IDCard = ?");

    (this->prep_stmt)->setString(1,info.card.idCard);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
