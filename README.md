# Fibonacci - Wasm

## How to run the apps?

The app relies on the `yarn` package manager.

To run the app:

```
git clone https://github.com/gnunez-dev/fibonacci-wasm.git
cd fibonacci-wasm/
yarn install
yarn start
```

## File structure

### C++
  Source code of C++
  - src/lib/
      - fibonacciSequence.cpp

### React.js Components
  - src/components/
    - Container
    - Fibonacci

### WASM
  .wasm files after compiling the .cpp files

  - src/wasm/
      - main.js
      - main.wasm

### SHELL
  Commands for compiling .cpp files to .js files and .wasm files.
  You must install Emscripten before you can run this file.
  To compile new wasm files run the shell file: wasm.sh
  - Fibonacci: 
    - wasm.sh