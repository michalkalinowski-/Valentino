#include "map_simple.h"

template <class KeyT, class ValT> MapSimple<KeyT, ValT>::MapSimple(int size) {
  keys = new char[size];
  values = new int[size];
  mapSize = size;
}

template <class KeyT, class ValT> void MapSimple<KeyT, ValT>::setForKey(KeyT key, ValT value) {
  keys[nextFree] = key;
  values[nextFree] = value;
  nextFree++;
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

TEST_CASE( "Setter works", "[setForKey]" ) {
    MapSimple<char, int> testMap(10);
    char key('a');

    testMap.setForKey(key, 666);

    REQUIRE( testMap.size() == 1);
    REQUIRE( testMap.getForKey(key) == 666 );
}