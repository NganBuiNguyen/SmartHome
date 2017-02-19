    
    #include "DbPerson.h"
    
    
    DbPerson* DbPerson::instance = NULL;
    std::string DbPerson::database = DATABASE;
   

    DbPerson* DbPerson::getInstance()
    {
      if(instance == NULL)
      {
         instance= new DbPerson();
      }
      return instance;
    }

    sql::Connection* DbPerson::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver=get_driver_instance();
        this->conn=driver->connect(url,userName,password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }
    DbPerson::DbPerson()
    {
        this->url=DBHOST;
        this->user=USER;
        this->password=PASSWORD;
    }

    void DbPerson::closeConn()
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

    void DbPerson::insert_to_db(sql::Connection* conn,Person person)
    {
        DbPerson* dbPerson = DbPerson::getInstance();

        conn = dbPerson->getConn(this->user,this->password,this->url);
        if(conn==NULL)
        {
            return;
        }
        this->prep_stmt = conn->prepareStatement("INSERT INTO Person(personID,personName,cardID,age,grantPerson) values(?,?,?,?)");
        if(this->prep_stmt==NULL)
        {
             return;
        }
        try{
        Card card;
        (this->prep_stmt)->setString(1, person.getPersonID());
        (this->prep_stmt)->setString(2, person.getPersonName());
        (this->prep_stmt)->setString(3, card.getCardID());
        (this->prep_stmt)->setInt(4, person.getAge());
        (this->prep_stmt)->setBoolean(5, person.getGrantPerson());

        int i=(this->prep_stmt)->executeUpdate();
        if(i>0)
        {
            std::cout<<"Them thanh cong";
        }else{
            std::cout<<"Them that bai";
          }
        }catch(sql::SQLException& e)
        {
            conn->rollback();
        }
        conn->commit();
         dbPerson->closeConn();
    }
    void DbPerson::select_to_db(sql::Connection* conn)
    {
        DbPerson* dbPerson = DbPerson::getInstance();

        stmt = conn->createStatement();

        conn= dbPerson->getConn(this->user,this->password,this->url);

        this->res = stmt->executeQuery("SELECT * FROM Person");

         while (res->next())
        {
            std::cout << res->getString("personID") << std::endl;
        }
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        
        dbPerson->closeConn();
    }
    void DbPerson::update_to_db(sql::Connection* conn, Person person)
    {
        
        DbPerson* dbPerson = DbPerson::getInstance();

        conn=dbPerson->getConn(this->user,this->password,this->url);

        this->prep_stmt = conn->prepareStatement("UPDATE Person SET personName = ? age = ? WHERE personID = ?");

        (this->prep_stmt)->setString(1, person.getPersonName());
        (this->prep_stmt)->setInt(2, person.getAge());
        (this->prep_stmt)->setString(3, person.getPersonID());
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        dbPerson->closeConn();
    }
    void DbPerson::delete_to_db(sql::Connection* conn,Person person)
    {
        DbPerson* dbPerson = DbPerson::getInstance();

        conn=dbPerson->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("DELETE FROM Person WHERE personID = ?");

        (this->prep_stmt)->setString(1, person.getPersonID());

        int updateCount = prep_stmt->executeUpdate();
        conn->commit();

        dbPerson->closeConn();
    }


