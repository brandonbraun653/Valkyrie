# Move up to the repo root
cd ../../

# Create the build directory
mkdir -p ./build
cd ./build

cmake -DTOOLCHAIN=arm-linux-gnueabihf -DNATIVE_THREADS=ON -DCMAKE_BUILD_TYPE=Debug ./../