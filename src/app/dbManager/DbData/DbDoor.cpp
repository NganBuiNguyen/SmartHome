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

bool DbDoor::insert_to_db_Door(const CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    
    this->prep_stmt = MYSQL_DB_CONNECTION->prepareStatement("INSERT INTO tbl_Door(IDDoor, NameDoor, Ip , Port) values(?,?,?,?)");
    if(this->prep_stmt==NULL)
    {
         return false;
    }

    int result = NO_ROW_EFFECTED;
    try{
        (this->prep_stmt)->setString(1, info.door.idDoor);
        (this->prep_stmt)->setString(2, info.door.nameDoor);
        (this->prep_stmt)->setString(3, info.door.ip);
        (this->prep_stmt)->setString(4, info.door.port);

        result = (this->prep_stmt)->executeUpdate();

        if(result < NO_ROW_EFFECTED)
        {
            return false;
        }
    }catch(sql::SQLException& e)
      {
          MYSQL_DB_CONNECTION->rollback(); 
      }
    conn->commit();
    this->closeConn();
    return true;
}

bool DbDoor::select_to_db_Door(sql::Connection* conn)
{
    stmt = MYSQL_DB_CONNECTION->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_Door");

     while (res->next())
    {
        std::cout << res->getString("IDDoor") << std::endl;
    }

    MYSQL_DB_CONNECTION->commit();
    
    this->closeConn();
    return true;
}

bool DbDoor::update_to_db_Door(sql::Connection* conn, CardInfo &info)
{
    
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);

    this->prep_stmt = conn->prepareStatement("UPDATE tbl_Door SET NameDoor = ? WHERE IDDoor = ?");

    if (this->prep_stmt == NULL)
    {
        return false;
    }
    int result = NO_ROW_EFFECTED;

    try
    {
    (this->prep_stmt)->setString(1, info.door.nameDoor);
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

bool DbDoor::delete_to_db_Door(sql::Connection* conn, CardInfo &info)
{
    MYSQL_DB_CONNECTION->setSchema(DATABASE);
    MYSQL_DB_CONNECTION->setAutoCommit(0);
    this->prep_stmt = conn->prepareStatement("DELETE FROM tbl_Door WHERE IDDoor = ?");

    (this->prep_stmt)->setString(1, info.door.idDoor);

    int updateCount = prep_stmt->executeUpdate();

    MYSQL_DB_CONNECTION->commit();

    this->closeConn();
    return true;
}
