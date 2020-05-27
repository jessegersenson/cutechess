FROM centos:8

RUN yum install -y zip wget qt5-qtbase-devel qt5-qtsvg-devel && \
   wget https://github.com/jessegersenson/cutechess/archive/master.zip && \
   unzip master.zip &&  yum groupinstall -y "Development Tools"

WORKDIR /cutechess-master
RUN /usr/lib64/qt5/bin/qmake && \
  make -j2

CMD ["/cutechess-master/projects/cli/cutechess-cli"]


~/tmp2$ cat Dockerfile
FROM centos:8

RUN yum install -y zip wget qt5-qtbase-devel qt5-qtsvg-devel && \
   wget https://github.com/jessegersenson/cutechess/archive/master.zip && \
   unzip master.zip &&  yum groupinstall -y "Development Tools"

WORKDIR /cutechess-master
RUN /usr/lib64/qt5/bin/qmake && \
  make -j2

CMD ["/cutechess-master/projects/cli/cutechess-cli"]
