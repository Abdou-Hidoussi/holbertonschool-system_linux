#!/usr/bin/env sh
# Task 8
if [ $# != 1 ]
then
	echo "Usage: $0 <pid>"
	exit 1
fi
kill -QUIT "$1"
