#ifndef MAPSIMPLE_H
  #define MAPSIMPLE_H

  #ifdef TESTING
    #define CATCH_CONFIG_MAIN
    #include "catch.hpp"
  #endif

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

template <class KeyT, class ValT> MapSimple<KeyT, ValT>::MapSimple(int size) {
  keys = new KeyT[size];
  values = new ValT[size];
  mapSize = size;
}

template <class KeyT, class ValT> void MapSimple<KeyT, ValT>::setForKey(KeyT key, ValT value) {
  for (int i = 0; i<mapSize; i++) {
    if (keys[i] == key) {
        values[i] = value;
        return;
    }
  }
  // it's a new key
  if (nextFree < mapSize) {
    keys[nextFree] = key;
    values[nextFree] = value;
    nextFree++;
  }
}

template <class KeyT, class ValT> ValT MapSimple<KeyT, ValT>::getForKey(KeyT key) {
  for (int i = 0; i<mapSize; i++) {
    if (key == keys[i]) {
      return values[i];
    }
  }
}

template <class KeyT, class ValT> int MapSimple<KeyT, ValT>::size() {
  return nextFree;
}

#endif