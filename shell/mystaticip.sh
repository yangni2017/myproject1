#!bin/bash

ETC_DIR=/etc/sysconfig/network-scripts
NET_DIR=/etc/sysconfig

ROOT_UID=0

if [ "$UID" -ne "$ROOT_UID" ]
then
   echo "Must be root to run this script"
   exit 1
fi

cd $ETC_DIR || {
    echo "Cannot change to necessary directory,">&2
    exit 1
}

cat /dev/null  >ifcfg-eth0 && echo "clean ifcfg-eth0 ok!"
cat /home/yangni/staticip/myip >ifcfg-eth0 && echo "write eth0 sucessfully"


cd $NET_DIR || {
    echo "Cannot change to necessary directory,">&2
    exit 1
}

cat /dev/null  >network
cat /home/yangni/staticip/mynetwork > network && echo "write network sucessfully"

service network restart

exit 0
