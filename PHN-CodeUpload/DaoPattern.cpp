/* Change the class name before posting */

#include  <stdio.h>

class ITransObjectManager // Interface
{
   protected:
      ITransObjectManager() {}
      virtual ~ITransObjectManager() {};

   public:
      virtual bool handleTransferObject()=0;
      void release();

      class Type
      {
         public:
            enum Type_t
            {
               GET_EMPLOYEE_INFO,
            };
      };
};


class IDaoFactory
{
   protected:
      IDaoFactory(){};
      virtual ~IDaoFactory(){}

   public:
      class StorageType
      {
         public:

            enum StorageType_t
            {
               MYSQL,
               ORACLE,
            };
      };

      static IDaoFactory* getFactoryType(StorageType::StorageType_t);
      void release();

      virtual ITransObjectManager* getTransferObjectHandler(ITransObjectManager::Type::Type_t)=0;

};


/* Concrete implemenation */

class MySqlDao : public IDaoFactory
{

   public:
      ITransObjectManager* getTransferObjectHandler(ITransObjectManager::Type::Type_t);
};


class OracleDao : public IDaoFactory
{

   public:
      ITransObjectManager* getTransferObjectHandler(ITransObjectManager::Type::Type_t);
};


/* Concrete TranferObjectHandler's */
class EmployeeInfoDao
{
   public:
      EmployeeInfoDao() {}

      class TranferObject
      {
         public:
            TranferObject(){emp_id=0;}
            int emp_id;
            int emp_name;
      };

      TranferObject m_emp_trans_obj;;
};


class EmployeeInfoMySqlDao : public EmployeeInfoDao, public ITransObjectManager
{
   public:
      bool handleTransferObject(); // Getting data using Mysql
};


class EmployeeInfoOracleDao : public EmployeeInfoDao, public ITransObjectManager
{
   public:
      bool handleTransferObject(); // Getting data using Oracle
};



IDaoFactory*  IDaoFactory::getFactoryType(StorageType::StorageType_t p_storage_type)
{
   switch(p_storage_type)
   {
      case StorageType::MYSQL:
         {
            return new MySqlDao();
         };
      case StorageType::ORACLE:
         {
            return new OracleDao();
         }
   }

   return NULL;
}

ITransObjectManager* OracleDao::getTransferObjectHandler(ITransObjectManager::Type::Type_t p_trans_obj_hand_type)
{
   switch(p_trans_obj_hand_type)
   {
      case ITransObjectManager::Type::GET_EMPLOYEE_INFO:
         return new EmployeeInfoOracleDao();
   }
   return NULL;
}


ITransObjectManager* MySqlDao::getTransferObjectHandler(ITransObjectManager::Type::Type_t p_trans_obj_hand_type)
{
   switch(p_trans_obj_hand_type)
   {
      case ITransObjectManager::Type::GET_EMPLOYEE_INFO:
         return new EmployeeInfoMySqlDao();
   }
   return NULL;
}


bool EmployeeInfoMySqlDao::handleTransferObject()
{
   printf("\n Mysql Rate");
   return true;
}

bool EmployeeInfoOracleDao::handleTransferObject()
{
   printf("\n Oracle Rate");
   return true;
}


//Application side usage

int main()
{

   IDaoFactory *l_factory= IDaoFactory::getFactoryType(IDaoFactory::StorageType::MYSQL);

   ITransObjectManager *l_transObjHandler= l_factory->getTransferObjectHandler(ITransObjectManager::Type::GET_EMPLOYEE_INFO);

   /* START :: QUESTION PART */

   // Need to set input independent of oracle or Mysql using transfer object, but currently it is dependent on the storage type

   EmployeeInfoMySqlDao *l_empInfoMysql = dynamic_cast<EmployeeInfoMySqlDao *>(l_transObjHandler);

   if(l_empInfoMysql)
   {
      l_empInfoMysql->m_emp_trans_obj.emp_id=10;
   }

   /* END :: QUESTION PART */

   /* Getting data using oracle */
   l_transObjHandler->handleTransferObject();

}

