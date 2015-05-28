#ifndef BUTTON_H
  #define BUTTON_H

  #define CATCH_CONFIG_MAIN
  #include "catch.hpp"

  template <class KeyT, class ValT>
  class MapSimple {
    KeyT* keys;
    ValT* values;
    int nextFree = 0;
    int mapSize;
    public:
      MapSimple(int);
      void setForKey(KeyT, ValT);
      ValT getForKey(KeyT);
      int size();
  };

#endif