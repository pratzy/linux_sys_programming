#!/usr/bin/env bash
set -e -x
# set noninteractive installation
export DEBIAN_FRONTEND=noninteractive
#install tzdata package
apt-get update && apt-get install -y tzdata
# set your timezone
ln -fs /usr/share/zoneinfo/Asia/Singapore /etc/localtime
dpkg-reconfigure --frontend noninteractive tzdata
