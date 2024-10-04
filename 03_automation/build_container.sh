#!/bin/bash

./create_container.sh build 192.168.20.10

docker exec -it build git clone https://github.com/H-T-6221/cplus_sample.git
docker exec -it build chmod 755 cplus_sample/04_source/build.sh
docker exec -it build ./cplus_sample/04_source/build.sh

docker cp build:/root/cplus_sample/04_source/module .

docker stop build
docker rm build
