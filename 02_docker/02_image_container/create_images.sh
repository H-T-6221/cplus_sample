#!/bin/bash

# docker pull ubuntu:16.04
docker build -t image_ubuntu:latest -f Dockerfile .
docker images
