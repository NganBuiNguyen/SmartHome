 #include "DbRoom.h"

    
    DbRoom* DbRoom::instance = NULL;
    std::string DbRoom::database = DATABASE;
   

    DbRoom* DbRoom::getInstance()
    {
      if(instance == NULL)
      {
         instance= new DbRoom();
      }
      return instance;
    }
    sql::Connection* DbRoom::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver=get_driver_instance();
        this->conn=driver->connect(url,userName,password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }
    DbRoom::DbRoom()
    {

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
        if(this->conn !=NULL)
        {
            this->conn->close();
            delete this->conn;
        }
    }
    void DbRoom::insert_node_to_db(sql::Connection* conn,Room room)
    {
        DbRoom* dbRoom = DbRoom::getInstance();

        dbRoom->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("INSERT INTO Room(roomID,roomName) values(?,?)");
        (this->prep_stmt)->setString(1, room.getRoomID());
        (this->prep_stmt)->setString(2, room.getNameRoom());
        
         dbRoom->closeConn();
    }
   