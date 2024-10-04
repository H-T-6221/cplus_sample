#!/bin/bash

./create_container.sh reciever 192.168.20.11
./create_container.sh sender 192.168.20.12

docker cp module/client reciever:/root
docker cp module/server sender:/root
