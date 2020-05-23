#!/usr/bin/sh
set -e -x
sudo apt install docker.io docker-compose
sudo systemctl enable --now docker
sudo usermod -aG docker ${USER}
sudo systemctl restart docker