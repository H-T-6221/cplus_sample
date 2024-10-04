#!/bin/bash

docker exec -it /root/sender server &
docker exec -it /root/reciever client &
