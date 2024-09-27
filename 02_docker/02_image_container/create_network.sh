#!/bin/bash

docker network rm container_nw
docker network create --subnet 192.168.20.0/24 container_nw
