#!/bin/bash

docker exec -it sender /root/server &
docker exec -it reciever /root/client &
