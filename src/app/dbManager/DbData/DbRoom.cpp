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
     this->url=DBHOST;
     this->user=USER;
     this->password=PASSWORD;    
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

        conn = dbRoom->getConn(this->user,this->password,this->url);
        if(conn==NULL)
        {
          return;
         }
        this->prep_stmt = conn->prepareStatement("INSERT INTO tbl_Room(IDRoom,NameRoom) values(?,?)");
        if(this->prep_stmt==NULL)
         {
          return;
         }
        try{
        (this->prep_stmt)->setString(1, room.getRoomID());
        (this->prep_stmt)->setString(2, room.getNameRoom());
        int i=(this->prep_stmt)->executeUpdate();
        if(i>0)
         {
          std::cout<<"Them thanh cong";
         }
         else
         {
         std::cout<<"Them that bai";
         }
        }catch(sql::SQLException& e)
          {
            conn->rollback();
          }
         conn->commit();
         dbRoom->closeConn();
         
    }


    void DbRoom::select_to_db(sql::Connection* conn)
    {
        DbRoom* dbRoom = DbRoom::getInstance();

        stmt = conn->createStatement();

        conn = dbRoom->getConn(this->user,this->password,this->url);

        this->res = stmt->executeQuery("SELECT * FROM Room");

         while (res->next())
        {
            std::cout << res->getString("roomID") << std::endl;
        }
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        
        dbRoom->closeConn();
    }
    void DbRoom::update_to_db(sql::Connection* conn, Room room)
    {
        
        DbRoom* dbRoom = DbRoom::getInstance();

        conn= dbRoom->getConn(this->user,this->password,this->url);

        this->prep_stmt = conn->prepareStatement("UPDATE Room SET roomName = ? WHERE roomID = ?");

        (this->prep_stmt)->setString(1, room.getNameRoom());
        (this->prep_stmt)->setString(2, room.getRoomID());
        
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        dbRoom->closeConn();
    }
    void DbRoom::delete_to_db(sql::Connection* conn,Room room)
       {
         DbRoom* dbRoom = DbRoom::getInstance();

        dbRoom->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("DELETE FROM Room WHERE roomID = ?");

        (this->prep_stmt)->setString(1, room.getRoomID());

        int updateCount = prep_stmt->executeUpdate();
        conn->commit();

        dbRoom->closeConn();
    }
   
