 #include "DbDoor.h"

    
    DbDoor* DbDoor::instance = NULL;
    std::string DbDoor::database = DATABASE;
   

    DbDoor* DbDoor::getInstance()
    {
      if(instance == NULL)
      {
         instance= new DbDoor();
      }
      return instance;
    }
    sql::Connection* DbDoor::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver=get_driver_instance();
        this->conn=driver->connect(url,userName,password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }
    DbDoor::DbDoor()
    {

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
        if(this->conn !=NULL)
        {
            this->conn->close();
            delete this->conn;
        }
    }
    void DbDoor::insert_node_to_db(sql::Connection* conn,Door door)
    {
        DbDoor* dbDoor= DbDoor::getInstance();

        dbDoor->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("INSERT INTO Door(DoorID,DoorName) values(?,?)");
        (this->prep_stmt)->setString(1, door.getDoorID());
        (this->prep_stmt)->setString(2, door.getNameDoor());
        
         dbDoor->closeConn();
    }
   