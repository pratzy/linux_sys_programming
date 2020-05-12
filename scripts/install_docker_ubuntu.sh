#!/usr/bin/sh
set -e -x
sudo apt install docker.io
sudo systemctl enable --now docker
sudo usermod -aG docker ${USER}
sudo systemctl restart docker