
mkdir -p ./build
cd ./build
rm -rf ./*

cmake -DTOOLCHAIN=gcc -DNATIVE_THREADS=ON -DDEVICE_TARGET=sim -DCMAKE_BUILD_TYPE=Debug ./../