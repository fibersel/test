FROM centos:7

ADD ./Counter /app/Counter
ADD ./CMakeLists.txt /app

RUN yum install -y gcc \ 
                   gcc-c++ \
                   make

RUN yum install -y http://repo.okay.com.mx/centos/7/x86_64/release/okay-release-1-1.noarch.rpm
RUN yum install -y cmake3 

RUN yum install -y centos-release-scl-rh
RUN yum install -y devtoolset-9

ENV CC=/opt/rh/devtoolset-9/root/usr/bin/gcc
ENV CXX=/opt/rh/devtoolset-9/root/usr/bin/g++

WORKDIR /app/build
RUN cmake3 .. && make Counter

ENTRYPOINT ["./Counter/Counter"]
