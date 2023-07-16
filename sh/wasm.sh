emcc --bind -O3 --no-entry -s ALLOW_MEMORY_GROWTH -s MALLOC=emmalloc -s MODULARIZE=1 -s EXPORT_ES6=1 -s ENVIRONMENT=web -s USE_BOOST_HEADERS=1 -std=c++14 ../src/lib/fibonacciSequence.cpp -o ../src/wasm/main.js

