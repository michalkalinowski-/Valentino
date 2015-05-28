#include "map_simple.h"

template <class KeyT, class ValT> MapSimple<KeyT, ValT>::MapSimple(int size) {
  keys = new char[size];
  values = new int[size];
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

TEST_CASE( "Testing Map", "[setForKey]" ) {
    int testMapSize = 5;
    MapSimple<char, int> testMap(testMapSize);
    char key('a');

    testMap.setForKey(key, 666);

    REQUIRE( testMap.size() == 1);
    REQUIRE( testMap.getForKey(key) == 666 );

    SECTION("Map overrides values") {
      int currentSize = testMap.size();
      testMap.setForKey(key, 666);
      testMap.setForKey(key, 1);
      REQUIRE( testMap.getForKey(key) == 1 );
    }

    SECTION("Map doesn't crash on overflow") {
      for(int i = 0; i < testMapSize + 1; i++) {
        testMap.setForKey(key + i, 666);
      }
    }
}