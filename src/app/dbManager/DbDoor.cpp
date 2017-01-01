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
       this->url=DBHOST;
       this->user=USER;
       this->password=PASSWORD;
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

        conn = dbDoor->getConn(this->user,this->password,this->url);
        if(conn==NULL)
        {
             return;
        }
        this->prep_stmt = conn->prepareStatement("INSERT INTO Door(DoorID,DoorName) values(?,?)");
        if(this->prep_stmt==NULL)
        {
             return;
        }try{
        (this->prep_stmt)->setString(1, door.getIDDoor());
        (this->prep_stmt)->setString(2, door.getnameDoor());
        int i = (this->prep_stmt)->executeUpdate();
        if(i>0)
        {
          std::cout<<"Them thanh cong";
        }else
        {
          std::cout<<"Them that bai";
        }
        }catch(sql::SQLException& e)
          {
              conn->rollback(); 
          }
         conn->commit();
         dbDoor->closeConn();
    }

   void DbDoor::select_to_db(sql::Connection* conn)
    {
        DbDoor* dbDoor = DbDoor::getInstance();

        stmt = conn->createStatement();

        conn= dbDoor->getConn(this->user,this->password,this->url);

        this->res = stmt->executeQuery("SELECT * FROM Door");

         while (res->next())
        {
            std::cout << res->getString("DoorID") << std::endl;
        }
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        
        dbDoor->closeConn();
    }
    void DbDoor::update_to_db(sql::Connection* conn, Door door)
    {
        
        DbDoor* dbDoor = DbDoor::getInstance();

        conn=dbDoor->getConn(this->user,this->password,this->url);

        this->prep_stmt = conn->prepareStatement("UPDATE Door SET DoorName = ? WHERE DoorID = ?");

        (this->prep_stmt)->setString(1, door.getnameDoor());
        (this->prep_stmt)->setString(2, door.getIDDoor());
        
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        dbDoor->closeConn();
    }
    void DbDoor::delete_to_db(sql::Connection* conn,Door door)
    {
        DbDoor* dbDoor = DbDoor::getInstance();

        conn=dbDoor->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("DELETE FROM Door WHERE DoorID = ?");

        (this->prep_stmt)->setString(1, door.getIDDoor());

        int updateCount = prep_stmt->executeUpdate();
        conn->commit();

        dbDoor->closeConn();
    }
