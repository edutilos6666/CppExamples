//
// Created by edutilos on 21.09.17.
//

#include "MysqlConnectorExample.h"

void MysqlConnectorExample::example1() {
    try {
        class MysqlPerson {
        private:
            long id;
            string name;
            int age;
            double wage;
            bool active;

        public:
            MysqlPerson() {

            }
            MysqlPerson(long id, string name, int age, double wage, bool active) {
                this->id = id;
                this->name = name;
                this->age = age;
                this->wage = wage;
                this->active = active;
            }

            MysqlPerson(string name, int age, double wage, bool active) {
                this->name = name;
                this->age = age;
                this->wage = wage;
                this->active = active;
            }

            string toString() const {
                stringstream ss ;
                ss << "[" << this->id << ", " << this->name
                   << ", " << this->age << ", " << this->wage
                   << ", " << this->active << "]";
                return ss.str();

            }

            long getId() const {
                return id;
            }

            void setId(long id) {
                MysqlPerson::id = id;
            }

            const string &getName() const {
                return name;
            }

            void setName(const string &name) {
                MysqlPerson::name = name;
            }

            int getAge() const {
                return age;
            }

            void setAge(int age) {
                MysqlPerson::age = age;
            }

            double getWage() const {
                return wage;
            }

            void setWage(double wage) {
                MysqlPerson::wage = wage;
            }

            bool isActive() const {
                return active;
            }

            void setActive(bool active) {
                MysqlPerson::active = active;
            }
        };




        sql::Driver *driver ;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *rs;
        sql::PreparedStatement *pstmt;
        driver = get_driver_instance();
        con = driver->connect("localhost", "root", "root");
        con->setSchema("test2");

        stmt = con->createStatement();

        // drop table if exists
        stringstream  sql;
        sql << "drop table if exists Person";
        stmt->executeUpdate(sql.str());

        //create table if not exists
        sql.str("");
        sql.clear();
        sql << "create table if not exists Person (" << endl;
        sql << "id bigint primary key , " << endl;
        sql << "name varchar(50) not null, " << endl;
        sql << "age int not null, " << endl;
        sql << "wage real not null, " << endl;
        sql << "active boolean not null)";
//        cout << sql.str() << endl;
        stmt->executeUpdate(sql.str());

        //insert some values
        sql.str("");
        sql.clear();
        sql << "insert into Person VALUES(?,?,?,?,?)";
        pstmt = con->prepareStatement(sql.str());

        vector<MysqlPerson> people;
        people.push_back(MysqlPerson(1, "foo", 10, 100.0, true));
        people.push_back(MysqlPerson(2, "bar", 20, 200.0, false));
        people.push_back(MysqlPerson(3, "bim", 30, 300.0, true));

        for(auto it = people.begin(); it != people.end(); ++it) {
            MysqlPerson p= *it;
            pstmt->setInt64(1, p.getId());
            pstmt->setString(2, p.getName());
            pstmt->setInt(3, p.getAge());
            pstmt->setDouble(4, p.getWage());
            pstmt->setBoolean(5, p.isActive());
            pstmt->executeUpdate();
        }


        //get all people
        sql.str("");
        sql.clear();
        sql << "select * from Person";
        rs = stmt->executeQuery(sql.str());
        cout << "<<all people>>" << endl;
        while(rs->next()) {
            long id = rs->getInt64(1);
            string name = rs->getString(2);
            int age = rs->getInt(3);
            double wage = rs->getDouble(4);
            bool active = rs->getBoolean(5);
            MysqlPerson p(id, name, age, wage, active);
            cout << p.toString() << endl;
        }

        cout << endl;

        //update
        sql.str("");
        sql.clear();
        sql << "update Person set name = ?, age = ?, wage = ?, active = ? " << endl;
        sql << "where id = ?" << endl;
        pstmt = con->prepareStatement(sql.str());

        pstmt->setString(1, "new_foo");
        pstmt->setInt(2, 66);
        pstmt->setDouble(3, 666.666);
        pstmt->setBoolean(4, false);
        pstmt->setInt64(5, 1);
        pstmt->executeUpdate();

        //get one
        sql.str("");
        sql.clear();
        sql << "select * from Person where id = ?";
        pstmt = con->prepareStatement(sql.str());
        pstmt->setInt64(1, 1);
        rs = pstmt->executeQuery();
        MysqlPerson p;
        while(rs->next()) {
            p.setId(rs->getInt64(1));
            p.setName(rs->getString(2));
            p.setAge(rs->getInt(3));
            p.setWage(rs->getDouble(4));
            p.setActive(rs->getBoolean(5));
        }

        cout << "p after update = " << p.toString() << endl;
        //remove one
        sql.str("");
        sql.clear();
        sql << "delete from Person where id = ?";
        pstmt = con->prepareStatement(sql.str());
        pstmt->setInt64(1, 1);
        pstmt->execute();
        //all
        sql.str("");
        sql.clear();
        sql << "select * from Person";
        rs = stmt->executeQuery(sql.str());
        cout << "<<all people after delete>>" << endl;
        while(rs->next()) {
            long id = rs->getInt64(1);
            string name = rs->getString(2);
            int age = rs->getInt(3);
            double wage = rs->getDouble(4);
            bool active = rs->getBoolean(5);
            MysqlPerson p(id, name, age, wage, active);
            cout << p.toString() << endl;
        }





        delete rs ;
        delete stmt;
        delete con;
//        delete driver ;    virtual ~Driver() is protected
    } catch(sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
