#include "DbStatus.h"

static sql::Driver* MYSQL_DRIVER_INSTANCE = get_driver_instance();
static sql::Connection* MYSQL_DB_CONNECTION =
                MYSQL_DRIVER_INSTANCE->connect(DBHOST, USER, PASSWORD);

DbStatus::DbStatus()
{
    this->prep_stmt = NULL;
    this->res = NULL;
    this->stmt = NULL;
    this->savept = NULL;
}
void DbStatus::closeConn()
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
bool DbStatus::insert_to_db_Status(const CardInfo &info, std::string& TimeIn)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);

    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Status(IDStatus ,IDCard, Ip ,Port ,TimeIn, TimeOut) values(?,?,?,?)");//chua insert card
    if(this->prep_stmt==NULL)
    {
        return false;
    }

    int result = NO_ROW_EFFECTED;

    try
    {
        (this->prep_stmt)->setString(1, status.getStatusID());
        (this->prep_stmt)->setBoolean(2, status.getStatusName());
        (this->prep_stmt)->setInt(3, (int) status.getTimeIn()) ;
        (this->prep_stmt)->setInt(4, (int) status.getTimeOut()) ;
        result = (this->prep_stmt)->executeUpdate();

        if(result < NO_ROW_EFFECTED)
        {
            return false;
        }
    }
    catch(sql::SQLException& e){
      MYSQL_DB_CONNECTION->rollback();
      return false;
    }
     
    MYSQL_DB_CONNECTION->commit();
    this->closeConn();
    return true;
}
void DbStatus::select_to_db_Status()
{
    DbStatus* dbStatus = DbStatus::getInstance();

    stmt = conn->createStatement();
    conn=dbStatus->getConn(this->user,this->password,this->url);

    this->res = stmt->executeQuery("SELECT * FROM Status");

     while (res->next())
    {
        std::cout << res->getString("statusID") << std::endl;
    }
    int updateCount = prep_stmt->executeUpdate();
    conn->commit();
    
    dbStatus->closeConn();
}
void DbStatus::update_to_db_Status(const CardInfo &info)
 {
  
    DbStatus* dbStatus = DbStatus::getInstance();

    conn= dbStatus->getConn(this->user,this->password,this->url);

    this->prep_stmt = conn->prepareStatement("UPDATE Status SET statusName = ? WHERE statusID = ?");

    (this->prep_stmt)->setBoolean(1, status.getStatusName());
    (this->prep_stmt)->setString(2, status.getStatusID());
    
    int updateCount = prep_stmt->executeUpdate();
    conn->commit();
    dbStatus->closeConn();
}
void DbStatus::delete_to_db_Status(const CardInfo &info)
{
    DbStatus* dbStatus = DbStatus::getInstance();

    conn= dbStatus->getConn(this->user,this->password,this->url);
    this->prep_stmt = conn->prepareStatement("DELETE FROM Status WHERE statusID = ?");

    (this->prep_stmt)->setString(1, status.getStatusID());

    int updateCount = prep_stmt->executeUpdate();
    conn->commit();

    dbStatus->closeConn();
}
