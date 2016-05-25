#include<iostream>
#include  <algorithm>
#include  <map>


template<typename T1,typename T2>
class KeyPair
{
   public:
      T1 key1;
      T2 key2;

      KeyPair(T1 a,T2 b): key1(a),key2(b) {}

      bool operator<(const KeyPair<T1,T2> &obj)const
      {
         if(key1 < obj.key1)
         {
            return true;
         }
         return false;
      }

};



int main()
{
   std::map<KeyPair<int,int>,int> l_timePeriodMap;
   l_timePeriodMap.insert( std::make_pair<KeyPair<int,int>,int>(KeyPair<int,int>(5,20),100) );

   return 0;
}

