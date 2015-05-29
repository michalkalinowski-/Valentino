#include "MapSimple.h"

#ifdef TESTING
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
#endif