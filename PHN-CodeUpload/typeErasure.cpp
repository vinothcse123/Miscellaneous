#include  <cstdio>

template<typename T>
struct DefaultDeleter
{
   void operator()(T *ptr) { printf("\n Default Deleter..."); delete ptr; }
};

template<typename T,typename Deleter=DefaultDeleter<T> >
class TypeErasureshared_ptr
{

   public:

      struct ObjectHolderBase
      {
         virtual void release()=0;
         virtual ~ObjectHolderBase() {}
      };

      template<typename Pointer_t,typename D>
         struct ObjectHolder : public ObjectHolderBase
      {
         Pointer_t *m_managedObjPtr;
         D m_deleter;

         ObjectHolder(Pointer_t *p_managedObjPtr,D p_deleter):
            m_managedObjPtr(p_managedObjPtr),
            m_deleter(p_deleter)
         {}

         void release()
         {
            m_deleter(m_managedObjPtr);
         }
      };


      TypeErasureshared_ptr(T *p_managedObjPtr):
         m_objHolderBasePtr( new ObjectHolder<T,Deleter>(p_managedObjPtr , Deleter()))
   {}


      TypeErasureshared_ptr(T *p_managedObjPtr,Deleter p_deleterObj):
         m_objHolderBasePtr( new ObjectHolder<T,Deleter>(p_managedObjPtr , p_deleterObj))
   {}

      ~TypeErasureshared_ptr()
      {
         // If reference count is 0

         m_objHolderBasePtr->release();

         delete m_objHolderBasePtr;
      }

   private:
      ObjectHolderBase *m_objHolderBasePtr;

};

struct ICacheDeleter
{
   void operator()(ICacheData* ptr)
   {
      cus::shared_ptr<CacheDataGarbageData> l_cacheGarbageSPtr(ptr);

      GarbageCollector::getInstance(). push( cus::dynamic_pointer_cast<GarbageData,CacheDataGarbageData>(l_cacheGarbageSPtr) );
   }
};


int main()
{
   TypeErasureshared_ptr<int,customDeleter> l_typeErasure(new int,customDeleter());
}
