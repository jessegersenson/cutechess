#!/bin/bash
if [[ ! -n "$1"  ]]
then
	echo ""
	echo "    DESCRIPTION: Compiles cutechess on centos"
	echo "    USAGE: $0 [# threads]"
	echo ""
	echo "Error! number of threads not given. Exiting"
	echo ""
	exit
fi


/usr/lib64/qt5/bin/qmake
make -j"$1"
