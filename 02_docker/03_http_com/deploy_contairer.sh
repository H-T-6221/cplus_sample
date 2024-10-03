#!/bin/bash

./create_container.sh reciever 192.168.20.10
./create_container.sh sender 192.168.20.20

docker cp module/client reciever:/root
docker cp module/server sender:/root
