#!/bin/bash

container_name=$1
ip_address=$2
network_name="container_nw"

docker run -it -d --network ${network_name} --ip ${ip_address} --name ${container_name} image_ubuntu
docker ps

docker exec -it ${container_name} bash
