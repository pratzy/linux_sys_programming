FROM ubuntu:focal

ADD scripts/docker_tzdata.sh /docker_tzdata.sh
RUN /docker_tzdata.sh

RUN apt-get install -y net-tools build-essential valgrind git cmake autoconf \
    libtool pkg-config net-tools rsync openssh-server cppcheck clang-tools clang-tidy clang-format \
    libboost-all-dev

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'PermitRootLogin yes' >> /etc/ssh/sshd_config && \
    echo 'PermitEmptyPasswords yes' >> /etc/ssh/sshd_config && \
    echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \
    ssh-keygen -A

# RUN git config --global user.name "Prateek Agarwal"
# RUN git config --global user.email "pratzy06@gmail.com"

# RUN git clone https://github.com/pratzy/linux_sys_programming.git
# expose port 22 and 55555 custom port
EXPOSE 22 55555

CMD ["/usr/sbin/sshd", "-D"]
