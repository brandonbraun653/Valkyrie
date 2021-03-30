
# Move up to the repo root
cd ../../

# Create the build directory
mkdir -p ./build
cd ./build

cmake -DTOOLCHAIN=gcc -DCOVERAGE=ON -DGTEST=ON -DFREERTOS_THREADS=ON -DCUSTOM_FREERTOS_CFG=ON -DDEVICE_TARGET=sim -DCMAKE_BUILD_TYPE=Debug ./../