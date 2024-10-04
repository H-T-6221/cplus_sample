#!/bin/bash

./create_container.sh build 192.168.20.10

docker exec -it build git clone https://github.com/H-T-6221/cplus_sample.git
