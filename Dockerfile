FROM ubuntu:focal

RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config net-tools rsync openssh-server

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# expose port 22 
EXPOSE 22
